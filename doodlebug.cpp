/*******************************************************************************
** Program Name: Predator Prey Game
** Author: Kelly von Borstel
** Date: 2/17/2018
** Description: This is the implementation file for doodlebug class. It's 
** derived from the critter class and inherits member variables for doodlebug's
** age, the symbol that will represent it on the board, a bool to indicate if 
** the doodlebug has already moved on a step, and a bool to indicate if it's the
** right age to breed. It also inherits member functions to get and increment 
** its age, get the symbol, set and get hasMoved and get canBreed. The move 
** function from the critter class is overriddent to increment the doodlebug's 
** age and determine if it is the correct age to breed. Unique to the doodlebug
** class is a variable to keep track of how many steps have passed since its
** last meal, and functions to get, increment, and reset that variable to zero.
*******************************************************************************/

#include "doodlebug.hpp"


/*******************************************************************************
** Description: The constructor function inherits from critter constructor and
** also sets the doodlebug's board symbol to 'X' and its last meal to zero. It 
** has no parameters.
*******************************************************************************/

Doodlebug::Doodlebug()
{
    this->symbol = 'X';
    this->lastMeal = 0;
}


/*******************************************************************************
** Description: The move function increments the ant's age and sets canBreed
** to true if its age is divisible by 8, and false if not. It has no parameters
** and returns nothing.
*******************************************************************************/

void Doodlebug::move()
{
    incrementAge();
    canBreed = (age % 8 == 0);
}


/*******************************************************************************
** Description: The getLastMeal function returns the number of steps since the
** doodlebug's last meal as an integer. It has no parameters.
*******************************************************************************/

int Doodlebug::getLastMeal()
{
    return lastMeal;
}


/*******************************************************************************
** Description: The incrementLastMeal function adds one to number of steps since
** the doodlebug's last meal. It has no parameters and returns nothing.
*******************************************************************************/

void Doodlebug::incrementLastMeal()
{
    lastMeal++;
}


/*******************************************************************************
** Description: The resetLastMeal function resets the last meal to zero. It has
** no parameters and returns nothing.
*******************************************************************************/

void Doodlebug::resetLastMeal()
{
    lastMeal = 0;
}


/*******************************************************************************
** Description: The hasStarved function returns true if the last meal was 3
** steps ago, and false if not. It has no parameters.
*******************************************************************************/

bool Doodlebug::hasStarved()
{
    return getLastMeal() == 3;
}

Doodlebug::~Doodlebug()
{
}
