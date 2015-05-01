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
    Head.loadImage("Head.png");
    Ring.loadImage("Circle.png");
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    
    for (int i = 0; i < 8; i++){ //draw all 8 particles
        particle myParticle;
        myParticle.setInitialCondition(ofRandom(500,550),ofRandom(500,550),0,0);
        particles.push_back(myParticle);
    }
    
    particles[0].bFixed = true;
    
    for (int i = 1; i < particles.size(); i++){
        spring mySpring;
        mySpring.distance		= 200;
        mySpring.springiness	= 0.1f;
        mySpring.particleA = & (particles[0 ]); //is this my main/center particle?
        mySpring.particleB = & (particles[i]);
        springs.push_back(mySpring);
    }


}

//--------------------------------------------------------------
void ofApp::update(){
    
    // on every frame
    // we reset the forces
    // add in any forces on the particle
    // perfom damping and
    // then update
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
    }
    
    for (int i = 0; i < particles.size(); i++){
        
        particles[i].addRepulsionForce(mouseX, mouseY, 200, 0.7f);
        
        for (int j = 0; j < i; j++){
            particles[i].addRepulsionForce(particles[j], 20, 0.03);
        }
    }
    
    for (int i = 0; i < springs.size(); i++){
        springs[i].update();
    }
    
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].addDampingForce();
        particles[i].update();
    }


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
    
    
    //----------balls
    float sinOfTime				= sin( ofGetElapsedTimef() );
    float sinOfTimeMapped		= ofMap( sinOfTime, -1, 1, 0, 255);
    
    float sinOfTime2			= sin( ofGetElapsedTimef() + PI);
    float sinOfTimeMapped2		= ofMap( sinOfTime2, -1, 1, 0, 255);
    
    sin(ofGetElapsedTimef()); // moves from -1 and 1 every 2Pi seconds
    float sinValue = sin(ofGetElapsedTimef()*2);
     float cosinValue = cos(ofGetElapsedTimef()*2);
    ofColor c;
    c.set(ofColor::pink);
    c.lerp( ofColor::blue,  ofMap(mouseX, 0, ofGetWidth(), 0, 1, true));
    ofSetColor(c);

    
    //----------rings----------------------------------------------------
    int opacityPressed = 50; //I will replace this with an equation
    int ring1x, ring1y, ring2x, ring2y, ring3x, ring3y, ring4x, ring4y, ring5x, ring5y, ring6x, ring6y, ring7x, ring7y;
    
    ring1x =490+sinValue*17;
    ring1y =490+cosinValue*17;
    ring2x =190+sinValue*17;
    ring2y =190+cosinValue*17;
    ring3x =790+sinValue*27;
    ring3y =190+cosinValue*27;
    
    ofSetColor(salmon);
    Ring.draw(ring1x,ring1y,300,300);
    ofSetColor(224,103,99,opacityPressed);
    ofCircle(ring1x+150,ring1y+150,149);
    
    ofSetColor(140,207,160); //green
    Ring.draw(ring2x,ring2y,300,300);
    ofSetColor(140,207,160,opacityPressed);
    ofCircle(ring2x+150,ring2y+150,149);
    
    ofSetColor(98,196,215); //bue
    Ring.draw(ring3x,ring3y,300,300);
    ofSetColor(98,196,215,opacityPressed);
    ofCircle(ring3x+150,ring3y+150,149);

    
    

    
    //---------------springs----------------
    ofSetColor(brown);
    for (int i = 0; i < particles.size(); i++){
        particles[i].draw();
    }
    
    for (int i = 0; i < springs.size(); i++){
        springs[i].draw();
    }
    
  

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key){
            
        case ' ':
            // reposition everything:
            for (int i = 0; i < particles.size(); i++){
                particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
            }
            break;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    particles[0].pos.set(mouseX, mouseY);
    /*particles.erase(particles.begin());
     particle myParticle;
     myParticle.setInitialCondition(x,y,0,0);
     particles.push_back(myParticle);*/


}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
//particles[0].bFixed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
//particles[0].bFixed = false;
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
