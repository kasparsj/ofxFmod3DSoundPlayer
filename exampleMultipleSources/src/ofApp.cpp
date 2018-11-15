#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    listener = shared_ptr<Draggable>(new Draggable(glm::vec3(ofGetWidth()/2.f, ofGetHeight()/2.f, 0)));
    
    addSound("soundscape1.wav");
    addSound("soundscape2.wav");
    addSound("soundscape3.wav");
}

//--------------------------------------------------------------
void ofApp::update(){
    listener->update();
    ofxFmod3DUpdateListener(listener->pos * soundScale);
    
    for (int i=0; i<players.size(); i++) {
        sounds[i]->update();
        players[i]->update(sounds[i]->pos * soundScale);
    }
    
    ofFmodSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0xff0000);
    for (int i=0; i<sounds.size(); i++) {
        ofDrawEllipse(sounds[i]->pos.x, sounds[i]->pos.y, 2*sounds[i]->radius, 2*sounds[i]->radius);
        ofDrawBitmapString(names[i], sounds[i]->pos.x + sounds[i]->radius, sounds[i]->pos.y + sounds[i]->radius);
    }
    ofSetHexColor(0x0000ff);
    ofDrawEllipse(listener->pos.x, listener->pos.y, 2*listener->radius, 2*listener->radius);
    ofSetHexColor(0xffffff);
    ofDrawBitmapString("l: load sound", 10, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'l':
            ofFileDialogResult result = ofSystemLoadDialog("Load sound");
            ofFile file (result.getPath());
            string fileExtension = ofToUpper(file.getExtension());
            if(result.bSuccess && fileExtension == "WAV") {
                addSound(result.getPath());
            }
            break;
    }
}

void ofApp::addSound(string path) {
    ofFile file(path);
    names.push_back(file.getFileName());
    sounds.push_back(shared_ptr<Draggable>(new Draggable(glm::vec3(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0))));
    players.push_back(shared_ptr<ofxFmod3DSoundPlayer>(new ofxFmod3DSoundPlayer));
    int idx = players.size() - 1;
    players[idx]->setLoop(true);
    players[idx]->load(path);
    players[idx]->play();
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
    listener->mousePressed(x, y, button);
    for (int i=0; i<sounds.size(); i++) {
        sounds[i]->mousePressed(x, y, button);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    listener->mouseReleased(x, y, button);
    for (int i=0; i<sounds.size(); i++) {
        sounds[i]->mouseReleased(x, y, button);
    }
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
