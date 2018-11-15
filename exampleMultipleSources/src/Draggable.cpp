#include "Draggable.hpp"

void Draggable::update() {
    if (mouseIsDown) {
        pos.x = ofGetMouseX();
        pos.y = ofGetMouseY();
    }
}

void Draggable::mousePressed(int x, int y, int button) {
    if ( button == 0 && x > pos.x - radius && x < pos.x + radius && y > pos.y - radius && y < pos.y + radius) {
        mouseIsDown = true;
    }
}

void Draggable::mouseReleased(int x, int y, int button) {
    if (button == 0) {
        mouseIsDown = false;
    }
}
