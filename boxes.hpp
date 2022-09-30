#include <iostream>
#include <vector>
#include <string>
#include "edges.hpp"

class Edge;

std::string horizontalFill (Edge *b);
std::string verticalFill (Edge *b);

class Box {
    protected:
        std::vector<Edge*> edges;
        bool status;
    public:
        Box (std::initializer_list<Edge*> _edges);
        void printEdges () {
            for (auto e: edges)
                std::cout << e->closed << " ";
            std::cout << std::endl;
        }
        explicit operator bool ();

        friend std::ostream& operator<< (std::ostream &os, const Box& box);
};