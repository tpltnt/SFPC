#pragma once
#ifndef _TEST_APP
#define _TEST_APP

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
    
    void drawTexture(float x, float y, float w, float h,
                              float tx, float ty, float tw, float th);
        
    void DrawPolkaDotCircle( float xPos, float yPos, float scale);
    
    
    float LineEnd, LineStart;
    float MyOutlineWidth = 4;
    
      void drawPinkPolkaCircle(float xPos, float yPos, float scale);
    // when do i use these floats?
    
    ofTrueTypeFont 	NTSAkkhara;
    ofImage img;
    char eventString[255];
    char timeString[255];
    
    unsigned long last;
    int counter;
    ofColor col;
    

    
    
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
//    ofColor Yellow = ofColor::fromHex(0xF9FF4B);
//    ofColor Yellow = ofSetHexColor(0xff0000);
};

#endif


