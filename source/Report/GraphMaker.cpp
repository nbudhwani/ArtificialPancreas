/**
 * \file GraphMaker.h
 * \author Thomas Vandeven
 * */

#include "GraphMaker.h"


std::string GraphMaker::makeGraph(
    XRange xrange, 
    YRange yrange, 
    DataSet data, 
    std::string title, 
    std::string extraOptions, 
    std::string gnuFile)
{

    int toGnuPlot[2];
    if (pipe(toGnuPlot)!= 0)
        return "";
    
    std::string commands = 
        "set xtics " 
        + std::to_string((std::time_t)std::difftime(xrange.second, xrange.first)/40) + ";"
        + "set xrange ["+
            std::to_string(xrange.first) 
            + ":"
            + std::to_string(xrange.second) 
        + "];" + extraOptions + ";";


    std::string graphFileName = 
        "build/output/graph" + 
        (title != "" ? "_" + title + "_" : "") 
        + std::to_string(std::time(NULL)) + std::to_string((int)data.back().second);

    // open the picture file we will save the graph to
    FILE* pic = fopen( (graphFileName + ".png").c_str(), "w");

    // open the write end of the pipe as a FILE* stream
    FILE* toGnuPlotFile = fdopen(toGnuPlot[1], "w");
    
    for (auto& point : data)
    {
        std::fprintf(toGnuPlotFile, "%d %lf\n", (int)point.first, (double)point.second);
    }
    fclose(toGnuPlotFile);
    
    pid_t pid = fork();
    
    if (pid == 0)
    {   
        dup2(toGnuPlot[0], STDIN_FILENO);
        dup2(fileno(pic), STDOUT_FILENO);
        
        execlp("gnuplot", 
            "gnuplot", "-e", commands.c_str(), gnuFile.c_str(), 
            NULL);
        std::cerr << "this line should never be reached" << std::endl;
        std::exit(1);
    }
    else
    {
        wait(NULL); // wait for child to exit
        dup2(STDOUT_FILENO, STDOUT_FILENO);
    }

    close(toGnuPlot[0]);
    fclose(pic);

    return graphFileName;
}