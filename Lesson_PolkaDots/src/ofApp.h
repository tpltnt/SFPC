#pragma once
#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

struct Ball {
    int x;
    int y;
    int vx;
    int vy;
};

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
        
    void DrawPolkaDotCircle( float xPos, float yPos, float scale);
    
    
    float counter, LineEnd, LineStart;
    float MyOutlineWidth = 4;
    
      void drawPinkPolkaCircle(float xPos, float yPos, float scale);
    // when do i use these floats?
    
    Ball whiteBall;
    Ball yellowBall;
    
    
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
};

#endif


