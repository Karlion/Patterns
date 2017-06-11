#include "stdafx.h"
#include"catch.hpp"


#define private public
#define protected public
#include"../Task 1 (SortPack)/SortPack.h"
namespace UnitTest
{
	TEST_CASE("Bubble Sort")
	{
		ArrayOfInt a(10);
		SortPack pb;
		a.fill();
		pb.attach(a);
		pb.bubble();
		REQUIRE(pb.isSorted());
	}
	TEST_CASE("Shell Sort")
	{
		ArrayOfInt a(10);
		SortPack pb;
		a.fill();
		pb.attach(a);
		pb.shell();
		REQUIRE(pb.isSorted());
	}
	TEST_CASE("Quick Sort")
	{
		ArrayOfInt a(10);
		SortPack pb;
		a.fill();
		pb.attach(a);
		pb.quick();
		REQUIRE(pb.isSorted());
	}
	TEST_CASE("Insert Sort")
	{
		ArrayOfInt a(10);
		SortPack pb;
		a.fill();
		pb.attach(a);
		pb.insert();
		REQUIRE(pb.isSorted());
	}
}