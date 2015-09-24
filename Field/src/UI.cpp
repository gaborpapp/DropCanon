#include "UI.h"
#include "Globals.h"


void UI::setup() {
    fontSmall.load("DIN.otf", 8 );
    ofxGuiSetFont( "DIN.otf", 8 );
    
    ofxGuiSetHeaderColor( ofColor( 200, 0, 200 ) );
    ofxGuiSetBackgroundColor(240),
    ofxGuiSetTextColor(100);
    ofxGuiSetFillColor(200);
    
    
    bCamReset.addListener(this, &UI::onCamReset);
    camParameters.setName("Cam Params");
    camGui.setup(camParameters);
    camGui.add(bCamReset.setup("Reset"));
    camGui.add(camZoom.set("Zoom Level", 0, 40, -10 ));
    camGui.setPosition(ofPoint(20,20));
    
    fieldParameters.setName("Field Params");
    fieldGui.setup(fieldParameters);
    fieldGui.add(fieldNoiseAmount.set("noise amount", 0, 0, 1));
    fieldGui.add(fieldSpiralAmount.set("spiral amount", 0, 0, 1));
    fieldGui.add(fieldUniformAmount.set("uniform amount", 1, 0, 1));
    fieldGui.add(fieldCircularAmount.set("circular amount", 0, 0, 1));
    fieldGui.add(fieldOscillAmount.set("oscill amount", 0, 0, 1));
    fieldGui.add(fieldMagnitude.set("magnitude", 0.1, 0, 1));
    fieldGui.add(fieldMaxAge.set("max age", 1.5, 0, 10 ));
    fieldGui.add(fieldMaxVel.set("max vel", 0.5, 0, 1  ));
    fieldGui.add(fieldSpaceFrequency.set("space freq",  0.1, 0, 1 ));
    fieldGui.add(fieldTimeFrequency.set("time freq", 0.5, 0, 1  ));
    fieldGui.add(fieldOldVelAmount.set("old vel amount", 0.5, 0, 1  ));
    fieldGui.add(fieldRandomOffset.set("random offset", 0, 0, 1 ));
    fieldGui.add(fieldSpiralRatio.set("spiral ratio", 0.5, -1, 1 ));
    fieldGui.add(fieldCircularRatio.set("circular ratio", 0.5, -1, 1 ));
    fieldGui.add(fieldOscillRatio.set("oscill ratio", 0.5, -1, 1 ));
    fieldGui.add(fieldTailLength.set("tail length", 6, 0, 100 ));
    
    fieldGui.setPosition(ofPoint(20,100));
}

void UI::draw() {
    Globals::camZoom = camZoom;
    
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

void UI::onCamReset() { /**/ }



