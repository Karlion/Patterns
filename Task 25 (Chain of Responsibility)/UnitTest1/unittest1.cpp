#include "stdafx.h"
#include "catch.hpp"

#include"../Task 25 (Chain of Responsibility)/Bank.h"

TEST_CASE("Testing Normal")
{
	Fix root;
	Control snd;
	TakePercent trd;
	GiveBonus fth;

	root.add(&snd);
	root.add(&trd);
	root.add(&fth);

	fth.setNext(&root);

	Payment A(1, 100, "Name");
	root.handle(&A);
	REQUIRE("Name" == A.getClient());
	REQUIRE("Normal" == A.fixed);
	REQUIRE("Normal" == A.controlled);
	REQUIRE(A.getSum() == int(100*0.95*1.02));
}
TEST_CASE("Testing Internal")
{
	Fix root;
	Control snd;
	TakePercent trd;
	GiveBonus fth;

	root.add(&snd);
	root.add(&trd);
	root.add(&fth);

	fth.setNext(&root);

	Payment A(2, 100, "Name");
	root.handle(&A);
	REQUIRE("Name" == A.getClient());
	REQUIRE("Internal" == A.fixed);
	REQUIRE("Internal" == A.controlled);
	REQUIRE(A.getSum() == int(100 * 0.96*1.03));
}
TEST_CASE("Testing State")
{
	Fix root;
	Control snd;
	TakePercent trd;
	GiveBonus fth;

	root.add(&snd);
	root.add(&trd);
	root.add(&fth);

	fth.setNext(&root);

	Payment A(3, 100, "Name");
	root.handle(&A);
	REQUIRE("Name" == A.getClient());
	REQUIRE("State" == A.fixed);
	REQUIRE("State" == A.controlled);
	REQUIRE(A.getSum() == int(100 * 0.97*1.04));
}
TEST_CASE("Preferential")
{
	Fix root;
	Control snd;
	TakePercent trd;
	GiveBonus fth;

	root.add(&snd);
	root.add(&trd);
	root.add(&fth);

	fth.setNext(&root);

	Payment A(4, 100, "Name");
	root.handle(&A);
	REQUIRE("Name" == A.getClient());
	REQUIRE("Preferential" == A.fixed);
	REQUIRE("Preferential" == A.controlled);
	REQUIRE(A.getSum() == int(100 * 0.98*1.05));
}