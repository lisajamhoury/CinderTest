//
//  PulseSensor1.cpp
//  Sketch1
//
//  Created by Lisa Jamhoury on 10/12/16.
//
//

#include "cinder/app/App.h"
#include "PulseSensor1.hpp"
#include "PulseLine.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

PulseSensor1::PulseSensor1() {
  float dest = getWindowWidth()/2/3; // half of third
  float frames = 7200.0; // two minutes at 60fps
  float tempVel = dest/frames;
  
  float length = getWindowHeight();
  float tempLength = length/frames;
    
  moving = false;
  now_ = 0;

  mLoc = vec2( getWindowWidth()/2, getWindowHeight()/2 );
  mVel = vec2( tempVel, 0 );
  lineVel = vec2( 0, tempLength );
}

void PulseSensor1::update() {
  frameCt = getElapsedFrames();
    
  if (frameCt > 360) { //change this to 1 min - 3600 frames
    
    
    if (!moving) {
      moving = true;
      now_ = frameCt;
    }
  }
  
  if (moving && (frameCt > now_ + 180)) {
    mPulseLines.push_back( PulseLine( mLoc, lineVel ) );
    mNumPLines = 0;
    
    now_ = frameCt;
  }
  
  if (mPulseLines.size() > 0) {
    for (auto line1 = mPulseLines.begin(); line1 != mPulseLines.end(); ++line1) {
      line1->step();
    }
    mLoc += mVel;
  }
}

void PulseSensor1::draw() {
  for (auto line1 = mPulseLines.begin(); line1 != mPulseLines.end(); ++line1) {
    line1->display();
  }
}
