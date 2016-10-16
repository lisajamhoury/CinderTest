//
//  RightSensor.hpp
//  Sketch1
//
//  Created by Lisa Jamhoury on 10/12/16.
//
//

#pragma once

class RightSensor {
public:
    RightSensor();
    
    void update();
    void draw();
    
    cinder::vec2 mLoc;
    cinder::vec2 mVel;
};