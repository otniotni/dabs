#include "boxes.hpp"

class Board {
    protected:
        const int n_v, n_h;
        std::vector<Edge*> edges;
        std::vector<Box*> boxes;

    public:
        const int N;
        Board (size_t v_edges, size_t h_edges);
        int selectEdge (int i);
        bool hasBoxes ();
        void printBoxes ();
        friend std::ostream& operator<< (std::ostream& os, const Board& board);
};