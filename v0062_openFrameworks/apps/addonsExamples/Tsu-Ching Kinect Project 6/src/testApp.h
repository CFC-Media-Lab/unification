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
	
	vector<ofPoint*>		cloudPts; // Stores points of point cloud
	vector<ofPoint*>		attractPts; // Stores points of attraction
	
	int		pointCloudX, pointCloudY; // Transform coordinates of point cloud

	
/****************** BALL *****************/

	float ballPositionX;
	float ballPositionY;
	float ballVelocityX;
	float ballVelocityY;

	
/****************** Particle System *****************/

	float timeStep;
	int lineOpacity, pointOpacity;
	float particleNeighborhood, particleRepulsion;
	float centerAttraction;
	
	int kParticles;
	ParticleSystem particleSystem;
	bool isMousePressed, keyAIsDown, slowMotion;
	
	
/****************** Background *****************/
	
	ofVideoPlayer video;
	ofImage img;
	
};

#endif
