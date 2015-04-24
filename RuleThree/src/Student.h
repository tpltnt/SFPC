//
//  Student.h
//  RuleThree
//
//  Created by Eve Weinberg on 4/22/15.
//
//

#ifndef __RuleThree__Student__
#define __RuleThree__Student__

#include "ofMain.h"

#include <stdio.h>


class Student{
    
    
    public :
    void setup(float _x, float _y, int _dim);
    void update(float _x, float _y, int _dim);
    void draw(float _x, float _y, int _dim);
    
    
    
    float quadrant;
    float image;
    float rotation;
    float x;
    float y;
    float speedY; // speed and direction
    float speedX;
    int dim;      // size
    
    ofColor color; // id like to set this to RGB,
    
    ofImage studentA, studentB, studentC, img;


    Student(); // constructor - used to initialize an object, if no properties are passed the program sets them to the default value
    
private: 

};



#endif 

