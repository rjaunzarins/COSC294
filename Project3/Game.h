#include "Player.h"

class Game {
    public:
        void selectPlayers();
        std::unique_ptr<Player> nextPlayer() const;
        bool isRunning() const;
        void play();
        void announceWinner();
    private:
        std::unique_ptr<Player> player1;
        std::unique_ptr<Player> player2;
};