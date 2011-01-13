#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"

#include "ofxOpenCv.h"
#include "ofxKinect.h"
#include "ParticleSystem.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();
	
		void drawPointCloud();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

/*********************** CAM Video *****************/

		ofTexture mirrorTexture;

		unsigned char * videoMirror;
		unsigned char * previousFrame;
	    unsigned char * frameDifferencing;
		
		int diffThreshold;
		
		int camWidth;
		int camHeight;
	
		ofImage img;
	
/****************** END of CAM Video *****************/
	
	
	
/****************** Kinect Video *****************/
	
	ofxKinect kinect;
	
	ofxCvColorImage		colorImg;
	
	ofxCvGrayscaleImage 	grayImage;
	ofxCvGrayscaleImage 	grayThresh;
	ofxCvGrayscaleImage 	grayThreshFar;
	
	ofxCvContourFinder 	contourFinder;
	
	bool				bThreshWithOpenCV;
	
	int 				nearThreshold;
	int					farThreshold;
	
	int					angle;
	
	float				zDepth;
	
	vector<ofPoint*>		cloudPts;
	vector<ofPoint*>		attractPts;
	
/****************** END of Kinect Video *****************/

	
/****************** BALL *****************/

	float ballPositionX;
	float ballPositionY;
	float ballVelocityX;
	float ballVelocityY;
	
/****************** END of BALL *****************/

	
/****************** Particle System *****************/

	float timeStep;
	int lineOpacity, pointOpacity;
	float particleNeighborhood, particleRepulsion;
	float centerAttraction;
	
	int kParticles;
	ParticleSystem particleSystem;
	bool isMousePressed, keyAIsDown, slowMotion;
	
/****************** End ofParticle System *****************/
	
};

#endif
