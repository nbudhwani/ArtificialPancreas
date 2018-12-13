#ifndef REPORTMAKER_H
#define REPORTMAKER_H

#include <string>

#include "GraphMaker.h"
#include "PatientInfo.h"
#include "LatexHelper.h"
#include "ReportHelper.h"
/** \class ReportMaker
 * \brief Makes a pdf report documenting a patient's health over a week. 
 * 
 * Reports are made by outputting to LaTex, using the graph created by graphmaker.
*/
class ReportMaker
{
    public:
        std::string makeReport(
            /// the patient whose data will be graphed
            PatientInfo* patient, 
            /// the graphmaker which will be used to graph the patient data
            GraphMaker graphMaker, 
            /// latex template file to generate the doc with.
            std::string templateFile = "base/reports/report01");
};

#endif