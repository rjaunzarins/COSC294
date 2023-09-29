#include <iostream>

class DayOfYear {
    public:
        //Constructor with defaults
        DayOfYear(int month = 1, int day = 1);
        //Default Constructor
        DayOfYear() = default;  
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

}

DayOfYear::DayOfYear(int month, int day) {
    this->month = month;
    this->day = day;
}

//DayOfYear::DayOfYear(int month, int day) : month(validateMonth(month)), day(day) {}

void DayOfYear::testDate() {
    if((month < 1) || (month > 12)) {
        std::cout << "Illegal month value!\n";
        exit(1);
    }
    if((day < 1) || (day > 31)){
        std::cout << "Illegal day value!\n";
        exit(1);
    }
}