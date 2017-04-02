#include "stdafx.h"
#include "catch.hpp"
#include"../Task 23 (Mediator)/Mediator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CASE("Testing Mediator")
	{
		ConcreteMediator m;

		ConcreteColleague1 c1(&m);
		ConcreteColleague2 c2(&m);

		m.SetColleague1(&c1);
		m.SetColleague2(&c2);
		c1.Send("How are you?");
		REQUIRE(m.getmess2==true);
		REQUIRE(m.getmess1 == false);
		c2.Send("Fine, thanks");
		REQUIRE(m.getmess2 == true);
		REQUIRE(m.getmess1 == true);
	}
}