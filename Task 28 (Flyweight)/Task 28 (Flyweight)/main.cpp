#include "Flyweight.h"

int main()
{
	BacteriaFactory bactFactory;
	Bacteria& First = bactFactory.getBacteria("Acholeplasma modicum", 30, 40);
	First.show();
	Bacteria& Second = bactFactory.getBacteria("Bartonella", 20, 10);
	Second.show();
	Bacteria& Third = bactFactory.getBacteria("Curtobacterium saperdae", 2, 6);
	Third.show();
	Bacteria& FirstCopy = bactFactory.getBacteria("Acholeplasma modicum", 30, 40);
	FirstCopy.show();
	system("pause");
}