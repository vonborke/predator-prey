/*******************************************************************************
** Program Name: Predator Prey Game
** Author: Kelly von Borstel
** Date: 2/17/2018
** Description: This is the implementation file for the simulation class, which
** contains all data and functions need to run the Predator Prey game. To use 
** it, create a simulation object in main. When the simulation runs, it will
** get the user input, create and populate the board, and start the game. For
** each game step, doodlebugs and ants will move, doodlebugs will eat ants if
** available, all critters will breed when they're the right age, and doodlebugs 
** will starve if they haven't eaten recently.
*******************************************************************************/

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

#include "simulation.hpp"


/*******************************************************************************
** Description: The constructor function displays a message to inform the grader
** of extra credit. It then starts the simulation.
** Parameters: None
*******************************************************************************/

Simulation::Simulation()
{
    cout << "\n-----------------------------------------------\n\n";
    cout << "PREDATOR PREY GAME\n\n";
    cout << "Recommended inputs are 20 rows, 20 columns,\n"
         << "5 doodlebugs, 100 ants, and at least 100 steps\n"
         << "to see a good representation of simulation.\n";
    cout << "\n-----------------------------------------------\n\n";

    run();
}


/*******************************************************************************
** Description: The run function displays a menu to play or quit. While the 
** user chooses to play, functions are called to get input for game, create 
** and populate the board, and start the game. 
** Parameters: None
** Return: None
*******************************************************************************/

void Simulation::run()
{
    vector<string> menuOptions = {"Play Again", "Quit Program"};
    Menu replayMenu(menuOptions);
    int choice = 1;

    while (choice == 1)
    {
        getUserInput();
        createBoard();
        populateBoard();
        startGame();

        cout << "\nChoose from options below:" << endl;
        choice = replayMenu.run();

        deallocateMemory();
    }
}


/*******************************************************************************
** Description: The getUserInput function prompts the user for the dimensions
** of the board, number of doodlebugs and ants, and number of game steps.
** Parameters: None
** Return: None
*******************************************************************************/

void Simulation::getUserInput()
{
    numRows = getInt(2, 30, "How many rows should board have?");
    numCols = getInt(2, 30, "How many columns?");
    numDoodlebugs = getInt(1, numRows * numCols, "How many doodlebugs?");
    numAnts = getInt(1, numRows * numCols - numDoodlebugs, "How many ants?");
    numSteps = getInt(1, 10000, "How many steps for game?");
}


/*******************************************************************************
** Description: The createBoard function allocates memory for the board and
** sets each position to null.
** Parameters: None
** Return: None
*******************************************************************************/

void Simulation::createBoard()
{
    board = new Critter**[numRows];

    for (int i = 0; i < numRows; i++)
    {
        board[i] = new Critter*[numCols];
    }

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            board[i][j] = nullptr;
        }
    }
}


/*******************************************************************************
** Description: The populateBoard function places the number of doodlebugs and
** ants the user input on the board.
** Parameters: None
** Return: None
*******************************************************************************/

void Simulation::populateBoard()
{
    int doodlebugsPlaced = 0;

    while (doodlebugsPlaced < numDoodlebugs)
    {
        int row = getRandNum(0, numRows - 1);
        int col = getRandNum(0, numCols - 1);

        if (!board[row][col])
        {
            board[row][col] = new Doodlebug;
            doodlebugsPlaced++;
        }
    }

    int antsPlaced = 0;

    while (antsPlaced < numAnts)
    {
        int row = getRandNum(0, numRows - 1);
        int col = getRandNum(0, numCols - 1);

        if (!board[row][col])
        {
            board[row][col] = new Ant;
            antsPlaced++;
        }
    }
}


/*******************************************************************************
** Description: The startGame function displays the initial board and then
** loops for the number of steps the user input, calling functions to move the
** doodlebugs and ants, breed all critters, remove doodlebugs that have starved,
** and print the updated board.
** Parameters: None
** Return: None
*******************************************************************************/

void Simulation::startGame()
{
    cout << "Initial Board" << endl;
    displayBoard();

    for (int i = 0; i < numSteps; i++)
    {
        resetHasMoved();
        moveDoodlebugs();
        moveAnts();
        breedCritters();
        starveDoodlebugs();

        cout << "Step: " << i + 1 << endl;
        displayBoard();
    }
}


/*******************************************************************************
** Description: The displayBoard function loops through the board, printing 
** an empty space if position is null, or if a critter occupies the position,
** printing the appropriate symbol.
** Parameters: None
** Return: None
*******************************************************************************/

void Simulation::displayBoard()
{
    cout << string(2 * numCols + 1, '-') << '\n'; 

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (!board[i][j])
            {
                cout << "| ";
            }

            else
            {
                cout << '|' << board[i][j]->getSymbol();
            }
        }

        cout << '|' << endl;
    }

    cout << string(2 * numCols + 1, '-') << '\n' << endl; 
}


/*******************************************************************************
** Description: The resetHasMoved function loops through the board, setting 
** each critter's hasMoved property to false. The hasMoved property is used to 
** prevent critters that have been moved to a farther position on board from 
** being moved again before the next step occurs.
** Parameters: None
** Return: None
*******************************************************************************/

void Simulation::resetHasMoved()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (board[i][j])
            {
                board[i][j]->setHasMoved(false);
            }
        }
    }
}


/*******************************************************************************
** Description: The moveDoodlebug function loops through the board and if a 
** doodlebug is found that has not already moved, it calls a function to get 
** the adjacent cell coordinates. It then calls a function to check for ants 
** in those adjacent cells. If none are found, it calls a function to move 
** doodlebut to an empty adjacent cell and increments steps since its last meal.
** Parameters: None
** Return: None
*******************************************************************************/

void Simulation::moveDoodlebugs()
{
    vector<Coordinates> coords;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            Doodlebug* doodle = dynamic_cast<Doodlebug*>(board[i][j]);

            // if doodlebug is found and it has not already moved
            if (doodlebugFound(i, j) && !doodle->getHasMoved())
            {
                doodle->move();
                coords = getAdjacentCoords(i, j);

                // pass vector of adjacent coordinates to look for ants to eat
                // if no ants found, move to empty position if available
                if (!ateAnt(coords, i, j))
                {
                    moveToEmptyPos(coords, i, j);
                    doodle->incrementLastMeal();
                }
            }
        }
    }
}


/*******************************************************************************
** Description: The moveAnts function loops through the board and if an ant is
** found that has not already moved, it calls a function to get the adjacent
** cell coordinates, then calls a function to move to an empty cell.
** Parameters: None
** Return: None
*******************************************************************************/

void Simulation::moveAnts()
{
    vector<Coordinates> coords;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            Ant* ant = dynamic_cast<Ant*>(board[i][j]);

            // if ant is found and it has not already moved
            if (antFound(i, j) && !ant->getHasMoved())
            {
                ant->move();
                coords = getAdjacentCoords(i, j);
                
                // move to empty position if available
                moveToEmptyPos(coords, i, j);
            }
        }
    }
}


/*******************************************************************************
** Description: The breedCritters function loops through the board, looking for
** ants and doodlebugs. If one is found and is the right age to breed, it calls
** a function to get the adjacent cell coordinates and adds a new critter if
** an empty cell is found.
** Parameters: None
** Return: None
*******************************************************************************/

void Simulation::breedCritters()
{
    vector<Coordinates> coords;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (antFound(i, j))
            {
                Ant* ant = dynamic_cast<Ant*>(board[i][j]);

                // if ant is right age to breed
                if (ant->getCanBreed())
                {
                    coords = getAdjacentCoords(i, j);

                    // add ant to empty position if available
                    addToEmptyPos(coords, i, j);
                }
            }

            else if (doodlebugFound(i, j))
            {
                Doodlebug* doodle = dynamic_cast<Doodlebug*>(board[i][j]);

                // if doodlebug is the right age to breed
                if (doodle->getCanBreed())
                {
                    coords = getAdjacentCoords(i, j);

                    // add doodlebug to empty position if available
                    addToEmptyPos(coords, i, j);
                }
            }
        }
    }
}


/*******************************************************************************
** Description: The starveDoodlebug function loops through the board, looking 
** for doodlebugs that have not eaten in the last three steps and removes them.
** Parameters: None
** Return: None
*******************************************************************************/

void Simulation::starveDoodlebugs()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            Doodlebug* doodle = dynamic_cast<Doodlebug*>(board[i][j]);

            if (doodlebugFound(i, j) && doodle->hasStarved())
            {
                removeCritter(i, j);
            }
        }
    }
}


/*******************************************************************************
** Description: The doodlebugFound function returns true if a doodlebug is found
** at the coordinates passed in and false if not.
** Parameters: two integers for row and column positions
** Return: true if doodlebug found, false if not
*******************************************************************************/

bool Simulation::doodlebugFound(int row, int col)
{
    return board[row][col] && dynamic_cast<Doodlebug*>(board[row][col]);
}


/*******************************************************************************
** Description: The antFound function returns true if an ant is found at the
** coordinates passed in and false if not.
** Parameters: two integers for row and column positions
** Return: true if ant found, false if not
*******************************************************************************/

bool Simulation::antFound(int row, int col)
{
    return board[row][col] && dynamic_cast<Ant*>(board[row][col]);
}


/*******************************************************************************
** Description: The isValidPosition checks to make sure the coordinates passed
** in are not outside the board. 
** Parameters: two integers for row and column positions
** Return: true if position is valid, false if not
*******************************************************************************/

bool Simulation::isValidPosition(int row, int col)
{
    return row >= 0 && row < numRows && col >= 0 && col < numCols;
}


/*******************************************************************************
** Description: The move function moves a critter from one position to another.
** Parameters: four integers for current row and column positions and new row
** and column positions.
** Return: None
*******************************************************************************/

void Simulation::move(int row, int col, int newRow, int newCol)
{
    board[newRow][newCol] = board[row][col];

    // set hasMove to true so it will not be moved again during same step
    board[newRow][newCol]->setHasMoved(true);

    board[row][col] = nullptr;
}


/*******************************************************************************
** Description: The getAdjacentCoords function looks at the positions above,
** below, left, and right of the current position. It they are valid positions,
** they are added to a vector of adjacent coordinates.
** Parameters: two integers for current row and column positions
** Return: vector of valid adjacent coordinates
*******************************************************************************/

vector<Coordinates> Simulation::getAdjacentCoords(int row, int col)
{
    // create coordinate objects for positions above, below, left, and right
    Coordinates up(row - 1, col);
    Coordinates down(row + 1, col);
    Coordinates left(row, col - 1);
    Coordinates right(row, col + 1);;

    vector<Coordinates> adjacentCoords;

    // for each position, if it's on the board, add it to vector of coordinates
    if (isValidPosition(up.getX(), up.getY()))
    {
        adjacentCoords.push_back(up);
    }

    if (isValidPosition(down.getX(), down.getY()))
    {
        adjacentCoords.push_back(down);
    }

    if (isValidPosition(left.getX(), left.getY()))
    {
        adjacentCoords.push_back(left);
    }

    if (isValidPosition(right.getX(), right.getY()))
    {
        adjacentCoords.push_back(right);
    }

    return adjacentCoords;
}


/*******************************************************************************
** Description: The ateAnt function loops through a vector of coordinates,
** looking for an ant. If found, it removes the ant and moves the doodlebug
** to that position, resetting the steps since last meal to zero.
** Parameters: vector of valid adjacent coordinates and two integers for row
** and column positions
** Return: true if an ant if eaten, false if not
*******************************************************************************/

bool Simulation::ateAnt(vector<Coordinates> coords, int row, int col)
{
    int x;
    int y;

    for (int i = 0; i < coords.size(); i++)
    {
        x = coords[i].getX();
        y = coords[i].getY();

        if (antFound(x, y))
        {
            // remove ant
            removeCritter(x, y);
            
            // move doodlebug from current position to ant's position
            move(row, col, x, y);

            Doodlebug* doodle = dynamic_cast<Doodlebug*>(board[x][y]);

            // reset steps since last meal to zero
            doodle->resetLastMeal();

            return true;
        }
    }

    return false;
}


/*******************************************************************************
** Description: The moveToEmptyPos function randomly chooses from a vector of
** coordinates. If the position is empty, the move is made. If not, another
** random set of coordinates is chosen and checked again. This continues until
** an empty cell is found or there are no more coordinates to check.
** Parameters: vector of valid adjacent coordinates and two integers for row
** and column positions
** Return: true if move to empty position was successful, false if not
*******************************************************************************/

bool Simulation::moveToEmptyPos(vector<Coordinates> coords, int row, int col)
{
    bool foundEmpty = false;
    int randCoords;
    int x;
    int y;

    // until empty position is found or there are no more coordinates to check
    while (!foundEmpty && coords.size() > 0)
    {
        randCoords = getRandNum(0, coords.size() - 1);
        
        x = coords[randCoords].getX();
        y = coords[randCoords].getY();

        // if position is empty, move criter to that position
        if (!board[x][y])
        {
            foundEmpty = true;
            move(row, col, x, y);
        }

        // remove coordinates that were checked so they won't be checked again
        coords.erase(coords.begin() + randCoords);
    }

    return foundEmpty;
}


/*******************************************************************************
** Description: The addToEmptyPos function randomly chooses from a vector of
** coordinates. If the position is empty, a critter is added. If not, another
** random set of coordinates is chosen and checked again. This continues until
** an empty cell is found or there are no more coordinates to check.
** Parameters: vector of valid adjacent coordinates and two integers for row
** and column positions
** Return: None
*******************************************************************************/

void Simulation::addToEmptyPos(vector<Coordinates> coords, int row, int col)
{
    bool foundEmpty = false;
    int randCoords;
    int x;
    int y;

    // until empty position is found or there are no more coordinates to check
    while (!foundEmpty && coords.size() > 0)
    {
        randCoords = getRandNum(0, coords.size() - 1);
        
        x = coords[randCoords].getX();
        y = coords[randCoords].getY();

        // if position is empty, add criter to that position
        if (!board[x][y])
        {
            foundEmpty = true;

            if (dynamic_cast<Doodlebug*>(board[row][col]))
            {
                addCritter(DOODLEBUG, x, y);
            }

            else
            {
                addCritter(ANT, x, y);
            }
        }

        // remove coordinates that were checked so they won't be checked again
        coords.erase(coords.begin() + randCoords);
    }
}


/*******************************************************************************
** Description: The addCritter function adds a new doodlebug or ant at the 
** position passed in.
** Parameters: type of critter to add and two integers for the row and column
** positions
** Return: None
*******************************************************************************/

void Simulation::addCritter(CritterType critter, int row, int col)
{
    if (critter == DOODLEBUG)
    {
        board[row][col] = new Doodlebug;
    }

    else
    {
        board[row][col] = new Ant;
    }
}


/*******************************************************************************
** Description: The removeCritter function removes a critter from the position
** passed in and sets it to null.
** Parameters: two integers for row and column positions
** Return: None
*******************************************************************************/

void Simulation::removeCritter(int row, int col)
{
    delete board[row][col];
    board[row][col] = nullptr;
}


/*******************************************************************************
** Description: The deallocateMemory function loops through the board,
** deallocating memory for each position, then loops through the rows and
** deallocates memory for each row array, then deallocates memory for the board.
** Parameters: None
** Return: None
*******************************************************************************/

void Simulation::deallocateMemory()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            delete board[i][j];
        }
    }

    for (int i = 0; i < numRows; i++)
    {
        delete [] board[i];
    }

    delete [] board;
}


Simulation::~Simulation()
{
}
