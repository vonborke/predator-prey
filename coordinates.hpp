/*******************************************************************************
** Program Name: Predator Prey Game
** Author: Kelly von Borstel
** Date: 2/17/2018
** Description: This is declaration file for the Coordinates class. It has
** member variables for the x and y positions, and member functions to get
** and set those positions.
*******************************************************************************/

#ifndef COORDINATES_HPP
#define COORDINATES_HPP

class Coordinates
{
    private:
        int xPosition;
        int yPosition;

    public:
        Coordinates(int x, int y);
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();
};

#endif
