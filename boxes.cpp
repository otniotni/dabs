#include "boxes.hpp"

std::string horizontalFill (Edge *b) {
    if (*b)
        return "--------";
    return "        ";
}

std::string verticalFill (Edge *b) {
    if (*b)
        return "|        ";
    return "         ";
}

Box::Box (std::initializer_list<Edge*> _edges)
    : status (false) {
        edges = _edges;
        for (Edge *e: _edges)
            e->insertBox (this);
    }

Box::operator bool() {
    for (Edge *e: edges) {
        if (!e->closed){
            return false;
            }
    }
    status = true;
    return status;
}

std::ostream& operator<< (std::ostream& os, const Box& box) {
    os << "o" << horizontalFill (box.edges[0]) << "o" << std::endl;
    for (int i = 0; i < 3; i++) {
        os << verticalFill (box.edges[1])
           << verticalFill (box.edges[2])
           << std::endl;
    }
    os << "o" << horizontalFill (box.edges[3]) << "o" << std::endl; 
    return os;
}