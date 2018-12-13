#ifndef PATIENTFACTORY_H
#define PATIENTFACTORY_H

#include "PatientInfo.h"

class PatientFactory
{
    public:
        PatientInfo* makePatient();
};

#endif