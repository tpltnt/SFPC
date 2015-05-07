#pragma once
#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "particle.h"
#include "spring.h"

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

        ofImage Head;
        ofImage Ring;
        ofImage GeneralDuties;
        ofImage PullEverything;

        ofColor colors[7];
        ofPoint CirclePos[7];

        ofImage Art[7];
        string str = "Art";
        ofImage myImg;
        // ofImage Art1, Art2, Art3, Art4, Art5, Art6, Art7;
        float opactity[7];

        // let's make a vector of the particles
        vector <particle> particles;
        vector <spring> springs;		
};
#endif
