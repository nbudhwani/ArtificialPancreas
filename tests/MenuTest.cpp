/**
*   \author Veronica Witzig
*   tests the UI Menu for the user
*/

#include "libPancreas.h"

using namespace std;

const std::string PATIENT_ACCOUNT = "Patient";
const std::string GUEST_ACCOUNT = "Guest";
const std::string UNKNOWN_ACCOUNT = "Unknown";

int main()
{
	/// test accounts
	Account *patientAccount = new Account(PATIENT_ACCOUNT);
	Account *guestAccount = new Account(GUEST_ACCOUNT);
	Account *unknownAccount = new Account(UNKNOWN_ACCOUNT);

	Menu patientMenu = Menu(patientAccount);
	Menu guestMenu = Menu(guestAccount);
	Menu unknownMenu = Menu(unknownAccount);

	bool testing = true;
	int selection = 0;
	while (testing)
	{
		selection = 0;
		cout << "\n=============\n" << endl;
		cout << "Which menu would you like to see?" << endl;
		cout << "Please choose the corresponding number: " << endl;
		cout << "1 - patient" << endl;
		cout << "2 - guest" << endl;
		cout << "3 - unknown" << endl;
		cout << "4 - quit testing" << endl;
		cin >> selection;

		switch(selection)
		{
			case 1:
				cout << "\nHere is the Menu: " << endl;
				patientMenu.printMenu();
				break;
			case 2:
				cout << "\nHere is the Menu: " << endl;
				guestMenu.printMenu();
				break;
			case 3:
				cout << "\nHere is the Menu: " << endl;
				unknownMenu.printMenu();
				break;
			case 4:
				cout << "\nQUITTING" << endl;
				testing = false;
				break;
			default:
				cout << "Invalid entry" << endl;
		}
	}	

	return 0;
}
