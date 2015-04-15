#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    myImage.loadImage("B0cWScpCYAAgN2m.jpg");
    video.loadMovie("BlackLoop.mov");
    
    video.setLoopState(OF_LOOP_NORMAL);
    //video.setSpeed(0.4);
    video.play();

    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);
    
    
  //-----------blob-------------------------
    ofSetColor(255,0,127);
    
    ofBeginShape();
    for (int i = 0; i < 100; i++){
        
        //float add = ofNoise(sin((i/100.0)*TWO_PI), ofGetElapsedTimef());  // symetrical
        
        float add = ofNoise(i/20.0f, ofGetElapsedTimef() * 3 * (float)mouseX / (float)ofGetWidth());
        
        ofVertex(	200 + (200 + 100 * add) * cos((i/100.0)*TWO_PI),
                 100 + (200 + 100 * add) * sin((i/100.0)*TWO_PI));
    }
    ofEndShape();
    
//
//    ofMesh tempMesh;
//    
//    tempMesh.setMode(OF_PRIMITIVE_TRIANGLES);
//    tempMesh.addVertex( ofPoint(100,100) );
//    tempMesh.addTexCoord( ofPoint(100,100));
//    tempMesh.addVertex( ofPoint(300,100) );
//    tempMesh.addTexCoord( ofPoint(300 ,100));
//    tempMesh.addVertex( ofPoint(200,180) );
//    tempMesh.addTexCoord( ofPoint(mouseX, mouseY));
//    
//    
//    
//    myImage.bind();
//    tempMesh.draw();
//    myImage.unbind();
    

    
     ofMesh tempMesh;
    tempMesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    
    float x = mouseX;
    float y = mouseY;
    float r = 200;
    
    float scale =  1; //ofMap( sin(ofGetElapsedTimef()), -1, 1, 0.4, 3);
    
    tempMesh.addVertex( ofPoint(x,y));
    tempMesh.addTexCoord(ofPoint(x,y) * scale+ ofPoint(mouseX, mouseY));
    
    
    for (int i = 0; i < 100; i++){
        
        float angle = ofMap(i, 0, 100-1, 0, TWO_PI);
        
        ofPoint pos;
        pos.x = x + r * cos(angle);
        pos.y = y + r * sin(angle);
        
        tempMesh.addVertex(pos);
        tempMesh.addTexCoord(pos*scale + ofPoint(mouseX, mouseY)
                            + ofPoint(ofRandom(-10, 10), ofRandom(-10,10)));
        
    }

    
    
//    video.bind();
    tempMesh.draw();
//    video.unbind();
    
    
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
