#include "Player.h"

class Game {
    public:
        void selectPlayers();
        Player* nextPlayer() const;
        void play();
        void announceWinner();
    private:
        bool isRunning() const;
        std::unique_ptr<Player> player1;
        std::unique_ptr<Player> player2;
};