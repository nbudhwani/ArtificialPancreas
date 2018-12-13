#include "PatientInfo.h"
#include "FileManager.h"

int main()
{
    PatientInfo *p;
    FileManager *fm = new FileManager();
    if(fm->checkForPatientFile())
    {
        p = fm->readFromFile();
        p->getMonitorRecords()->push_back(MonitorRecord(std::time(NULL), GlucoseReading(17.0)));
        p->getMedicationRecords()->push_back(MedicationRecord(std::time(NULL), HormoneDose(BASAL_INSULIN, 17)));
    }
    else
    {
        p = new PatientInfo();        
    }
    fm->writeToFile(p);
    delete fm;
    delete p;


    return 0;
}
