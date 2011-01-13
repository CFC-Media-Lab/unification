#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	/************ SET UP BALL ***********************/

	// Initialize Ball
	ballPositionX = 150;
	ballPositionY = 150;
	ballVelocityX = ofRandom(-5, 5);
	ballVelocityY = ofRandom(-5, 5);
	
	/************ SET UP CAMERA & BACKGROUND ***********************/

	// Initialize camera setting
	camWidth  = 1280; //1024; //640;
	camHeight = 720; //678; //480;
	
	// Initialize mirror and frame differencing
	videoMirror = new unsigned char[camWidth*camHeight*3];
	previousFrame = new unsigned char[camWidth*camHeight*3];
	frameDifferencing = new unsigned char[camWidth*camHeight*3];
	diffThreshold = 20;

	// Set mirror image
	mirrorTexture.allocate(camWidth, camHeight, GL_RGB);
	
	// Set the background
	ofBackground(0, 0, 0);

	// Load background picture
	img.loadImage("space.jpg");
	
	/************ SET UP PARTICLE SYSTEM ***********************/
	
	//Initialize bins
	int binPower = 2;
	
	particleSystem.setup(ofGetWidth(), ofGetHeight(), binPower);
	
	kParticles = 2;
	float padding = 1;
	float maxVelocity = 1.5;
	for(int i = 0; i < kParticles * (ofGetWidth() - padding); i++) { //1024; i++) {
		float x = ofRandom(padding, ofGetWidth() - padding);
		float y = ofRandom(padding, ofGetHeight() - padding);
		float xv = ofRandom(-maxVelocity, maxVelocity);
		float yv = ofRandom(-maxVelocity, maxVelocity);
		Particle particle(x, y, xv, yv);
		particleSystem.add(particle);
	}
	
	timeStep = 1;
	lineOpacity = 100; //128;
	pointOpacity = 255;
	isMousePressed = false;
	keyAIsDown = false;
	slowMotion = false;
	particleNeighborhood = 4;
	particleRepulsion = 1;
	centerAttraction = .05;
	
	/************ SET UP KINECT ***********************/
	
	// Initialize Kinect
	kinect.init();
	kinect.setVerbose(true);
	kinect.open();
	
	
	// Set up different camera views
	colorImg.allocate(kinect.width, kinect.height);
	grayImage.allocate(kinect.width, kinect.height);
	grayThresh.allocate(kinect.width, kinect.height);
	grayThreshFar.allocate(kinect.width, kinect.height);
	
	
	// Establish depth and threshold settings
	zDepth = 1.0;
	nearThreshold = 50;
	farThreshold  = 180;
	bThreshWithOpenCV = true;
	
	//ofSetFrameRate(60);
	
	//angle = 0;
	//kinect.setCameraTiltAngle(angle);
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	// Display background
	//ofSetColor(255, 255, 255, 50);
	//img.draw(0, 0, ofGetWidth(), ofGetHeight());
	
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
	
	if (kinect.isFrameNew()) { 
		
		// Get frame's pixels
		unsigned char * pixels = kinect.getCalibratedRGBPixels();
	
		/************ MIRROR & FRAME DIFFERENCING ALGORITHM ***********************/
		
		int movementSum = 0; // initialize difference
		
		for (int i = 0; i < camHeight; i++) {
			for (int j = 0; j < camWidth*3; j+=3) {
				
				// pixel number
				int pix1 = (i*camWidth*3) + j;
				int pix2 = (i*camWidth*3) + (j+1);
				int pix3 = (i*camWidth*3) + (j+2);
				
				// mirror pixel number
				int mir1 = (i*camWidth*3)+1 * (camWidth*3 - j-3);
				int mir2 = (i*camWidth*3)+1 * (camWidth*3 - j-2);
				int mir3 = (i*camWidth*3)+1 * (camWidth*3 - j-1);
				
				// mirror new fame
				videoMirror[pix1] = pixels[mir1];
				videoMirror[pix2] = pixels[mir2];
				videoMirror[pix3] = pixels[mir3];
				
				// frame differencing
				
				/*frameDifferencing[pix1] = ABS(videoMirror[pix1] - previousFrame[pix1]);
				frameDifferencing[pix2] = ABS(videoMirror[pix2] - previousFrame[pix2]);
				frameDifferencing[pix3] = ABS(videoMirror[pix3] - previousFrame[pix3]);*/
				
				if ((frameDifferencing[pix1] = ABS(videoMirror[pix1] - previousFrame[pix1])) < diffThreshold) {
					frameDifferencing[pix1] = 0;
				}
				if ((frameDifferencing[pix2] = ABS(videoMirror[pix2] - previousFrame[pix2])) < diffThreshold) {
					frameDifferencing[pix2] = 0;
				} 
				if ((frameDifferencing[pix3] = ABS(videoMirror[pix3] - previousFrame[pix3])) < diffThreshold) {
					frameDifferencing[pix3] = 0;
				}
				
				// calculate frame differencing
				movementSum += frameDifferencing[pix1] + frameDifferencing[pix2] + frameDifferencing[pix3];
			}
			
			//printf("Pixel: %x \n", frameDifferencing[(1*camWidth*3) + 1]);
		}
		
		// set new previous frame
		unsigned char * tempFrame; // temp pointer to save location of previous frame
		tempFrame = previousFrame;
		previousFrame = videoMirror; // Set previous frame to current frame
		videoMirror = tempFrame;

		
		// if there is no movement, do not display all black screen
		if (movementSum > 0) {		
			mirrorTexture.loadData(frameDifferencing, camWidth, camHeight, GL_RGB);
		}
	} 
}

//--------------------------------------------------------------
void testApp::draw(){
	
	// Display background
	ofSetColor(255, 255, 255, 50);
	img.draw(0, 0, ofGetWidth(), ofGetHeight()); // camWidth, camHeight);
	
	// Make screen white before drawing the frame differencing
	//ofSetColor(255, 255, 255, 0.5);
	mirrorTexture.draw(0,0, camWidth*3.5, camHeight*4);
	
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
	
	// single global forces, uses the mouse as the attractor - for now
	//particleSystem.addAttractionForce(mouseX, mouseY, ofGetWidth(), centerAttraction); //ofGetWidth() / 2, ofGetHeight() / 2, ofGetWidth(), centerAttraction);
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
	ofPushMatrix();
	ofTranslate(800, 650);
	drawPointCloud();
	ofPopMatrix();
	
	// Make attraction with point
	/*for (int i=0; i < cloudPts.size(); i++) {
		particleSystem.addAttractionForce(cloudPts[i]->x + 800, cloudPts[i]->y + 650, 25, 1);
		
		//printf("Point Clouds: %f %f \n", cloudPts[i]->x, cloudPts[i]->y);
	} */
	
	//particleSystem.addAttractionForce(725, 725, ofGetWidth(), 200);
	
	//printf("Mouse positions: %d %d \n", mouseX, mouseY);
	

	 }

//--------------------------------------------------------------

/************ DRAW POINT CLOUD ***********************/

void testApp::drawPointCloud() {
	ofScale(200, 200, 200);
	int w = 640;
	int h = 480;
	
	float* distancePixels = kinect.getDistancePixels();
	//printf("Current Distance: %f \n", kinect.getDistancePixels());
	
	glBegin(GL_POINTS);
	//glBegin(GL_LINES);
	int step = 3;
	for(int y = step; y < h; y += step) {
		for(int x = step; x < w; x += step) {
			
			//ofPoint cur = kinect.getWorldCoordinateFor(x, y);
			ofPoint cur = kinect.getWorldCoordinateFor(x-ofRandom(0, step), y-ofRandom(0,step));
			
			float curDistance = kinect.getDistanceAt(cur);	
			//printf("Current Distance: %f \n", curDistance);
		    
			// Display pixel if it is less than current distance
			if (cur.z < zDepth) {
				
				cloudPts.push_back(new ofPoint(cur));	
				//printf("Point Clouds: %f %f \n", cur.x, cur.y);
				
				// set random colour to point
				//glColor3f(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
				ofColor curColor = kinect.getColorAt(cur);
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
		
		// d -- Increase difference threashold	
		case 'd':
			diffThreshold ++;
			break;
			
		// x -- Decrease difference threashold
		case 'f':
			diffThreshold --;
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

