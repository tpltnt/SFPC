
#include "Student.h"

Student::Student(){
}

void Student::setup(float _x, float _y, string fileName){
    
    varSpeedX = ofRandom(.99,.999);

    
        x = _x; //why do we do this?
        y = _y;
        
        speedX = ofRandom(-1,1); //look below for where we use this
        speedY = ofRandom(-1,1);
        rotation = ofRandom(-10,10);
        color.setHsb(ofRandom(255),ofRandom(100,110),ofRandom(200,220));
    
    img.loadImage(fileName);
    cout << fileName  << " " << img.width << endl;

   
    varDistance = ofRandom(300,900);
    

    }





void Student::moveTowards( float xTarget, float yTarget){
   
    
//    // (a) calculate my angle from the center of the screen
//    float dy = yTarget - y;
//    float dx = xTarget - x;
//    float myAngle = atan2(dy, dx);
//    
//    // (b) project based on varDistance where I should stop
//    float xStop = xTarget + 100 * cos(myAngle);
//    float yStop = yTarget + 100 * sin(myAngle);
    x = varSpeedX * x + (1-varSpeedX) * stopPoint.x;
    y = varSpeedX * y + (1-varSpeedX) * stopPoint.y;
//    
    
    
    
//    float dist = ofDist(x,y, xTarget, yTarget);
//    
//    if (dist > varDistance){
//        x = varSpeedX * x + (1-varSpeedX) * xTarget;
//        y = varSpeedX * y + (1-varSpeedX) * yTarget;
//    }
  
}


//}





void Student::update(float _x, float _y, int _dim){
    
//    if(x < 0 ){ // if x is less than 0, then speedX is negative ??
//        x = 0;
//        speedX *= -1; // speedX = speedX * -1
//    } else if(x > ofGetWidth()){ //if x is greater than the canvas, then speedX is also negative ?
//        x = ofGetWidth();
//        speedX *= -1;
//    }
//    
//    if(y < 0 ){
//        y = 0;
//        speedY *= -1;
//    } else if(y > ofGetHeight()){
//        y = ofGetHeight();
//        speedY *= -1;
//    }
//    
//    x+=speedX; // x = x + speedX
//    y+=speedY;
}

void Student::draw(){
    
    ofPushStyle();
    ofPushMatrix();
    
    ofSetColor(color);
    
img.draw(x,y,83,180);

    
    ofPopMatrix();
    ofPopStyle();

}

    
    

