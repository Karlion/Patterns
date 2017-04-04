#include"State.h"

void main()
{
	Grant* grant = new Grant("MyGrant");
	cout<<grant->state->showStatus()<<endl;
	grant->nextState();
	cout<<grant->state->showStatus()<<endl;
	grant->nextState();
	cout<<grant->state->showStatus()<<endl;
	grant->setState(new Canceled(grant));
	cout<<grant->state->showStatus()<<endl;
	grant->nextState();
	system("pause");
}