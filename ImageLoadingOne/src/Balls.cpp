//
//  Balls.cpp
//  ImageLoadingOne
//
//  Created by Eve Weinberg on 4/28/15.
//
//

#include "Balls.h"


//-----------------------------------------------------------------------
void Balls::setup(){

aStart.set(0,0);
bEnd.set(ofGetWidth()/2, ofGetHeight()/2);
pct = 0;
    
//    cloud.loadImage("cloud.png");
    
}



//-----------------------------------------------------------------------
void Balls::update(){

  
    pct += 0.005;   // ie: pct = pct + 0.005
    
    if (pct > 1){
        pct = 0;
    }
}





//-----------------------------------------------------------------------
void Balls::draw(){
    float x,y;
    ofPoint(0,0);
    ofPoint(ofGetWidth(),ofGetHeight());
    
    
    float pctShaped =  powf(pct, 0.5);     //pct * pct;      ///powf(pct, 2);
    ofPoint mixPt = (1.0-pctShaped) * aStart + pctShaped * bEnd;

    ofSetColor(50);
    ofCircle(mixPt, 350);
    
    ofSetColor(0);
    ofCircle(mixPt, 100);
    
    for (int i = 0; i < 20; i ++) {
        
        ofSetColor(30);
        ofCircle(300*i, ofGetElapsedTimef()*i*20, 20);

    }
    
//    ofSetColor(20);
//    cloud.draw(3*ofGetElapsedTimef(),400,214,91);

    
}
