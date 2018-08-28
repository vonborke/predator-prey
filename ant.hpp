/*******************************************************************************
** Program Name: Predator Prey Game
** Author: Kelly von Borstel
** Date: 2/17/2018
** Description: This is the declaration file for ant class. It's derived from
** the critter class and inherits member variables for the ant's age, the symbol
** that will represent it on the board, a bool to indicate if the ant has 
** already moved on a step, and a bool to indicate if it's the right age to 
** breed. It also inherits member functions to get and increment its age, get
** the symbol, set and get hasMoved and get canBreed. The move function from
** the critter class is overridden to increment the ant's age and determine if
** it is the correct age to breed.
*******************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP	

#include "critter.hpp"

class Ant : public Critter
{
    public:
        Ant();
        virtual void move();
        virtual ~Ant();
};

#endif
