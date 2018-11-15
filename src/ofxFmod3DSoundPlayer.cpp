#include "ofxFmod3DSoundPlayer.hpp"
#include "ofFmodSoundPlayer.cpp"

bool ofxFmod3DInitialized_ = false;

void ofxFmod3DUpdateListener(glm::vec3 position, glm::vec3 velocity, glm::vec3 forward, glm::vec3 up)
{
    FMOD_VECTOR listenerVelocity, listenerUp, listenerForward, listenerPos;
    
    listenerVelocity.x = velocity.x;
    listenerVelocity.y = velocity.y;
    listenerVelocity.z = velocity.z;
    
    listenerPos.x = position.x;
    listenerPos.y = position.y;
    listenerPos.z = position.z;
    
    listenerForward.x = forward.x;
    listenerForward.y = forward.y;
    listenerForward.z = forward.z;
    
    listenerUp.x = up.x;
    listenerUp.y = up.y;
    listenerUp.z = up.z;
    
    FMOD_System_Set3DListenerAttributes(sys, 0, &listenerPos, &listenerVelocity, &listenerForward, &listenerUp);
}

void ofxFmod3DSoundPlayer::initializeFmod(){
    
    if(!ofxFmod3DInitialized_){
        ofFmodSoundPlayer::initializeFmod();
        FMOD_System_Set3DSettings(sys, 10.0f, 10.0f, 10.0f);
        ofxFmod3DInitialized_ = true;
    }
    
}

void ofxFmod3DSoundPlayer::closeFmod(){
    ofFmodSoundPlayer::closeFmod();
    ofxFmod3DInitialized_ = false;
}

bool ofxFmod3DSoundPlayer::load(string _fileName, bool stream)
{
    auto fileName = ofToDataPath(_fileName);
    bMultiPlay = false;
    initializeFmod();
    unload();
    
    result = FMOD_System_CreateSound(sys, fileName.c_str(), FMOD_3D, NULL, &sound);
    result = FMOD_Sound_Set3DMinMaxDistance(sound, 1.f, 5000.0f);
    
    if (result != FMOD_OK){
        bLoadedOk = false;
        printf("ofSoundPlayer: Could not load sound file %s \n", fileName.c_str() );
    } else {
        bLoadedOk = true;
        FMOD_Sound_GetLength(sound, &length, FMOD_TIMEUNIT_PCM);
        isStreaming = stream;
    }
    return bLoadedOk;
}

void ofxFmod3DSoundPlayer::play(){

    ofFmodSoundPlayer::play();
    FMOD_VECTOR pos = {  0.0f, 0.0f, 0.0f };
    FMOD_VECTOR vel = {  0.0f, 0.0f, 0.0f };
    FMOD_Channel_Set3DAttributes(channel, &pos, &vel);
    FMOD_System_Update(sys);
}

void ofxFmod3DSoundPlayer::update( glm::vec3 position, glm::vec3 velocity )
{
    pos3d.x = position.x;
    pos3d.y = position.y;
    pos3d.z = position.z;
    
    vel.x = velocity.x;
    vel.y = velocity.y;
    vel.z = velocity.z;

    if (isPlaying()) {
        FMOD_Channel_Set3DAttributes(channel, &pos3d, &vel);
    }
}
