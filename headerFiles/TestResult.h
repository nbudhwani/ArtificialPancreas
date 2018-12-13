#ifndef TESTRESULT_H
#define TESTRESULT_H

#include "TestValue.h"
#include <sstream>

class TestResult
{
    public:
        TestResult(const TestValue, const std::string);
        TestValue getValue() const;
        std::string getMessage() const;
        std::string toString() const;
    private:
        const std::string message;
        const TestValue value;
};

#endif
