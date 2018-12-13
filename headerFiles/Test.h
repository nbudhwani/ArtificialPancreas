#ifndef TEST_H
#define TEST_H

#include "TestResult.h"
#include <iostream>
#include <string>
/** Test class

    Test Class is meant to be subclassed where the user overrides runTest
*/
class Test 
{
    public:
        virtual TestResult runTest() = 0;
        TestResult runAndPrint();
        std::string getName() const;
        void setName(std::string);
    private:
        std::string name;
};


#endif
