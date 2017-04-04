#include<iostream>
#include<string>
#include <ctime>

using namespace std;

class State;

class Grant
{
public:
	State*state;
	string name;
	Grant(string _name);
	void nextState();
	void setState(State*s);
};
class State
{
protected:
	Grant *grant;
public:
	virtual void setNextStatus() = 0;
	virtual string showStatus() = 0;
};
class Created :public State
{
public:
	Created(Grant*_grant) {this->grant = _grant; };
	virtual void setNextStatus();
	virtual string showStatus();

};
class Declined :public State
{
public:
	Declined(Grant *_grant){ this->grant = _grant; };
	virtual void setNextStatus();
	virtual string showStatus();
};
class Canceled :public State
{
public:
	Canceled(Grant*_grant){ this->grant = _grant; };
	virtual void setNextStatus();
	virtual string showStatus();
};
class Accepted : public State
{
public:
	Accepted(Grant*_grant){ this->grant = _grant; };
	virtual void setNextStatus();
	virtual string showStatus();
};
class Considered :public State
{
public:
	Considered(Grant *_grant){ this->grant = _grant; };
	virtual void setNextStatus();
	virtual string showStatus();
};

Grant::Grant(string _name) :name(_name){ 
	state = new Created(this);
}
void Grant::nextState(){
	this->state->setNextStatus();
}
void Grant::setState(State*s){
	state = s;
}

void Created::setNextStatus(){
	grant->setState(new Considered(grant));
}
string Created::showStatus(){
	string temp = "Grant is created";
	return temp;
}

void Declined::setNextStatus(){
	cout << "No next status, grant was declined\n";
}
string Declined::showStatus(){
	string temp = "Grant is declined";
	return temp;
}

void Canceled::setNextStatus(){
	cout << "No next status\n";
}
string Canceled::showStatus(){
	string temp = "Grant is canceled";
	return temp;
}

void Accepted::setNextStatus(){
	cout << "No next status, grant was accepted\n";
}
string Accepted::showStatus(){
	string temp = "Grant is accepted";
	return temp;
}

void Considered::setNextStatus(){
	srand(time(0));
	int temp = rand() % 2;
	if (temp)
		grant->setState(new Accepted(grant));
	else grant->setState(new Declined(grant));
}
string Considered::showStatus(){
	string temp = "Grant is considered";
	return temp;
}