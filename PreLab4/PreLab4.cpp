#include <iostream>
#include <string>

//CLASS DATE ------------------------------------------------
class Date {
    public:
        Date(int year = 2000, int month = 1, int day = 1);
        int getYear();
        int getMonth();
        int getDay();
        void printDate();
    private:
        int year;
        int month;
        int day;
        void validateDate();
};

//CLASS PERSON ------------------------------------------------
class Person {
    public:
        //CONSTRUCTOR
        Person(std::string firstName, std::string lastName, int year, int month, int day);
        //DEFAULT CONSTRUCTOR
        Person();
        std::string getFirstName();
        std::string getLastName();
        Date getBirthday();
        void printPerson();
    private:
        std::string firstName;
        std::string lastName;
        Date birthday;
};

//FUNCTION DECLARATIONS ----------------------------------------
void getDateInput(int& year, int& month, int& day);

void getNameInput(std::string& firstName, std::string& lastName);

int main() {
    int year, month, day;
    // Date date1;
    // date1.printDate();
    // getDateInput(year, month, day);
    // Date date2(year, month, day);
    // date2.printDate();

    //----Person----//
    std::string firstName;
    std::string lastName;
    getNameInput(firstName, lastName);
    getDateInput(year, month, day);
    Person p(firstName, lastName, year, month, day);
    p.printPerson();

    //std::cout << __cplusplus << std::endl;
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

int Date::getYear() {
    return year;
}

int Date::getMonth() {
    return month;
}

int Date::getDay() {
    return day;
}

void Date::printDate() {
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

//PERSON ------------------------------------------------
//PERSON - CONSTUCTOR
Person::Person(std::string firstName, std::string lastName, int year, int month, int day) : firstName(firstName), lastName(lastName), birthday(year, month, day) { }

//PERSON - DEFAULT CONSTUCTOR
Person::Person() : Person("blank", "blank", 1900, 01, 01) { } 

std::string Person::getFirstName() {
    return firstName;
}

std::string Person::getLastName() {
    return lastName;
}

Date Person::getBirthday() {
    return birthday;
}

void Person::printPerson() {
    std::cout << "Firstname: " << firstName << std::endl;
    std::cout << "Lastname: " << lastName << std::endl;
    std::cout << "Birthday: "; birthday.printDate(); std::cout << std::endl;
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

void getNameInput(std::string& firstName, std::string& lastName) {
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
}