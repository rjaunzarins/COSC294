/*
Programming Project 1 - Conway's Game of Life

This program simulates Conway's Game of Life. It relies on user input to simulate gameplay of how a colony
lives and dies over a specified number of generations.

Authors: Rhy Jaunzarins - 0404377, Kaylee Joyce - 0383068
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

/*
Retrieve user input to set size of grid and number of simulations.
Precondition: Grid dimension values must be numeric values, where 20 <= x <= 50.
Number of steps must be >5
Param int&: Number of rows of game board
Param int&: Number of columns of game board
Param int&: Number of simulations
Postcondition: The number of rows, columns, and simulation values are set.
*/
void getUserInput(int&, int&, int&);

/*
Initialize the board at random, where each element has a 20% chance of being alive (true).
Precondition: Board dimensions values must have been previously set by getUserInput()
Param bool [][]: 2D bool array
Param int: Number of rows of game board
Param int: Number of columns of game board
Postcondition: The board is initialized with the first simulation and printed to screen.
*/
void initializeBoard(bool [][50], int, int);

/*
Print the current state of the game.
Precondition: initializeBoard() must have successfully executed.
Param const bool [][]: 2D bool array, which cannot be modified by the function
Param int: Number of rows of game board
Param int: Number of columns of game board
Postcondition: Current state of all cells is printed to screen.
*/
void printStateOfGame(const bool [][50], int, int);

/*
Checks gamestate, simulates generation, and prints gamestate to screen.
Precondition: initializeBoard() must have successfully executed.
Param bool [][]: 2D bool array
Param int: Number of rows of game board
Param int: Number of columns of game board
Param int: Number of simulations
Postcondition: Prints current state of game to screen. If all cells are dead, or current
gamestate is equal to previous gamestate, game is ended. 
*/
void gameLoop(bool [][50], int, int, int);

/*
Checks if any elements on board are alive. If all elements are dead, ends current game.
Precondition: Game must be initialized.
Param bool [][]: 2D bool array
Param int: Number of rows of game board
Param int: Number of columns of game board
Return: Returns wheteher or not any elements are alive.
*/
bool checkGameStateAlive(bool [][50], int, int);

/*
Pauses game for a specified number of milliseconds, for user experience.
Precondition: Game must be initialized and gameLoop() running.
Postcondition: Game paused for specified number of milliseconds.
*/
void pauseGame();

/*
Simulate a single generation, computing the life and/or death of all cells.
Precondition: Board initialization must have been completed by initializeBoard()
Param bool [][]: 2D bool array
Param int: Number of rows of game board
Param int: Number of columns of game board
Return: Return validity of whether gamestate is valid.
*/
bool simGeneration(bool [][50], int, int);

/*
Compares current generation to previous generation. If states are equal 
(meaning in an unchangable loop), returns true.
Precondition: At least two generations must have been simulated.
Param const bool [][]: 2D bool array - current gamestate
Param const bool [][]: 2D bool array - previous gamestate
Param int: Number of rows of game board
Param int: Number of columns of game board
Return: Returns validity of equal gamestates.
*/
bool checkGamestatesEqual(const bool [][50], const bool [][50], int, int);

/*
Prompts user to play again once a game has ended.
Precondition: At least 1 game must have been played.
Return: Returns true if user chooses to play again.
*/
bool playAgain();


constexpr int maxGridRows = 50, maxGridCols = 50;                                                           //Maximum size for rows and cols
const int pauseMilliseconds = 350;                                                                          //Global for visibility - Amount of milliseconds to pause game loop


int main() { 
    do {
        bool grid[maxGridRows][maxGridCols];                                                                //Create grid with maxGridRows and maxGridCols
        int gridRows, gridCols, simulations;                                                                //Declare variables for user input
        getUserInput(gridRows, gridCols, simulations);                                                      //Get user input
        initializeBoard(grid, gridRows, gridCols);                                                          //Initialize board
        gameLoop(grid, gridRows, gridCols, simulations);                                                    //Run game loop
    } while(playAgain());                                                                                   //Run while playAgain() returns true
}


void getUserInput(int& gridRows, int& gridCols, int& simulations) {                                         //Get size of grid and number of simulations from user
    bool inputValid = false;
    while(!inputValid) {  
        std::cout << "\nEnter the num of rows and columns to make game board\n" 
                  << "(Rows * columns must be >= 20 and <= 50) " << std::endl;
        std::cout << "Rows: ";
        if((std::cin >> gridRows) && (gridRows > 0)) {                                                      //If gridRows input valid
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');                             //Ignore any garbage input after int for gridRows
            std::cout << "Columns: ";
            if((std::cin >> gridCols) && (gridCols > 0)) {                                                  //If gridCols input is valid
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if((gridRows * gridCols >= 20) && (gridRows*gridCols <= 50)) {                              //If grid size is between 20 and 50, continue
                    std::cout << "Enter the number of simulations (Must be > 5): " << std::endl;
                    std::cout << "Simulations: ";
                    if((std::cin >> simulations) && (simulations > 5)) {                                    //If simulation input is vaid 
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        inputValid = true;
                    }
                    else {                                                                                  //If simulations input not valid, reset error flag & skip bad input
                        std::cin.clear(); 
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cerr << "Invalid Simulation Input." << std::endl;
                    }
                }
                else                                                                                        //If row * col is invalid         
                    std::cout << "\nRows * columns is not >= 20 and <= 50." << std::endl;               
            }
            else {                                                                                          //If gridCols input not valid, reset error flag & skip bad input
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                std::cerr << "\nInvalid Column Input." << std::endl;
            }
        }
        else {                                                                                              //If gridRows input not valid, reset error flag & skip bad input
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cerr << "\nInvalid Row Input." << std::endl;
        }
    }
    std::cout << std::endl;
}


void initializeBoard(bool grid[][50], int gridRows, int gridCols) {                                         //Uses <cstdlib>, <ctime>
    srand(time(0));                                                                                         //Set seed - pass current time
    for(int i = 0; i < gridRows; ++i) {                                                                     //Iterate through grid
        for(int j = 0; j < gridCols; ++j){
            int chanceOfLife = rand()%100 + 1;                                                              //Assign number, 1-100
            if(chanceOfLife <= 20)                                                                          //If number between 1 and 20 (20%), cell is alive
                grid[i][j] = true;
            else                                                                                            //If number between 21 and 100 (80%), cell is not alive
                grid[i][j] = false;
        }
    }
    std::cout << "\nCurrent Generation: 1" << std::endl;                                                    //Display header for first generation
    printStateOfGame(grid, gridRows, gridCols);                                                             //Print initialized state of game
}


void printStateOfGame(const bool grid[][50], int gridRows, int gridCols) {                              
    for(int i = 0; i < gridCols; ++i)                                                                       //Draw horizontal line at top of gamestate
        std::cout << "----";
    std::cout << "-" << std::endl;
    for(int i = 0; i < gridRows; ++i) {                                                                     //Print gamestate
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
        for(int i = 0; i < gridCols; ++i)                                                                   //Draw horizontal lines for each row
            std::cout << "----";
        std::cout << "-" << std::endl;
    }
    std::cout << std::endl;
}


void gameLoop(bool grid[][50], int gridRows, int gridCols, int simulations) {
    int currentGeneration = 1;                                                                              //Set generation at current generation
    while(currentGeneration < simulations) {                                                                //Run for specified number of simulations                                                                                   
        pauseGame();                                                                                        //Pause game for user experience/output aesthetics
        if(!simGeneration(grid, gridRows, gridCols))                                                        //If simGeneration returns false
            return;
        ++currentGeneration;                                                                                //Iterate generation before number is printed to screen
        std::cout << "Current Generation: " << currentGeneration << std::endl;                              //Print current generation header and state of game
        printStateOfGame(grid, gridRows, gridCols);
    }
}


bool checkGameStateAlive(bool grid[][50], int gridRows, int gridCols) {                                     //Uses <cstdlib>
    int lifeCount = 0;                                                                                      //Number of elements with life
    for(int i = 0; i < gridRows; ++i) {                                                                     //Loop through grid to check for live elements
        for(int j = 0; j < gridCols; ++j) {
            if(grid[i][j])                                                                                  //If element is 1 (alive), increment lifeCount
                ++lifeCount;
        }
    }
    if(lifeCount == 0) {                                                                                    //If lifeCount is 0 after search, colony extinct
        std::cout << "Your colony has died. Game over.\n" << std::endl;
        return false;
    }
    return true;                                                                                            //Colony still alive
}


void pauseGame() {                                                                                          //Uses <chrono>, <thread>
    if(pauseMilliseconds > 0) {                                                                             //If pauseMilliseconds is valid time
        std::chrono::milliseconds dura(pauseMilliseconds);                                                  //Sleep so all generations are not instantaneously displayed
        std::this_thread::sleep_for(dura);
    }
}


bool simGeneration(bool grid[][50], int gridRows, int gridCols) {                                           //Simulate a single generation
    if(!checkGameStateAlive(grid, gridRows, gridCols))                                                      //If colony has died off
        return false;
    bool grid2[maxGridRows][maxGridCols];                                                                   //Create second board so changes can be made on first without changing result
    for(int i = 0; i < gridRows; ++i) {                                                                     //Copy grid to grid2
        for(int j = 0; j < gridCols; ++j) 
            grid2[i][j] = grid[i][j];
    }
    for(int i = 0; i < gridRows; ++i) {                                                                     //Iterate through grid2 to search for live neighbors
        for(int j = 0; j < gridCols; ++j) {
            int liveNeighbours = 0;                                                                         //Declare count of neighbors for grid2[i][j]
            for(int k = i-1; k <= i+1; ++k) {                                                               //Count live neighbors around grid2[i][j]
                for(int l = j-1; l <= j+1; ++l) {
                    if(k >= 0 && k < gridRows && l >= 0 && l < gridCols && !(k == i && l == j)){            //If valid element in grid2 and not grid[i][j]
                        if(grid2[k][l])                                                                     //If valid element is true, increment liveNeighbours
                            ++liveNeighbours;
                    }
                }
            }
            if(grid2[i][j]) {                                                                               //If current cell alive  
                if(liveNeighbours != 2 && liveNeighbours != 3)                                              //If liveNeighbours is != 2 || !=3
                    grid[i][j] = false;                                                                     //Cell dies
            }  
            else {                                                                                          //If current cell dead
                if(liveNeighbours == 3)                                                                              //if liveNeighbours = 3
                    grid[i][j] = true;                                                                      //Cell becomes alive
            } 
        } 
    }
    if(checkGamestatesEqual(grid, grid2, gridRows, gridCols))                                               //Compare gamestates - grid and grid2
        return false;                                                                                       //If equal, gamestate will never change
    return true;                                                                                            //Conditions valid for next simulation
}


bool checkGamestatesEqual(const bool grid[][50], const bool grid2[][50], int gridRows, int gridCols) {      //Uses <cstdlib>
    bool gamestateEqual = true;
    for(int i = 0; i < gridRows; ++i) {                                                                     //Loop through both states to check if they are not equal
        for(int j = 0; j < gridCols; ++j) {
            if(grid[i][j] != grid2[i][j])                                                                   //If any element in grid is not equal to grid2 they are not equal
                gamestateEqual = false;
        }
    }
    if(gamestateEqual) {                                                                                    //If states are equal, game will never change state > print state of game and exit
        std::cout << "Your colony has reached equilibrium and will not change state again.\n" << std::endl;
        std::cout << "Final state of the game: " << std::endl;
        printStateOfGame(grid, gridRows, gridCols);                                                         //Print updated state of game that is equal to previous state
        return true;                                                                                        //Gamestates are equal
    }
    return false;                                                                                           //Gamestates are not equal
}


bool playAgain() {
    char playChoice;
    std::cout << "Play again?: ";
    std::cin >> playChoice;
    if(playChoice == 'y' || playChoice == 'Y') {
        return true;                                                                                        //User wants to play again
    }
    return false;                                                                                           //User does not want to play again
}