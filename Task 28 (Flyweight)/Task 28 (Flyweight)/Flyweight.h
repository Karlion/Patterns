#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Bacteria
{
protected:
	string name, colony;
	int age, size;
public:
	virtual void show() = 0;

};

class BacteriaFactory
{
private:
	unordered_map<string, Bacteria*> bact;
public:
	Bacteria &getBacteria(string name, int age, int size);
};

class BacteriaPersonality :public Bacteria
{
public:
	BacteriaPersonality(string name, int age, int size);
	virtual void show();
};


BacteriaPersonality::BacteriaPersonality(string _name, int _age, int _size)
{
	this->colony = "Assassin colony";
	this->name = _name;
	this->age = _age;
	this->size = _size;
};

void BacteriaPersonality::show()
{
	cout << name << " is " << age << " days old, size: " << size << "mm from " << colony << endl;
}

Bacteria &BacteriaFactory::getBacteria(string name, int age, int size)
{
	unordered_map<string, Bacteria*>::iterator it;
	it = bact.find(name);
	if (it == bact.end())
	{
		Bacteria* temp = new BacteriaPersonality(name, age, size);
		bact[name] = temp;
		return *temp;
	}
	else return *it->second;
}