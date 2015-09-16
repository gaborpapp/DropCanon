#include "ofApp.h"

#include "ofApp.h"
#include "Globals.h"

float  Globals::camZoom;
bool   Globals::invert;
int    Globals::fieldNumParticles;
float  Globals::fieldNoiseAmount;
float  Globals::fieldSpiralAmount;
float  Globals::fieldUniformAmount;
float  Globals::fieldRandomOffset;
float  Globals::fieldMagnitude;
float  Globals::fieldSpaceFrequency;
float  Globals::fieldTimeFrequency;
float  Globals::fieldOldVelAmount;
float  Globals::fieldMaxVel;
float  Globals::fieldMaxAge;
float  Globals::fieldSpiralRatio;
int    Globals::fieldTailLength;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    
    Globals::invert = true;
    
    Globals::camZoom = 0;
    
    Globals::fieldNumParticles = 2000;
    Globals::fieldNoiseAmount = 0;
    Globals::fieldSpiralAmount = 0;
    Globals::fieldUniformAmount = 1;
    Globals::fieldRandomOffset = 0;
    Globals::fieldMagnitude = 0.1;
    Globals::fieldSpaceFrequency = 0.1;
    Globals::fieldTimeFrequency = 0.5;
    Globals::fieldOldVelAmount = 0.5;
    Globals::fieldMaxVel = 0.5;
    Globals::fieldMaxAge = 1.5;
    Globals::fieldSpiralRatio = 0;
    Globals::fieldTailLength = 6;
    
    showUI = true;
    mUI.setup();
    fieldGenerator.setup();
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
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
