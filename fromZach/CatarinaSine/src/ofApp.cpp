#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    panelA.setup("WaveA", "settings.xml", 750, 250);
    panelA.add(peaksA.set("peaksA",50, 20, 100));
    panelA.add(amplitudeA.set("amplitudeA",0.01f, 0.01f, 0.2f));
    panelA.add(radiusA.set("RadiusA", 150.0, 20, 300));
    panelA.add(noiseModFactorA.set("NoiseA", 0.0, 0.0, 5.0));
    panelA.add(velocityA.set("velocityA", 0.1f, 0.01f, 1.0f));

    panelB.setup("WaveB", "settings.xml", 750, 400);
    panelB.add(peaksB.set("peaksB",50, 20, 100));
    panelB.add(amplitudeB.set("amplitudeB",0.01f, 0.01f, 0.2f));
    panelB.add(radiusB.set("RadiusB", 150.0, 20, 300));
    panelB.add(noiseModFactorB.set("NoiseB", 0.0, 0.0, 5.0));
    panelB.add(velocityB.set("velocityB", 0.15f, 0.01f, 1.0f));

    
    ofBackground(0);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofNoFill();
    
    float resolution = 1000;
    
    ofPushMatrix();
    
    
    
    ofBeginShape();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    for(int i=0; i<=resolution; i++) {
        
        float t = i/resolution;
        
        float xraw = sin(t*TWO_PI);
        float yraw = cos(t*TWO_PI);
        
        float displaceNoiseMod = ofNoise(xraw+ofGetElapsedTimef(), yraw+ofGetElapsedTimef()) * radiusA;
        displaceNoiseMod*=noiseModFactorA.get();
        
        float wave = (displaceNoiseMod+radiusA) * amplitudeA * sin(t*TWO_PI*peaksA + ofGetFrameNum()*velocityA)  ;
        
        float x = (radiusA+wave) * xraw;
        float y = (radiusA+wave) * yraw;
        
        ofCurveVertex(x, y);
        
    }
    
    ofEndShape(true);
    
    
    
    ofBeginShape();
    
    for(int i=0; i<=resolution; i++) {
        
        float t = i/resolution;
        
        float xraw = sin(t*TWO_PI);
        float yraw = cos(t*TWO_PI);
        
        float displaceNoiseMod = ofNoise(xraw+ofGetElapsedTimef(), yraw+ofGetElapsedTimef()) * radiusB;
        displaceNoiseMod*=noiseModFactorB.get();
        
        float wave = (displaceNoiseMod+radiusB) * amplitudeB * sin(t*TWO_PI*peaksB + ofGetFrameNum()*velocityB)  ;
        
        float x = (radiusB+wave) * xraw;
        float y = (radiusB+wave) * yraw;
        
        ofCurveVertex(x, y);
        
    }
    
    ofEndShape(true);
    
    
    
    ofPopMatrix();
    
    
//    float spacing = 10;
//    ofBeginShape();
//    for(int x=0; x<ofGetWidth(); x+= spacing) {
//        ofCurveVertex(x, ofGetHeight()/2 + ofGetHeight()*amplitudeB * sin(x * wavelengthB + ofGetFrameNum()*0.1f));
//    }
//    ofEndShape(false);
 
    
    panelA.draw();
    panelB.draw();


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
