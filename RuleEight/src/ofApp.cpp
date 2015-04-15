#include "ofApp.h"

void ofApp::drawAnalyze(float xPos, float yPos, float scale){
    
    RuleEightAnalyze.draw(0,0,ofGetWidth(),ofGetHeight());
    
}

//--------------------------------------------------------------
void ofApp::setup(){
    
    salmon.setHsb(0,140,224);
    tan.setHsb(30,58,234);
    atthesametimebrown.loadImage("atthesametimebrown.png");
    DontTrybrown.loadImage("DontTrybrown.png");
    RuleEightAnalyze.loadImage("RuleEightAnalyze.png");
    theyareblue.loadImage("theyareblue.png");
    theyaretan.loadImage("theyaretan.png");
    sprintf(RuleEightCreate, "CREATE");
    IntroBlack.loadFont("Intro Black.otf", 182); //font size


}

//--------------------------------------------------------------
void ofApp::update(){
    RuleEightAnalyze.draw(0,0,ofGetWidth(),ofGetHeight());

   

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
    ofSetColor(salmon);
    drawAnalyze(0,0,1);
    IntroBlack.drawString(RuleEightCreate, 182,472);
    atthesametimebrown.draw(493,732,543,79);
    DontTrybrown.draw(520,30,435,116);
    theyaretan.draw(0,245,100,317);
    ofSetColor(tan);
    ofRect(0,0,105,ofGetHeight());
    theyareblue.draw(0,245,100,317);
    
 //---------this is the mesh to reveal the analyze artwork------------

    RuleEightLeftVertex = mouseY-100;
    RuleEightRightVertex = mouseY;
    ofMesh tempMesh;
    tempMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    tempMesh.addVertex( ofPoint(0,RuleEightLeftVertex));
    tempMesh.addColor(0);
    
    tempMesh.addVertex( ofPoint(ofGetWidth(),RuleEightRightVertex));
    tempMesh.addColor(0);
    
    tempMesh.addVertex( ofPoint(0,ofGetHeight()));
    tempMesh.addColor(0);
    
    tempMesh.addVertex( ofPoint(ofGetWidth(),ofGetHeight()));
    tempMesh.addColor(0);
    
    RuleEightAnalyze.bind();
    tempMesh.draw();
    RuleEightAnalyze.unbind();
 


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
