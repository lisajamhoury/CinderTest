//
//  RightSensor.cpp
//  Sketch1
//
//  Created by Lisa Jamhoury on 10/12/16.
//
//

#include "cinder/app/App.h"
#include "RightSensor.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

RightSensor::RightSensor() {
    int dest = getWindowWidth()/2;
    float frames = 10800.0;
    float tempVel = dest/frames;
    
    mLoc = vec2( getWindowWidth(), getWindowHeight()/2);
    mVel = vec2( -tempVel, 0);
}

void RightSensor::update() {
    mLoc += mVel;
}

void RightSensor::draw() {
    int rad = 10;
    
    gl::color(0.68, 0.68, 0.68);
    gl::drawSolidCircle(mLoc, rad);
}

