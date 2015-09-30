#include "UI.h"
#include "Globals.h"

void UI::setup() {
    fontSmall.load("DIN.otf", 8 );
    ofxGuiSetFont( "DIN.otf", 8 );
    
    ofxGuiSetHeaderColor( ofColor( 200, 0, 200 ) );
    ofxGuiSetBackgroundColor( ofColor(240,200) );
    ofxGuiSetTextColor(100);
    ofxGuiSetFillColor(240);
    
    bInvert.addListener(this, &UI::onInvert);
    camParameters.setName("Cam & Col Params");
    camGui.setup(camParameters);
    camGui.add(bInvert.setup("invert"));
    camGui.add(distanceAlpha.set("distance-based alpha", 0, 200, 0 ));
    camGui.add(camZoom.set("zoom level", 0, 40, -10 ));
    camGui.add(camPanX.set("horizontal pan", 0, -40, 40 ));
    camGui.add(camPanY.set("vertical pan", 0, -40, 40 ));
    camGui.setPosition(ofPoint(20,20));
    
    fieldParticleShape.addListener(this,&UI::changeParticleShape);
    fieldResetPos.addListener(this,&UI::resetParticlePos);
    fieldParameters.setName("Field Params");
    fieldGui.setup(fieldParameters);
    fieldGui.add(fieldNoiseAmount.set("noise amount", 0, 0, 1));
    fieldGui.add(fieldSpiralAmount.set("spiral amount", 0, 0, 1));
    fieldGui.add(fieldUniformAmount.set("uniform amount", 1, 0, 1));
    fieldGui.add(fieldCircularAmount.set("circular amount", 0, 0, 1));
    fieldGui.add(fieldOscillAmount.set("oscill amount", 0, 0, 1));
    fieldGui.add(fieldMagnitude.set("magnitude", 0.6, 0, 1));
    fieldGui.add(fieldMaxAge.set("max age", 1.5, 0, 60 ));
    fieldGui.add(fieldMaxVel.set("max vel", 0.5, 0, 1  ));
    fieldGui.add(fieldSpaceFrequency.set("space freq",  0.1, 0, 1 ));
    fieldGui.add(fieldTimeFrequency.set("time freq", 0.5, 0, 1  ));
    fieldGui.add(fieldOldVelAmount.set("old vel amount", 0.5, 0, 1  ));
    fieldGui.add(fieldRandomOffset.set("random offset", 0, 0, 1 ));
    fieldGui.add(fieldSpiralRatio.set("spiral ratio", 0.5, -1, 1 ));
    fieldGui.add(fieldCircularRatio.set("circular ratio", 0.5, -1, 1 ));
    fieldGui.add(fieldOscillRatio.set("oscill ratio", 0.5, -1, 1 ));
    fieldGui.add(fieldTailLength.set("tail length", 4, 0, 100 ));
    fieldGui.add(fieldConnections.set("show connections", 0, 0, 5 ));
    fieldGui.add(fieldParticleShape.setup("tails / dots"));
    fieldGui.add(fieldResetPos.setup("reset pos"));
    fieldGui.add(fieldAging.set("aging",true));
    fieldGui.setPosition(ofPoint(20,150));
}

void UI::draw() {
    Globals::distanceAlpha = distanceAlpha;
    Globals::camZoom = camZoom;
    Globals::camPanX = camPanX;
    Globals::camPanY = camPanY;
    Globals::fieldRandomOffset = fieldRandomOffset;
    Globals::fieldNoiseAmount = fieldNoiseAmount;
    Globals::fieldSpiralAmount = fieldSpiralAmount;
    Globals::fieldUniformAmount = fieldUniformAmount;
    Globals::fieldCircularAmount = fieldCircularAmount;
    Globals::fieldOscillAmount = fieldOscillAmount;
    Globals::fieldMagnitude = fieldMagnitude;
    Globals::fieldSpaceFrequency = fieldSpaceFrequency;
    Globals::fieldTimeFrequency = fieldTimeFrequency;
    Globals::fieldOldVelAmount = fieldOldVelAmount;
    Globals::fieldMaxVel = fieldMaxVel;
    Globals::fieldMaxAge = fieldMaxAge;
    Globals::fieldSpiralRatio = fieldSpiralRatio;
    Globals::fieldCircularRatio = fieldCircularRatio;
    Globals::fieldOscillRatio = fieldOscillRatio;
    Globals::fieldTailLength = fieldTailLength;
    Globals::fieldConnections = fieldConnections;
    Globals::fieldAging = fieldAging;
    
    camGui.draw();
    fieldGui.draw();
}

void UI::keyPressed(int key) {
    if( key == 's') {
        fieldGui.saveToFile("fieldSettings.xml");
    }else if( key == 'l') {
        fieldGui.loadFromFile("fieldSettings.xml");
    }
}

void UI::onInvert() {
    Globals::invert = !Globals::invert;
}

void UI::changeParticleShape() {
    Globals::fieldShowTail = !Globals::fieldShowTail;
}

void UI::resetParticlePos() {
    Globals::fieldResetPos = 0;
}

