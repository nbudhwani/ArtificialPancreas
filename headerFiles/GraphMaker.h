/**\file GraphMaker.h
 * Author:  Thomas Vandeven
 * Date:    November 7th 2018
 * 
 * GraphMaker Produces graphs given xrange, yrange and a set of data.
 * */

#ifndef GRAPHMAKER_H
#define GRAPHMAKER_H



#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <sys/wait.h>

#include "ReportHelper.h"

typedef std::time_t XType;
typedef double YType;
typedef std::pair<XType, XType> XRange;
typedef std::pair<YType, YType> YRange;
typedef std::pair<XType, YType> DataPoint;
typedef std::vector<DataPoint> DataSet;

/**! A class for generating graphs of patient data
 *  
 * Uses GnuPlot to generate graphs of class data.
 * */
class GraphMaker
{
    public:
        /// Make a graph of patient data. date/time on the x-axis, float on the y-axis.
        ///
        /// Makes double/time graphs, used to create the graphs in reportmaker 
        /// such as the graph of insulin doses over time and glucose measurements over time.
        /// execs gnuplot and pipes in a custom graph file, which can be customized.
        /// uses Xrange and Yrange to set corresponding values in the graph,
        /// for example, to make the range as some particular week in the life of the patient.
        ///
        /// If more customized graph printing is needed, you can create a custom gnuplot file,
        /// adding it to the base directory and calling it by name.
        std::string makeGraph(
            /// XRange to filter out data
            XRange xrange,
            /// YRange to filter out data from
            YRange yrange,
            /// the actual data which will be graphed
            DataSet data,
            /// title for the graph, used in the file name.
            std::string title = "",
            /// extra gnuplot options to add to the script. defaults to empty
            std::string extraOptions = "",
            /// datafile to customize gnuplot output of the graph.
            std::string gnuFile = "base/graphing/basicgraph.gnu"); 
};

#endif