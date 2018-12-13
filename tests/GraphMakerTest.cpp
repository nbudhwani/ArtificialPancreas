#include "libPancreas.h"

DataPoint gen_point(std::time_t anchor, std::time_t timeAgo, int i)
{
    // seconds into the past which point lies 
    
    return  DataPoint(
        (XType) (anchor - timeAgo), 
        (YType) std::sin(0.2*i));
}

DataSet gen_dataset(XRange xrange, YRange yrange)
{
    int numPoints = 100;
    DataSet data;

    std::time_t currentTime = xrange.second;
    std::time_t timeAgo = (std::time_t)std::difftime(xrange.second, xrange.first)/100;
    std::time_t anchor = currentTime - timeAgo*numPoints;
    
    for (int i =0; i < numPoints; i++)
    {
        DataPoint d = gen_point(anchor, -i*timeAgo, i);
        data.push_back(d);
    }
    return data;
}

int main(int argc, char** argv)
{
    PatientInfo* spaghetti = Spaghetti().makePatient();

    vector<MonitorRecord>* records = spaghetti->getMonitorRecords();
    
    // data to fill in
    DataSet data;
 
    
    for (auto& record: *records)
    {
        data.push_back(DataPoint(
            (XType)record.getRecordTime(), 
            (YType)record.getReading().getAmount()));
    }
    
    XType max = data.back().first;
    XType min = data.back().first;

    for (auto & point : data)
    {
        if ( max < point.first )
        {
            max = point.first;
        }
        else if (min > point.first)
        {
            min = point.first;
        }
    }

    GraphMaker graphMaker;

    // make the graph
    XRange xrange(min, max);
    YRange yrange(0,250);
    std::string graphname = graphMaker.makeGraph(xrange, yrange, data);
    
    // tell us about it
    std::cout << "Made graph. Stored in:\t\v" << graphname << std::endl;
    
    return 0;
}