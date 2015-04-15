#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    a.set(50,250); //width of 50, height of 250
    b.set(1000-50,250);
    

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofCircle(a, 10);
    ofCircle(b, 10);
    
    
    float mousePct = ofMap(mouseY, 0,ofGetHeight(),1,1); // pont1 range, point2 range, output between 01 and 1, and cap it
    

    float pct = 0.5; // scale of zero to one
    ofPoint mixPt = (1-pct) * a + pct * b;
        ofSetColor(ofColor:: fuchsia);
    ofCircle(mixPt,10);
    

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
