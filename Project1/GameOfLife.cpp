//COSC2947 - Programming Project 1 - Conway's Game Of Life
//Due Date - Sept 30th 2023
//Author - Rhy Jaunzarins
//Student Number - 0404377

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

void getUserInput(int& gridRows, int& gridCols, int& simulations);
//Get the size of the grid and number of simulations from the user
//gridRows*gridCols must be greater than or equal to 20 and less than or equal to 50
//Number of simulations must be at least 5

void initializeBoard(int grid[][50], int gridRows, int gridCols);
//Initializes board at random - each element in grid is randomly assigned a value of 1 or 0
//Each element within board has 20% chance of being "alive" (1 being assigned), otherwise 0
//The initialized board will be the first generation

void printStateOfGame(const int grid[][50], int gridRows, int gridCols);
//Print the current state of the game
//Loop through grid and print the current state of the game to screen

void gameLoop(int grid[][50], int gridRows, int gridCols, int simulations);
//Runs the game loop
//Updates every 0.5 seconds (500 milliseconds) so generations are displayed over time
//gameLoop starts with generation 2 and will run simular-1 number of times

void checkGameStateAlive(int grid[][50], int gridRows, int gridCols);
//Checks to see if colony has completely died
//If colony has completely died, all elements are 0, end game early

void pauseGame(int waitMilliseconds);
//Pause game for waitMilliseconds amount of time
//Game is paused to delay each generation being printed to screen

void simGeneration(int grid[][50], int gridRows, int gridCols);
//Simulate a single generation
//Loop through a copy of grid to check all elements touch current element
//Based on surrounding elements, grid will be updated with next state of game

void compareGamestatesEqual(const int grid[][50], const int grid2[][50], int gridRows, int gridCols);
//Compare current gamestate with previous gamestate to see if they are equal
//If gamestate are equal, colony is in an unchangeable loop and program will terminate early

//Maximum size for rows and cols
constexpr int maxGridRows = 50, maxGridCols = 50;

int main() { 
    //Create grid with maxGridRows and maxGridCols
    int grid[maxGridRows][maxGridCols];

    //Declare variables for user input
    int gridRows, gridCols, simulations;            

    //Get user input and initialize board
    getUserInput(gridRows, gridCols, simulations);
    initializeBoard(grid, gridRows, gridCols);
    //Run game loop
    gameLoop(grid, gridRows, gridCols, simulations);
}


//Get the size of the grid and number of simulations from the user
void getUserInput(int& gridRows, int& gridCols, int& simular) {
    //Set flag to false
    bool valid = false;
    //While flag is not valid
    while(!valid) {  
        std::cout << "\nEnter the num of rows and columns (Grid must be >= 20 and <= 50): " << std::endl;
        std::cout << "Rows: ";
        //If input for gridRows is valid, assign to gridRows and continue
        if(std::cin >> gridRows) {
            //Ignore any garbage input after int for gridRows
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Columns: ";
            //If input for gridCols is valid, assign to gridCold and continue
            if(std::cin >> gridCols) {
                //Ignore any garbage input after int for gridCols
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                //If grid size is between 20 and 50, continue
                if(gridRows * gridCols >= 20 && gridRows*gridCols <= 50) {
                    std::cout << "Enter the number of simulations (Must be > 5): " << std::endl;
                    std::cout << "Simulations: ";
                    //If input for number of simulations is valid, assign to simulations and continue
                    if(std::cin >> simular) {
                        //Ignore any garbage input after int for simulations
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        //If number of simulations is greater than 5, continue
                        if(simular > 5)
                            valid = true;
                        //If number of simulations is less than 5, print err
                        else
                            std::cerr << "Invalid Simulation Count\n" << std::endl;
                    }
                    //Input for simulations was not valid input
                    else {   
                        std::cin.clear(); //Reset error flag
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Skip bad input
                        std::cerr << "Invalid Simulation Input\n" << std::endl;
                    }
                }
                //Grid size is less than 20 or greater than 50
                else {   
                    std::cin.clear(); //Reset error flag
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Skip bad input
                    std::cerr << "Grid Size Invalid\n" << std::endl;
                }
            }
            //Input for gridCols was not valid input
            else {
                std::cin.clear(); //Reset error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Skip bad input
                std::cerr << "Invalid Column Input\n" << std::endl;
            }
        }
        //Input for gridRows was not valid input
        else {
            std::cin.clear(); //Reset error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Skip bad input
            std::cerr << "Invalid Row Input\n" << std::endl;
        }
    }
    //Newline for formatting
    std::cout << std::endl;
}


//Initializes board at random
void initializeBoard(int grid[][50], int gridRows, int gridCols) {
    //Set seed - pass current time
    srand(time(0)); 
    //Iterate through each element passing 1(alive) 20% of the time, otherwise 0 (dead)
    for(int i = 0; i < gridRows; ++i) {
        for(int j = 0; j < gridCols; ++j){
            //Random number between 1 and 100
            int number = rand()%100 + 1;
            //If number is between 1 and 20 (20%) cell is alive
            if(number <= 20) {
                grid[i][j] = 1;
            }
            //If number is between 21 and 100 (80%) cell is not alive
            else {   
                grid[i][j] = 0;
            }
        }
    }
    //Display header for first generation
    std::cout << "\nCurrent Generation: 1" << std::endl;
    //Print initialized state of game
    printStateOfGame(grid, gridRows, gridCols);
}


//Print the current state of the game
void printStateOfGame(const int grid[][50], int gridRows, int gridCols) {
    //Draw horizontal line at top of gamestate
    for(int i = 0; i < gridCols; ++i) {
        std::cout << "----";
    }
    std::cout << "-" << std::endl;

    //Print Gamestate
    for(int i = 0; i < gridRows; ++i) {
        for(int j = 0; j < gridCols; ++j) {            
            if(grid[i][j] == 1)
                if(j == gridCols - 1)
                    std::cout << "| * |" << std::endl;
                else
                    std::cout << "| * ";
            else   
                if(j == gridCols - 1)
                    std::cout << "|   |" << std::endl;
                else
                    std::cout << "|   ";
        }
        //Draw horizontal lines for each row
        for(int i = 0; i < gridCols; ++i) {
            std::cout << "----";
        }
        std::cout << "-" << std::endl;
    }
    //Newline for formatting
    std::cout << std::endl;
}


//Runs the game loop
void gameLoop(int grid[][50], int gridRows, int gridCols, int simulations) {
    //Set generation at current generation
    int currentGeneration = 1;
    //Set the amount of time to pause game each loop
    const int waitMilliseconds = 350;
    //Game Loop - run for specified number of simulations
    while(currentGeneration < simulations) {
        //Check to see if colony has died off
        checkGameStateAlive(grid, gridRows, gridCols);
        //Pause for set amount of time (350ms)
        pauseGame(waitMilliseconds);
        //Simulate generation
        simGeneration(grid, gridRows, gridCols);
        //Iterate generation before number is printed to screen
        ++currentGeneration;
        //Print current generation header and state of game
        std::cout << "Current Generation: " << currentGeneration << std::endl;
        printStateOfGame(grid, gridRows, gridCols);
    }
}


//Check to see if colony has completely died off
void checkGameStateAlive(int grid[][50], int gridRows, int gridCols) {
    //Number of elements with life
    int lifeCount = 0;
    //Loop through grid to check for alive elements
    for(int i = 0; i < gridRows; ++i) {
        for(int j = 0; j < gridCols; ++j) {
            //If element is 1 (alive), increment lifeCount
            if(grid[i][j] == 1)
                ++lifeCount;
        }
    }
    //If lifeCount is zero after searching entire array, there are no elements alive -> exit
    if(lifeCount == 0) {
        std::cout << "Your colony has died. Game over\n" << std::endl;
        std::exit(0);
    }
}


//Pause game for waitMilliseconds amount of time
void pauseGame(int waitMilliseconds) {
    //Sleep for waitMilliseconds so all generations are not instantaneously displayed
    std::chrono::milliseconds dura(waitMilliseconds);
    std::this_thread::sleep_for(dura);
}


//Simulate a single generation
void simGeneration(int grid[][50], int gridRows, int gridCols) {
    //Create second board so changes can be made on first without changing result
    int grid2[maxGridRows][maxGridCols];  
    //Copy grid to grid2 so we can search through grid2 and update grid
    for(int i = 0; i < gridRows; ++i) {
        for(int j = 0; j < gridCols; ++j) {
            grid2[i][j] = grid[i][j];
        }
    }
    //Iterate through grid2 to search for alive neighbors
    for(int i = 0; i < gridRows; ++i) {
        for(int j = 0; j < gridCols; ++j) {
            //Declare count of neighbors for grid2[i][j]
            int count = 0; 
            //Count alive neighbors around grid2[i][j]
            for(int k = i-1; k <= i+1; ++k) {
                for(int l = j-1; l <= j+1; ++l) {
                    //If valid element in grid2 and not grid2[i][j], continue
                    if(k >= 0 && k < gridRows && l >= 0 && l < gridCols && !(k == i && l == j)){
                        //If valid element is equal to 1, increase count by 1
                        if(grid2[k][l] == 1) {
                            ++count;
                        }
                    }
                }
            }
            //Execute change to grid based on neighbor count of grid2
            //If Current Cell Alive  
            if(grid2[i][j] == 1) { 
                //If neighbor count is != 2 || !=3 --> cell becomes dead
                if(count != 2 && count != 3) {
                    //Cell dies
                    grid[i][j] = 0;
                }
            }
            //If Current Cell Dead  
            else { 
                //if neighbor count = 3 --> cell becomes alive
                if(count == 3) {
                    //Cell becomes alive
                    grid[i][j] = 1;
                }
            } 
        } 
    }
    //Compare gamestates - grid and grid2 - if equal, gamestate will not change again
    compareGamestatesEqual(grid, grid2, gridRows, gridCols);
}


//Checks to see if current generation is the same as previous generation
void compareGamestatesEqual(const int grid[][50], const int grid2[][50], int gridRows, int gridCols) {
    //Flag to determine if states of game are equal
    bool equal = true;
    //Loop through both states to check if they are not equal
    for(int i = 0; i < gridRows; ++i) {
        for(int j = 0; j < gridCols; ++j) {
            //If any element in grid is not equal to grid2 they are not equal
            if(grid[i][j] != grid2[i][j])
                equal = false;
        }
    }
    //If states are equal, game will not change state again > print state of game and exit
    if(equal == true) {
        std::cout << "Your colony has reached equilibrium and will not change state again\n" << std::endl;
        std::cout << "Final state of the game: " << std::endl;
        //Print updated state of game that is equal to previous state
        printStateOfGame(grid, gridRows, gridCols);
        std::exit(1); 
    }
}