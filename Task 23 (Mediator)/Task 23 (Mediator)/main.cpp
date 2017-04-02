#include "Mediator.h"
using namespace std;

int main()
{
	ConcreteMediator m;

	ConcreteColleague1 c1(&m);
	ConcreteColleague2 c2(&m);

	m.SetColleague1(&c1);
	m.SetColleague2(&c2);
	c1.Send("How are you?");
	c2.Send("Fine, thanks");

	system("pause");
	return 0;
}