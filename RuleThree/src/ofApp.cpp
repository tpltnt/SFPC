#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    

    //----------------------style sheets--------------------
    salmon.setHsb(0,140,224);
    tan.setHsb(30,58,234); // (x/360*255, x/100*255, x/100*255)
    brown.setHsb(30,96,63);
    yellow.setHsb(34,150,234);
    green.setHsb(49,127,219);
    royal.setHsb(157,127,181);
    blue.setHsb(133,138,214);
    pink.setHsb(4,43,237);
  
    IntroBlack.loadFont("Intro Black.otf", 20); //font size
    studentA.loadImage("studentA.png");
    studentB.loadImage("studentB.png");
    studentC.loadImage("studentC.png");
    TaeyoonTeaching.loadImage("TaeyoonTeaching.png");
    BGtemp.loadImage("BGtemp.png");
    
    //------load class of Students, tell them what position to start in ------------------
    for(int i=0; i<NSTUDENTS; i++){ // i've said in .h that NSTUDENTS is 100
        
        int randomX = ofRandom( -1200, ofGetWidth()*2 ); //generate a random value between (a,b)
        int randomY = ofRandom( -1200, ofGetHeight()*2 ); //generate a random value between (a,b)
        
        myStudent[i].setup(randomX, randomY, 1);
        }

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // for all students, move towards this point
    if (ofGetMousePressed()){
        for(int i=0; i<NSTUDENTS; i++){
            myStudent[i].moveTowards(ofGetWidth()/2, ofGetHeight()/2); // i do not understand this syntax
            }
        }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    //BG------white paper with light blue gridded lines--------------------
    ofBackground(255);
    ofSetColor( ofColor::lightBlue);
    ofSetLineWidth(1);
    for (int i = 0; i < ofGetWidth(); i = i + 20){
        ofLine(i,0,i, ofGetHeight()); //draw a line at pt1: i,0, pt2: i,get width
        
    }
    for (int i = 0; i < ofGetHeight(); i = i + 20){
        ofLine(0, i, ofGetWidth(), i);
    }
 
    
    
    lineFbo.begin();
    ofSetColor(salmon);
    ofSetLineWidth(8);
    line.draw(); // this is the main line for the user
    lineFbo.end();
    
//    
//    shader.begin();
//    
//    shader.setUniformTexture("tex0",lineFbo, 0 );
//    shader.setUniformTexture("tex1",rockImage.getTextureReference(), 1 ); //i think I need to call these earlier somewhere up top with a #
//    
//    ofSetColor(255);
//    
//    lineFbo.draw(0,0);
//    shader.end();

   


    
    //--------call student class-------------------
    ofSetColor(255);
    for(int i=0; i<NSTUDENTS; i++){
        
        
        int randomX = ofRandom( 0, ofGetWidth() ); //generate a random value bigger than 0 and smaller than our application screen width
        int randomY = ofRandom( 0, ofGetHeight() ); //generate a random value bigger than 0 and smaller than our application screen height
        
        myStudent[i].draw(randomX, randomY, 1);
    }
    

    ofSetColor(255);
    TaeyoonTeaching.draw(450,242,442,612);


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
     line.addVertex(ofPoint(x,y));

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
