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

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP	

#include "critter.hpp"

class Doodlebug : public Critter
{
    private:
        int lastMeal;

    public:
        Doodlebug();
        virtual void move();
        int getLastMeal();
        void incrementLastMeal();
        void resetLastMeal();
        bool hasStarved();
        virtual ~Doodlebug();
};

#endif
