
#include "Student.h"

Student::Student(){
}

void Student::setup(float _x, float _y, int _dim){
    
        x = _x;
        y = _y;
        dim = _dim;
        
        speedX = ofRandom(-1,1);
        speedY = ofRandom(-1,1);
        rotation = ofRandom(-10,10);
        color.setHsb(ofRandom(255),ofRandom(100,110),ofRandom(200,220));
    
        studentA.loadImage("studentA.png"); //load all 6 images
        studentB.loadImage("studentB.png");
        studentC.loadImage("studentC.png");
        studentD.loadImage("studentD.png");
        studentE.loadImage("studentE.png");
        studentF.loadImage("studentF.png");
   
    
    float randomVal = ofRandom(0,1); //randomly select A,B,or C
    if (randomVal < 0.33){
        img.loadImage("studentA.png");
    } else if (randomVal >= 0.33 && randomVal < 0.66){
        img.loadImage("studentB.png");
    } else {
        img.loadImage("studentC.png");
        }
    }

//for(int i=0; i<NSTUDENTS; i++){
//    myStudent[i].moveTowards(mouseX, mouseY);   // or ofGetWidth()/2, ofGetHeight()/2
//}
//
//void Student::moveTowards( float xTarget, float yTarget){
//    u = 0.95 * x + 0.05 * xTarget;
//    v = 0.95 * x + 0.05 * yTarget;
//    
//}


void Student::update(float _x, float _y, int _dim){
    
    if(x < 0 ){
        x = 0;
        speedX *= -1;
    } else if(x > ofGetWidth()){
        x = ofGetWidth();
        speedX *= -1;
    }
    
    if(y < 0 ){
        y = 0;
        speedY *= -1;
    } else if(y > ofGetHeight()){
        y = ofGetHeight();
        speedY *= -1;
    }
    
    x+=speedX;
    y+=speedY;
}

void Student::draw(float _x, float _y, int _dim){
    
    ofPushStyle();
    ofPushMatrix();
    
    ofSetColor(color);
    
img.draw(x,y,80,180);

    
    ofPopMatrix();
    ofPopStyle();

}

    
    

