#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	camWidth  = 1280; //1024; //640;
	camHeight = 720; //678; //480;
	
	ballPositionX = 150;
	ballPositionY = 150;
	ballVelocityX = ofRandom(-5, 5);
	ballVelocityY = ofRandom(-5, 5);
	
	vidGrabber.setVerbose(true);
	vidGrabber.initGrabber(camWidth, camHeight);
	
	videoMirror = new unsigned char[camWidth*camHeight*3];
	previousFrame = new unsigned char[camWidth*camHeight*3];
	frameDifferencing = new unsigned char[camWidth*camHeight*3];

	mirrorTexture.allocate(camWidth, camHeight, GL_RGB);
	
	img.loadImage("space.jpg");
	
	
	kinect.init();
	kinect.setVerbose(true);
	kinect.open();
	
	colorImg.allocate(kinect.width, kinect.height);
	grayImage.allocate(kinect.width, kinect.height);
	grayThresh.allocate(kinect.width, kinect.height);
	grayThreshFar.allocate(kinect.width, kinect.height);
	
	
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

	ofBackground(0, 0, 0);
	
	//ofSetColor(0xFFFFFF);
	ofSetColor(255, 255, 255, 95);
	img.draw(0, 0);
	
	ballPositionX += ballVelocityX;
	ballPositionY += ballVelocityY;
	
	if(ballPositionX < 0 || ballPositionX > ofGetWidth()) {
		ballVelocityX *= -1;
	}
	
	if (ballPositionY < 0 || ballPositionY > ofGetHeight()) {
		ballVelocityY *= -1;
	}
	
	kinect.update();
	
	//grayImage.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height);
	
	//we do two thresholds - one for the far plane and one for the near plane
	//we then do a cvAnd to get the pixels which are a union of the two thresholds.	
	/*if( bThreshWithOpenCV ){
		grayThreshFar = grayImage;
		grayThresh = grayImage;
		grayThreshFar.threshold(farThreshold, true);
		grayThresh.threshold(nearThreshold);
		cvAnd(grayThresh.getCvImage(), grayThreshFar.getCvImage(), grayImage.getCvImage(), NULL);
	}else{
		
		//or we do it ourselves - show people how they can work with the pixels
		
		unsigned char * pix = grayImage.getPixels();
		int numPixels = grayImage.getWidth() * grayImage.getHeight();
		
		for(int i = 0; i < numPixels; i++){
			if( pix[i] > nearThreshold && pix[i] < farThreshold ){
				pix[i] = 255;
			}else{
				pix[i] = 0;
			}
		}
	}
	
	//update the cv image
	grayImage.flagImageChanged();
	
    // find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
    // also, find holes is set to true so we will get interior contours as well....
    contourFinder.findContours(grayImage, 10, (kinect.width*kinect.height)/2, 20, false);
	
	*/
	
	// vidGrabber.grabFrame();
	//kinect.grabRgbFrame();
	
	if (kinect.isFrameNew()) { //vidGrabber.isFrameNew()) {
	
	
		//unsigned char * pixels = grayImage.getPixels();
		unsigned char * pixels = kinect.getCalibratedRGBPixels(); // vidGrabber.getPixels();
		//frameDifferencing = new unsigned char[camWidth*camHeight*3];

		
		int movementSum = 0;
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
				frameDifferencing[pix1] = ABS(videoMirror[pix1] - previousFrame[pix1]);
				frameDifferencing[pix2] = ABS(videoMirror[pix2] - previousFrame[pix2]);
				frameDifferencing[pix3] = ABS(videoMirror[pix3] - previousFrame[pix3]);
				
				// calculate frame differencing
				movementSum += frameDifferencing[pix1] + frameDifferencing[pix2] + frameDifferencing[pix3];
			}
		}
		
		unsigned char * tempFrame;
		
		// set new previous frame
		tempFrame = previousFrame;
		previousFrame = videoMirror;
		videoMirror = tempFrame;
		
		// set the video to display frame differencing
		//videoMirror = frameDifferencing;
		
		// if there is no movement, do not display all black screen
		if (movementSum > 0) {		
			//mirrorTexture.loadData(videoMirror, camWidth, camHeight, GL_RGB);
			mirrorTexture.loadData(frameDifferencing, camWidth, camHeight, GL_RGB);
		}
	} 
}

//--------------------------------------------------------------
void testApp::draw(){
	
	// display background
	//ofSetColor(255, 255, 255);
	img.draw(0, 0, ofGetWidth(), ofGetHeight()); // camWidth, camHeight);
	
	// make screen white before drawing the frame
	ofSetColor(255, 255, 255, 90);
	mirrorTexture.draw(0,0, camWidth*3.5, camHeight*4);
	
	ofCircle(ballPositionX, ballPositionY, 15);
	
	
	// draw depth and color view
	//kinect.drawDepth(10, 10, 200, 150);
	//kinect.draw(220, 10, 200, 150);
	//colorImg.mirror(false, true);
	//colorImg.draw(100,100);
	
	// draw point cloud
	ofPushMatrix();
	ofTranslate(800, 650);
	drawPointCloud();
	ofPopMatrix();

	 }

//--------------------------------------------------------------

void testApp::drawPointCloud() {
	ofScale(200, 200, 200);
	int w = 640;
	int h = 480;
	ofRotateY(mouseX);
	ofRotateX(mouseY);
	float* distancePixels = kinect.getDistancePixels();
	//printf("Current Distance: %f \n", kinect.getDistancePixels());
	
	glBegin(GL_POINTS);
	//glBegin(GL_LINES);
	int step = 8;
	for(int y = 8; y < h; y += step) {
		for(int x = 8; x < w; x += step) {
			
			//ofPoint cur = kinect.getWorldCoordinateFor(x, y);
			ofPoint cur = kinect.getWorldCoordinateFor(x-ofRandom(0, step), y-ofRandom(0,step));
			
			float curDistance = kinect.getDistanceAt(cur);	
			//printf("Current Distance: %f \n", curDistance);
		    
			// Display pixel if it is less than current distance
			if (cur.z < zDepth) {
				// set random colour to point
				//glColor3f(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
				ofColor curColor = kinect.getColorAt(cur);
				ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
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
		
		case 'z':
			zDepth ++;
			break;

		case 'x':
			zDepth --;
			break;

			
		case OF_KEY_UP:
			angle++;
			if(angle>30) angle=30;
			kinect.setCameraTiltAngle(angle);
			break;
			
		case OF_KEY_DOWN:
			angle--;
			if(angle<-30) angle=-30;
			kinect.setCameraTiltAngle(angle);
			break;
	}	

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

