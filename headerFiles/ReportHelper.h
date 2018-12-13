/**
 * \brief Helper for report maker
 * \author Group 22
 * 
 * This class helps make reports
 *
 */

#ifndef REPORTHELPER_H
#define REPORTHELPER_H

#include <string>

/// namespace to provide easy access fields when making Reports and Graphs
namespace ReportHelper
{
    /// A container for graph related strings
    ///
    /// Contains graph related strings such as the root path 
    /// and each of the distinct gnuplot files
    namespace Graph
    {
        /// base direcotry where gnuplot files are stored
        const std::string ROOT_PATH = "base/graphing/";
        /// path to the basicgraph
        const std::string BASIC     = ROOT_PATH + "basicgraph.gnu";
        /// path to the glucose graph file
        const std::string GLUCOSE   = ROOT_PATH + "glucosegraph.gnu";
        /// path to the Insulin graph file
        const std::string INSULIN   = ROOT_PATH + "insulingraph.gnu";
    }
    
};



#endif