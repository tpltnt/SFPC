#include "ofApp.h"
#include "ofMain.h"

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
    sprintf(ThereisOnly, "THERE IS ONLY WORK");
    IntroBlack.loadFont("Intro Black.otf", 20); //font size
    
    scribbles.loadMovie("ScribblesonWhite.mov");
    scribbles.setLoopState(OF_LOOP_NORMAL);
    //video.setSpeed(0.4);
    scribbles.play();
    
    videoone.loadMovie("RuleSevenVideoOne.mov");
    videoone.setLoopState(OF_LOOP_NORMAL);
    videoone.play();
    
    videotwo.loadMovie("RuleSevenVideoTwo.mov");
    videotwo.setLoopState(OF_LOOP_NORMAL);
    videotwo.play();
    
    
    videothree.loadMovie("RuleSevenVideoThree.mov");
    videothree.setLoopState(OF_LOOP_NORMAL);
    videothree.play();
    
    allofthetime.loadImage("allofthetime.png");
    arrow.loadImage("arrow.png");
    RuleSevenBG.loadImage("RuleSevenBG.png");
    ifyouwork.loadImage("ifyouwork.png");
    itspeople.loadImage("itspeople.png");



}

//--------------------------------------------------------------
void ofApp::update(){
    
    scribbles.update();
    videoone.update();
    videotwo.update();
    videothree.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    float iywmove = 10*ofGetElapsedTimef();
    ofSetColor(green);
    ofRect(30,110,350,200);
    ofSetColor(green);
    ofRect(990,340,350,200);
    ofSetColor(royal);
    ofRect(370,340,350,200);
    ofSetColor(brown);
    ifyouwork.draw(iywmove,150,627/2,177/2);
    allofthetime.draw(40,660,383/2,231/2);
    itspeople.draw(1020,340,530/2,392/2);
    ofSetColor(255);
    videoone.draw(370,110,350,200);
    videotwo.draw(990,110,350,200);
    videothree.draw(680,340,350,200);
    ofSetColor(salmon);
    ofRect(690,110,340,200);
    ofSetColor(blue);
    ofRect(690,560,340,200);
    ofSetColor(pink);
    ofRect(30,560,340,200);
    
    ofSetColor(255);
    RuleSevenBG.draw(0,0,ofGetWidth(),ofGetHeight());
    
//    // --------------background with code--------------------
//    ofBackground(255);
//    ofSetColor( ofColor::lightBlue);
//    ofSetLineWidth(1);
//    for (int i = 0; i < ofGetWidth(); i = i + 20){
//        ofLine(i,0,i, ofGetHeight());
//        
//    }
//    
//    for (int i = 0; i < ofGetHeight(); i = i + 20){
//        ofLine(0, i, ofGetWidth(), i);
//    }
//    
    

    
//    //-----------blob-------------------------
//    ofSetColor(255,0,127);
//    
//    ofBeginShape();
//    for (int i = 0; i < 100; i++){
//        
//        //float add = ofNoise(sin((i/100.0)*TWO_PI), ofGetElapsedTimef());  // symetrical
//        
//        float add = ofNoise(i/20.0f, ofGetElapsedTimef() * 3 * (float)mouseX / (float)ofGetWidth());
//        
//        ofVertex(	00 + (200 + 100 * add) * cos((i/100.0)*TWO_PI),
//                 100 + (200 + 100 * add) * sin((i/100.0)*TWO_PI));
//    }
//    
//    ofEndShape();

    
    // --------------------mesh circle that follows mouse---------------
    ofSetColor(255);
    ofMesh tempMesh;
    tempMesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    float x = mouseX-PI;
    float y = mouseY-PI;
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
        tempMesh.addTexCoord(pos); // i dont know what to put here to just make it track the arrow

//        tempMesh.addTexCoord(pos*scale + ofPoint(mouseX, mouseY)
//        + ofPoint(ofRandom(-10, 10), ofRandom(-10,10))); // this is a crazy thing I dont understand
//        ofVec2f(0, RuleEightLeftVertex));
        
    }
    
    
    scribbles.getTextureReference().bind();
    tempMesh.draw();
    scribbles.getTextureReference().unbind(); //bind this movie to the mesh
    
    
    
    IntroBlack.drawString(ThereisOnly, mouseX-100,mouseY+120); //type the words
//    arrow.draw(mouseX, mouseY,50,60);
    
    ofSetLineWidth(3);
    ofSetColor(255,0,0);
    TS.draw(videoone.getPosition());
    for (int i = 0; i < strokes.size(); i++){
        strokes[i].draw(videoone.getPosition());
    }
    
    ofPushMatrix();
    ofTranslate(0, 70);
//    ofDrawBitmapStringHighlight("press spacebar to clear", ofPoint(videoone.getWidth() + 250, 50), ofColor::magenta, ofColor::white);
    ofDrawBitmapStringHighlight("press + to increase video speed", ofPoint(videoone.getWidth() + 200, ofGetHeight()-160), ofColor::magenta, ofColor::white);
    ofDrawBitmapStringHighlight("press - to increase video speed", ofPoint(videoone.getWidth() + 200, ofGetHeight()-130), ofColor::magenta, ofColor::white);
    ofDrawBitmapStringHighlight("video speed: " + ofToString(videoone.getSpeed(), 3), ofPoint(videoone.getWidth() + 250, ofGetHeight()-100), ofColor::magenta, ofColor::white);
    ofPopMatrix();



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' '){
        strokes.clear();
        TS.pts.clear();
    }
    
    
    if (key == '+'){
        videoone.setSpeed(videoone.getSpeed()+0.05);
    }
    
    if (key == '-'){
        videoone.setSpeed(videoone.getSpeed()-0.05);
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
