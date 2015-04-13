#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    NTSAkkhara.loadFont("NTSAkkhara.ttf", 32); //font size

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor myColor;    // create a color variable
    int randomNumber = (int) ofRandom(0,100);
    int navcirc;
    int addcolor = 0;
    float distance = 100;
    int circlesTotal = 10;
    int addedcolorR = 100;
    int addedcolorG = 100;
    int addedcolorB = 100;
    for (navcirc = 0; navcirc < circlesTotal; navcirc++) {
        ofSetColor(myColor);    // set the draw color to this.
        myColor.setHsb(ofMap(navcirc, 0, circlesTotal, 0, 255), 190, 255);     // set it's color via hsb, map navcirc to 0 to 255 (ie, go one way around the circle during the for loop)
        ofCircle(-60*navcirc+ofGetWidth()-40,ofGetHeight()-60,20);
        int currentCircle = circlesTotal - navcirc;
        ofSetColor(0);
        NTSAkkhara.drawString(ofToString(currentCircle), -60*navcirc+ofGetWidth()-50,ofGetHeight()-50);
    }
    
    


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
