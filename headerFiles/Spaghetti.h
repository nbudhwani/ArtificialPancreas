#ifndef SPAGHETTI_H
#define SPAGHETTI_H

#include "PatientFactory.h"
#include <iostream>
#include <fstream>

class Spaghetti : public PatientFactory
{
    public:
        PatientInfo* makePatient();
};

#endif
