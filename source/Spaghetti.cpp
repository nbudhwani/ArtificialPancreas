#include "Spaghetti.h"

PatientInfo* Spaghetti::makePatient()
{
    std::string name = "Tortellini Linguini";
    std::string sex = "sphaghettini";
    int age = 41;
    double weight = 741;
    double height = 167;
    std::string email = "pastafarianPrincess@ragu.fart";

    PatientInfo* patient = new PatientInfo(name, age, sex, weight, height, email);

    std::vector<MonitorRecord> *glucoseRecords = patient->getMonitorRecords();
    std::vector<MedicationRecord> *insulinRecords = patient->getMedicationRecords();

    std::ifstream glucoseDataStream;
        glucoseDataStream.open("base/patientData/glucose23340.dat");
    std::ifstream insulinDataStream("base/patientData/insulin23340.dat");
    std::time_t timeSetting = std::time(NULL) -24*60*60;

    // read in glucose records to patient
    while ( !(glucoseDataStream >> std::ws).eof() )
    {
        
        double glucose=0;
        double hour=0;

        glucoseDataStream >> hour >> glucose; 
        std::time_t currentTime = (std::time_t)(timeSetting + hour*60*60);

        glucoseRecords->push_back(MonitorRecord(currentTime, GlucoseReading(glucose)));
    }

    // read in insulin records to patient
    while ( !(insulinDataStream >> std::ws).eof() )
    {
        
        double hour = 0;
        double insulin = 0;

        insulinDataStream >> hour >> insulin;
        std::time_t currentTime = (std::time_t)(timeSetting + hour*60*60);

        insulinRecords->push_back(
            MedicationRecord(
                currentTime,
                HormoneDose(
                    hormoneType::BASAL_INSULIN, 
                    insulin)));
    }

    return patient;
}