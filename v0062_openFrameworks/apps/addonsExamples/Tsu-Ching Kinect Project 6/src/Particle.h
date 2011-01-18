#pragma once

#include "ofMain.h"
#include "ofGraphics.h"

class Particle {
public:
	float x, y;
	float xv, yv;
	float xf, yf;
	Particle(float _x = 0, float _y = 0,
		float _xv = 0, float _yv = 0) :
		x(_x), y(_y),
		xv(_xv), yv(_yv) {
	}
	void updatePosition(float timeStep) {
		// f = ma, m = 1, f = a, v = int(a)
		xv += xf;
		yv += yf;
		x += xv * timeStep;
		y += yv * timeStep;
	}
	void resetForce() {
		xf = 0;
		yf = 0;
	}
	void bounceOffWalls(float left, float top, float right, float bottom, float damping = .3) {
		bool collision = false;

		if (x > right){
			x = right;
			xv *= -1;
			collision = true;
		} else if (x < left){
			x = left;
			xv *= -1;
			collision = true;
		}

		if (y > bottom){
			y = bottom;
			yv *= -1;
			collision = true;
		} else if (y < top){
			y = top;
			yv *= -1;
			collision = true;
		}

		if (collision == true){
			xv *= damping;
			yv *= damping;
		}
	}
	void addDampingForce(float damping = .01) {
		xf = xf - xv * damping;
    yf = yf - yv * damping;
	}
	void draw() {
		
		//glEnable(GL_POINT_SMOOTH);
		glPointSize(ofRandom(1, 5));
		ofSetColor(255, 255, 255, 100);
		ofCircle(x, y, ofRandom(1,3));
		//glColor3f(ofRandom(10, 230), ofRandom(10, 230), ofRandom(10, 230));
		glBegin(GL_LINES);
		ofSetColor(255, 255, 255, 80);
		glVertex2f(x-ofRandom(1,10), y);
		glVertex2f(x+ofRandom(1,10), y);
		glEnd();
		glBegin(GL_LINES);
		ofSetColor(255, 255, 255, 80);
		glVertex2f(x, y-ofRandom(1,10));
		glVertex2f(x, y+ofRandom(1,10));
		glEnd();
	}
};
