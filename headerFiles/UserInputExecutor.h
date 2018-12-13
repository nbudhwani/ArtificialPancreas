/**
*	\author Veronica Witzig
*	\brief Header file for the UserInputExecutor class
*/

#ifndef USER_INPUT_EXECUTOR_H
#define USER_INPUT_EXECUTOR_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#include "ArtificialPancreas.h"
#include "ReportMaker.h"

class UserInputExecutor
{	
public:	
	/// constructor, expects an artifical pancreas
	UserInputExecutor(ArtificialPancreas* artificialPancreas);

	/// constructor, expects an artifical pancreas, used for testing
	UserInputExecutor();

	/// destructor
	~UserInputExecutor();

	/// determines which option the user has selected based on the menu presented
	void menuSwitch(int option);
	
private:
	/// The minimum number of carbs allowed for user input
	const int MINIMUM_CARBS = 0;

	/// The maximum number of carbs allowed for user input
	const int MAXIMUM_CARBS = 1250;

	ArtificialPancreas* artificialPancreas;
	
	void quitProgram();
	void medicalHistory();
	void currentGlucose();
	void manualGlucoseEntry();
	void manualInsulinAdministration();

	void updateCarbsExerciseSleep();
	void updatePatientInfoCarbs(PatientInfo* patientInfo);
	void updatePatientInfoExercise(PatientInfo* patientInfo);
	void updatePatientInfoSleep(PatientInfo* patientInfo);
};

#endif
