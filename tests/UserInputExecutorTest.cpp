/**
*   \author Veronica Witzig
*   \brief tests the UI Menu for the user
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

	ArtificialPancreas* pancreas = new ArtificialPancreas();

	PatientInfo* patient = pancreas->getPatientInfo();

	UserInputExecutor executor = UserInputExecutor(pancreas);

	bool testing = true;
	int selection = 0;
	while (testing)
	{
		selection = 0;
		cout << "\n=============\n" << endl;
		cout << "Which menu option would you like to see?" << endl;
		cout << "Please choose the corresponding number: " << endl;

		cout << "1 - medical histoy" << endl;
		cout << "2 - current glucose" << endl;
		cout << "3 - manual glucose entry" << endl;
		cout << "4 - manual insulin administration" << endl;
		cout << "5 - update carbs, exercise, and sleep" << endl;
		cout << "6 - quit testing" << endl;

		cin >> selection;
		switch(selection)
		{
			case 1:
				cout << "\nTesting the medical history option: " << endl;
				executor.menuSwitch(selection + 1);
				break;
			case 2:
				cout << "\nTesting the current glucose option: " << endl;
				executor.menuSwitch(selection + 1);
				break;
			case 3:
				cout << "\nTesting the manual glucose entry option: " << endl;
				executor.menuSwitch(selection + 1);
				break;
			case 4:
				cout << "\nTesting the manual insulin administration: " << endl;
				executor.menuSwitch(selection + 1);
				break;
			case 5:
				cout << "\nTesting the patient info update option: " << endl;
				executor.menuSwitch(selection + 1);
				break;
			case 6:
				cout << "\nQUITTING" << endl;
				testing = false;
				break;
			default:
				cout << "Invalid entry" << endl;
		}
	}	

	

	return 0;
}
