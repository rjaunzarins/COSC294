#include <iostream>

class DayOfYear {
    public:
        //Constructor with defaults
        DayOfYear(int month = 1, int day = 1);
        //Default Constructor
        //DayOfYear() = default;  
        void input();
        void output();
        int getMonthNumber();
        int getDay();
    private:
        int month;
        int day;
        void testDate();
};

int main() {
    DayOfYear date1(2, 21), date2(5), date3; //Note date3 has no ()
    std::cout << "Initialized dates:\n";
    std::cout << "Date 1: ";
    date1.output();
    std::cout << "Date 2: ";
    date2.output();
    std::cout << "Date 3: ";
    date3.output();

    date1 = DayOfYear(10, 31); //Call to DayOfYear::DayOfYear
    std::cout << "Date 1 revised: ";
    date1.output();
    date2 = DayOfYear(); //Note when calling constructor explicitly you do use ()
    std::cout << "Date 2 revised: ";
    date2.output();
}

//Do not do it this way!!
// DayOfYear::DayOfYear(int month, int day) {
//     this->month = month;
//     this->day = day;
// }

//Use this instead!
DayOfYear::DayOfYear(int month, int day) : month(month), day(day) {
    testDate();
}

//Not needed because 2 arg constructor has defaults
// DayOfYear::DayOfYear() : month(month), day(day) {
//     this->month = 1;
//     this->day = 1;
// }

void DayOfYear::testDate() {
    if((month < 1) || (month > 12)) {
        std::cout << "Illegal month value!\n";
        std::exit(1);
    }
    // else 
    //     this->month = month;
    
    if((day < 1) || (day > 31)) {
        std::cout << "Illegal day value!\n";
        std::exit(1);
    }
    // else 
    //     this->day = day;
}

void DayOfYear::input() {

    std::cout << "Enter a month number: ";
    std::cin >> month;
    std::cout << "Enter a day number: ";
    std::cin >> day;
    if((month < 1) || (month > 12) || (day < 1) || (day > 31)){
        std::cout << "Illegal date! Program aborted.\n";
        std::exit(1);
    }
}


void DayOfYear::output() {
    switch(month) {
        case 1:
            std::cout << "January "; break;
        case 2:
            std::cout << "February "; break;
        case 3:
            std::cout << "March "; break;
        case 4:
            std::cout << "April "; break;
        case 5:
            std::cout << "May "; break;
        case 6:
            std::cout << "June "; break;
        case 7:
            std::cout << "July "; break;
        case 8:
            std::cout << "August "; break;
        case 9:
            std::cout << "September "; break;
        case 10:
            std::cout << "October "; break;
        case 11:
            std::cout << "November "; break;
        case 12:
            std::cout << "December "; break;
        default:
            std::cout << "Error in DayOfYear::output.";
    }
    std::cout << ", " << day << std::endl;
}