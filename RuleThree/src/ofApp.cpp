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

    TaeyoonTeaching.loadImage("TaeyoonTeaching.png");
    BGtemp.loadImage("BGtemp.png");
    
    //------load class of Students, tell them what position to start in ------------------
    for(int i=0; i<NSTUDENTS; i++){ // i've said in .h that NSTUDENTS is 100
        
        
    float radius = ofRandom(700,2500);      // <---- pick a random distance away from the center
    float angle = ofRandom(0, TWO_PI);     // <---- pick a random angle
    float centerX = ofGetWidth()/2;    // <----- this is the center of the circle x
    float centerY = ofGetHeight()/2;   // <------ also, center of the circle y
    float x = centerX + radius * cos(angle);   // <---- this is using the circle formula we discussed in class
    float y = centerY + radius * sin(angle);
        
        string fileName;
        float dy =  ofGetHeight()/2 - y;
        float dx = ofGetWidth()/2 - x;
        float angle2 = atan2(dy, dx ) * RAD_TO_DEG;
        
        cout << angle2 << endl;
        
        
        if (angle2 >= 0 && angle2 < 60){
            fileName = "studentD.png";
        } else if (angle2 >= 60 && angle2 < 120){
            fileName = "studentF.png";
        } else if (angle2 >= 120 && angle2 < 180){
            fileName = "studentC.png";
        } else if (angle2 < 0 && angle2 >= -60){
                fileName = "studentB.png";
        } else if (angle2 < -60 && angle2 >= -120){ // -60  --120
            fileName = "studentD.png";
        } else if (angle2 < -120 && angle2 >= -180){
            fileName = "studentE.png";
      }
        myStudents[i].setup(x,y, fileName);   // <----- now, this is where they should be setup....
        
        
        myStudents[i].stopPoint.x = 645 + myStudents[i].varDistance * cos(angle);
        myStudents[i].stopPoint.y = 366 + myStudents[i].varDistance * sin(angle);
        

    }

}

//--------------------------------------------------------------
void ofApp::update(){
    // for all students, move towards this point
    if (ofGetMousePressed()){
        for(int i=0; i<NSTUDENTS; i++){
        myStudents[i].moveTowards(645, 366);
        
        }
    }
//    if (ofGetMousePressed()){
//        for(int i=0; i<NSTUDENTS; i++){
//            if(ofRandom(0,1) > 0.5) {
//                myStudents[i].moveTowards(645, 366, ofRandom(100,1000));
//            } else {
//                myStudents[i].moveTowardsB(645, 366, ofRandom(100,1000));
//                    }
//                }
//            }
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

//    lineFbo.begin();
    ofSetColor(salmon);
    ofSetLineWidth(7);
    line.draw(); // this is the main line for the user
//    lineFbo.end();
  
    
 //-----shader not woring, eventhough in data/bin, abandoning it for now-----------
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
        
        myStudents[i].draw();
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
    
       if (mouseX > 484 && mouseX < 800 && mouseY <474 && mouseY > 300){
    line.addVertex(ofPoint(x,y));
             }

    cout << mouseX << endl;
    cout << mouseY << endl;
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
