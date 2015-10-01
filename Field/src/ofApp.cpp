#include "ofApp.h"
#include "Globals.h"

#define EXP_VID 1

float  Globals::camZoom;
float  Globals::camPanY;
float  Globals::camPanX;

bool   Globals::invert;
float  Globals::distanceAlpha;
bool   Globals::fieldShowTail;
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
float  Globals::fieldConnections;
int    Globals::fieldResetPos;
bool   Globals::fieldAging;

void ofApp::setup() {
    ofBackground(0,0,0);
    ofSetVerticalSync(false);
    ofEnableAlphaBlending();
    
    Globals::invert = true;
    Globals::distanceAlpha = 0;
    Globals::camZoom = 0;
    
    Globals::fieldNumParticles = 2000;
    Globals::fieldShowTail = true;
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
    Globals::fieldConnections = 0;
    Globals::fieldResetPos = 1;
    Globals::fieldAging = true;
    
    showUI = true;
    mUI.setup();
    fieldGenerator.setup();
    
#if EXP_VID == 1
    //  setup video recording
    fileName = "field_recording_";
    fileExt = ".mov";
    videoRecorder.setVideoCodec("h264");
    videoRecorder.setVideoBitrate("20000k");
    bRecording = false;
    ofFbo::Settings s;
    s.width = 1920;
    s.height = 1080;
    s.numSamples = ofFbo::maxSamples();
    s.internalformat = GL_RGB;
    recordFbo.allocate(s);
    recordFbo.begin();
    ofClear(0,0,0,0);
    recordFbo.end();
#endif
}

void ofApp::update() {
    recordFbo.readToPixels(recordPixels);
    bool success = videoRecorder.addFrame(recordPixels);
    if(!success) { /**/ }
    if(videoRecorder.hasVideoError()) {
        cout << "video error" << endl;
    }
    fieldGenerator.update();
}

void ofApp::draw(){
#if EXP_VID == 1
    recordFbo.begin();
#endif
    ofColor c = (Globals::invert) ? 0 : 255;
    ofSetColor(c);
    ofDrawRectangle( 0, 0, recordFbo.getWidth(), recordFbo.getHeight() );
    
    fieldGenerator.draw();
#if EXP_VID == 1
    recordFbo.end();
    recordFbo.draw(0,0,ofGetWidth(),ofGetHeight());
    if(bRecording) {
        ofSetColor(200,0,0);
        ofDrawCircle(ofGetWidth()-100,20,10);
        ofSetColor(255);
    }
#endif
    if(showUI)mUI.draw();
    //ofSetColor(200,0,0);
    //ofDrawCircle(p.x,p.y,2);
    ofDrawBitmapString("fps: " + ofToString(int(ofGetFrameRate())), ofGetWidth()-80,20);
    ofDrawBitmapString("sec: " + ofToString(int(elapsed)), ofGetWidth() - 80, 40);
    elapsed += ofGetLastFrameTime();
}

void ofApp::exit() {
    videoRecorder.close();
}

void ofApp::keyPressed(int key){
    fieldGenerator.keyPressed( key );
    mUI.keyPressed( key );
    if( key == ' ' ) {
        showUI = !showUI;
    }
#if EXP_VID == 1
    if( key == '9' ) {
        bRecording = !bRecording;
        elapsed = 0;
        if(bRecording && !videoRecorder.isInitialized()) {
            videoRecorder.setup(fileName+ofGetTimestampString()+fileExt, 1920, 1080, 30);
            videoRecorder.start();
        }else if(!bRecording && videoRecorder.isInitialized()) {
            videoRecorder.setPaused(true);
        }else if(bRecording && videoRecorder.isInitialized()) {
            videoRecorder.setPaused(false);
        }
    }
#endif
}

void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}
