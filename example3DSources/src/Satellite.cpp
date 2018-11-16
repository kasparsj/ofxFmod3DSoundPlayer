#include "Satellite.hpp"

void Satellite::update(float time) {
    glm::mat4 rotation = glm::rotate(ofDegToRad(inclination), glm::vec3(0, 0, 1));
    float theta = (fmodf(time, orbitTime) / orbitTime) * TWO_PI;
    position = glm::vec3(rotation * glm::vec4(glm::vec3(distance * cos(theta), 0, distance * sin(theta)), 1.0));
    velocity = glm::vec3(1, 1, 1);
}
