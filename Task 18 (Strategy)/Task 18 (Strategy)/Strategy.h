#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class IStrategy {
public:
	virtual string action() = 0;
};

class Walk : public IStrategy {
public:
	string action();
};

class Fly : public IStrategy {
public:
	string action();
};

class GameUnit
{
protected:
	IStrategy* strategy;
public:
	virtual string moveStrategy() = 0;
	void setStrategy(IStrategy*);
};

class Unit : public GameUnit {
public:
	string name;
	Unit(string name);
	string moveStrategy();
};

string Walk::action()	{
	cout << "I can walk\n";
	return "I can walk";
}

string Fly::action() {
	cout << "I can fly\n";
	return "I can fly";
}

Unit::Unit(string name) {
	this->name = name;
}

string Unit::moveStrategy() {
	return name + ": " + strategy->action();
}

void GameUnit::setStrategy(IStrategy* strategy) {
	this->strategy = strategy;
}