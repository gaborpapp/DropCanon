#pragma once

#include "ofMain.h"
#include "MathUtils.h"
#include "FieldParticle.h"
#include "ofxTween.h"
#include "UI.h"

class FieldGenerator {
public:
    void setup();
    void drawParticles();
    void reInitParticle( FieldParticle* _p );
    void update();
    void draw();
    void keyPressed(int key);
    
    //  different vector fields
    ofVec3f getNoise( ofVec3f _noisePos, float _time );
    ofVec3f getUniform();
    ofVec3f getCircular( ofVec3f _particlePos, float _distance, float _ratio, float _time );
    ofVec3f getSpiral( ofVec3f _particlePos, float _distance, float _ratio, float _time );
    ofVec3f getOscill( ofVec3f _particlePos, float _distance, float _ratio, float _spin, float _time );
    
    void numParticlesChanged(int& _param );			// Callbacks from the UI
    void randomizeParticleAges();
    void resetParticles();
    
    vector< FieldParticle >		particles;
    
    ofxTween twx, twy, twz;
    ofxEasingExpo 	easingexpo;
    float rx, ry, rz;

    ofEasyCam camera;
    bool inited = false;
};