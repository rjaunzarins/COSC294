#include "Player.h"

class Game {
    public:
        void selectPlayers();
        Player* nextPlayer() const;
        void play();
        void announceWinner();
    private:
        bool isRunning() const;
        bool isHumanPlayer(Player* currentPlayer);
        void getDifficulty(std::unique_ptr<Player>&);
        void createHumanPlayer(std::unique_ptr<Player>& currentPlayer);
        void announcePlayers(const std::unique_ptr<Player>&, const std::unique_ptr<Player>&);
        EnemyPiece getEnemyPiece(std::unique_ptr<Player> player, size_t index);
        std::unique_ptr<Player> player1;
        std::unique_ptr<Player> player2;
        Player* currentPlayer;
};