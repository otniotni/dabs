#include <iostream>
#include <vector>
#include <string>
#include "boxes.hpp"

/* 
Edge data type for the game Dots and Boxes. 

An edge is a line between two dots. 

Each edge has a public variable 'false' which
is a boolean indicating whether or not the 
edge has been chosen previously. All edges
are initiated with closed = false, implying
that they're open for selection in the game.

Any given edge is part of at most 2 different boxes.
The vector 'boxes' holds adresses to these boxes.
*/



Edge::Edge ()
    : closed (false) {};

Edge::operator bool() const {
    return closed;
    }

int Edge::countCompletedBoxes () {
    int count = 0;
    for (int i = 0; i < boxes.size(); i++) {
        if (*boxes[i]) {
            count++;
        }
    }
    return count;
}

void Edge::insertBox (Box* box) {
    boxes.emplace_back (box);
}

bool Edge::selectIfViable () {
    if (!closed) {
        closed = true;
        return true;
    }
    return false;
}