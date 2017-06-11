#include "stdafx.h"
#include "catch.hpp"
#include"../Task 29 (Thread Pool)/ThreadPool.h"


double foo()
{
	return 14.5;
}

int sum(int a, int b)
{
	return a + b;
}


TEST_CASE("Thread Pool testing")
{
	ThreadPool pool;


	auto r1 = pool.runAsync<double>(&foo);
	auto r2 = pool.runAsync<int>(&sum, 100, 54);
	auto r3 = pool.runAsync<bool>([](){ return true; });
	REQUIRE(r1->data == 14.5);
	REQUIRE(r2->data == 154);
	REQUIRE(r3->data);
}