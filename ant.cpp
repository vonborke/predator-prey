/*******************************************************************************
** Program Name: Predator Prey Game
** Author: Kelly von Borstel
** Date: 2/17/2018
** Description: This is the implementation file for ant class. It's derived from
** the critter class and inherits member variables for the ant's age, the symbol
** that will represent it on the board, a bool to indicate if the ant has 
** already moved on a step, and a bool to indicate if it's the right age to 
** breed. It also inherits member functions to get and increment its age, get
** the symbol, set and get hasMoved and get canBreed. The move function from
** the critter class is overridden to increment the ant's age and determine if
** it is the correct age to breed.
*******************************************************************************/

#include "ant.hpp"


/*******************************************************************************
** Description: The constructor function inherits from critter constructor and
** sets the ant's board symbol to '0'. It has no parameters.
*******************************************************************************/

Ant::Ant()
{
    this->symbol = 'O';
}


/*******************************************************************************
** Description: The move function increments the ant's age and sets canBreed
** to true if its age is divisible by 3, and false if not. It has no parameters
** and returns nothing.
*******************************************************************************/

void Ant::move()
{
    incrementAge();
    canBreed = (age % 3 == 0);
}

Ant::~Ant()
{
}
