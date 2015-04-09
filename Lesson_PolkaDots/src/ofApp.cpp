#include "ofApp.h"

void ofApp::drawPinkPolkaCircle(float xPos, float yPos, float scale){
    
    ///pink circle ----------------------------------------
    
    
    ofPushMatrix(); // we're going to push this thing
    ofTranslate(xPos, yPos); // push it this far. Why is this a variable and not a fixed number?
    ofScale(scale, scale); //scale it this much
    
    
    float CircCenterBX, CircCenterBY, CircRadius;
    CircCenterBX = 0;
    CircCenterBY = 0;
    CircRadius = 100; // why am i defining this here?

    
    ofSetColor(myOutlines);
    ofNoFill();
    ofSetLineWidth(6);
    ofCircle(CircCenterBX,CircCenterBY,CircRadius); // centerx, centery, radius - this is drawing the black outline to be at 0,0,100 radius
    
    ofSetColor(Pink); //now i'm doing the polka dots
    ofFill();
    
    
    float circleX = CircCenterBY;
    float circleY = CircCenterBX;
    float circleRadius = CircRadius;
    
        for (int i = 0; i < ofGetHeight(); i = i + 20){ //scoot it over 20 each time
        for (int k = 0; k < ofGetWidth(); k = k + 20){ //scoot it over 20 each time
        float distance = ofDist(CircCenterBX, CircCenterBY, i, k);
            if (distance < circleRadius-4){
                if ((k/20) % 2 == 0) {     // is k even or not ?
                    ofCircle(k,i,4);
                } else {
                    ofCircle(k,i + 10,4);
                }
            }
        }
    }
    
    //why are these polkadots not filling the circle?
    

    
     ofPopMatrix(); //now we're done, reset coordinates to normal
    
}

//--------------------------------------------------------------
void ofApp::setup(){

    //    ofEnableAntiAliasing();
    ofSetLineWidth(2);
    
   
    cairo = ofPtr<ofCairoRenderer>(new ofCairoRenderer);
    cairo->setup("", ofCairoRenderer::IMAGE, false, false);     // allocate for 2d graphics
    tex.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    opengl = ofGetCurrentRenderer();                            // grab the current renderer
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSetFrameRate(6);
    counter =  1.0f;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    //--------------------------------------------------------  draw into cairo
    ofSetCurrentRenderer(cairo);
    cairo_set_line_cap(cairo->getCairoContext(), CAIRO_LINE_CAP_ROUND);
    cairo_set_line_join(cairo->getCairoContext(), CAIRO_LINE_JOIN_ROUND);
    ofClear(0,0,0, 255);

    
    ofBackground(255);  // Clear the screen with a black color

  ofSetColor(Blue);
    ofFill();
    

    
//    for (int rows=0; rows<5; rows++) {
//        for (int cols=0; cols<10; cols++) {
//            drawPinkPolkaCircle( rows * 100, cols*100, 0.5);
//            
//        }
//    }
    
    
    ofPushMatrix();
    ofTranslate(300, 50);
    drawPinkPolkaCircle(0, 0, 0.5);
    ofPopMatrix();
    
    //draw a U--------
    
    ofPushMatrix();
    ofTranslate(350, 0);
    ofSetColor(Blue);
    ofFill();
    ofRect(0,0,25,50);
    ofRect(75, 0, 25, 50);
    ofCircle(50,50,50);
     ofPopMatrix();

    
    // draw an M --------------------------

    ofNoFill();
    ofSetColor(myOutlines);
    ofSetLineWidth(MyOutlineWidth);
    ofBeginShape();
    ofVertex(0,100);
    ofVertex(50,0);
    ofVertex(100,100);
    ofVertex(80,100);
    ofVertex(50,35);
    ofVertex(20,100);
    ofVertex(0,100);
    ofEndShape();
    
    ofPushMatrix();
    ofTranslate(50, 00);
    ofNoFill();
    ofSetColor(myOutlines);
    ofSetLineWidth(MyOutlineWidth);
    ofBeginShape();
    ofVertex(0,100);
    ofVertex(50,0);
    ofVertex(100,100);
    ofVertex(80,100);
    ofVertex(50,35);
    ofVertex(20,100);
    ofVertex(0,100);
    ofEndShape();
    ofPopMatrix();
    
    /// draw an i --------------------------
    
    ofPushMatrix();
    ofTranslate(150, 00);
    ofNoFill();
    ofSetColor(myOutlines);
    ofSetLineWidth(MyOutlineWidth);
    ofBeginShape();
    ofCurveVertex(10, 100);
    ofCurveVertex(20, 40);
    ofCurveVertex(0, 80);
    ofCurveVertex(40, 20);
    ofCurveVertex(40, 20);
    ofCurveVertex(50, 20);
    ofCurveVertex(90, 90);
    ofCurveVertex(80, 100);
    ofCurveVertex(60, 30);
    ofCurveVertex(60, 30);
    ofCurveVertex(50, 30);
     ofCurveVertex(50, 30);
    ofCurveVertex(10, 100);
       ofCurveVertex(10, 100);
    ofEndShape();
    ofPopMatrix();

    
    // draw an H
    
    ofColor colorOne;
    ofColor colorTwo;
    

    
    //-------------draw a triangle-------------------
    ofFill();
    ofSetColor(MedAqua);
    
    if (ofGetElapsedTimef() <= 10){
    ofTriangle(10*ofGetElapsedTimef(),100,10*ofGetElapsedTimef()+50,150,10*ofGetElapsedTimef(),200);
    }
    
  
    
    ofPushMatrix();
    ofTranslate(500, 20);
    ofScale(.2, .2);
    float triangleX = 100;
    
    ofSetColor(MedAqua);
    
    if (ofGetFrameNum() % 12 == 0){
        ofTriangle(100,100,150,150,100,200);
    }
    if (ofGetFrameNum() % 12 == 1){
        ofTriangle(100+20,100,150+20,150,100+20,200);
    }
    if (ofGetFrameNum() % 12 == 2){
        ofTriangle(100+40,100,150+40,150,100+40,200);
    }
    if (ofGetFrameNum() % 12 == 3){
        ofTriangle(100+60,100,150+60,150,100+60,200);
    }
    if (ofGetFrameNum() % 12 == 4){
        ofTriangle(100+80,100,150+80,150,100+80,200);
    }
    if (ofGetFrameNum() % 12 == 5){
        ofTriangle(100+100,100,150+100,150,100+100,200);
    }
    if (ofGetFrameNum() % 12 == 6){
        ofTriangle(100+140,100,150+140,150,100+140,200);
    }
    if (ofGetFrameNum() % 12 == 7){
        ofTriangle(100+160,100,150+160,150,100+160,200);
    }
    if (ofGetFrameNum() % 12 == 8){
        ofTriangle(100+180,100,150+180,150,100+180,200);
    }
    if (ofGetFrameNum() % 12 == 9){
        ofTriangle(100+220,100,150+220,150,100+220,200);
    }
    if (ofGetFrameNum() % 12 == 10){
        ofTriangle(100+240,100,150+240,150,100+240,200);
    }
    if (ofGetFrameNum() % 12 == 11){
        ofTriangle(100+270,100,150+270,150,100+270,200);
    }
    else if (ofGetFrameNum() % 12 == 12){
        ofTriangle(100+300,100,150+300,150,100+300,200);
    }
    
    ofSetColor(Salmon);
    
    if (ofGetFrameNum() % 12 == 1){
        ofTriangle(70,100,120,150,70,200);
    }
    if (ofGetFrameNum() % 12 == 2){
        ofTriangle(100,100,150,150,100,200);
    }
    if (ofGetFrameNum() % 12 == 3){
        ofTriangle(100+20,100,150+20,150,100+20,200);
    }
    if (ofGetFrameNum() % 12 == 4){
        ofTriangle(100+40,100,150+40,150,100+40,200);
    }
    if (ofGetFrameNum() % 12 == 5){
        ofTriangle(100+70,100,150+70,150,100+70,200);
    }
    if (ofGetFrameNum() % 12 == 6){
        ofTriangle(100+100,100,150+100,150,100+100,200);
    }
    if (ofGetFrameNum() % 12 == 7){
        ofTriangle(100+130,100,150+130,150,100+130,200);
    }
    if (ofGetFrameNum() % 12 == 8){
        ofTriangle(100+160,100,150+160,150,100+160,200);
    }
    if (ofGetFrameNum() % 12 == 9){
        ofTriangle(100+180,100,150+180,150,100+180,200);
    }
    if (ofGetFrameNum() % 12 == 10){
        ofTriangle(100+200,100,150+200,150,100+200,200);
    }
    if (ofGetFrameNum() % 12 == 11){
        ofTriangle(100+220,100,150+220,150,100+220,200);
    }
    if (ofGetFrameNum() % 12 == 12){
        ofTriangle(100+240,100,150+240,150,100+240,200);
    }
    else if (ofGetFrameNum() % 12 == 0){
        ofTriangle(100+260,100,150+260,150,100+260,200);
    }

    
    
    ofPopMatrix();
    
    float animateAtime = 1.0;
    float animateBtime = 1.0;  // assume that b is first
    float totalAnimatetime = animateAtime + animateBtime;
    float currentTime = ofGetElapsedTimef(); // get the current time
    float timeInAnimation = currentTime;
    while (timeInAnimation > totalAnimatetime){
        timeInAnimation -= totalAnimatetime; // this is like fmod for time (I can explain)
    }
    
    //now we've gotten a value that counts up to 2 seconds every two seconds.  Now some logic to figure out what pct of a and b we've done given time
    
    float apct = ofMap(timeInAnimation -animateBtime , 0,
                       animateAtime, 0,1, true);  // the minus animateBtime is cause b is assumed first
    float bpct = ofMap(timeInAnimation, 0,
                       animateBtime, 0,1, true);
    float cpct = ofMap(timeInAnimation+1, 0,
                       animateBtime, 0,1, true);
    float a = ofMap(apct, 0,1,0,100); // what do these numbers mean?
    float b = ofMap(bpct, 0,1,0,100);
    float c = ofMap(cpct, 0,1,0,100);
    ofLine(600,b,600,c);
    ofSetColor(Aqua);
    ofLine(590,a,590,b);
    ofSetColor(Salmon);
    ofLine(500,b,500,a);
//    ofLine(c+500,60,b+500,60); // why why why?
    ofLine(510,a,510,b);
    
    
    
    
    
    // ------------------------- finish cairo
    
    ofSetCurrentRenderer(opengl);
    tex.loadData(   cairo->getImageSurfacePixels().getPixels(),
                 cairo->getImageSurfacePixels().getWidth(),
                 cairo->getImageSurfacePixels().getHeight(),
                 GL_BGRA_EXT);
  
    tex.draw(0,0);
    
    
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
