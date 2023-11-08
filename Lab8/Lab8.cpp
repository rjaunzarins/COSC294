#include <iostream> 
#include <string>
#include <fstream>

class BankAccount {
    public:
        BankAccount(double amount = 0.00, std::string name = "Default");
        friend std::ostream& operator <<(std::ostream& outStream, const BankAccount& account);
        friend std::istream& operator >>(std::istream& outStream, BankAccount& account);
    private:
        double amount;
        std::string name;
};


int main() {

    //Create output objects
    BankAccount account1(100.00, "Name1");
    BankAccount account2(150.00, "Name2");
    std::ofstream outStream("labFile.txt");
    //Output objects and close file
    outStream << account1;
    outStream << account2;
    outStream.close();

    //Create input objects
    std::ifstream inStream("labFile.txt");
    BankAccount account3;
    BankAccount account4;
    //Input and display
    inStream >> account3;
    inStream >> account4;
    std::cout << account3;
    std::cout << account4;
    std::cin >> account4;

}

BankAccount::BankAccount(double amount, std::string name) : amount(amount), name(name) {}

// OVERLOADED << OPERATOR
std::ostream& operator <<(std::ostream& output, const BankAccount& account) {
    output << account.amount << " " << account.name << "\n"; 
    return output;
}

// OVERLOADED >> OPERATOR
std::istream& operator >>(std::istream& input, BankAccount& account) { 
    input >> account.amount;
    input >> account.name;
    return input;
}
