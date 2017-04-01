#include "stdafx.h"
#include"catch.hpp"
#include"../Task 27 (Singleton)/Singleton.h"

namespace UnitTest
{
	TEST_CASE("Check creating Singleton")
	{
		Singleton *example = Singleton::Get();
		string temp = example->getCheck();
		REQUIRE("Singleton was created" == temp);
	}
}