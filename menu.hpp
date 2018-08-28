/*******************************************************************************
** Program Name: Generic Menu Class
** Author: Kelly von Borstel
** Date: 1/28/2018
** Description: This is the declaration file for the Menu class, which displays
** menu options and gets and validates the user's choice. To use it, pass the
** constructor a vector of string menu options. Call menu.run() to display the
** menu options and get and validate the user's input. The run() function
** returns the user's choice as an integer.
*******************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
using std::vector;
using std::string;

#include "utility.hpp"

class Menu
{
    private:
        // menu options the user will choose from
        vector<string> menuOptions;

        // display the menu options
        void print();

        // prompt user with message and then get and validate their choice
        int getChoice();

    public:
        // construct a menu object based on the menu options passed in
        Menu(vector<string> options);

        // print menu and get user choice
        int run();
};

#endif
