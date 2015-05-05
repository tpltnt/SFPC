#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    //
    //	ofBackground(0,0,0);
    
    ofSetCircleResolution(100);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //------draw gridded paper and type--------------------
    ofBackground(255);
    ofSetColor( ofColor::lightBlue);
    ofSetLineWidth(1);
    for (int i = 0; i < ofGetWidth(); i = i + 20){
        ofLine(i,0,i, ofGetHeight());
    }
    for (int i = 0; i < ofGetHeight(); i = i + 20){
        ofLine(0, i, ofGetWidth(), i);
    }

  
    
    
    float sinOfTime				= sin( ofGetElapsedTimef() );
    float sinOfTimeMapped		= ofMap( sinOfTime, -1, 1, 0, 255);
    
    
    float sinOfTime2			= sin( ofGetElapsedTimef() + PI);
    float sinOfTimeMapped2		= ofMap( sinOfTime2, -1, 1, 0, 255);
    
    ofSetColor(sinOfTimeMapped2, sinOfTimeMapped2, sinOfTimeMapped2);
    
    sin(ofGetElapsedTimef()); // moves from -1 and 1 every 2Pi seconds
    
    
    ofColor c;
    c.set(ofColor::pink);
    c.lerp( ofColor::blue,  ofMap(mouseX, 0, ofGetWidth(), 0, 1, true));
    ofSetColor(c);
    
    for (int i = 0; i < 20; i ++){
        float expander = (1 + i / 15.0);
        float sinValue = sin(ofGetElapsedTimef()*expander);
        ofCircle(500+sinValue*100*expander, 20*i, 7);
        
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
