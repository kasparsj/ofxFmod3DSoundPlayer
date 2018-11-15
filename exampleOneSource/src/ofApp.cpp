#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    keyIsDown = false;
    
    lvelocity = glm::vec3(0, 0, 0);
    lup = glm::vec3(0, 1, 0);
    lforward = glm::vec3(0, 0, 1);
    lposition = glm::vec3(ofGetWidth()/2.f*scale, ofGetHeight()/2.f*scale, 0);
    
    sposition = glm::vec3(ofRandom(ofGetWidth())*scale, ofRandom(ofGetHeight())*scale, 0);
    svelocity = glm::vec3(0, 0, 0);
    
    player.load(ofToDataPath("organ.wav"));
    player.setLoop(true);
    player.setVolume(0.75);
    player.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofxFmod3DUpdateListener(lposition, lvelocity, lforward, lup);
    if (mouseIsDown) {
        if(keyIsDown) {
            lposition.x = mouseX*scale;
            lposition.y = mouseY*scale;
        } else {
            sposition.x = mouseX*scale;
            sposition.y = mouseY*scale;
        }
    }
    player.update(sposition, svelocity);
    ofFmodSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0xff0000);
    ofDrawEllipse(sposition.x*(1/scale), sposition.y*(1/scale), 10, 10);
    ofSetHexColor(0x0000ff);
    ofDrawEllipse(lposition.x*(1/scale), lposition.y*(1/scale), 10, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    keyIsDown = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    keyIsDown = false;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (button == 0) {
        mouseIsDown = true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (button == 0) {
        mouseIsDown = false;
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
