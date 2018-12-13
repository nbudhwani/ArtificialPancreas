#include "ArtificialPancreas.h"
#include "GlucoseMonitor.h"
#include <thread>

int main()
{
    ArtificialPancreas *artificialPancreas = new ArtificialPancreas();
	GlucoseMonitor *glucoseMonitor = new GlucoseMonitor();

	std::thread t1(&GlucoseMonitor::listen, glucoseMonitor, artificialPancreas);
	t1.join();
}