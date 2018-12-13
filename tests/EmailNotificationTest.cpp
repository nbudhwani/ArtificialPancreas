/**
*	\brief Test harness for the EmailNotification class
*/

#include "EmailNotification.h"

using namespace std;

int main()
{
	string email = "noah123body@gmail.com";
	string password = "pass123word";
	string recipientEmail = "noah123body@gmail.com";

	EmailNotification notify = EmailNotification(email, password, recipientEmail);

	int selection = 0;
	bool testing = true;
	while (testing)
	{
		selection = 0;

		cout << "Please check the test gmail account noah123body@gmail.com to confirm the results of the test" << endl;
		cout << "Choose an email notification to test: " << endl;
		cout << "1 - unauthorized access" << endl;
		cout << "2 - hypoglycemic event" << endl;
		cout << "3 - email to emergency contact" << endl;
		cout << "4 - medical record accessed" << endl;
		cout << "5 - quit testing" << endl;

		cin >> selection;
		switch(selection)
		{
			case 1:
				notify.sendUnauthorizedAccessEmail();
				break;
			case 2:
				notify.sendHypoglycemicEventEmail();
				break;
			case 3:
				notify.sendEmergencyContactEmail();
				break;
			case 4:
				notify.sendMedicalRequestEmail();
				break;
			case 5:
				testing = false;
				break;
			default:
				cout << "invalid selection" << endl;
		}
	}


	return 0;
}
