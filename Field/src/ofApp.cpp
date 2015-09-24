#include "ofApp.h"

#include "ofApp.h"
#include "Globals.h"

float  Globals::camZoom;
bool   Globals::invert;
int    Globals::fieldNumParticles;
float  Globals::fieldNoiseAmount;
float  Globals::fieldSpiralAmount;
float  Globals::fieldUniformAmount;
float  Globals::fieldCircularAmount;
float  Globals::fieldOscillAmount;
float  Globals::fieldRandomOffset;
float  Globals::fieldMagnitude;
float  Globals::fieldSpaceFrequency;
float  Globals::fieldTimeFrequency;
float  Globals::fieldOldVelAmount;
float  Globals::fieldMaxVel;
float  Globals::fieldMaxAge;
float  Globals::fieldSpiralRatio;
float  Globals::fieldCircularRatio;
float  Globals::fieldOscillRatio;
int    Globals::fieldTailLength;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    ofSetBackgroundAuto(false);
    ofSetVerticalSync(false);
    ofEnableAlphaBlending();
    
    Globals::invert = true;
    Globals::camZoom = 0;
    
    Globals::fieldNumParticles = 1500;
    Globals::fieldNoiseAmount = 0;
    Globals::fieldSpiralAmount = 0;
    Globals::fieldUniformAmount = 1;
    Globals::fieldCircularAmount = 0;
    Globals::fieldOscillAmount = 0;
    Globals::fieldRandomOffset = 0;
    Globals::fieldMagnitude = 0.1;
    Globals::fieldSpaceFrequency = 0.1;
    Globals::fieldTimeFrequency = 0.5;
    Globals::fieldOldVelAmount = 0.5;
    Globals::fieldMaxVel = 0.5;
    Globals::fieldMaxAge = 1.5;
    Globals::fieldSpiralRatio = 0;
    Globals::fieldCircularRatio = 0;
    Globals::fieldOscillRatio = 0;
    Globals::fieldTailLength = 6;
    
    showUI = true;
    mUI.setup();
    fieldGenerator.setup();
    ofHideCursor();
}

//--------------------------------------------------------------
void ofApp::update(){
    fieldGenerator.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor c = (Globals::invert) ? 0 : 255;
    ofSetColor(c);
    ofDrawRectangle( 0, 0, ofGetWidth(), ofGetHeight() );
    
    fieldGenerator.draw();
    if(showUI)mUI.draw();
    ofSetColor(200,0,200);
    ofDrawCircle(p.x,p.y,2);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    ofShowCursor();
    p = ofVec2f(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    p = ofVec2f(x,y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    p = ofVec2f(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    p = ofVec2f(x,y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
