#include <iostream>

//CLASS DATE ------------------------------------------------
class Date {
    public:
        Date(int year = 2000, int month = 1, int day = 1);
        int getYear() const;
        int getMonth() const;
        int getDay() const;
        void printDate()const;
    private:
        int year;
        int month;
        int day;
        void validateDate();
};


//FUNCTION DECLARATIONS ----------------------------------------
void getDateInput(int& year, int& month, int& day);

//Const
void testFunctionConst(const Date &date);
//Non-Const
void testFunctionNonConst(Date &date);


int main() {
    //Creating const object using constructor
    const Date d1(1900,1,1);
    //Using const accessors
    d1.getDay(); d1.getMonth(); d1.getDay(); d1.printDate();
    //Creating non-const object
    Date d2(2000,2,2);
    //using const accessors
    d2.getDay(); d2.getMonth(); d2.getDay(); d2.printDate();
    //Using testFunctionConst by passing the creation of a Date with literals
    testFunctionConst(Date{1999,9,9});
    //Using testFunctionNonConst by passing the creation of a Date with literals
    //testFunctionNonConst(Date{1999,10,10}); //Literals cannot be passed by non-const reference
}


//DATE -------------------------------------------------
Date::Date(int year, int month, int day) : year(year), month(month), day(day) {
    validateDate();
}

void Date::validateDate() {
    //If year is valid
    if(year >= 1000 && year <= 3000) {
        //If month is valid
        if(month >= 1 && month <= 12) {
            //If month is Feb
            if(month == 2) {
                //And if year is divisible by 4
                if(year % 4 == 0) {
                    //And year is divisible by 100 - Not leap year
                    if(year % 100 == 0) {
                        //Unless it is divisible by 400 - Leap year
                        if(year % 400 == 0) {
                            if(day < 1 || day > 29) {
                                std::cout << "Invalid day, leap year" << std::endl;
                                std::exit(1);
                            }
                        }
                        //Divisible by 100 but not 400 - not leap year
                        else {
                            if(day < 1 || day > 28) {
                            std::cout << "Invalid day, not leap year" << std::endl;
                            std::exit(1);
                            }
                        }
                    }
                    //Not divisible by 100
                    else {
                        if(day < 1 || day > 29) {
                            std::cout << "Invalid day, leap year" << std::endl;
                            std::exit(1);
                        }
                    }
                }
                //Not divisible by 4
                else {
                    if(day < 1 || day > 28) {
                        std::cout << "Invalid day, not leap year" << std::endl;
                        std::exit(1);
                    }
                }
            }
            //Month is Apr, Jun, Sept, Nov
            else if(month == 4 || month == 6 || month == 9 || month == 11) {
                if(day < 1 || day > 30){
                    std::cout << "Invalid day" << std::endl;
                    std::exit(1);
                }
            }
            //Month is Jan, Mar, May, Jul, Aug, Oct, Dec
            else {
                if(day < 1 || day > 31) {
                    std::cout << "Invalid Day" << std::endl;
                    std::exit(1);
                }   
            }
        }
        //Month is not valid
        else {
            std::cout << "Invalid Month" << std::endl;
            std::exit(1);
        }
    }
    //Year is not valid
    else {
        std::cout << "Invalid Year" << std::endl;
        std::exit(1);
    }
}

int Date::getYear() const{
    return year;
}

int Date::getMonth() const{
    return month;
}

int Date::getDay() const{
    return day;
}

void Date::printDate() const{
    if(month > 10) {
        if(day > 10) {
            std::cout << year << "-" << month << "-" << day << std::endl;
        }
        else {
            std::cout << year << "-" << month << "-0" << day << std::endl;
        }   
    }
    else {
        if(day > 10) {
            std::cout << year << "-0" << month << "-" << day << std::endl;
        }
        else {
            std::cout << year << "-0" << month << "-0" << day << std::endl;
        }
    }
}

//FUNCTIONS ------------------------------------------------
void getDateInput(int& year, int& month, int& day){
    bool inputInvalid = true;
    while(inputInvalid) {    
        std::cout << "Enter year: ";
        if(std::cin >> year) {
            std::cout << "Enter month: ";
            if(std::cin >> month) {
                std::cout << "Enter day: ";
                if(std::cin >> day) {
                    inputInvalid = false;
                }
                else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid day input" << std::endl;
                }
            }
            else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid month input" << std::endl;
            }
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid year input" << std::endl;
        }
    }
}

void testFunctionConst(const Date &date) {
    std::cout << "Const Date Reference" << std::endl;
    date.printDate();
}

void testFunctionNonConst(Date &date) {
    std::cout << "Non-Const Date Reference" << std::endl;
    date.printDate();
}