

#include "button.h"


void button::draw(){
    ofCircle(pos, radius);
}

bool button::mousePressed(float x, float y){
    ofPoint mousePt;
    mousePt.set(x,y);
    float distance = (pos - mousePt).length();
    if (distance < radius){
        return true;
    } else {
        return false;
    }
}