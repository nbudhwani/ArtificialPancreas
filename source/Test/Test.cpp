#include "Test.h"


TestResult Test::runAndPrint()
{
    TestResult tr = this->runTest();
    
    std::cout << "Running Test: " << this->name << std::endl;
    std::cout << tr.toString() << std::endl;

    return tr;
}

std::string Test::getName() const
{
    return this->name;
}

void Test::setName(std::string name)
{
    this->name = name;
}