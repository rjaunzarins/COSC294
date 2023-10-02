#include <iostream>

struct CDAccountV1 {
    double balance;
    double interestRate;
    int term;
};  // MAKE SURE TO ADD SEMICOLON AFTER DEFINING STRUCT

//Can make structs that will be members of other structs
struct Date {
    int month;
    int day;
    int year;
};

//birthday is a Date struct member of PersonInfo
struct PersonInfo {
    double height;
    int weight;
    Date birthday;
};

void getData(CDAccountV1& account);

int main() { 

    ////////////////////////
    //CDAccountV1 struct
    ////////////////////////
    CDAccountV1 account;
    getData(account);

    //Structs of same type can equal each other
    CDAccountV1 account2;
    account2 = account;

    //Can also define struct literally - values go in order they are defined in struct
    // ex. balance, interestRate, term
    CDAccountV1 account3 = {1000.0, 0.10, 24};

    double rateFraction, interest;
    rateFraction = account.interestRate/100;
    interest = account.balance * (rateFraction * (account.term / 12.0));
    account.balance = account.balance + interest;

    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);

    std::cout << "When your CD matures in " << account.term << " months,\n"
              << "it will have a balance of $" << account.balance << std::endl;
    
    /////////////////////////
    //PersonInfo Struct
    /////////////////////////
    PersonInfo person1;
    person1.height = 77;
    person1.weight = 150;
    //can pass all values to birthday member (date struct)
    person1.birthday = {12,12,86};
    //can also modify them individually
    person1.birthday.day = 15;
}

//Pass struct by reference to make changes to actual struct object created in main
void getData(CDAccountV1& account) {
    std::cout << "Enter account balance: $";
    std::cin >> account.balance;
    std::cout << "Enter account interest rate: ";
    std::cin >> account.interestRate;
    std::cout << "Enter the number of months until maturity: ";
    std::cin >> account.term;
}