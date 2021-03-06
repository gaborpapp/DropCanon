#pragma once

#include "ofMain.h"
#include "UI.h"
#include "FieldGenerator.h"
#include "ofxVideoRecorder.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
        void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        FieldGenerator fieldGenerator;
        UI mUI;
        bool showUI;
    
        // record video
        ofxVideoRecorder videoRecorder;
        bool bRecording;
        string fileName;
        string fileExt;
        ofFbo recordFbo;
        ofPixels recordPixels;
        float elapsed;
};
