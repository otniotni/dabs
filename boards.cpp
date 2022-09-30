#include "boards.hpp"

Board::Board (size_t v_edges, size_t h_edges)
    : n_v (v_edges),
      n_h (h_edges),
      N (v_edges * (h_edges + 1) + h_edges * (v_edges + 1)) {
        int r, c, i;
        for (i = 0; i < N; ++i)
            edges.emplace_back (new Edge);
        for (r = 0; r < n_v; ++r)
            for (c = 0; c < n_h; ++c) {
                i = r * (2 * n_h + 1) + c;
                Box* box = new Box ({edges[i], 
                          edges[i + n_h],
                          edges[i + n_h + 1],
                          edges[i + 2 * n_h + 1]});
                boxes.emplace_back (box);
            }
}

bool Board::hasBoxes () {
    for (Box *box: boxes) {
        if (!*box) {
            return true;
        }
    }
    return false;
}

int Board::selectEdge (int i) {
    bool status = edges[i]->selectIfViable ();
    if (!status) 
        return -1;
    return edges[i]->countCompletedBoxes ();
}

std::ostream& operator<< (std::ostream& os, const Board& board) {
    int k, j, i = 0;

    while (i < board.N) {
        for (j = 0; j < board.n_h; ++j)
            os << "o" << horizontalFill (board.edges[i+j]);
        os << "o";
        i += j;
        if (i <= board.N - board.n_h) {
            for (k = 0; k < 3; k++) {
                os << std::endl;
                for (j = 0; j < board.n_h + 1; ++j)
                    os << verticalFill (board.edges[i+j]);
            }
            i += j;
        }
        os << std::endl;
    }
    return os;
}
