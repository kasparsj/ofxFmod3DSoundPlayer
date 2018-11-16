#pragma once

#include "ofMain.h"
#include "ofxFmod3DSoundPlayer.hpp"
#include "Satellite.hpp"

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
    
    void reset();
    void unload();
    void loadFiles(int numFiles = 0);
    void loadFile(const ofFile &file);
    void loadSound(string path);
    void randomize();

    ofEasyCam cam;
    vector<shared_ptr<ofxFmod3DSoundPlayer>> players;
    vector<shared_ptr<Satellite>> satellites;
    
    bool showHelp = true;
    bool lCam;
    glm::vec3 lPos;
    glm::vec3 lForward;
    float soundScale = 1/35.f;
    double resetTime = 0;
    ofDirectory dir;
		
};
