/*******************************************************************************
** Program Name: Predator Prey Game
** Author: Kelly von Borstel
** Date: 2/17/2018
** Description: This is implementation file for the critter class. It's the base
** class for ant and doodlebug classes. The critter class has member variables
** for the critter's age, the symbol that will represent it on the board, a 
** bool to indicate if the critter has already moved on a step, and a bool to 
** indicate if it's the right age to breed. There are member functions to get
** and increment its age, get the symbol, set and get hasMoved and get canBreed,
** and a virtual function move that will be overridden in derived classes.
*******************************************************************************/

#include "critter.hpp"


/*******************************************************************************
** Description: The constructor function initilizes the age to zero and the 
** hasMoved and canBreed bools to false. It has no parameters.
*******************************************************************************/

Critter::Critter()
{
    this->age = 0;
    this->hasMoved = false;
    this->canBreed = false;
}


/*******************************************************************************
** Description: The getAge function returns the critter's age as an integer.
** It has no parameters.
*******************************************************************************/

int Critter::getAge()
{
    return age;
}


/*******************************************************************************
** Description: The incrementAge function increases the critter's age by one.
** It has no parameters and returns nothing.
*******************************************************************************/

void Critter::incrementAge()
{
    age++;
}


/*******************************************************************************
** Description: The getSymbol function returns a char as the symbol that 
** represents the critter on the board. It has no parameters.
*******************************************************************************/

char Critter::getSymbol()
{
    return symbol;
}


/*******************************************************************************
** Description: The setHasMoved function has one parameter, a bool that
** represents whether the critter has already moved on step. It returns nothing.
*******************************************************************************/

void Critter::setHasMoved(bool moved)
{
    hasMoved = moved;
}


/*******************************************************************************
** Description: The getHasMoved function returns a bool to indicate whether the
** critter has already moved on step. It has no parameters.
*******************************************************************************/

bool Critter::getHasMoved()
{
    return hasMoved;
}


/*******************************************************************************
** Description: The getCanBreed function returns a bool to indicate whether the
** critter is at correct age to breed. It has no parameters.
*******************************************************************************/

bool Critter::getCanBreed()
{
    return canBreed;
}

Critter::~Critter()
{
}
