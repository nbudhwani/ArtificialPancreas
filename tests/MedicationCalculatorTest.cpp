/**
* \author Claire Dong
* \brief tests medication calculator 
*/

// Change to makefiles
#include <ctime>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <sstream>

#include "libPancreas.h"

using namespace std;

/**
* \name: main
* \brief tests medication calculator. 
* Adminsters glucagon if patient is hypoglycemic. Administers basal or bolus insulin depending on what is needed.
* Considers current glucose levels, patient weight, age, and exercise level into calcuations.
* Patient can enter carb consumed or 0 if none. Patient can also enter sleep time or a sleep time of 11pm is assumed. 
* Sleep time is compared to current time to administer insulin appropriately. 
* PLEASE ASSUME INPUTS ARE IN CORRECT FORMAT AS THEY EVENTUALLY WILL BE TAKEN FROM OTHER CLASSES.
*/

int main(){

	double glucose;
	double weight;
	double age;
	int sleepTime;
	string exerciseLevel;
	double carbs;
	string basalOrBolus;

	bool running = true;
	int optionInt = 0;

	while(running)
	{
		cout << "Please follow the prompts for testing the calculator. Would you like to continue testing?" << endl;
		cout << "1 - Yes, run the test" << endl;
		cout << "2 - No, quit the test" << endl;
		cin >> optionInt;

		if(optionInt == 2)
		{
			running = false;
		}
		else
		{
			cout << "Please enter a glucose level in mg/dL: ";
			cin >> glucose;
			
			cout << "Please enter a weight in lbs: ";
			cin >> weight;

			cout << "Please enter an age: ";
			cin >> age;

			cout << "Please enter intake of carbohydrates in grams or 0: ";
			cin >> carbs;

			cout << "Please enter an hour of sleep in military time(hour) or -1 for hour if not specified: ";
			cin >>sleepTime;

			cout << "Please enter an exercise level (Low/Medium/High/None): ";
			getline(cin, exerciseLevel);

			cout << "Please enter if a 'Basal' or 'Bolus' insulin dose is needed: ";
			getline(cin, basalOrBolus);

			PatientInfo* patient = new PatientInfo();

			patient->setAge(age);
			patient->setWeight(weight);
			patient->setCarbs(carbs);
			patient->setExercise(exerciseLevel);
			patient->setSleep(sleepTime);

			MedicationCalculator calc(glucose, patient, basalOrBolus);

		    // Compute Dosage to give
		    /** 
		    *	Make medication calculator
		    *   Parameters are: (double glucoseReading, double weight, double age, double sleepTime, string exerciseLevel, double carbInGrams);
		    */
		    HormoneDose *hormone = calc.computeDosage();
		    switch(hormone->getHormoneType())
		    {
		     	case 2:
		     		cout << "----Administer glucagon----" << endl; 
		     		break;
		     	case 1:
		     		cout << "----Administer bolus insulin----" << endl; 
		     		break;
		     	case 0:
		     		cout << "----Administer basal insulin----" << endl; 
		     		break;
		    } 

		    cout << "Units of hormone (100 units = 1 mL): " << hormone->getHormoneAmount() << endl;

			delete hormone;
		    return 0;
		}
	}    
}
