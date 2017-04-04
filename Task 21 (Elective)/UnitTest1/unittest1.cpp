#include "stdafx.h"
#include"catch.hpp"


#define private public
#define protected public
#include"../Task 21 (Elective)/Elective.h"

namespace UnitTest
{
	TEST_CASE("Test lecturer")
	{
		Archive *arc = new Archive;
		Course *math = new MathCourse;
		Course *eng = new EnglishCourse;
		Lecturer *l1 = new Lecturer("Petro Petrovych", arc);
		Lecturer *l2 = new Lecturer("Ivan Ivanovych", arc);
		l1->addCourse(math);
		l2->addCourse(eng);
		REQUIRE("Petro Petrovych" == l1->name);
		REQUIRE("Ivan Ivanovych" == l2->name);
		REQUIRE("Mathematical analysis" == l1->courses[0]->getName());
		REQUIRE("English" == l2->courses[0]->getName());
	}
	TEST_CASE("Test stusent")
	{
		Archive *arc = new Archive;
		Course *math = new MathCourse;
		Course *eng = new EnglishCourse;
		Lecturer *l1 = new Lecturer("Petro Petrovych", arc);
		Lecturer *l2 = new Lecturer("Ivan Ivanovych", arc);
		Student *st1 = new Student("Kolya");
		Student *st2 = new Student("Petya");
		st1->enterForCourse(math);
		st1->passCourse(math);
		st2->enterForCourse(eng);
		REQUIRE(st1->passedCourses[0] == true);
		REQUIRE(st2->passedCourses[0] == false);

	}
	TEST_CASE("Test archive")
	{
		Archive *arc = new Archive;
		Course *math = new MathCourse;
		Course *eng = new EnglishCourse;
		Lecturer *l1 = new Lecturer("Petro Petrovych", arc);
		Lecturer *l2 = new Lecturer("Ivan Ivanovych", arc);
		Student *st1 = new Student("Kolya");
		Student *st2 = new Student("Petya");
		l1->addCourse(math);
		l2->addCourse(eng);
		st1->enterForCourse(math);
		l1->addStudent(math, st1);
		st1->passCourse(math);
		l1->rateStudent(st1, math);
		REQUIRE(arc->students[0]->getName() == "Kolya");
		st2->enterForCourse(eng);
		l2->addStudent(eng, st2);
		st2->passCourse(eng);
		l2->rateStudent(st2, eng);
		REQUIRE(arc->students[1]->getName() == "Petya");
	}
}