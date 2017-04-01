#include "stdafx.h"
#include"catch.hpp"


#define private public
#define protected public
#include"../Task 16 (Decorator)/Decorator.h"

namespace UnitTest
{
	TEST_CASE("Check adding chocolate")
	{
		AddChocolate *full = new AddChocolate(new AddCream(new Pancake, "oil cream"), "milk chocolate");
		string check = "milk chocolate";
		REQUIRE(check == full->chocolate);
		full = new AddChocolate(new AddCream(new Pancake, "oil cream"), "white chocolate");
		check = "white chocolate";
		REQUIRE(check == full->chocolate);
	}
	TEST_CASE("Check adding cream")
	{
		AddCream *creamy = new AddCream(new Pancake, "oil cream");
		string check = "oil cream";
		REQUIRE(check == creamy->cream);
		creamy = new AddCream(new Pancake, "custard");
		check = "custard";
		REQUIRE(check == creamy->cream);
	}
}