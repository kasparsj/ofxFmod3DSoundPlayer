#pragma mark once

#include "ofMain.h"

void ofxFmod3DUpdateListener(glm::vec3 position, glm::vec3 velocity = glm::vec3 (0, 0, 0), glm::vec3 forward = glm::vec3 (0, 0, 1), glm::vec3 up = glm::vec3 (0, 1, 0));

class ofxFmod3DSoundPlayer : public ofFmodSoundPlayer {
public:
    
    static void initializeFmod();
    static void closeFmod();
    bool load(string fileName, bool stream = false);
    void play();
    void update( glm::vec3 position, glm::vec3 velocity = glm::vec3() );
    
    glm::vec3 getPosition3D() const {
        return glm::vec3(pos3d.x, pos3d.y, pos3d.z);
    }
    glm::vec3 getVelocity() const {
        return glm::vec3(vel.x, vel.y, vel.z);
    }
    
private:
    FMOD_VECTOR pos3d, vel;
        
};
