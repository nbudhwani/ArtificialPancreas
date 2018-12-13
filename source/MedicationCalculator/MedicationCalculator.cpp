/*
Author: Claire Dong
Date: Nov 5th, 2018
Description: Calculates hormone based on glucose reading, time, sleep, exercise, and carbohydrate intake
*/

#include "MedicationCalculator.h"
using namespace std;

MedicationCalculator::MedicationCalculator(double givenGlu, PatientInfo *patient, string basalOrBolus){
	
	// Initialize variables
	patientInfo = patient;
	gluRead = givenGlu;
	weight = patient->getWeight();
	age = patient->getAge();
	sleepHour = patient->getSleep();
	exLevel = patient->getExercise();
	carbGrams = patient->getCarbs();
	insType = basalOrBolus;
	
	TDD = getTDD();      // Find total daily dose of basal insulin
}

MedicationCalculator::~MedicationCalculator(){
}


/* Computes dosages of glucagon, basal, or bolus insulin. 
   Checks if patient is hypoglycemic and gives glucagon before checking insulin needs.
   Basal is given once per hour.
   Bolus is given when patient specifies their carb intake + blood glucose correction is needed (every 25 mins).
   Returns HormoneDose.
   Reference: 5
*/

HormoneDose * MedicationCalculator::computeDosage(){
    hormoneType gluc = GLUCAGON; 
    hormoneType basal = BASAL_INSULIN; 
    hormoneType bolus = BOLUS_INSULIN; 

    int valid = validateReading();	 // Validate glucose readings, return null if invalid
    if (valid > 0){
	    return NULL;
	}

	/* 
	 * Administer glucagon if hypoglycemic. Commented out print statement for future debugging.
	*/
	double glucagonToAdmin = getGlucagon();
	if (glucagonToAdmin > 0){
		// cout << "Administer glucagon: "<< glucagonToAdmin << endl;
	    return new HormoneDose(gluc, glucagonToAdmin);
	}


	/* 
	 * Administer basal insulin. Commented out print statement for future debugging.
	*/
	double basalToAdmin = getHourBasal();
	if (basalToAdmin > 0 && insType == "Basal"){
		// cout << "Administer hourly basal insulin: "<<  basalToAdmin << endl;
        return new HormoneDose(basal, basalToAdmin);
	}

	/* 
	 * Administer bolus insulin for meals. Commented out print statement for future debugging.
	*/
	double bolusToAdmin = getBolus();
	if (bolusToAdmin > 0 && insType == "Bolus"){
		// cout << "Administer meal bolus insulin: "<<  bolusToAdmin << endl;
    	return new HormoneDose(bolus, bolusToAdmin);
    }

    return new HormoneDose(bolus, 0);
}

/* Validate glucose readings
   Reference: 5
*/
int MedicationCalculator::validateReading(){
	if (gluRead < 1.7 || gluRead > 40){
		cout << "Invalid glucose readings" << endl;
		return 1;
	}
	return 0;
}

// Retrieve glucose reading
double MedicationCalculator::GetGlucoseReading() {
	return gluRead;
}

/* Admininister 1 unit of glucagon if hypoglycemic
   Reference: 5
*/
double MedicationCalculator::getGlucagon(){
	double glucagon = 0;
	
	if (gluRead < 2.8){
		//EmailNotification notify = EmailNotification(patientInfo);
		//notify.sendEmergencyContactEmail();
		glucagon = 1;
	}
	
	return glucagon;
}


/* Calculate hourly basal dose based on time to 2 decimals
   Accounts for circadian rythm where glucose levels decrease at night
   Accounts for the "Dawn phenomenon" where glucose is normally higher during dawn
   Reference: 2
*/
double MedicationCalculator::getHourBasal(){
	int hour = findCurrentHour();

	// Find hourly basal insulin (not calculating time)
	double hourlyBasal = (TDD * 0.5) / 24;
	double currentBasal;

	// Account for nightly decrease and dawn increase of glucose
	if (hour >= 0 && hour < 4){
		currentBasal = (double) (int) ((hourlyBasal * 0.5) * 100 + 0.5) / 100;
	} else if (hour >= 4 && hour < 10){
		currentBasal = (double) (int) ((hourlyBasal * 1.5) * 100 + 0.5) / 100;
	} else {
		currentBasal = (double) (int) (hourlyBasal * 100 + 0.5) / 100;
	}

	double sleepBasal = calcSleep(currentBasal);
	double adjustedBasal = calcEx(sleepBasal);	
	return adjustedBasal;

}


/* Calculate total bolus amount to accound for meal size and blood glucose correction
   Reference: 2
*/
double MedicationCalculator::getBolus(){
	return calcMeal() + calcCorrection();
}


/* Adjusts basal insulin based on user sleep time. Uses default of 11pm - 7am if
   sleep time not given.
   Reference: 2
*/
double MedicationCalculator::calcSleep(double basal){
	double sleepBasal = basal;
	int currentHour = findCurrentHour();

	// Default is sleep at 11pm
	if (sleepHour == -1){
		sleepHour = 23;
	}

	// If current time is within 7 hours of sleep time
	int timeToWrap = 24 - sleepHour;
	if ((currentHour >= sleepHour && currentHour < sleepHour + 7) || (currentHour < 7 - timeToWrap)){

		// For patients under 16
		if(age < 16){
			
			// Adjust basal rates to be higher or lower depending on blood glucose levels
			if (gluRead < 6.66){
				sleepBasal = basal * 0.85;
			} else if (gluRead > 8.88){
				sleepBasal = basal * 1.15;
			}

		// For patients 16 and up
		}else{

			// Adjust basal rates to be higher or lower depending on blood glucose levels
			if (gluRead < 6.10){
				sleepBasal = basal * 0.85;
			} else if (gluRead > 7.21){
				sleepBasal = basal * 1.15;
			}
		}
	}

	return (double) (int) (sleepBasal * 100 + 0.5) / 100; 
}


/* Adjusts basal insulin based on user exercise level. Exercise is identified as low, medium, or high. 
   Reference: 4
*/
double MedicationCalculator::calcEx(double basal){
   double exBasal = basal;
   
   if (exLevel == "Low"){
   		exBasal = basal * 0.75;
   } else if (exLevel == "Medium"){
   		exBasal = basal * 0.5;
   } else if (exLevel == "High"){
   		exBasal = basal * 0.25;
   }

   // Reset exercise to none 
   patientInfo->setExercise("None");

   return (double) (int) (exBasal * 100 + 0.5) / 100;  
}


/* Calculates bolus insulin dose based on carbohydrate intake
	Reference: 2
*/
double MedicationCalculator::calcMeal(){
	double CHOPerUnit = 450 / TDD;
	double mealBolus = carbGrams / CHOPerUnit;

	// Reset carbs to 0
	patientInfo->setCarbs(0);

	return (double) (int) (mealBolus * 100 + 0.5) / 100;  
}

/* Calculates bolus insulin dose based glucose reading to administer a correction dose
	Reference: 2
*/
double MedicationCalculator::calcCorrection(){
	
	// Find insulin sensitivity factor;
	double insSensFactor = 1700 / TDD;
	double targetGlu;

	// Target blood glucose is different for each age range
	if(age < 16){
		targetGlu = 7.49;
	} else {
        targetGlu = 5.55;
	}

	double correctBolus = (gluRead - targetGlu) / insSensFactor;

	if (correctBolus >= 0){
		return (double) (int) (correctBolus * 100 + 0.5) / 100;  
	} else {
		return 0;
	}

}

// Find current hour
int MedicationCalculator::findCurrentHour(){
	time_t now = time(0);
	tm* structTime = localtime(&now);
	return structTime->tm_hour;

}

/* Calculate total daily dose of basal insulin (TDD)
   Reference: 2
*/
double MedicationCalculator::getTDD(){
	double TDD = weight * 0.23;
	return TDD;
}
