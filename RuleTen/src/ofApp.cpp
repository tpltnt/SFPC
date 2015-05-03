#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    salmon.setHsb(0,140,224);
    tan.setHsb(30,58,234); // (x/360*255, x/100*255, x/100*255)
    brown.setHsb(30,96,63);
    yellow.setHsb(34,150,234);
    green.setHsb(49,127,219);
    royal.setHsb(157,127,181);
    blue.setHsb(133,138,214);
    pink.setHsb(4,43,237);
    
    IntroBlack.loadFont("Intro Black.otf", 52); //font size
    panelA.setup("WAVE ONE", "settings.xml", ofGetWidth()-230, 50);
    panelA.add(peaksA.set("pPeaks",50, 20, 100));
    panelA.add(amplitudeA.set("Amplitude",0.01f, 0.01f, 0.2f));
    panelA.add(radiusA.set("Radius", 150.0, 20, 300));
    panelA.add(noiseModFactorA.set("Noise", 0.0, 0.0, 5.0));
    panelA.add(velocityA.set("Velocity", 0.1f, 0.01f, 1.0f));
    panelA.add(LineWeightA.set("Line Weight", 2, 2, 50));
    
    panelB.setup("WAVE TWO", "settings.xml", ofGetWidth()-230, 200);
    panelB.add(peaksB.set("peaksB",50, 20, 100));
    panelB.add(amplitudeB.set("amplitudeB",0.01f, 0.01f, 0.2f));
    panelB.add(radiusB.set("RadiusB", 150.0, 20, 300));
    panelB.add(noiseModFactorB.set("NoiseB", 0.0, 0.0, 5.0));
    panelB.add(velocityB.set("velocityB", 0.15f, 0.01f, 1.0f));
    panelB.add(LineWeightB.set("Line Weight", 2, 2, 50));
    
    
    ofBackground(0);
    
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
    
    //------------------- start drawing ------------------------------------
    
    ofNoFill();
    
    float resolution = 1000;
    
    ofPushMatrix();
    ofBeginShape();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    ofSetColor(salmon);
    ofSetLineWidth(LineWeightA);
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
    ofSetColor(pink);
     ofSetLineWidth(LineWeightB);
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
