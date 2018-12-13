/*!
	@author Graeme Brabers
	Responsible for managing patient info and determining insulin administration for the patient
*/

#include "ArtificialPancreas.h"

/*!
	@name ArtificialPancreas
	@purpose constructor
*/
ArtificialPancreas::ArtificialPancreas()
{
	fileManager = new FileManager();
	if(fileManager->checkForPatientFile())
	{
		user = fileManager->readFromFile();
	}
	else
	{
		user = new PatientInfo();
	}
    output = new LaptopOutput("127.0.0.1", 3307);
    email = new EmailNotification(user);
}

/*!
	@name ~ArtificialPancreas
	@purpose destructor
*/
ArtificialPancreas::~ArtificialPancreas()
{
	fileManager->writeToFile(user);
    delete fileManager;
	delete user;
    delete output;
	delete email;
}

/*!
	@name setPatient
	@purpose sets user
	@param *newPatient - patient info to set
*/
void ArtificialPancreas::setPatient(PatientInfo *newPatient)
{
    user = newPatient;
}

/*!
	@name getPatientInfo
	@purpose gets the patient info
	@return the patient info
*/
PatientInfo * ArtificialPancreas::getPatientInfo()
{
    return user;
}

/*!
	@name calculateMedication
	@purpose calculates the medication needed for the patient based on their glucose reading
	@param reading - the glucose reading
*/
void ArtificialPancreas::calculateMedication(const double reading, std::string bolusOrBasal)
{
	user->getMonitorRecords()->push_back(MonitorRecord(std::time(NULL), GlucoseReading(reading)));
    MedicationCalculator *calculator = new MedicationCalculator(reading, user, bolusOrBasal);
    HormoneDose *dose = calculator->computeDosage();
	if(dose != NULL)
    {
		user->getMedicationRecords()->push_back(MedicationRecord(std::time(NULL), *dose));
        output->sendInstruction(dose);
        delete dose;
    }
    delete calculator;
}

/*!
	@name manuallyAdministerInsulin
	@purpose administers the amount of insulin to the patient
	@param insulinAmount - the insulin amount to administer
*/
void ArtificialPancreas::manuallyAdministerInsulin(const double insulinAmount)
{
	HormoneDose *dose = new HormoneDose(BOLUS_INSULIN, insulinAmount);
	output->sendInstruction(dose);
    delete dose;
}
