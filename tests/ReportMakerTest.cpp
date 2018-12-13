#include "libPancreas.h"

int main(int argc, char **argv)
{
    PatientInfo* spaghetti = Spaghetti().makePatient();
	
	// instantiate graphMaker
	GraphMaker graphMaker;
    
	// instantiate reportMaker
	ReportMaker reportMaker;

	// make the report
	std::string reportLocation = reportMaker.makeReport(spaghetti, graphMaker);

	// talk about it.
	std::cerr << "Done making report. Stored in:\t\v"<< reportLocation << std::endl;

    return 0;
}

