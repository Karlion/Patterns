#include<iostream>
#include<string>
using namespace std;
class Singleton
{
	Singleton();
	static Singleton* member;
	string check;
public:
	static Singleton* Get();
	string getCheck();
};

Singleton*Singleton::member = nullptr;


Singleton*Singleton::Get()
{
	if (!member)
		member = new Singleton;
	return member;
}

Singleton::Singleton(){
	check = "Singleton was created";
}


string Singleton::getCheck(){
	return check;
}