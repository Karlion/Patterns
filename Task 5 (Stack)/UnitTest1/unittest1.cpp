#include "stdafx.h"
#include "catch.hpp"
#include"../Task 5 (Stack)/Stack.h"


namespace UnitTest
{		
	TEST_CASE("Checking push()")
	{
		Stack<int> s;
		for (int i = 0; i < 10; i++)
		{
			s.push(i);
			REQUIRE(s.top() == i);
		}
	}

	TEST_CASE("Cheking empty()")
	{
		Stack<int> s;
		REQUIRE(s.empty() == true);
		s.push(1);
		REQUIRE(s.empty() == false);
	}

	TEST_CASE("Checking pop()")
	{
		Stack<int> s;
		REQUIRE_THROWS(s.pop());
		for (int i = 0; i < 10; i++) s.push(i);
		for (int i = 9; i >0; i--)
		{
			s.pop();
			REQUIRE(s.top() == i - 1);
		}

	}
}