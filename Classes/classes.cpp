#include <iostream>
#include <cstdlib>  //Used for exit(1)
class DayOfYear {
    public:
        void input();
        void output();
        void set(int newMonth, int newDay);
        //Precondition: newMonth and newDay form a possible date
        void set(int newMonth);
        //Precondition: 1 <= newMonth <= 12
        //Postcondition: The date is set to the first day of the given month
        int getMonthNumber();   // Returns 1 for Jan, 2 for Feb, etc
        int getDay();
    private:
        int month;
        int day;
};

int main() {

    DayOfYear today, bachBirthday;
    std::cout << "Enter todays date: " << std::endl;
    today.input();
    std::cout << "Todays date is ";
    today.output();
    std::cout << std::endl;

    bachBirthday.set(3, 21);
    std::cout << "J. S. Bach's birthday is ";
    bachBirthday.output();
    std::cout << std::endl;

    if(today.getMonthNumber() == bachBirthday.getMonthNumber() && today.getDay() == bachBirthday.getDay())
        std::cout << "Happy Birthday Johann Sebastian!\n";
    else   
        std::cout << "Happy Unbirthday Johann Sebastian!\n";

}

void DayOfYear::set(int newMonth, int newDay) {
    if((newMonth >= 1) && (newMonth <=12))
        month = newMonth;
    else {
        std::cout << "Illegal month value! Program aborted.\n";
        exit(1);
    }

    if((newDay >= 1) && (newDay <= 31))
        day = newDay;
    else {
        std::cout << "Illegal day value! Program aborted.\n";
        exit(1);
    }
}

void DayOfYear::set(int newMonth) {
    if((newMonth >=1) && (newMonth <= 12))
        month = newMonth;
    else {
        std::cout << "Illegal month value! Program aborted.\n";
        exit(1);
    }
    day = 1;
}

int DayOfYear::getMonthNumber() {
    return month;
}

int DayOfYear::getDay() {
    return day;
}

void DayOfYear::input() {
    std::cout << "Enter the month as a number: ";
    std::cin >> month;
    std::cout << "Enter the day of the month: ";
    std::cin >> day;
    if((month < 1) || (month > 12) || (day < 1) || (day > 31)) {
        std::cout << "Illegal date! Program aborted.\n";
        exit(1);
    }
}

void DayOfYear::output() {
    switch(month) {
        case 1:
            std::cout << "Jan "; break;
        case 2:
            std::cout << "Feb "; break;
        case 3:
            std::cout << "Mar "; break;
        case 4:
            std::cout << "Apr "; break;
        case 5:
            std::cout << "May "; break;
        case 6:
            std::cout << "Jun "; break;
        case 7:
            std::cout << "Jul "; break;
        case 8:
            std::cout << "Aug "; break;
        case 9:
            std::cout << "Sep "; break;
        case 10:
            std::cout << "Oct "; break;
        case 11:
            std::cout << "Nov "; break;
        case 12:
            std::cout << "Dec "; break;
        default:
            std::cout << "Error in DayOfYear::output.";
    }
}