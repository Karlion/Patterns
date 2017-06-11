#include "stdafx.h"
#include"catch.hpp"

#define protected public
#define private public
#include"../Task 18 (Strategy)/Strategy.h"

TEST_CASE("Test Strategy Pattern") {
	Unit orc("Orc");
	Unit elf("Elf");
	Unit troll("Troll");

	orc.setStrategy(new Fly());
	REQUIRE(orc.moveStrategy() == "Orc: I can fly");

	troll.setStrategy(new Fly());
	REQUIRE(troll.moveStrategy() == "Troll: I can fly");

	orc.setStrategy(new Walk());
	REQUIRE(orc.moveStrategy() == "Orc: I can walk");

	elf.setStrategy(new Walk());
	REQUIRE(elf.moveStrategy() == "Elf: I can walk");
}