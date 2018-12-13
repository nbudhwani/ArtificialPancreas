#include "main.h"

int main(void)
{
	HormoneDose * h = new HormoneDose(GLUCAGON, 15.0);

	LaptopOutput * lo = new LaptopOutput("127.0.0.1", 3307);
	lo->sendInstruction(h);

	h->setHormoneType(BASAL_INSULIN);
	h->setHormoneAmount(9.0);

	sleep(5);
	lo->sendInstruction(h);
	
	delete(h);
	delete(lo);
}
