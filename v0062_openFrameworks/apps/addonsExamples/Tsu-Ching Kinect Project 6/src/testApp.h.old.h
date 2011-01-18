
#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"
#include "ParticleSystem.h"

class testApp : public ofBaseApp
{

	public:

		void setup();
		void update();
		void draw();
        void exit();
	
	void drawPointCloud();

		void keyPressed  (int key);
		void keyReleased(int key);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

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
	int					pointCloudX;
	int					pointCloudY;
	
	vector<ofPoint*>		cloudPts;
	vector<ofPoint*>		attractPts;
	
	/****************** Particle System *****************/
	
	float timeStep;
	int lineOpacity, pointOpacity;
	float particleNeighborhood, particleRepulsion;
	float centerAttraction;
	
	int kParticles;
	ParticleSystem particleSystem;
	bool isMousePressed, keyAIsDown, slowMotion;
	
	
	/************** Video Background ********************/
	
	ofVideoPlayer 		video;
	ofImage				backgroundImg;
	
	

};

#endif
