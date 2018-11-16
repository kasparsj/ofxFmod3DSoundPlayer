#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    dir.listDir(ofToDataPath(""));
    ofFmodSoundSetVolume(0.75);
    ofEnableDepthTest();
    ofSetCircleResolution(100);
    
    cam.rotateDeg(30, glm::vec3(1, 0, 1));
    
    reset();
}
              
void ofApp::reset() {
    resetTime = ofGetElapsedTimef();
    int numFiles = 3 + ofRandom(dir.size() - 3);
    unload();
    loadFiles(numFiles);
}

//--------------------------------------------------------------
void ofApp::update(){
    if (lCam) {
        lPos = cam.getPosition();
        lForward = cam.getLookAtDir();
    }
    ofxFmod3DUpdateListener(lPos * soundScale, glm::vec3(), lForward);
    
    for (int i=0; i<satellites.size(); i++) {
        satellites[i]->setDistance(satellites[i]->getDistance() + (0.5 - ofNoise(i*100, ofGetElapsedTimef()*0.1)));
        satellites[i]->setOrbitTime(satellites[i]->getOrbitTime() + (0.5 - ofNoise(i*200, ofGetElapsedTimef()*0.1)));
        satellites[i]->setInclination(satellites[i]->getInclination() + (0.5 - ofNoise(i*300, ofGetElapsedTimef()*0.1)));
        satellites[i]->update(ofGetElapsedTimef());
        players[i]->update(satellites[i]->getPosition() * soundScale, satellites[i]->getVelocity());
    }
    
    ofFmodSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofBackground(0);
    cam.begin();
    for (int i=0; i<satellites.size(); i++) {
        ofFill();
        ofSetHexColor(0xff0000);
        ofDrawSphere(satellites[i]->getPosition(), satellites[i]->getRadius());
        ofNoFill();
        ofSetHexColor(0xffffff);
        ofPushMatrix();
        ofRotateDeg(90, 1, 0, 0);
        ofRotateDeg(satellites[i]->getInclination(), 0, 1, 0);
        ofDrawEllipse(glm::vec3(), satellites[i]->getDistance()*2, satellites[i]->getDistance()*2);
        ofPopMatrix();
    }
    cam.end();
    
    if (showHelp) {
        ofDrawBitmapString("l: load file", 10, 10);
        ofDrawBitmapString("d: load directory", 10, 20);
        ofDrawBitmapString("c: toggle listener cam/center", 10, 30);
        ofDrawBitmapString("h: toggle help", 10, 40);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ofFileDialogResult result;
    switch (key) {
        case 'd':
        case 'l':
            result = ofSystemLoadDialog("Load sound", key == 'd');
            if(result.bSuccess) {
                ofFile file (result.getPath());
                if (file.isDirectory()) {
                    dir.listDir(file.getAbsolutePath());
                    loadFiles();
                }
                else {
                    loadFile(file);
                }
            }
            break;
        case 'r':
            reset();
            break;
        case 'q':
            randomize();
            break;
        case 'c':
            lCam = !lCam;
            if (!lCam) {
                lPos = glm::vec3();
                lForward = glm::vec3(0, 0, 1);
            }
            break;
        case 'u':
            unload();
            break;
        case 'h':
            showHelp = !showHelp;
            break;
    }
}

void ofApp::unload() {
    satellites.clear();
    players.clear();
}

void ofApp::loadFiles(int numFiles) {
    vector<string> paths;
    for (int i = 0; i < dir.size(); i++){
        paths.push_back(dir.getPath(i));
    }
    ofRandomize(paths);
    for (int i=0; i<numFiles; i++) {
        loadFile(ofFile(paths[i]));
    }
}

void ofApp::loadFile(const ofFile &file) {
    string fileExtension = ofToUpper(file.getExtension());
    if (fileExtension == "WAV") {
        loadSound(file.getAbsolutePath());
    }
}

void ofApp::loadSound(string path) {
    float orbitTime = ofRandom(60.f);
    satellites.push_back(shared_ptr<Satellite>(new Satellite(ofRandom(150.f), orbitTime, ofRandom(180.f))));
    players.push_back(shared_ptr<ofxFmod3DSoundPlayer>(new ofxFmod3DSoundPlayer));
    
    int idx = players.size() - 1;
    players[idx]->setLoop(true);
    players[idx]->load(path);
    players[idx]->play();
}

void ofApp::randomize() {
    resetTime = ofGetElapsedTimef();
    for (int i=0; i<satellites.size(); i++) {
        satellites[i]->setDistance(ofRandom(150.f));
        satellites[i]->setOrbitTime(ofRandom(60.f));
        satellites[i]->setInclination(ofRandom(180.f));
    }
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
