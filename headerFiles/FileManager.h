/**
*	\author Graeme Brabers
*	\brief Header file for the FileManager class
*	Contains File I/O information for serialization of PatientInfo objects
*/

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Contact.h"
#include "DeviceRecord.h"
#include "HormoneDose.h"
#include "MedicationRecord.h"
#include "MonitorRecord.h"
#include "PatientInfo.h"

class FileManager
{
    public:
        /**
         *  \name FileManager
         *  \brief Default constructor
         * */
        FileManager();

        /**
         * \name ~FileManager
         * \brief Default destructor
         * */
        ~FileManager();
        
        /**
         *  \name checkForPatientFile
         *  \brief checks if patient file exists
         *  \return boolean value indicating presence of file
         * */
        bool checkForPatientFile();

        /**
         *  \name readFromFile
         *  \brief Loads data from file into PatientInfo object
         *  \return Created PatientInfo object
         * */
        PatientInfo * readFromFile();
        
        /**
         *  \name writeToFile
         *  \brief Writes PatientInfo object to file
         *  \param Pointer to PatientInfo object
         * */
        void writeToFile(PatientInfo *);
    private:
        //streams for file io
        ifstream inFile;
        ofstream outFile;
};

#endif
