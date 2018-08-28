/*******************************************************************************
** Program Name: Generic Menu Class
** Author: Kelly von Borstel
** Date: 1/28/2018
** Description: This is the implementation file for Menu class, which displays
** menu options and gets and validates the user's choice. To use it, pass the
** constructor a vector of string menu options. Call menu.run() to display the
** menu options and get and validate the user's input. The run() function
** returns the user's choice as an integer.
*******************************************************************************/

#include <iostream>
#include "menu.hpp"
using std::cout;
using std::endl;


/*******************************************************************************
** Description: The print() function loops throught the menu options and prints
** each one to the console. It has no parameters and returns nothing.
*******************************************************************************/

void Menu::print()
{
    cout << '\n';

    for (int i = 0; i < menuOptions.size(); i++)
    {
        cout << i + 1 << ". " << menuOptions[i] << endl;
    }

    cout << '\n';
}


/*******************************************************************************
** Description: The getChoice() function calls the getInt() function to prompt
** the user to choose a menu option, then checks if they entered a valid option.
** If they didn't, it prompts them again for a valid integer. The function has
** no parameters and returns the user's choice as an integer.
*******************************************************************************/

int Menu::getChoice()
{
    return getInt(1, menuOptions.size());
}


/*******************************************************************************
** Description: The Menu() constructor function has one parameter, a vector of
** strings of the menu options. It assigns the values passed in to initialize
** the menu options.
*******************************************************************************/

Menu::Menu(vector<string> options)
{
    menuOptions = options;
}


/*******************************************************************************
** Description: The run() function prints the menu and gets the menu option 
** choice from the user. The function has no paramaters and returns the user's
** choice as an integer.
*******************************************************************************/

int Menu::run()
{
    print();
    return getChoice();
}
