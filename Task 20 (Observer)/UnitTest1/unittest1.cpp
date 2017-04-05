#include "stdafx.h"
#include "catch.hpp"

#define private public
#define protected public
#include"../Task 20 (Observer)/Observer.h"

namespace UnitTest
{		
	TEST_CASE("Test Post")
	{
		Post post;
		string subName = "Luna Lovegood", newspaper = "Quibbler";
		SubObserver sub(&post, newspaper, subName);
		post.setNewspapersName(newspaper);
		REQUIRE(post.subs[0]->subscribed == subName);
		REQUIRE(post.getName() == newspaper);
	}
}