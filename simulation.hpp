/*******************************************************************************
** Program Name: Predator Prey Game
** Author: Kelly von Borstel
** Date: 2/17/2018
** Description: This is the declaration file for the simulation class, which
** contains all data and functions need to run the Predator Prey game. To use 
** it, create a simulation object in main. When the simulation runs, it will
** get the user input, create and populate the board, and start the game. For
** each game step, doodlebugs and ants will move, doodlebugs will eat ants if
** available, all critters will breed when they are old enough, and doodlebugs 
** will starve if they have not eaten recently.
*******************************************************************************/

#ifndef SIMULATION_HPP
#define SIMULATION_HPP	

#include <vector>
using std::vector;

#include "doodlebug.hpp"
#include "ant.hpp"
#include "utility.hpp"
#include "menu.hpp"
#include "coordinates.hpp"

enum CritterType {DOODLEBUG, ANT};

class Simulation 
{
    private:
        Critter*** board;
        int numRows;
        int numCols;
        int numDoodlebugs;
        int numAnts;
        int numSteps;
        void run();
        void getUserInput();
        void createBoard();
        void populateBoard();
        void startGame();
        void displayBoard();
        void resetHasMoved();
        void moveDoodlebugs();
        void moveAnts();
        void breedCritters();
        void starveDoodlebugs();
        bool doodlebugFound(int row, int col);
        bool antFound(int row, int col);
        bool isValidPosition(int row, int col);
        void move(int row, int col, int newRow, int newCol);
        vector<Coordinates> getAdjacentCoords(int row, int col);
        bool ateAnt(vector<Coordinates> coords, int row, int col);
        bool moveToEmptyPos(vector<Coordinates> coords, int row, int col);
        void addToEmptyPos(vector<Coordinates> coords, int row, int col);
        void addCritter(CritterType critter, int row, int col);
        void removeCritter(int row, int col);
        void deallocateMemory();

    public:
        Simulation();
        ~Simulation();
};

#endif
