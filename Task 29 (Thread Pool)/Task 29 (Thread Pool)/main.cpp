#include <iostream>
#include <thread>
#include <random>
#include <chrono>
#include <string>

#include "ThreadPool.h"

using namespace std;

double foo()
{
	return 14.5;
}

int sum(int a, int b)
{
	return a + b;
}

int main()
{
	ThreadPool pool;


	auto r1 = pool.runAsync<double>(&foo);
	auto r2 = pool.runAsync<int>(&sum, 100, 54);
	auto r3 = pool.runAsync<bool>([](){ return true; });

	while (!r1->ready); 
	std::cout << r1->data << std::endl;
	while (!r2->ready);
	std::cout << r2->data << std::endl;
	while (!r3->ready);
	std::cout << r3->data << std::endl;

	system("pause");
	return 0;
}