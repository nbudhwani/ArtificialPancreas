/**
*	\author Veronica Witzig
*	\brief Header file for the Menu class
*/

#ifndef MENU_HEADER
#define MENU_HEADER

#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <vector>
#include <sstream>

#include "Menu.h"
#include "Account.h"

class Menu
{	
public:
	/// constructor, expects a pointer to the account
	Menu(Account* account);

	/// destructor
	~Menu();
	
	/// prints the menu to the terminal for the user to choose from
	void printMenu();

	/// determines which menu item the user selected
	int getMenuSelection();

private:
	/// contains the type of the account
	std::string accountType;

	/// dynamically built list based on the account type containing menu items
	std::vector<std::string> _items;

	/// determines if the user input is valid
	bool validateSelection(std::string);
};

#endif
