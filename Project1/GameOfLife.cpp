//COSC2947 - Programming Project 1 - Conway's Game Of Life
//Due Date - Sept 30th 2023
//Authors - Rhy Jaunzarins - 0404377, Kaylee Joyce - 0383068

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

/*
Retrieve user input to set size of grid and number of simulations.
Precondition: Grid dimension values must be numeric values, where 20 <= x <= 50.
Number of steps must be >5
Param gridRows: Number of rows  of game board
Param gridCols: Number of columns of game board
Param simulations: Number of simulations
Postcondition: The number of rows, columns, and simulation values are set.
*/
void getUserInput(int& gridRows, int& gridCols, int& simulations);

/*
Initialize the board at random, where each element is assigned true or false.
Precondition: Board dimensions values must have been previously set by getUserInput()
Param grid: 2D bool array
Param gridRows: Number of rows of game board
Param gridColsL Number of columns of game board
Postcondition: The board is initialized with first simulation and printed to screen.
*/
void initializeBoard(bool grid[][50], int gridRows, int gridCols);

/*
Print the current state of the game.
Precondition: Grid dimensions and grid must have been set by getUserParams() and initializeBoard().
Param grid: 2D bool array, which cannot be modified by the function
Param gridRows: Number of rows of game board
Param gridCols: Number of columns of game board
Postcondition: Current state of all cells is printed to screen.
*/
void printStateOfGame(const bool grid[][50], int gridRows, int gridCols);

/*
Checks gamestate, simulates generation and prints current generation to screen.
Precondition: simulations must be set by getUserInput().
Param grid: 2D bool array
Param gridRows: Number of rows of game board
Param gridCols: Number of columns of game board
Param simulations: Number of simulations
Postcondition: Prints current state of game to screen. If all cells are dead game is terminated. 
If gamestate is equal to previous gamestate, game is terminated.
*/
void gameLoop(bool grid[][50], int gridRows, int gridCols, int simulations);

/*
Checks if all elements in board are alive. If all elements are dead, terminate game.
Precondition: Game must be initialized.
Param grid: 2D bool array
Param gridRows: Number of rows of game board
Param gridCols: Number of columns of game board
Postcondition: If all elements are dead, terminate game and print reason to screen.
*/
bool checkGameStateAlive(bool grid[][50], int gridRows, int gridCols);

/*
Pauses game for a specified number of milliseconds, for user experience.
Precondition: Game must be initialized and gameLoop() running.
Param milliSeconds: Number of milliseconds
Postcondition: Game paused for specified number of milliseconds.
*/
void pauseGame(int waitMilliseconds);

/*
Simulate a single generation, computing the life and/or death of all cells.
Precondition: Board initialization must have been completed by initializeBoard()
Param grid: 2D bool array
Param gridRows: Number of rows of game board
Param gridCols: Number of columns of game board
Postcondition: A single generation has been simulated.
*/
bool simGeneration(bool grid[][50], int gridRows, int gridCols);

/*
Compares current generation to previous generation, if states are equal 
(meaning in an unchangable loop), terminate game.
Precondition: At least two generations must have been simulated.
Param grid: 2D bool array
Param grid2: 2D bool array
Param gridRows: Number of rows of game board
Param gridCols: Number of columns of game board
Postcondition: If gamestates are equal, terminate game.
*/
bool compareGamestatesEqual(const bool grid[][50], const bool grid2[][50], int gridRows, int gridCols);

/*
Prompts user to play again.
Precondition: At least 1 game must have been played.
Postcondition: Triggers new game if user answers 'y', otherwise terminates game.
*/
bool playAgain();

//Maximum size for rows and cols
constexpr int maxGridRows = 50, maxGridCols = 50;

int main() { 
    bool again = true;
    while(again) {
        //Create grid with maxGridRows and maxGridCols
        bool grid[maxGridRows][maxGridCols];
        //Declare variables for user input
        int gridRows, gridCols, simulations;            
        //Get user input and initialize board
        getUserInput(gridRows, gridCols, simulations);
        initializeBoard(grid, gridRows, gridCols);
        //Run game loop
        gameLoop(grid, gridRows, gridCols, simulations);
        again = playAgain();
    }
}


//Get the size of the grid and number of simulations from the user
void getUserInput(int& gridRows, int& gridCols, int& simulations) {
    //Set flag to false
    bool valid = false;
    //While flag is not valid
    while(!valid) {  
        std::cout << "\nEnter the num of rows and columns to make game board\n" 
                  << "(Rows * columns must be >= 20 and <= 50) " << std::endl;
        std::cout << "Rows: ";
        //If input for gridRows is valid, assign to gridRows and if gridRows > 0, continue
        if((std::cin >> gridRows) && (gridRows > 0)) {
            //Ignore any garbage input after int for gridRows
            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Columns: ";
            //If input for gridCols is valid, assign to gridCold and gridCols > 0, continue
            if((std::cin >> gridCols) && (gridCols > 0)) {
                //Ignore any garbage input after int for gridCols
                //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                //If grid size is between 20 and 50, continue
                if((gridRows * gridCols >= 20) && (gridRows*gridCols <= 50)) {
                    std::cout << "Enter the number of simulations (Must be > 5): " << std::endl;
                    std::cout << "Simulations: ";
                    //If input for number of simulations is valid, assign to simulations and continue
                    if(std::cin >> simulations) {
                        //Ignore any garbage input after int for simulations
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        //If number of simulations is greater than 5, continue
                        if(simulations > 5)
                            valid = true;
                        //If number of simulations is less than 5, print err
                        else
                            std::cerr << "Invalid Simulation Count.\n" << std::endl;
                    }
                    //Input for simulations was not valid input, reset error flag and skip bad input
                    else {   
                        std::cin.clear(); 
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cerr << "Invalid Simulation Input.\n" << std::endl;
                    }
                }
                //Grid size is less than 20 or greater than 50, reset error flag and skip bad input
                else {   
                    std::cin.clear(); 
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                    std::cerr << "Grid Size Invalid.\n" << std::endl;
                }
            }
            //Input for gridCols was not valid input, reset error flag and skip bad input
            else {
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                std::cerr << "Invalid Column Input.\n" << std::endl;
            }
        }
        //Input for gridRows was not valid input, reset error flag and skip bad input
        else {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cerr << "Invalid Row Input.\n" << std::endl;
        }
    }
    std::cout << std::endl;
}


//Uses <cstdlib>, <ctime> - Initializes board at random
void initializeBoard(bool grid[][50], int gridRows, int gridCols) {
    //Set seed - pass current time
    srand(time(0)); 
    //Iterate through each element passing 1(alive) 20% of the time, otherwise 0 (dead)
    for(int i = 0; i < gridRows; ++i) {
        for(int j = 0; j < gridCols; ++j){
            //Random number between 1 and 100
            int number = rand()%100 + 1;
            //If number is between 1 and 20 (20%) cell is alive
            if(number <= 20) 
                grid[i][j] = true;
            //If number is between 21 and 100 (80%) cell is not alive
            else 
                grid[i][j] = false;
        }
    }
    //Display header for first generation
    std::cout << "\nCurrent Generation: 1" << std::endl;
    //Print initialized state of game
    printStateOfGame(grid, gridRows, gridCols);
}


//Print the current state of the game
void printStateOfGame(const bool grid[][50], int gridRows, int gridCols) {
    //Draw horizontal line at top of gamestate
    for(int i = 0; i < gridCols; ++i) 
        std::cout << "----";
    std::cout << "-" << std::endl;
    //Print Gamestate
    for(int i = 0; i < gridRows; ++i) {
        for(int j = 0; j < gridCols; ++j) {            
            if(grid[i][j])
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
        for(int i = 0; i < gridCols; ++i) 
            std::cout << "----";
        std::cout << "-" << std::endl;
    }
    //Newline for formatting
    std::cout << std::endl;
}


//Runs the game loop
void gameLoop(bool grid[][50], int gridRows, int gridCols, int simulations) {
    //Set generation at current generation
    int currentGeneration = 1;
    //Set the amount of time to pause game each loop
    const int waitMilliseconds = 350;
    //Game Loop - run for specified number of simulations
    while(currentGeneration < simulations) {
        //Check to see if colony has died off
        if(!checkGameStateAlive(grid, gridRows, gridCols))
            return;
        //Pause for set amount of time (350ms)
        pauseGame(waitMilliseconds);
        //Simulate generation
        if(!simGeneration(grid, gridRows, gridCols))
            return;
        //Iterate generation before number is printed to screen
        ++currentGeneration;
        //Print current generation header and state of game
        std::cout << "Current Generation: " << currentGeneration << std::endl;
        printStateOfGame(grid, gridRows, gridCols);
    }
}


//Uses <cstdlib> - Check to see if colony has completely died off
bool checkGameStateAlive(bool grid[][50], int gridRows, int gridCols) {
    //Number of elements with life
    int lifeCount = 0;
    //Loop through grid to check for alive elements
    for(int i = 0; i < gridRows; ++i) {
        for(int j = 0; j < gridCols; ++j) {
            //If element is 1 (alive), increment lifeCount
            if(grid[i][j])
                ++lifeCount;
        }
    }
    //If lifeCount is zero after searching entire array, there are no elements alive -> exit
    if(lifeCount == 0) {
        std::cout << "Your colony has died. Game over.\n" << std::endl;
        return false;
    }
    return true;
}


//Uses <chrono>, <thread> - Pause game for waitMilliseconds amount of time
void pauseGame(int waitMilliseconds) {
    //If waitMilliseconds is valid time
    if(waitMilliseconds > 0) {
        //Sleep for waitMilliseconds so all generations are not instantaneously displayed
        std::chrono::milliseconds dura(waitMilliseconds);
        std::this_thread::sleep_for(dura);
    }
}


//Simulate a single generation
bool simGeneration(bool grid[][50], int gridRows, int gridCols) {
    //Create second board so changes can be made on first without changing result
    bool grid2[maxGridRows][maxGridCols];  
    //Copy grid to grid2 so we can search through grid2 and update grid
    for(int i = 0; i < gridRows; ++i) {
        for(int j = 0; j < gridCols; ++j) 
            grid2[i][j] = grid[i][j];
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
                        if(grid2[k][l]) 
                            ++count;
                    }
                }
            }
            //Execute change to grid based on neighbor count of grid2
            //If Current Cell Alive  
            if(grid2[i][j]) { 
                //If neighbor count is != 2 || !=3 --> cell becomes dead
                if(count != 2 && count != 3)
                    //Cell dies
                    grid[i][j] = false;
            }
            //If Current Cell Dead  
            else { 
                //if neighbor count = 3 --> cell becomes alive
                if(count == 3)
                    //Cell becomes alive
                    grid[i][j] = true;
            } 
        } 
    }
    //Compare gamestates - grid and grid2 - if equal, gamestate will not change again
    if(compareGamestatesEqual(grid, grid2, gridRows, gridCols))
        return false;
    return true;
}


//Uses <cstdlib> - Checks to see if current generation is the same as previous generation
bool compareGamestatesEqual(const bool grid[][50], const bool grid2[][50], int gridRows, int gridCols) {
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
        std::cout << "Your colony has reached equilibrium and will not change state again.\n" << std::endl;
        std::cout << "Final state of the game: " << std::endl;
        //Print updated state of game that is equal to previous state
        printStateOfGame(grid, gridRows, gridCols);
        return true;
    }
    return false;
}


//Ask if user wants to play again
bool playAgain() {
    char again;
    std::cout << "Play again?: ";
    std::cin >> again;
    if(again == 'y' || again == 'Y') {
        return true;
    }
    return false;
}