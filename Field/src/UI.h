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
    ofxButton bCamReset;
    ofParameterGroup camParameters;
    ofParameter< float > camZoom;
    
    void onCamReset();
    
    //  field
    
    ofxPanel fieldGui;
    ofParameterGroup fieldParameters;
    
    ofParameter<float>		fieldNoiseAmount;
    ofParameter<float>		fieldSpiralAmount;
    ofParameter<float>		fieldUniformAmount;
    ofParameter<float>		fieldRandomOffset;
    ofParameter<float>		fieldMagnitude;
    ofParameter<float>		fieldSpaceFrequency;
    ofParameter<float>		fieldTimeFrequency;
    ofParameter<float>		fieldOldVelAmount;
    ofParameter<float>		fieldMaxVel;
    ofParameter<float>		fieldMaxAge;
    ofParameter<float>		fieldSpiralRatio;
    ofParameter<float>		fieldTailLength;
    
    

};