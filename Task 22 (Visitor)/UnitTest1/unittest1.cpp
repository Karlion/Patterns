#include "stdafx.h"
#include "catch.hpp"


#define protected public;
#define private public;

#include"../Task 22 (Visitor)/Visitor.h"

namespace UnitTest
{		
	TEST_CASE("Tesing Visitor")
	{
		Visitor *vis = new ConcreteVisitor;
		Square *sq = new Square(10);
		Triangle *tr = new Triangle(3, 4, 5);
		REQUIRE(12 == tr->accept(vis));
		REQUIRE(40 == sq->accept(vis));
	}
}