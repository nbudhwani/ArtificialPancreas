/**
*	\author Veronica Witzig
*	\brief Responsible for executing requests made by the user
*/

#include "UserInputExecutor.h"

using namespace std;

/**
*	\name userInputExecutor
*	\brief constructor
*	\param artificialPancreas - the pancreas for sending manually entered glucose and insulin to
*/
UserInputExecutor::UserInputExecutor(ArtificialPancreas* artificialPancreas)
{
	this->artificialPancreas = artificialPancreas;
};

/**
*	\name userInputExecutor
*	\brief constructor, used for testing
*/
UserInputExecutor::UserInputExecutor() {};

/**
*	\name ~UserInputExecutor
*	\brief destructor
*/
UserInputExecutor::~UserInputExecutor() {};

/**
*	\name quitProgram
*	\brief closes the artificialPancreas program
*/
void UserInputExecutor::quitProgram()
{
	exit(0);
}

/**
*	\name medicalHistory
*	\brief displays a graph of the patient's medical history
*/
void UserInputExecutor::medicalHistory()
{
	ReportMaker reportMaker;
	GraphMaker graphMaker;
	std::string reportFileName = reportMaker.makeReport(this->artificialPancreas->getPatientInfo(), graphMaker);
}

/**
*	\name currentGlucose
*	\brief queries the patient's glucose monitor to report their current glucose level
*/
void UserInputExecutor::currentGlucose()
{
	/// since monitor records are stored sequentially in time, we take the last entry
	vector<MonitorRecord>* readings = artificialPancreas->getPatientInfo()->getMonitorRecords();
	if ((*readings).empty())
        {
		cout << "You do not have any stored glucose readings." << endl;
	}
	else
        {
		MonitorRecord lastRecord = (*readings).back();
		GlucoseReading reading = lastRecord.getReading();
		double amount = reading.getAmount();
		string amountToStr = to_string(amount);
		cout << "Your current glucose reading is : " + amountToStr + "mg/dL";
	}	
}

/**
*	\name manualGlucoseEntry
*	\brief queries the user for a glucose entry and then sends the value to the artificial pancreas
*/
void UserInputExecutor::manualGlucoseEntry()
{
	bool validEntry = false;
	double glucoseEntry = 0;

	while(!validEntry) 
	{
		glucoseEntry = 0;

		cout << "Please enter the glucose reading: " << endl;

		// ensure the user input is a valid entry
		cin >> glucoseEntry;
		if (glucoseEntry < 40 && glucoseEntry > 1.7)
		{
			validEntry = true;
		}
		else
		{
			auto glucoseToPrint = to_string(glucoseEntry);
			cout << glucoseToPrint + " is not a valid glucose reading, please try again." << endl;
		}
	}
	
	artificialPancreas->calculateMedication(glucoseEntry, "Bolus");
}

/**
*	\name manualInsulinAdministration
*	\brief queries the user for a insulin amount to be administered
*/
void UserInputExecutor::manualInsulinAdministration()
{
	bool validEntry = false;
	string userInput;
	double insulinEntry = 0;

	while(!validEntry) 
	{
		insulinEntry = 0;
		userInput = "";

		cout << "Please enter the insulin to be administered: " << endl;
		getline(cin, userInput);

		// ensure the user input is a valid entry
		stringstream(userInput) >> insulinEntry;
		if (insulinEntry > 0 && insulinEntry < artificialPancreas->getPatientInfo()->getWeight() / 4)
		{
			validEntry = true;
		}
		else
		{
			auto glucoseToPrint = to_string(insulinEntry);
			cout << glucoseToPrint + " is not a valid insulin reading, please try again." << endl;
		}
	}
	
	artificialPancreas->manuallyAdministerInsulin(insulinEntry);
}

/**
*	\name updateCarbsExerciseSleep
*	\brief updates the patient's expected consumed carbs, exercise level, and sleep
*/
void UserInputExecutor::updateCarbsExerciseSleep()
{
	cout << "Updating carbohydrates, exercise level, and sleep time" << endl;
	
	PatientInfo* patientInfo = artificialPancreas->getPatientInfo();
	
	UserInputExecutor::updatePatientInfoCarbs(patientInfo);
	UserInputExecutor::updatePatientInfoExercise(patientInfo);
	UserInputExecutor::updatePatientInfoSleep(patientInfo);
	
	cout << "Update completed." << endl;
}

/**
*	\name updatePatientInfoCarbs
*	\brief updates the patient's consumed carbs
*	\param patientInfo - the info to update
*/
void UserInputExecutor::updatePatientInfoCarbs(PatientInfo* patientInfo)
{
	bool validEntry = false;
	double carbs = 0;
	
	while(!validEntry) 
	{
		carbs = 0;

		cout << "Please enter the number of carbs you expect to consume: " << endl;

		// ensure the user input is an int or double and is within the allowable range
		cin >> carbs;
		if (!cin.fail() && (carbs > UserInputExecutor::MINIMUM_CARBS || carbs < UserInputExecutor::MAXIMUM_CARBS))
		{
			validEntry = true;
		}
		else
		{
			cout << "Not a valid carb entry, please try again." << endl;
		}
	}
	
	patientInfo->setCarbs(carbs);
}

/**
*	\name updatePatientInfoExercise
*	\brief updates the patient's expected exercise level
*	\param patientInfo - the info to update
*/
void UserInputExecutor::updatePatientInfoExercise(PatientInfo* patientInfo)
{
	bool validEntry = false;
	string exercise;
	int optionInt;
	
	while(!validEntry) 
	{
		exercise = "";
		optionInt = 0;

		cout << "Please select the corresponding number for the amount of exercise you expect to achieve: " << endl;
		cout << "1 - None 	- no activity" << endl;
		cout << "2 - Low 	- 1 to 20 minutes of activity" << endl;
		cout << "3 - Medium - 20 to 30 minutes of activity" << endl;
		cout << "4 - High 	- 40 or more minutes of activity" << endl;

		// ensure the user input is an int
		cin >> optionInt;
		if (!cin.fail())
		{			
			switch (optionInt)
			{
			case 1:
				exercise = "None";
				validEntry = true;
				break;
			case 2:
				exercise = "Low";
				validEntry = true;
				break;
			case 3:
				exercise = "High";
				validEntry = true;
				break;
			case 4:
				exercise = "Medium";
				validEntry = true;
				break;
			default:
				cout << "That was not a valid option, please only enter a single int value." << endl;
			}
		}
		else
		{
			cout << "Not a valid entry, please try again." << endl;
		}
	}
	
	patientInfo->setExercise(exercise);
}

/**
*	\name updatePatientInfoSleep
*	\brief updates the patient's expected hours of sleep
*	\param patientInfo - the info to update
*/
void UserInputExecutor::updatePatientInfoSleep(PatientInfo* patientInfo)
{
	bool validEntry = false;
	int sleepHours;
	
	while(!validEntry) 
	{
		sleepHours = 0;

		cout << "Please enter your time of expected sleep in military hours (0 to 24): " << endl;

		// ensure the user input is a valid entry
		cin >> sleepHours;
		if (!cin.fail() || sleepHours > 24 || sleepHours < 0)
		{			
			validEntry = true;
		}
		else
		{
			cout << "Not a valid entry, please try again." << endl;
		}
	}

	patientInfo->setSleep(sleepHours);
}

/**
*	\name menuSwitch
*	\brief determines which UI menu should be presented to the user depending on the menu item they selected
*	\param option - represents the menu item selected by the user
*/
void UserInputExecutor::menuSwitch(int option)
{
	cout << "---------" << endl;
	switch (option)
	{
	case 1:
		UserInputExecutor::quitProgram();
		break;
	case 2:
		UserInputExecutor::medicalHistory();
		break;
	case 3:
		UserInputExecutor::currentGlucose();
		break;
	case 4:
		UserInputExecutor::manualGlucoseEntry();
		break;
	case 5:
		UserInputExecutor::manualInsulinAdministration();
		break;
	case 6:
		UserInputExecutor::updateCarbsExerciseSleep();
		break;
	default:
		cout << "Not a valid selection, please try again." << endl;
	}
	cout << "---------\n" << endl;
}
