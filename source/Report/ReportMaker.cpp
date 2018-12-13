#include "ReportMaker.h"

std::string ReportMaker::makeReport(
    PatientInfo *patient,
    GraphMaker graphMaker,
    std::string templateFile)
{
    /**
     * Method:
     * Dynamically alter contents for use in latex by adding
     * a list of commands to include before the file.
     * */
    

    DataSet glucoseData;
    for (auto& record : *(patient->getMonitorRecords()) )
    {
        glucoseData.push_back(
            DataPoint(record.getRecordTime(), 
            record.getReading().getAmount()));
    }

    XType glucoseTMax = glucoseData.back().first;
	XType glucoseTMin = glucoseData.back().first;
	
    // get the max and min times to construct XRange
	for (auto & point : glucoseData)
	{
		if (point.first < glucoseTMin)
		{
			glucoseTMin = point.first;
		}
		else if (point.first > glucoseTMax)
		{
			glucoseTMax = point.first;
		}
	}
    if (glucoseTMax - glucoseTMin < 100)
    {
        std::cerr << "need longer sample time" << std::endl;
        return "";
    }
    XRange xrange(glucoseTMin, glucoseTMax);
    YRange yrange(0, 230);
    
    // push all the medication Records from patient to  
    DataSet insulinData;
    for (auto& record : *(patient->getMedicationRecords()) )
    {
        insulinData.push_back(
            DataPoint(record.getRecordTime(), 
            record.getHormoneDose().getHormoneAmount()));
    }

    XType insulinTMax = insulinData.back().first;
	XType insulinTMin = insulinData.back().first;
	
    // get the max and min times for insulin data for insulin graph
	for (auto & point : insulinData)
	{
		if (point.first < insulinTMin)
		{
			insulinTMin = point.first;
		}
		else if (point.first > insulinTMax)
		{
			insulinTMax = point.first;
		}
	}

    // make the graphs
    std::string glucoseGraphName = graphMaker.makeGraph(
        XRange(glucoseTMin, glucoseTMax),
        YRange(0,250),
        glucoseData,
        "Glucose_Graph",
        "",
        ReportHelper::Graph::GLUCOSE);
    std::string insulinGraphName = graphMaker.makeGraph(
        XRange(insulinTMin,insulinTMax),
        YRange(0,250),
        insulinData,
        "Insulin_Graph",
        "",
        ReportHelper::Graph::INSULIN);
    
    std::string commandDefinitions =  
        LatexHelper::newCommand("patientName", patient->getName()) 
        + LatexHelper::newCommand("patientWeight", std::to_string(patient->getWeight()))
        + LatexHelper::newCommand("patientHeight", std::to_string(patient->getHeight()))
        + LatexHelper::newCommand("patientAge", std::to_string(patient->getAge()) )
        + LatexHelper::newCommand("patientSex", patient->getSex())
        + LatexHelper::newCommand("patientGlucoseGraph", glucoseGraphName)
        + LatexHelper::newCommand("patientInsulinGraph", insulinGraphName);
    std::string inputCommand = LatexHelper::input(templateFile);
    std::string reportName = "report"+ std::to_string(std::time(NULL));
    std::string reportDirectory = "build/output";
    
    std::string options = 
        "-jobname " + reportName
        + " -output-directory " + reportDirectory;
    
    std::string command = 
        "pdflatex " 
        + options 
        + " \"" + commandDefinitions + inputCommand + "\"";
    std::cerr << command << std::endl;

    system(command.c_str());
    
    return reportDirectory + "/" + reportName + ".pdf";  
}
