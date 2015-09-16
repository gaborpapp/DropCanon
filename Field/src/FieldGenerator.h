#pragma once

#include "ofMain.h"
#include "MathUtils.h"
#include "FieldParticle.h"

class FieldGenerator {
public:
    void setup();
    void drawParticles();
    void reInitParticle( FieldParticle* _p );
    void update();
    void draw();
    
    //  different vector fields
    ofVec3f getNoise( ofVec3f _noisePos, float _time );
    ofVec3f getUniform();
    ofVec3f getSpiral( ofVec3f _particlePos, float _distance, float _ratio, float _time );
    
    
    void numParticlesChanged(int& _param );			// Callbacks from the UI
    vector< FieldParticle >		particles;
    
    ofEasyCam camera;
    bool inited = false;
    string mode;
};