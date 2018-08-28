/*******************************************************************************
** Program Name: Predator Prey Game
** Author: Kelly von Borstel
** Date: 2/17/2018
** Description: This is implementation file for the Coordinates class. It has
** member variables for the x and y positions, and member functions to get
** and set those positions.
*******************************************************************************/

#include "coordinates.hpp"

Coordinates::Coordinates(int x, int y)
{
    setX(x);
    setY(y);
}

void Coordinates::setX(int x)
{
    xPosition = x;
}

void Coordinates::setY(int y)
{
    yPosition = y;
}

int Coordinates::getX()
{
    return xPosition;
}

int Coordinates::getY()
{
    return yPosition;
}
