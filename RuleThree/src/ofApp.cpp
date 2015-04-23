#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //---------------------------lerp ball------------------
    
    aStart.set(0,0);
    bEnd.set(ofGetWidth()/2, ofGetHeight()/2);
    
    pct = 0;

    //-------style sheets--------------------
    salmon.setHsb(0,140,224);
    tan.setHsb(30,58,234); // (x/360*255, x/100*255, x/100*255)
    brown.setHsb(30,96,63);
    yellow.setHsb(34,150,234);
    green.setHsb(49,127,219);
    royal.setHsb(157,127,181);
    blue.setHsb(133,138,214);
    pink.setHsb(4,43,237);
    sprintf(ThereisOnly, "THERE IS ONLY WORK");
    IntroBlack.loadFont("Intro Black.otf", 20); //font size
    studentA.loadImage("studentA.png");
    studentB.loadImage("studentB.png");
    studentC.loadImage("studentC.png");
    BGtemp.loadImage("BGtemp.png");
    
    //-------------load class--------------------------
        for(int i=0; i<NSTUDENTS; i++){
        
        int size = (i+1) * 10; // defining the size of each ball based on its place in the array
        int randomX = ofRandom( 0, ofGetWidth() ); //generate a random value bigger than 0 and smaller than our application screen width
        int randomY = ofRandom( 0, ofGetHeight() ); //generate a random value bigger than 0 and smaller than our application screen height
        
        myStudent[i].setup(randomX, randomY, 1);
        }


}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    //--------lerp ball moving------------------
    pct += 0.005;   // ie: pct = pct + 0.005
    
    if (pct > 1){
        pct = 0;
    }

    //--------call student class-------------------

    for(int i=0; i<NSTUDENTS; i++){
        
        int size = (i+1) * 10; // defining the size of each ball based on its place in the array
        int randomX = ofRandom( 0, ofGetWidth() ); //generate a random value bigger than 0 and smaller than our application screen width
        int randomY = ofRandom( 0, ofGetHeight() ); //generate a random value bigger than 0 and smaller than our application screen height
        
        myStudent[i].update(randomX, randomY, 1);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    BGtemp.draw(0,0,ofGetWidth(),ofGetHeight());


    //-------------ball lerp----------------------
    float pctShaped =  powf(pct, 0.5);     //pct * pct;      ///powf(pct, 2);
    ofPoint mixPt = (1.0-pctShaped) * aStart + pctShaped * bEnd;
    ofSetColor(ofColor::fuchsia);
    ofCircle(mixPt, 100);
    
    //--------call student class-------------------
    for(int i=0; i<NSTUDENTS; i++){
        
        int size = (i+1) * 10; // defining the size of each ball based on its place in the array
        int randomX = ofRandom( 0, ofGetWidth() ); //generate a random value bigger than 0 and smaller than our application screen width
        int randomY = ofRandom( 0, ofGetHeight() ); //generate a random value bigger than 0 and smaller than our application screen height
        
        myStudent[i].draw(randomX, randomY, 1);
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
