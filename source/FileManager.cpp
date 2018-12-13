/**
*	\author Graeme Brabers
*	\brief Implementation file for the FileManager class
*	Contains File I/O information for serialization of PatientInfo objects
*/

#include "FileManager.h"

FileManager::FileManager()
{
}

FileManager::~FileManager()
{
	if(inFile.is_open())
	{
		inFile.close();
	}
	
	if(outFile.is_open())
	{
		outFile.close();
	}
}

bool FileManager::checkForPatientFile()
{
    inFile.open("patient.txt");
    if(inFile.is_open())
    {
        inFile.close();
        return true;
    }
    return false;
}

PatientInfo * FileManager::readFromFile()
{
    inFile.open("patient.txt");
	std::string name, sex, email, emailPassword, emergName, emergEmail;
    double weight, height;
    int age;
	inFile >> name >> weight >> height >> age  >> sex >> email >> emailPassword >> emergName >> emergEmail;
	Contact *emergencyContact = new Contact(emergName, emergEmail);
	
    std::string input, toEnum, delimiter = ",";
    time_t inputTime;
    size_t pos;
    double amount;
    HormoneDose *dose;
	vector<MonitorRecord> *monRecords = new vector<MonitorRecord>;

	getline(inFile, input);
	while(getline(inFile, input) && input != "-----")
	{
		pos = input.find(delimiter);
		inputTime = (time_t)stol(input.substr(0, pos));
		input.erase(0, pos + delimiter.length());
		monRecords->push_back(MonitorRecord(inputTime, GlucoseReading(stod(input))));
	}

	vector<MedicationRecord> *medRecords = new vector<MedicationRecord>;

	while(getline(inFile, input))
	{
		pos = input.find(delimiter);
		inputTime = (time_t)stol(input.substr(0, pos));
		input.erase(0, pos + delimiter.length());
		pos = input.find(delimiter);
		toEnum = input.substr(0, pos);
		input.erase(0, pos + delimiter.length());
		amount = stod(input);
		if(toEnum == "Bolus Insulin")
		{
			medRecords->push_back(MedicationRecord(inputTime, HormoneDose(BOLUS_INSULIN, amount)));
		}
		else if(toEnum == "Basal Insulin")
		{
			medRecords->push_back(MedicationRecord(inputTime, HormoneDose(BASAL_INSULIN, amount)));
		}
		else if(toEnum == "Glucacon")
		{
			medRecords->push_back(MedicationRecord(inputTime, HormoneDose(GLUCAGON, amount)));
		}
	}
	PatientInfo *user = new PatientInfo(name, height, weight, age, sex, email, emailPassword, emergencyContact, monRecords, medRecords);

	inFile.close();
	return user;
}

void FileManager::writeToFile(PatientInfo *user)
{
	outFile.open("patient.txt", ios::trunc);
	outFile << user->getName() << std::endl;
	outFile << user->getWeight() << std::endl;
	outFile << user->getHeight() << std::endl;
	outFile << user->getAge() << std::endl;
	outFile << user->getSex() << std::endl;
	outFile << user->getEmail() << std::endl;
	outFile << user->getEmailPassword() << std::endl;
    outFile << user->getEmergencyContact()->getName() << std::endl;
    outFile << user->getEmergencyContact()->getEmail() << std::endl;

	for(vector<MonitorRecord>::iterator it = user->getMonitorRecords()->begin(); it != user->getMonitorRecords()->end(); ++it)
	{
		outFile << it->getRecordTime() << ",";
		outFile << it->getReading().getAmount() << endl;
	}
	outFile << "-----" << endl;
	for(vector<MedicationRecord>::iterator it = user->getMedicationRecords()->begin(); it != user->getMedicationRecords()->end(); ++it)
	{
		outFile << it->getRecordTime() << ",";
		switch(it->getHormoneDose().getHormoneType())
		{
			case BOLUS_INSULIN:
				outFile << "Bolus Insulin,";
				break;
			case BASAL_INSULIN:
				outFile << "Basal Insulin,";
				break;
			case GLUCAGON:
				outFile << "Glucagon,";
				break;
		}
		outFile << it->getHormoneDose().getHormoneAmount() << std::endl;
	}
	outFile.close();
}
