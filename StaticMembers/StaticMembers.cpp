#include <iostream>

class Server {
    public:
        Server(char letterName);
        static int getTurn();
        void serveOne();
        static bool stillOpen();
        //static void showStatus(); //test function - does not work because it uses 'name' - a non-static member in a static function
    private:
        static int turn;
        static int lastServed;
        static bool nowOpen;
        char name;
};

int Server::turn = 0;
int Server::lastServed = 0;
bool Server::nowOpen = true;

int main() {
    Server s1('A'), s2('B');
    int number, count;
    do {
        std::cout << "How many in your group? ";
        std::cin >> number;
        std::cout << "Your turns are: ";
        for (size_t count = 0; count < number; ++count)
            std::cout << Server::getTurn() << ' ';
        std::cout << std::endl;
        s1.serveOne();
        //s1.showStatus(); - does not work
        s2.serveOne();
        //s2.showStatus(); - does not work
    } while(Server::stillOpen());

    std::cout << "Now closing service.\n";
}

Server::Server(char letterName) : name(letterName) {}
int Server::getTurn() { return ++turn; }
bool Server::stillOpen() { return nowOpen; }
void Server::serveOne() {
    if(nowOpen && lastServed < turn) 
        std::cout << "Server " << name << " now serving " << ++lastServed << std::endl;
    if(lastServed >= turn)
        nowOpen = false;
}

//Cannot use because name is non-static member in static function
// void Server::showStatus() {
//     std::cout << "\nCurrently serving " << turn << std::endl;
//     std::cout << "server name " << name << "\n" << std::endl;
// }