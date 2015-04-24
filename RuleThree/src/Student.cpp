//
//  Student.cpp
//  RuleThree
//
//  Created by Eve Weinberg on 4/22/15.
//
//

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
        color.setHsb(ofRandom(255),ofRandom(90,130),ofRandom(200,230));
    
        studentA.loadImage("studentA.png");
        studentB.loadImage("studentB.png");
        studentC.loadImage("studentC.png");
    
    float randomVal = ofRandom(0,1);
    if (randomVal < 0.33){
        img.loadImage("studentA.png");
    } else if (randomVal >= 0.33 && randomVal < 0.66){
        img.loadImage("studentB.png");
    } else {
        img.loadImage("studentC.png");
    }

        
}


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

    
    

