#include <iostream>
#include <ctime>
#include <cstdlib>

int getAnswer();

int main(){

    int answer = getAnswer();

    std::cout << answer << std::endl;
    
    std::cout << __cplusplus;
}

int getAnswer() {
    //Use current time as seed for random generator
    srand(time(0));
    //Return random number
    //return rand()%2; // Gives random between 0 & 1
    //return rand()%2 +1 gives random between 1 & 2
    return rand()%10 + 10; // gives random number between 10 & 20
} 