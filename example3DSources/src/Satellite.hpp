#pragma once

#include "ofMain.h"

class Satellite {
  
public:
    Satellite(float distance, float orbitTime, float inclination = 0.f, float radius = 5.f) : distance(distance), orbitTime(orbitTime), inclination(inclination), radius(radius) {
        
    }
    void update(float time);
    float getDistance() const {
        return distance;
    }
    void setDistance(float value) {
        distance = value;
    }
    float getOrbitTime() const {
        return orbitTime;
    }
    void setOrbitTime(float value) {
        orbitTime = value;
    }
    float getInclination() const {
        return inclination;
    }
    void setInclination(float value) {
        inclination = value;
    }
    glm::vec3 getPosition() const {
        return position;
    }
    glm::vec3 getVelocity() const {
        return velocity;
    }
    float getRadius() const {
        return radius;
    }
    
private:
    float distance;
    float orbitTime;
    float inclination;
    float radius;
    glm::vec3 position;
    glm::vec3 velocity;
    
};
