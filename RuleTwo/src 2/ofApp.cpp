#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    colors[0].setHsb(0,140,224);
    colors[1].setHsb(30,58,234); // (x/360*255, x/100*255, x/100*255)
    colors[2].setHsb(30,96,63);
    colors[3].setHsb(34,150,234);
    colors[4].setHsb(49,127,219);
    colors[5].setHsb(157,127,181);
    colors[6].setHsb(133,138,214);
    
    for (int i = 0; i < 7; i++){
        opactity[i] = 0;
    }
    
    //colors[7].setHsb(4,43,237);
    Head.loadImage("Head.png");
    Ring.loadImage("Circle.png");
    PullEverything.loadImage("PullEverything.png");
    GeneralDuties.loadImage("GeneralDuties.png");
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    
    for (int i = 0; i < 8; i++){ //draw all 8 particles
        particle myParticle;
        myParticle.setInitialCondition(ofRandom(500,550),ofRandom(500,550),0,0); //
        particles.push_back(myParticle);
    }
    
    particles[0].bFixed = true;
    
    
    for (int i = 1; i < particles.size(); i++){
        spring mySpring;
        mySpring.distance		= 200;
        mySpring.springiness	= 0.05f;
        mySpring.particleA = & (particles[0]); //is this my main/center particle?
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
    
    //----------variables for circles-------------------------------------------------
    
    int opacityPressed;

    int circleRad = 150;
    int FillCircleRad = circleRad-3;
    

    
    
    for (int i = 0; i < 7; i++){
        bool bAnyNotInMe = false;
        for (int j = 0; j < particles.size(); j++){
            if (  (CirclePos[i] - particles[j].pos).length() > FillCircleRad){
                bAnyNotInMe = true;
            }
            
            if (bAnyNotInMe){
                opactity[i] = 0.99 * opactity[i] + 0.01 * 0.0;
            } else {
                opactity[i] = 0.99 * opactity[i] + 0.01 * 255.0;
            }
        }
    }
    

    
    sin(ofGetElapsedTimef()); // moves from -1 and 1 every 2Pi seconds
    float sinValue = sin(ofGetElapsedTimef()*2);
    float sinValueB = sin(ofGetElapsedTimef()*1.5);
    float cosinValue = cos(ofGetElapsedTimef()*2);
    
    CirclePos[0].x =490+sinValue*27;
    CirclePos[0].y =490+cosinValue*17;
    CirclePos[1].x =190+sinValueB*17;
    CirclePos[1].y =190+cosinValue*17;
    CirclePos[2].x =790+sinValue*27;
    CirclePos[2].y =190+cosinValue*27;
    CirclePos[3].x =990+sinValueB*27;
    CirclePos[3].y =590+cosinValue*-37;
    CirclePos[4].x =1100+sinValueB*27;
    CirclePos[4].y =90+cosinValue*-37;
    CirclePos[5].x =90+sinValueB*27;
    CirclePos[5].y =600+cosinValue*-37;
    CirclePos[6].x =400+sinValue*27;
    CirclePos[6].y =110+cosinValue*17;

    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    for (int i = 0; i < 7; i++){
        ofSetColor(colors[i]);
        Ring.draw(CirclePos[i].x,CirclePos[i].y,circleRad*2,circleRad*2);
        ofSetColor(colors[i].r, colors[i].g, colors[i].b, opactity[i]);
        ofCircle(CirclePos[i],FillCircleRad);
    }
    
    //-----draw outer ring at 100% and circle at variable opacity------------
//    ofSetColor(salmon); // red
//    Ring.draw(ring1x,ring1y,circleRad*2,circleRad*2);
//    ofSetColor(224,103,99,opacityPressed);
//    ofCircle(circlePos1,FillCircleRad);
//    
//    ofSetColor(140,207,160); //green
//    Ring.draw(ring2x,ring2y,circleRad*2,circleRad*2);
//    ofSetColor(140,207,160,opacityPressed);
//    ofCircle(circlePos2,FillCircleRad);
//    
//    ofSetColor(98,196,215); //bue
//    Ring.draw(ring3x,ring3y,circleRad*2,circleRad*2);
//    ofSetColor(98,196,215,opacityPressed);
//    ofCircle(circlePos3,FillCircleRad);
//    
//    ofSetColor(91,116,183); //drkbue
//    Ring.draw(ring4x,ring4y,circleRad*2,circleRad*2);
//    ofSetColor(91,116,183,opacityPressed);
//    ofCircle(circlePos4,FillCircleRad);
//    
//    ofSetColor(236,214,95); //yellow
//    Ring.draw(ring5x,ring5y,circleRad*2,circleRad*2);
//    ofSetColor(236,214,95,opacityPressed);
//    ofCircle(circlePos5,FillCircleRad);
//    
//    ofSetColor(150,107,138); //purple
//    Ring.draw(ring6x,ring6y,circleRad*2,circleRad*2);
//    ofSetColor(150,107,138,opacityPressed);
//    ofCircle(circlePos6,FillCircleRad);
//    
//    ofSetColor(243,167,153); //pink
//    Ring.draw(ring7x,ring7y,circleRad*2,circleRad*2);
//    ofSetColor(243,167,153,opacityPressed);
//    ofCircle(circlePos7,FillCircleRad);
    
    ofSetRectMode(OF_RECTMODE_CORNER);
    
    
    //---------------springs and  particles----------------
    ofSetColor(ofColor::brown);
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
