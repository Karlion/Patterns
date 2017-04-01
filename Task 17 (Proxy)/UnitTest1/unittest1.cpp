#include "stdafx.h"
#include"catch.hpp"
#include<algorithm>


#define private public
#define protected public
#include"../Task 17 (Proxy)/Proxy.h"

namespace UnitTest1
{		
	TEST_CASE("Check selection sort")
	{
		ISortings *sortings = new Sortings;
		ISortings *proxy = new ProxySortings(sortings);
		vector<double> mas1{ 4, 245, 35, 5, 2, 65, 2, 6 },
			mas2{ 21, 4, 12, 55, 3, 6, 23, 6, 23, 4, 66, 4 };
		vector<double>temp = mas1;
		sort(temp.begin(), temp.end());
		REQUIRE(temp == proxy->selection(mas1));
		temp = mas2;
		sort(temp.begin(), temp.end());
		REQUIRE(temp == proxy->selection(mas2));
	}
	TEST_CASE("Check bubble sort")
	{
		ISortings *sortings = new Sortings;
		ISortings *proxy = new ProxySortings(sortings);
		vector<double> mas1{ 4, 245, 35, 5, 2, 65, 2, 6 },
			mas2{ 21, 4, 12, 55, 3, 6, 23, 6, 23, 4, 66, 4 };
		vector<double>temp = mas1;
		sort(temp.begin(), temp.end());
		REQUIRE(temp == proxy->bubble(mas1));
		temp = mas2;
		sort(temp.begin(), temp.end());
		REQUIRE(temp == proxy->bubble(mas2));
	}
	TEST_CASE("Check shaker sort")
	{
		ISortings *sortings = new Sortings;
		ISortings *proxy = new ProxySortings(sortings);
		vector<double> mas1{ 4, 245, 35, 5, 2, 65, 2, 6 },
			mas2{ 21, 4, 12, 55, 3, 6, 23, 6, 23, 4, 66, 4 };
		vector<double>temp = mas1;
		sort(temp.begin(), temp.end());
		REQUIRE(temp == proxy->shaker(mas1));
		temp = mas2;
		sort(temp.begin(), temp.end());
		REQUIRE(temp == proxy->shaker(mas2));
	}
}