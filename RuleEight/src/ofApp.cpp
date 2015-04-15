#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    salmon.setHsb(0,5,88);
    tan.setHsb(43,79,192);
    atthesametimebrown.loadImage("atthesametimebrown.png");
    DontTrybrown.loadImage("DontTrybrown.png");
    RuleEightAnalyze.loadImage("RuleEightAnalyze.png");
    theyareblue.loadImage("theyareblue.png");
    theyaretan.loadImage("theyaretan.png");
    sprintf(RuleEightCreate, "CREATE");
    IntroBlack.loadFont("Intro Black.otf", 82); //font size


}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(255);

}

//--------------------------------------------------------------
void ofApp::draw(){
//BG
   
    ofSetColor( ofColor::lightBlue);
    ofSetLineWidth(1);
    for (int i = 0; i < ofGetWidth(); i = i + 20){
        ofLine(i,0,i, ofGetHeight());
        
    }
    
    for (int i = 0; i < ofGetHeight(); i = i + 20){
        ofLine(0, i, ofGetWidth(), i);
    }
    
//    RuleEightAnalyze.draw(0,0,ofGetWidth(),ofGetHeight());
    ofSetColor(salmon);
    
    IntroBlack.drawString(RuleEightCreate, 182,272);
//
//    atthesametimebrown.draw(493,732,543,79);
//    DontTrybrown.draw(520,30,435,116);
//    theyaretan.draw(0,245,100,317);
    ofSetColor(tan);
    ofRect(0,0,105,ofGetHeight());
    ofSetColor(salmon);
    theyareblue.draw(0,245,100,317);


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
