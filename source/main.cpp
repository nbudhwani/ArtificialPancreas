/**
	\brief Runs the artificial pancreas program
	\author Group 22
	
	Main for the artificial pancreas program
*/

#include "main.h"

using namespace std;

int main(int argc, char **argv) 
{
	cout << "starting" <<endl;

	ArtificialPancreas* artificialPancreas = new ArtificialPancreas();
	GlucoseMonitor* glucoseMonitor = new GlucoseMonitor();

	std::thread t1(&GlucoseMonitor::listen, glucoseMonitor, artificialPancreas);

	UserInputExecutor *executor = new UserInputExecutor(artificialPancreas);
	
	
	Account *account = new Account();
	Menu *menu = new Menu(account);
	
	bool running = true;

	while(running)
	{
		menu->printMenu();
		int optionToRetrieve = menu->getMenuSelection();

		if(optionToRetrieve == 0)
		{
			PatientInfo* patient = artificialPancreas->getPatientInfo();
			EmailNotification notify = EmailNotification(patient);
			notify.sendUnauthorizedAccessEmail();
			running = false;
		}

		if(optionToRetrieve == 1)
		{
			running = false;
			delete artificialPancreas;
		}


		executor->menuSwitch(optionToRetrieve);
	}
	
	return 0;
}
