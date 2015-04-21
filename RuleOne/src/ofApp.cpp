#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    sprintf(letterT, "T");
    sprintf(letterR, "R");
    sprintf(letterU, "U");
    sprintf(letterS, "S");
    sprintf(letterT2, "T");
    IntroBlack.loadFont("Intro Black.otf", 187); //font size
    Zach.loadImage("Zach.png");
    RuleOneeverything.loadImage("RuleOneeverything.png");
    
    salmon.setHsb(0,140,224);
    tan.setHsb(30,58,234); // (x/360*255, x/100*255, x/100*255)
    brown.setHsb(30,96,63);
    yellow.setHsb(34,150,234);
    green.setHsb(49,127,219);
    royal.setHsb(157,127,181);
    blue.setHsb(133,138,214);
    pink.setHsb(4,43,237);



}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //BG------white paper with light blue gridded lines--------------------
    ofBackground(255);
    ofSetColor( ofColor::lightBlue);
    ofSetLineWidth(1);
    for (int i = 0; i < ofGetWidth(); i = i + 20){
        ofLine(i,0,i, ofGetHeight());
        
    }
    
    for (int i = 0; i < ofGetHeight(); i = i + 20){
        ofLine(0, i, ofGetWidth(), i);
    }

//----------draw letters-----------------
    
    letterheight = 380;
    ofMap(intalpha, 0, 0, ofGetWidth()-100, 50);
    intalpha = mouseX;
    ofSetColor(224,103,99,intalpha);
    IntroBlack.drawString(letterT, 235,letterheight);
    ofSetColor(245,155,181,intalpha);
    IntroBlack.drawString(letterR, 405,letterheight);
    ofSetColor(200,221,109,intalpha);
    IntroBlack.drawString(letterU, 605,letterheight);
    ofSetColor(98,196,215,intalpha);
    IntroBlack.drawString(letterS, 805, letterheight);
    ofSetColor(245,155,181,intalpha);
    IntroBlack.drawString(letterT2, 1005,letterheight);
    
    
    ofSetColor(brown);
    RuleOneeverything.draw(50,50,1328,754);
    Zach.draw(mouseX,430,484,430);

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
