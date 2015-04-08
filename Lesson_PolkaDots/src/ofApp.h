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
    
    void DrawPolkaDotCircle( float xPos, float yPos, float scale);
    
    
    float counter, LineEnd, LineStart;
    
      void drawPinkPolkaCircle(float xPos, float yPos, float scale);
    
    
    ofPtr<ofCairoRenderer> cairo;
    ofPtr<ofBaseRenderer> opengl;
    ofTexture tex;
    
    ofColor myPurple = ofColor :: crimson;
    ofColor myBlue = ofColor :: blue;
};


