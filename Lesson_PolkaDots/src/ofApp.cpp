#include "ofApp.h"

void ofApp::drawPinkPolkaCircle(float xPos, float yPos, float scale){
    
    ///pink circle ----------------------------------------
    
    
    ofPushMatrix(); // we're going to push this thing
    ofTranslate(xPos, yPos); // push it this far
    ofScale(scale, scale); //scale it this much
    
    float CircCenterBX, CircCenterBY, CircRadius;
    CircCenterBX = 0;
    CircCenterBY = 0;
    CircRadius = 100;

    
    ofSetColor(0);
    ofNoFill();
    ofSetLineWidth(6);
    ofCircle(CircCenterBX,CircCenterBY,CircRadius); // centerx, centery, radius
    
    ofSetColor( ofColor::pink);
    ofFill();
    
        for (int i = 0; i < ofGetHeight(); i = i + 20){
        for (int k = 0; k < ofGetWidth(); k = k + 20){
            float circleX = CircCenterBY;
            float circleY = CircCenterBX;
            float circleRadius = CircRadius;
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
    
    
    
//    ofSetColor(0);
//    ofNoFill();
//    ofSetLineWidth(6);
//    ofCircle(CircCenterBX, CircCenterBY, CircRadius);
    
     ofPopMatrix(); //now we're done, reset coordinates to normal
    
}

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetCircleResolution(100);
    //    ofEnableAntiAliasing();
    ofSetLineWidth(2);
    
   
    cairo = ofPtr<ofCairoRenderer>(new ofCairoRenderer);
    cairo->setup("", ofCairoRenderer::IMAGE, false, false);     // allocate for 2d graphics
    tex.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    opengl = ofGetCurrentRenderer();                            // grab the current renderer
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSetFrameRate(12);
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
    ofSetColor(0);  // Set the drawing color to white
    

    ofSetColor( ofColor::lightBlue);
    ofFill();
    

//
//    for (int rows=0; rows<5; rows++) {
//        for (int cols=0; cols<5; cols++) {
//            drawPinkPolkaCircle( 200+rows *110, 200+cols*110, 1);
//            
//        }
//    }
//    
//  drawPinkPolkaCircle( 0,0, 1);
    
    for (int rows=0; rows<5; rows++) {
        for (int cols=0; cols<10; cols++) {
            drawPinkPolkaCircle( rows * 100, cols*100, 0.5);
            
        }
    }

    
    
    // draw polka dots inside a circle ----------------------------
    
//    float MyCircA, MyCircB;
//    MyCircA = mouseX;
//    MyCircB = mouseY;
//    for (int i = 0; i < ofGetHeight(); i = i + 20){
//        for (int k = 0; k < ofGetWidth(); k = k + 20){
//            float circleX = MyCircB;
//            float circleY = MyCircA;
//            float circleRadius = 300;
//            float distance = ofDist(circleX, circleY, i, k);
//            if (distance < circleRadius-4){
//                if ((k/20) % 2 == 0) {     // is k even or not ?
//                    ofCircle(k,i,4);
//                } else {
//                    ofCircle(k,i + 10,4);
//                }
//            }
//        }
//    }
    
    
    
    //-------------draw a triangle-------------------
    ofFill();
    ofSetColor( ofColor::lightBlue);
 
    ofPushMatrix();
    ofTranslate(500, 900);
    ofScale(.5, .5);
    
    
    if (ofGetFrameNum() % 12 == 0){
        ofTriangle(100,100,150,150,100,200);
    }
    if (ofGetFrameNum() % 12 == 1){
        ofTriangle(100+20,100,150,150,100,200);
    }
    if (ofGetFrameNum() % 12 == 2){
         ofTriangle(100+40,100,150,150,100,200);
    } if (ofGetFrameNum() % 12 == 3){
         ofTriangle(100+60,100,150,150,100,200);
    } if (ofGetFrameNum() % 12 == 4){
         ofTriangle(100+80,100,150,150,100,200);
    }  else if (ofGetFrameNum() % 12 == 5){
         ofTriangle(100+90,100,150,150,100,200);
    }
//    }if (ofGetFrameNum() % 12 == 6){
//             ofTriangle(100,100,150,150,100,200);
//    } if (ofGetFrameNum() % 12 == 7){
//        ofTriangle(100,100,150,150,100,200);
//    } if (ofGetFrameNum() % 12 == 8){
//        ofTriangle(100,100,150,150,100,200);
//    } if (ofGetFrameNum() % 12 == 9){
//        ofTriangle(100,100,150,150,100,200);
//    } if (ofGetFrameNum() % 12 == 10){
//        ofTriangle(100,100,150,150,100,200);
//    } if (ofGetFrameNum() % 12 == 11){
//        ofTriangle(100,100,150,150,100,200);
//    }
        
//    } else if (ofGetSeconds() <=15){
//        ofTriangle(100+50,100,150+50,150,100+50,200);
//    } else {
//        ofTriangle(100+100,100,150+100,150,100+100,200);
        
    }
    //    if (ofGetSeconds() % 3 == 0){
    //        ofTriangle(100,100,150,150,100,200);
    //    } else if (ofGetSeconds() % 3 == 1){
    //        ofTriangle(100+50,100,150+50,150,100+50,200);
    //    } else {
    //        ofTriangle(100+100,100,150+100,150,100+100,200);
    //
    //    }
    ofPopMatrix();
    ofNoFill();
    
    ofSetColor( ofColor::black);
    
    // draw an animated line --------------------------
    
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
    float a = ofMap(apct, 0,1,50,400);
    float b = ofMap(bpct, 0,1,50,400);
    ofLine(700,a,700,b);
    ofLine(500,b,500,a);
    ofLine(a+400,200,b+300,400);
    ofLine(800,a,800,b);
    
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
