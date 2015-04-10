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
    void drawanM(float xPos, float yPos, float scale);
    void drawaU(float xPos, float yPos, float scale);
    void drawHI(float xPos, float yPos, float scale);
     void drawanH(float xPos, float yPos, float scale);

    
    
    
    ofTrueTypeFont 	NTSAkkhara;
    
    char eventString[255];  // when do i use these floats?
    char timeString[255];   // whats a char?
    
    unsigned long last;
    int counter;
    ofColor col;
    int Myradius;
    int Mousereact;
    
    void drawGradient();
    
    ofImage imggrad;
    ofImage FU;
    ofImage img;
 
    

    
    
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
//    ofColor Yellow = ofColor::fromHex(0xF9FF4B);
//    ofColor Yellow = ofSetHexColor(0xff0000);
};

#endif


