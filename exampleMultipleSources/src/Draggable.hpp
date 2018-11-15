#pragma once

#include "ofMain.h"

class Draggable {
    
public:
    Draggable(glm::vec3 pos, int radius = 5) : pos(pos), radius(radius) {
        
    }
    void update();
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    string name;
    glm::vec3 pos;
    bool mouseIsDown = false;
    int radius;    
};
