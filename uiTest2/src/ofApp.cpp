#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    state = 0;

    for (int i = 0; i < 10; i++){
        myButtons[i].pos.set(300 + i * 60, 768 - 50);
        myButtons[i].radius = 20;
    }



}

//--------------------------------------------------------------
void ofApp::update(){

    for (int i = 0; i < 10; i++){
        myButtons[i].pos.set(300 + i * 60, 500 + 200 * sin(ofGetElapsedTimef()*(i*0.1 + 1)));
    }
    
    
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
        myButtons[i].draw();
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

    
    for (int i = 0; i < 10; i++){
        bool bPressed = myButtons[i].mousePressed(x,y);
        if (bPressed){
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
