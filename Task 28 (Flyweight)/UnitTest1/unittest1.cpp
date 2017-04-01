#include "stdafx.h"
#include"catch.hpp"

#define protected public
#define private public
#include"../Task 28 (Flyweight)/Flyweight.h"

namespace UnitTest
{
	TEST_CASE("Add Bacteria")
	{
		BacteriaFactory myFactory;
		REQUIRE(myFactory.bact.size() == 0);
		Bacteria& First = myFactory.getBacteria("Bartonella", 30, 40);
		REQUIRE(myFactory.bact.size() == 1);
		Bacteria& FirstCopy = myFactory.getBacteria("Bartonella", 30, 40);
		REQUIRE(myFactory.bact.size() == 1);
	}
}