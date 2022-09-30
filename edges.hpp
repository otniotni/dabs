#include <iostream>
#include <vector>
#include <string>

class Box;

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

class Edge {
    private:
        std::vector<Box*> boxes;
    public:
        bool closed;

        Edge ();
        explicit operator bool() const;

        int countCompletedBoxes ();

        void insertBox (Box* box);

        bool selectIfViable ();
};