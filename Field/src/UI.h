#pragma once
#include "ofxGui.h"
#include "ofTrueTypeFontExt.h"

class UI {
public:
    void setup();
    void draw();
    void keyPressed( int key );
    
    ofTrueTypeFontExt		fontSmall;
    
    //  camera
    ofxPanel camGui;
    ofxButton bInvert;
    ofParameterGroup camParameters;
    ofParameter< float > distanceAlpha;
    ofParameter< float > camZoom;
    ofParameter< float > camPanX;
    ofParameter< float > camPanY;
    
    void onInvert();
    void changeParticleShape();
    void resetParticlePos();
    void changeAging(bool yes);
    
    //  field
    ofxPanel fieldGui;
    ofParameterGroup fieldParameters;
    
    ofxButton               fieldParticleShape;
    ofxButton               fieldResetPos;
    ofParameter<bool>       fieldAging;
    ofParameter<float>		fieldNoiseAmount;
    ofParameter<float>		fieldSpiralAmount;
    ofParameter<float>		fieldUniformAmount;
    ofParameter<float>		fieldCircularAmount;
    ofParameter<float>		fieldOscillAmount;
    ofParameter<float>		fieldRandomOffset;
    ofParameter<float>		fieldMagnitude;
    ofParameter<float>		fieldSpaceFrequency;
    ofParameter<float>		fieldTimeFrequency;
    ofParameter<float>		fieldOldVelAmount;
    ofParameter<float>		fieldMaxVel;
    ofParameter<float>		fieldMaxAge;
    ofParameter<float>		fieldSpiralRatio;
    ofParameter<float>		fieldCircularRatio;
    ofParameter<float>		fieldOscillRatio;
    ofParameter<float>		fieldTailLength;
    ofParameter<float>		fieldConnections;
    
};