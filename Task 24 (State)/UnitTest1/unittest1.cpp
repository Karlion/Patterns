#include "stdafx.h"
#include "catch.hpp"

#define protected public
#define private public
#include"../Task 24 (State)/State.h"


namespace UnitTest
{		
	TEST_CASE("Test Grant")
	{
		Grant* grant = new Grant("myGrant");
		string check = "myGrant";
		REQUIRE(check == grant->name);
		grant->setState(new Created(grant));
		check = "Grant is created";
		REQUIRE(check == grant->state->showStatus());
		grant->setState(new Canceled(grant));
		check = "Grant is canceled";
		REQUIRE(check == grant->state->showStatus());
		grant->setState(new Declined(grant));
		check = "Grant is declined";
		REQUIRE(check == grant->state->showStatus());
		grant->setState(new Considered(grant));
		check = "Grant is considered";
		REQUIRE(check == grant->state->showStatus());
		grant->setState(new Accepted(grant));
		check = "Grant is accepted";
		REQUIRE(check == grant->state->showStatus());
	}
	TEST_CASE("Test accepted")
	{
		Grant* grant = new Grant("grant");
		Accepted* accept = new Accepted(grant);
		string toCheck = "grant";
		REQUIRE(toCheck == accept->grant->name);
		REQUIRE("Grant is accepted" == accept->showStatus());
	}
	TEST_CASE("Test declined")
	{
		Grant* grant = new Grant("grant");
		Declined* accept = new Declined(grant);
		string toCheck = "grant";
		REQUIRE(toCheck == accept->grant->name);
		REQUIRE("Grant is declined" == accept->showStatus());
	}
	TEST_CASE("Test created")
	{
		Grant* grant = new Grant("grant");
		Created* accept = new Created(grant);
		string toCheck = "grant";
		REQUIRE(toCheck == accept->grant->name);
		REQUIRE("Grant is created" == accept->showStatus());
	}
	TEST_CASE("Test considered")
	{
		Grant* grant = new Grant("grant");
		Considered* accept = new Considered(grant);
		string toCheck = "grant";
		REQUIRE(toCheck == accept->grant->name);
		REQUIRE("Grant is considered" == accept->showStatus());
	}
	TEST_CASE("Test canceled")
	{
		Grant* grant = new Grant("grant");
		Canceled* accept = new Canceled(grant);
		string toCheck = "grant";
		REQUIRE(toCheck == accept->grant->name);
		REQUIRE("Grant is canceled" == accept->showStatus());
	}
}