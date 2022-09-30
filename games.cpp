#include "boards.hpp"

class Player {
    private: 
        int score;
    public:
        Player () : score (0) {};

        int get () {
            return score;
        }

        void set (int _score) {
            score += _score;
        }
};

class Game {
    private:
        Board board;
        std::vector<Player> players;
        bool turn;
    public:
        Game (size_t v_edges, size_t h_edges)
            : board (v_edges, h_edges),
              turn (false)
            {
                players.resize (2);
                players[0] = Player ();
                players[1] = Player ();
            }
        void play () {
            int i;
            int score;

            while (board.hasBoxes()) {
                std::cout << board;
                std::cout << "Player " << turn+1 << "'s turn. Select an edge: ";
                std::cin >> i;
                if (i < 0 || i >= board.N) {
                    std::cout << "Please choose an index between 0 and " << board.N << std::endl;
                    continue;
                }
                if ((score = board.selectEdge (i)) < 0) {
                    std::cout << "Edge " << i << " has already been selected. Try again." << std::endl;
                }
                else if (score > 0) {
                    players[turn].set (score);
                }
                else {
                    turn = !turn;
                }
                std::cout << "Scores: " << std::endl;
                std::cout << "    Player 1: " << players[0].get() << std::endl;
                std::cout << "    Player 2: " << players[1].get() << std::endl;
            }
            std::cout << board;
            std::cout << "Final score: " << std::endl;
            std::cout << "    Player 1: " << players[0].get() << std::endl;
            std::cout << "    Player 2: " << players[1].get() << std::endl;
        }          
};


int main (int argc, char *argv[]) {
    Game game (3, 3);
    game.play ();
}