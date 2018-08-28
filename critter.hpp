/*******************************************************************************
** Program Name: Predator Prey Game
** Author: Kelly von Borstel
** Date: 2/17/2018
** Description: This is declaration file for the critter class. It's the base
** class for ant and doodlebug classes. The critter class has member variables
** for the critter's age, the symbol that will represent it on the board, a 
** bool to indicate if the critter has already moved on a step, and a bool to 
** indicate if it's the right age to breed. There are member functions to get
** and increment its age, get the symbol, set and get hasMoved and get canBreed,
** and a virtual function move that will be overridden in derived classes.
*******************************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP	

class Critter 
{
    protected:
        int age;
        char symbol;
        bool hasMoved;
        bool canBreed;

    public:
        Critter();
        int getAge();
        void incrementAge();
        char getSymbol();
        void setHasMoved(bool moved);
        bool getHasMoved();
        bool getCanBreed();
        virtual void move() = 0;
        virtual ~Critter();
};

#endif
