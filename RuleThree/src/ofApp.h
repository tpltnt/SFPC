#pragma once

#include "ofMain.h"
#include "Student.h"
#define NSTUDENTS 100

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    
    
    //----------for lerping from pt A to pt B--------------------
    ofPoint aStart;
    ofPoint bEnd;
    
    float pct;
    
    //---------------for drawing a line into a shader------------
    ofFbo       lineFbo;
    ofImage     rockImage;
    ofPolyline  line;
    ofShader    shader;
    
    
    Student myStudentA;
    Student myStudentB;
    Student myStudentC;
    Student myStudentD;
    Student myStudentE;
    Student myStudentF;
    Student myStudent[NSTUDENTS];
    
    ofTrueTypeFont 	IntroBlack;
    char ThereisOnly[255];
    ofColor salmon;
    ofColor tan;
    ofColor yellow;
    ofColor brown;
    ofColor green;
    ofColor royal;
    ofColor blue;
    ofColor pink;
    ofImage studentA, studentB, studentC;
    ofImage BGtemp;
		
};
