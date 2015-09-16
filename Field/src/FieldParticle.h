#pragma once
#include "ofMain.h"

class FieldParticle
{
public:
    
    ofVec3f pos;
    ofVec3f vel;
    ofVec3f fieldRandomOffset;
    deque<ofVec3f> posHistory;
    float age;
    float distanceFromMiddle;
    
};
