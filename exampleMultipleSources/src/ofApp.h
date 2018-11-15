#pragma once

#include "ofMain.h"
#include "Draggable.hpp"
#include "ofxFmod3DSoundPlayer.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void addSound(string path);
    
    vector<shared_ptr<Draggable>> sounds;
    vector<string> names;
    shared_ptr<Draggable> listener;
    vector<shared_ptr<ofxFmod3DSoundPlayer>> players;
    
    float soundScale = 1/20.f;
		
};
