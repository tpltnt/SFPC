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
    
    ofxPanel panelA;
    ofParameter <int> peaksA;
    ofParameter <float> amplitudeA;
    ofParameter <float> radiusA;
    ofParameter <float> noiseModFactorA;
    ofParameter <float> velocityA;

    ofxPanel panelB;
    ofParameter <int> peaksB;
    ofParameter <float> amplitudeB;
    ofParameter <float> radiusB;
    ofParameter <float> noiseModFactorB;
    ofParameter <float> velocityB;


    
    
    
};
