//
//  PulseLine.hpp
//  Sketch1
//
//  Created by Lisa Jamhoury on 10/12/16.
//
//

#pragma once

class PulseLine {
public:
    
    PulseLine() {}
    PulseLine( cinder::vec2 aLoc, cinder::vec2 aVel );
    
    void step();
    void display();
    
    //float x_, y_;
    
    cinder::vec2 mLoc;
    cinder::vec2 mVel;
};