#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    state = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    if (state == 0){
        ofBackground(0);
    } else if (state == 1){
        ofBackground(127);
    } else if (state == 2){
        ofBackground(ofColor::yellowGreen);
    }
    
    
    for (int i = 0; i < 10; i++){
        ofCircle(300 + i * 60, 768 - 50,20);
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

    
    ofPoint mousePt;
    mousePt.set(x,y);
    
    
    for (int i = 0; i < 10; i++){
        ofPoint myPt(300 + i * 60, 768 - 50);
        float distance = (myPt - mousePt).length();
        if (distance < 20){
            state = i;
        }
    }
    
    
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
