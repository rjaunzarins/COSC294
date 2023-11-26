#include "Player.h"

class Game {
    public:
        void selectPlayers();
        Player* nextPlayer() const;
        void play();
        void announceWinner();
    private:
        bool isRunning() const;
        EnemyPiece getEnemyPiece(std::unique_ptr<Player> player, size_t index);
        std::unique_ptr<Player> player1;
        std::unique_ptr<Player> player2;
        Player* currentPlayer;
};