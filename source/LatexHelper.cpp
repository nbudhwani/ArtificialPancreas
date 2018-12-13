#include "LatexHelper.h"

std::string LatexHelper::newCommand(std::string command, std::string definition)
{
    return "\\newcommand{\\" + command + "}{" + definition + "}";
}

std::string LatexHelper::header()
{
    return "\\documentclass{article}\n";
}

std::string LatexHelper::begin(std::string environment)
{
    return "\\begin{" + environment + "}";
}

std::string LatexHelper::end(std::string environment)
{
    return "\\end{" + environment + "}";
}

std::string LatexHelper::environment(std::string environment, std::string text)
{
    return 
        begin(environment) + "\n"
        + text + "\n"
        + end(environment);
}

std::string LatexHelper::input(std::string inputFile)
{
    return "\\input{" + inputFile + "}";
}