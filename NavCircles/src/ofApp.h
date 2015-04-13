#pragma once

#include "ofMain.h"

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
    
    ofColor col;
    ofColor color;
    
    
    char eventString[255];  // when do i use these floats?
    char eventStringB[255];  // when do i use these floats?
    char timeString[255];   // whats a char?
    
    unsigned long last;
    int counter;
    int Myradius;
    int Mousereact;
    
    void drawGradient();
    
    ofImage imggrad;
    ofImage FU;
    ofImage img;
    ofTrueTypeFont 	NTSAkkhara;
    
    ofPtr<ofCairoRenderer> cairo;
    ofPtr<ofBaseRenderer> opengl;
    ofTexture tex;
    
    ofColor myPurple = ofColor :: crimson;
    ofColor Pink = ofColor :: hotPink;
    ofColor Blue = ofColor :: skyBlue;
    ofColor myOutlines = ofColor :: black;
    ofColor green = ofColor :: aquamarine;
    ofColor Aqua = ofColor :: aquamarine;
    ofColor MedAqua = ofColor :: mediumAquaMarine;
    ofColor Salmon = ofColor :: salmon;
    ofColor Gold = ofColor :: gold;
    ofColor yellow;
    

		
};
