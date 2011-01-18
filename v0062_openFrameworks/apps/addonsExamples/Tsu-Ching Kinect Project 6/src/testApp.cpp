#include "testApp.h"

// For GUI
#include "ofxSimpleGuiToo.h"
#include "ofxVectorMath.h"
#include "ofxCvKalman.h"

// depth image stuff
ofxCvGrayscaleImage		depthOrig;
ofxCvGrayscaleImage		depthProcessed;
ofxCvContourFinder		depthContours;

// RGB image stuff
ofxCvColorImage			colorImageRGB;

// depth
bool	invert;
bool	mirror;
int		preBlur;
float	bottomThreshold;
float	topThreshold;
int		erodeAmount;
int		dilateAmount;
bool	dilateBeforeErode;

// contours
bool	findHoles;
bool	useApproximation;
float	minBlobSize;
float	maxBlobSize;
int		maxNumBlobs;

// transform
float	depthScale;
float	depthOffset;

// tracking
bool doKalman;
float lerpSpeed = 0.1;

ofxVec2f viewRot;


#define kNumPoints		500
ofxVec3f points[kNumPoints];
ofxVec3f curPoint;
int pointHead = 0;

ofxCvKalman *curPointSmoothed[3];


float updateKalman(int i, float v) {
	if(curPointSmoothed[i] == NULL) {
		curPointSmoothed[i] = new ofxCvKalman(v);
		return v;
	} else {
		return curPointSmoothed[0]->correct(v);
	}
}

void clearKalman(int i) {
	if(curPointSmoothed[i]) {
		delete curPointSmoothed[i];
		curPointSmoothed[i] = NULL;
	}
}


//--------------------------------------------------------------
void testApp::setup(){
	

	
	/************ SET UP BALL ***********************/

	// Initialize Ball
	ballPositionX = 150;
	ballPositionY = 150;
	ballVelocityX = ofRandom(-5, 5);
	ballVelocityY = ofRandom(-5, 5);
	
	/************ SET UP BACKGROUND ***********************/
	
	// Set the background
	ofBackground(0, 0, 0);

	// Load background picture
	//mirrorTexture.allocate(camWidth, camHeight, GL_RGB);
	img.loadImage("space.jpg");
	
	// Load background movie
	//video.loadMovie("MilkywayLow.mov");
	//video.play();
	
	/************ SET UP PARTICLE SYSTEM ***********************/
	
	//Initialize bins
	int binPower = 2;
	
	particleSystem.setup(ofGetWidth(), ofGetHeight(), binPower);
	
	kParticles = 2;
	float padding = 1;
	float maxVelocity = 1.5;
	for(int i = 0; i < kParticles * (ofGetWidth() - padding); i++) { 
		float x = ofRandom(padding, ofGetWidth() - padding);
		float y = ofRandom(padding, ofGetHeight() - padding);
		float xv = ofRandom(-maxVelocity, maxVelocity);
		float yv = ofRandom(-maxVelocity, maxVelocity);
		Particle particle(x, y, xv, yv);
		particleSystem.add(particle);
	}
	
	timeStep = 1;
	lineOpacity = 100; 
	pointOpacity = 255;
	isMousePressed = false;
	keyAIsDown = false;
	slowMotion = false;
	particleNeighborhood = 4;
	particleRepulsion = 1;
	centerAttraction = .05;
	
	/************ SET UP KINECT ***********************/
	
	ofSetVerticalSync(true);

	
	// Initialize Kinect
	kinect.init();
	kinect.setVerbose(true);
	kinect.enableDepthNearValueWhite(true);

	kinect.open();
	
	
	// Set up different camera views
	colorImg.allocate(kinect.width, kinect.height);
	grayImage.allocate(kinect.width, kinect.height);
	grayThresh.allocate(kinect.width, kinect.height);
	grayThreshFar.allocate(kinect.width, kinect.height);
	
	depthOrig.allocate(kinect.getWidth(), kinect.getHeight());
	depthProcessed.allocate(kinect.getWidth(), kinect.getHeight());
	
	colorImageRGB.allocate(kinect.getWidth(), kinect.getHeight());
	
	
	// Establish depth and threshold settings
	zDepth = 1.0;
	nearThreshold = 50;
	farThreshold  = 180;
	bThreshWithOpenCV = true;
	
	
	/******** SET UP GUI ***********************/
	
	gui.setup();
	gui.config->gridSize.x = 250;
	gui.addTitle("DEPTH PRE PROCESSING");
	gui.addToggle("invert", invert);
	gui.addToggle("mirror", mirror);
	gui.addSlider("preBlur", preBlur, 0, 20);
	gui.addSlider("bottomThreshold", bottomThreshold, 0, 1);
	gui.addSlider("topThreshold", topThreshold, 0, 1);
	gui.addSlider("erodeAmount", erodeAmount, 0, 10);
	gui.addSlider("dilateAmount", dilateAmount, 0, 10);
	gui.addToggle("dilateBeforeErode", dilateBeforeErode);
	
	gui.addTitle("CONTOURS");
	gui.addToggle("findHoles", findHoles);
	gui.addToggle("useApproximation", useApproximation);
	gui.addSlider("minBlobSize", minBlobSize, 0, 1);
	gui.addSlider("maxBlobSize", maxBlobSize, 0, 1);
	gui.addSlider("maxNumBlobs", maxNumBlobs, 0, 100);
	
	gui.addTitle("DEPTH TRANSFORM");
	gui.addSlider("depthScaling", depthScale, -100, 100);
	gui.addSlider("depthOffset", depthOffset, -128, 128);
	
	gui.addTitle("TRACKING");
	gui.addToggle("doKalman", doKalman);
	gui.addSlider("lerpSpeed", lerpSpeed, 0, 1);
	
	
	gui.addContent("depthOrig", depthOrig).setNewColumn(true);
	gui.addContent("depthProcessed", depthProcessed);
	gui.addContent("depthContours", depthContours);
	
	gui.loadFromXML();
	gui.setDefaultKeys(true);
	gui.show();
	
	
	GLfloat position[] = {ofGetWidth() * 0.6, ofGetHeight() * 0.3, -2000, 1.0 };
	GLfloat ambientLight[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat diffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
	
	GLfloat matShininess[] = { 50.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matShininess);
	
	glEnable(GL_LIGHT0);
	glShadeModel (GL_SMOOTH);
	glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ) ;
	glEnable ( GL_COLOR_MATERIAL ) ;	
	
	// init kalman
	curPointSmoothed[0] = NULL;
	curPointSmoothed[1] = NULL;
	curPointSmoothed[2] = NULL;
	
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	
	/************ UPDATE BALL ***********************/

	//Update ball position
	ballPositionX += ballVelocityX;
	ballPositionY += ballVelocityY;
	
	if(ballPositionX < 0 || ballPositionX > ofGetWidth()) {
		ballVelocityX *= -1;
	}
	
	if (ballPositionY < 0 || ballPositionY > ofGetHeight()) {
		ballVelocityY *= -1;
	}
	
	/************ UPDATE KINECT ***********************/

	kinect.update();
	
	// get color pixels
	colorImageRGB			= kinect.getPixels();
	
	// get depth pixels
	depthOrig = kinect.getDepthPixels();
	
	// save original depth, and do some preprocessing
	depthProcessed = depthOrig;
	if(invert) depthProcessed.invert();
	if(mirror) {
		depthOrig.mirror(false, true);
		depthProcessed.mirror(false, true);
		colorImageRGB.mirror(false, true);
	}
	if(preBlur) cvSmooth(depthProcessed.getCvImage(), depthProcessed.getCvImage(), CV_BLUR , preBlur*2+1);
	if(topThreshold) cvThreshold(depthProcessed.getCvImage(), depthProcessed.getCvImage(), topThreshold * 255, 255, CV_THRESH_TRUNC);
	if(bottomThreshold) cvThreshold(depthProcessed.getCvImage(), depthProcessed.getCvImage(), bottomThreshold * 255, 255, CV_THRESH_TOZERO);
	if(dilateBeforeErode) {
		if(dilateAmount) cvDilate(depthProcessed.getCvImage(), depthProcessed.getCvImage(), 0, dilateAmount);
		if(erodeAmount) cvErode(depthProcessed.getCvImage(), depthProcessed.getCvImage(), 0, erodeAmount);
	} else {
		if(erodeAmount) cvErode(depthProcessed.getCvImage(), depthProcessed.getCvImage(), 0, erodeAmount);
		if(dilateAmount) cvDilate(depthProcessed.getCvImage(), depthProcessed.getCvImage(), 0, dilateAmount);
	}
	depthProcessed.flagImageChanged();
	
	// find contours
	depthContours.findContours(depthProcessed,
							   minBlobSize * minBlobSize * depthProcessed.getWidth() * depthProcessed.getHeight(),
							   maxBlobSize * maxBlobSize * depthProcessed.getWidth() * depthProcessed.getHeight(),
							   maxNumBlobs, findHoles, useApproximation);
	
	
	// Clear old attraction points
	attractPts.clear();
	
	// Find centroid point for each blob area and add an attraction force to it
	for (int i=0; i<depthContours.blobs.size(); i++) {
		
		attractPts.push_back(new ofPoint(depthContours.blobs[i].centroid));
		//printf("Blob %d: %f %f \n", i, depthContours.blobs[i].centroid.x, depthContours.blobs[i].centroid.y);
	}
	
	// if one blob found, find nearest point in blob area
	static ofxVec3f newPoint;
	if(depthContours.blobs.size() == 1) {
		ofxCvBlob &blob = depthContours.blobs[0];
		
		depthOrig.setROI(blob.boundingRect);
		
		double minValue, maxValue;
		CvPoint minLoc, maxLoc;
		cvMinMaxLoc(depthOrig.getCvImage(), &minValue, &maxValue, &minLoc, &maxLoc, NULL);
		
		depthOrig.resetROI();
		
		newPoint.x = maxLoc.x + blob.boundingRect.x;
		newPoint.y = maxLoc.y + blob.boundingRect.y;
		//		newPoint.z = (maxValue + offset) * depthScale;	// read from depth map
		//printf("Min: %f %f Max: %f %f \n", minLoc.x, minLoc.y, maxLoc.x, maxLoc.y);
		
		// read directly from distance (in cm)
		// this doesn't seem to work, need to look into it
		newPoint.z = (kinect.getDistanceAt(newPoint) + depthOffset) * depthScale;
		
		// apply kalman filtering
		if(doKalman) {
			newPoint.x = updateKalman(0, newPoint.x);
			newPoint.y = updateKalman(1, newPoint.y);
			newPoint.z = updateKalman(2, newPoint.z);
		}

	} else {
		clearKalman(0);
		clearKalman(1);
		clearKalman(2);
	}
	
	pointHead = (pointHead + 1) % kNumPoints;
	curPoint += (newPoint - curPoint) * lerpSpeed;
	points[pointHead] = curPoint;
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	// Display background
	ofSetColor(255, 255, 255, 50);
	img.draw(0, 0, ofGetWidth(), ofGetHeight());
	
	// Draw ball
	ofSetColor(255, 150, 0);
	ofCircle(ballPositionX, ballPositionY, 10);
	
	/************ DRAW PARTICLE SYSTEM ***********************/
	
	particleSystem.setTimeStep(timeStep);
	
	ofEnableAlphaBlending();
	ofSetColor(251, 236, 93, lineOpacity);
	particleSystem.setupForces();
	
	// apply per-particle forces
	glBegin(GL_LINES);
	for(int i = 0; i < particleSystem.size(); i++) {
		Particle& cur = particleSystem[i];
		
		// global force on other particles
		particleSystem.addRepulsionForce(cur, particleNeighborhood, particleRepulsion);
		
		// forces on this particle
		cur.bounceOffWalls(0, 0, ofGetWidth(), ofGetHeight());
		cur.addDampingForce();
	}
	glEnd();
	
	// Apply attraction to selected points
	for (int i=0; i < attractPts.size(); i++) {
		particleSystem.addAttractionForce(attractPts[i]->x, attractPts[i]->y, ofGetWidth(), centerAttraction);
	}
		
	// Add repulsion force by mouse click
	if(isMousePressed)
		particleSystem.addRepulsionForce(mouseX, mouseY, 100, 10);
	
	// Set the ball to repulse
	particleSystem.addRepulsionForce(ballPositionX, ballPositionY, 25, 10);
	
	particleSystem.update();
	ofSetColor(255, 255, 255, pointOpacity);
	particleSystem.draw();
	ofDisableAlphaBlending();
	
	ofSetColor(255, 255, 255);
	//ofDrawBitmapString(ofToString(kParticles) + "k particles", 32, 32);
	//ofDrawBitmapString(ofToString((int) ofGetFrameRate()) + " fps", 32, 52);
	
	
	// draw depth and color view
	//kinect.drawDepth(10, 10, 200, 150);
	//kinect.draw(220, 10, 200, 150);
	//colorImg.mirror(false, true);
	//colorImg.draw(100,100);
	
	/************ DRAW POINT CLOUD ***********************/
	
	// draw point cloud
	pointCloudX = 800;
	pointCloudY = 800;
	
	ofSetColor(0, 0, 0);
	ofPushMatrix();
	ofTranslate(pointCloudX, pointCloudY);
	drawPointCloud();
	ofPopMatrix();
	
	// Make attraction with point
	/*for (int i=0; i < cloudPts.size(); i++) {
		particleSystem.addAttractionForce(cloudPts[i]->x + 800, cloudPts[i]->y + 650, 25, 1);
		//printf("Point Clouds: %f %f \n", cloudPts[i]->x, cloudPts[i]->y);
	} */

	

	// Rotate drawing
	if(depthContours.blobs.size() == 2) {
		ofxVec2f center = depthContours.blobs[0].centroid + depthContours.blobs[1].centroid;
		
		ofxVec2f targetViewRot;
		targetViewRot.x = ofMap(center.x, 0, ofGetWidth(), -360, 360);
		targetViewRot.y = ofMap(center.y, 0, ofGetHeight(), 360, -360);
		
		viewRot += (targetViewRot - viewRot) * 0.05;
	} else {
		viewRot -= viewRot * 0.05;
	}
	
	ofxVec3f camToWorld(ofGetWidth()/depthOrig.getWidth(), ofGetHeight()/depthOrig.getHeight(), 1);
	ofxVec3f up(0, 1, 0);
	
	
gui.draw();

	
	/********** Calculate 2D Coordinate from 3D Space ********/
	GLdouble screenX = 0;
	GLdouble screenY = 0;
	GLdouble screenZ = 0;
	
	GLint viewport[4];
	GLdouble mvmatrix[16], projmatrix[16];
	
	glGetIntegerv(GL_VIEWPORT, viewport);
	glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
	glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);
	
	gluProject(pointCloudX, pointCloudY, -3000,
			   mvmatrix, projmatrix, viewport,
			   &screenX, &screenY, &screenZ);
	
	screenY = ofGetHeight() - screenY;
	
	
	// Draws contours on the screen
	depthContours.draw(screenX, screenY, 640, 480);
	
	 }



//--------------------------------------------------------------


/************ CREATE POINT CLOUD ***********************/

void testApp::drawPointCloud() {
	ofScale(200, 200, 200);
	int w = 640;
	int h = 480;
	
	
	// Fixed rotation so that avatar is facing forward and mirrored
	ofRotateY(1268);
	
	float* distancePixels = kinect.getDistancePixels();
	//printf("Current Distance: %f \n", kinect.getDistancePixels());
	
	glPointSize(1);
	glBegin(GL_POINTS);
	int step = 2;
	for(int y = step; y < h; y += step) {
		for(int x = step; x < w; x += step) {
			
			//ofPoint cur = kinect.getWorldCoordinateFor(x, y);
			ofPoint cur = kinect.getWorldCoordinateFor(x-ofRandom(0, step), y-ofRandom(0,step));
			
			float curDistance = kinect.getDistanceAt(cur);	
			//printf("Current Distance: %f \n", curDistance);
		    
			// Display pixel if it is less than current distance
			if (cur.z < zDepth) {
				
				// Stores visible points on the point cloud
				cloudPts.push_back(new ofPoint(cur));	
				//printf("Point Clouds: %f %f \n", cur.x, cur.y);
				
				// set random colour to point
				ofColor curColor = kinect.getColorAt(cur);
				//glColor3f(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
				//ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
				//SetColor(curColor.r, curColor.g, curColor.b);
				//glColor3f(curColor.r/255.0, curColor.g/255.0, curColor.b/255.0);
				//printf("R: %f  G: %f  B: %f \n", curColor.r, curColor.g, curColor.b);
				
				// display point
				glVertex3f(cur.x, cur.y, cur.z);
			
			}
			
		}
	}
	glEnd();
	
	
}

//--------------------------------------------------------------
void testApp::exit(){
	kinect.close();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	switch (key)
	{
		case ' ':
			bThreshWithOpenCV = !bThreshWithOpenCV;
			break;
			
		case '>':
		case '.':
			farThreshold ++;
			if (farThreshold > 255) farThreshold = 255;
			break;
			
		case '<':
		case ',':		
			farThreshold --;
			if (farThreshold < 0) farThreshold = 0;
			break;
			
			
		case '+':
		case '=':
			nearThreshold ++;
			if (nearThreshold > 255) nearThreshold = 255;
			break;
			
		case '-':		
			nearThreshold --;
			if (nearThreshold < 0) nearThreshold = 0;
			break;
			
		case 'w':
			kinect.enableDepthNearValueWhite(!kinect.isDepthNearValueWhite());
			break;
		
		// z -- Increase point cloud depth	
		case 'z':
			zDepth ++;
			break;

		// x -- Decrease point cloud depth
		case 'x':
			zDepth --;
			break;
			
		case 'a':
			keyAIsDown = true;
			break;
			
		// p -- Screen capture	
		case 'p':
			ofSaveScreen(ofToString(ofGetMinutes()) + "_" + ofToString(ofGetFrameNum()) + ".png");
			break;
			
		case 's':
			slowMotion = !slowMotion;
			if(slowMotion)
				timeStep = .05;
			else
				timeStep = 1;
			break;
			
		case 'i':
			ofRotateY(mouseX);
			break;
		case 'o':
			ofRotateX(mouseY);
			break;
			
		// UP button -- Moves Kinect camera up
		case OF_KEY_UP:
			angle++;
			if(angle>30) angle=30;
			kinect.setCameraTiltAngle(angle);
			break;
			
		// DOWN button -- Moves Kinect camera down
		case OF_KEY_DOWN:
			angle--;
			if(angle<-30) angle=-30;
			kinect.setCameraTiltAngle(angle);
			break;
	}	

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	switch (key) {
		case 'a':
			keyAIsDown = false;
			attractPts.push_back(new ofPoint(mouseX, mouseY));
			break;
	}

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	isMousePressed = true;

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	isMousePressed = false;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

