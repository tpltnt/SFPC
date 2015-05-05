#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
    
    ofxPanel panel[8];
    ofParameter <int> peaks[8];
    ofParameter <float> amplitude[8];
    ofParameter <float> radius[8];
    ofParameter <float> noiseModFactor[8];
    ofParameter <float> velocity[8];
    ofParameter <float> LineWeight[8];
    
    
    
//    ofxPanel panelA;
//    ofParameter <int> peaksA;
//    ofParameter <float> amplitudeA;
//    ofParameter <float> radiusA;
//    ofParameter <float> noiseModFactorA;
//    ofParameter <float> velocityA;
//    ofParameter <float> LineWeightA;
//    
//    ofxPanel panelB;
//    ofParameter <int> peaksB;
//    ofParameter <float> amplitudeB;
//    ofParameter <float> radiusB;
//    ofParameter <float> noiseModFactorB;
//    ofParameter <float> velocityB;
//     ofParameter <float> LineWeightB;
    
    ofTrueTypeFont 	IntroBlack;
    ofTrueTypeFont 	IntroBlackLrg;
    char ThereisOnly[255];
    char WORK [255];
    ofColor salmon;
    ofColor tan;
    ofColor yellow;
    ofColor brown;
    ofColor green;
    ofColor royal;
    ofColor blue;
    ofColor pink;
    
    
    
};
