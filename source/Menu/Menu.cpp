/**
*	\author Veronica Witzig
*	\brief Responsible for displaying the UI menu
*/

#include "Menu.h"

using namespace std;

/**
*	\name Menu
*	\brief builds the menu items available for the user based on their account type
*/
Menu::Menu(Account *account)
{
	_items;
	accountType = account->getAccountType();
	
	if (accountType == "Patient")
	{
		_items = vector<string>({
			"1 - Exit Program",
			"2 - Medical History",
			"3 - Check Current Glucose Level",
			"4 - Manual Glucose Entry",
			"5 - Manual Insulin Administration",
			"6 - Update carbohydrate intake, exercise, and sleep time"			
		});
	}
	else if (accountType == "Guest")
	{
		_items = vector<std::string>({
			"1 - Exit Program",
			"2 - Medical History"
		});
	}
	else if (accountType == "Unknown")
	{
		cout << "Get out." << endl;
	}
};

/**
*	\name ~Menu
*	destructor
*/
Menu::~Menu() {};

/**
*	\name printMenu
*	\brief prints the UI menu to the terminal for the user
*/
void Menu::printMenu()
{
	for (const auto& item : _items)
	{
		cout << item << endl;
	}
};

/**
*	\name getMenuSelection
*	\brief retrieves the option that the user has selected from the available menu items
*	\return int representing which menu item was selected, return 0 if invalid user
*/
int Menu::getMenuSelection()
{
	bool validSelection = false;
	string userInput;
	int optionInt = 0;
	
	if(accountType == "Unknown")
	{
		return 0;
	}

	while(!validSelection)
	{
		userInput = "";
		optionInt = 0;
		
		cin.ignore(1, '\n');
		cout << "Please select a corresponding number from the above selection: " << endl;
		getline(cin, userInput);
		
		/// ensure the user entered an int
		validSelection = Menu::validateSelection(userInput);		
		stringstream ss(userInput, std::ios_base::in);
		ss >> optionInt;		
	}
	
	return optionInt;
};

/**
*	\name ValidateSelection
*	\brief verfies that the user entered value is valid
*	\param userInput - value to verify
*	\return true is the selection is valid, false otherwise
*/
bool Menu::validateSelection(string userInput)
{	
	/// ensure the input is an int
	int asInt = 0;
	std::stringstream ss(userInput, std::ios_base::in);
	ss >> asInt;
	
	if(accountType == "Unknown")
	{
		return false;
	}

	if(asInt > 6 || asInt < 1)
	{
		cout << userInput + " is not a valid selection, please try again." << endl;
		return false;
	}
	
	/// ensure the user is not trying to select an option they should not be able to
	if (accountType != "Patient" && asInt > 2)
	{
		cout << asInt + " is not a valid selection, please try again." << endl;
		return false;
	}
	
	return true;
};
