#include<iostream>
#include <Windows.h>
#include<vector>
#include<string>
#include<map>
#include<ctime>

using namespace std;

class Course
{
protected: 
	string name;
public:
	string getName(){
		return name;
	}
	virtual void passExam(string studentName) = 0;
};


class MathCourse :public Course
{
public:
	MathCourse()
	{
		name = "Mathematical analysis";
	};
	void passExam(string studentName){
		cout << "Student: " << studentName << " has passed his exam in: " << name << endl;
	}

};

class EnglishCourse : public Course
{
public:
	EnglishCourse()
	{
		name = "English";
	}
	void passExam(string studentName)
	{
		cout << "Student: " << studentName << " has passed an exam in: " << name << endl;
	}
};
class Student{
private:
	string name;
	vector<Course*>courses;
	vector<bool>passedCourses;
	vector<short> marks;
public:
	Student(string _name) :name(_name){};
	string getName(){
		return name;
	}
	void enterForCourse(Course *course);
	bool passCourse(Course *course);
	bool isPassed(string courseName);
	void setMark(short mark, Course *course);
};

class Archive
{
private:
	vector<Student*>students;
	vector<Course*>courses;
	short marks[100][20];
public:
	Archive(){
		for (size_t i = 0; i < 20; i++)
			for (size_t j = 0; j < 99; j++)
				marks[i][j] = -1;
	}
	void addStudent(Student *student);
	void addCourse(Course *course);
	int getStudentIndex(string name);
	int getCourseIndex(string name);
	void setMark(Student *student, Course* course, short mark);
	void showArchive();
};
class Lecturer
{
private:
	string name;
	vector<Course*>courses;
	map<string, vector<Student*>> students;
	Archive *archive;
public:
	Lecturer(string _name, Archive *_archive) :name(_name), archive(_archive){};
	void addCourse(Course* course);
	void addStudent(Course *course, Student *student);
	bool rateStudent(Student *student, Course*course);
};
void menu();







//#include"Elective.h"

void Student::enterForCourse(Course *course)
{
	courses.push_back(course);
	passedCourses.push_back(false);
	marks.push_back(-1);
}
bool Student::passCourse(Course *course)
{
	for (size_t i = 0; i < courses.size(); i++)
	{
		if (courses[i]->getName() == course->getName())
		{
			courses[i]->passExam(name);
			passedCourses[i] = true;
			return true;
		}
	}
	return false;
}
bool Student::isPassed(string courseName)
{
	for (size_t i = 0; i < courses.size(); i++)
	{
		if (courses[i]->getName() == courseName)
		{
			return true;
		}
	}
	return false;
}
void Student::setMark(short mark, Course *course)
{
	for (size_t i = 0; i < courses.size(); i++)
	{
		if (courses[i]->getName() == course->getName())
		{
			marks[i] = mark;
			return;
		}
	}
}


void Archive::addStudent(Student *student)
{
	students.push_back(student);
}
void Archive::addCourse(Course *course)
{
	courses.push_back(course);
}
int Archive::getStudentIndex(string name)
{
	for (size_t i = 0; i < students.size(); i++)
	{
		if (students[i]->getName() == name)
		{
			return i;
		}
	}
	return -1;
}
int Archive::getCourseIndex(string name)
{
	for (size_t i = 0; i < courses.size(); i++)
	{
		if (courses[i]->getName() == name)
		{
			return i;
		}
	}
	return -1;
}
void Archive::setMark(Student *student, Course *course, short mark)
{
	int indexS, indexC;
	indexS = getStudentIndex(student->getName());
	if (indexS == -1)
	{
		addStudent(student);
		indexS = students.size() - 1;
	}
	indexC = getCourseIndex(course->getName());
	if (indexC == -1)
	{
		addCourse(course);
		indexC = courses.size() - 1;
	}
	marks[indexS][indexC] = mark;
}
void Archive::showArchive()
{
	for (size_t i = 0; i < students.size(); i++)
	{
		cout << "~~~~~~Student: " << students[i]->getName() << "~~~~~~~~~" << endl;
		for (size_t j = 0; j < courses.size(); j++)
		{
			if (marks[i][j] != -1)
			{
				cout << courses[j]->getName() << ": " << marks[i][j] << endl;
			}
		}
	}
}

void Lecturer::addCourse(Course*course){
	courses.push_back(course);
}
void Lecturer::addStudent(Course *course, Student*student){
	for (size_t i = 0; i < courses.size(); i++){
		if (courses[i]->getName() == course->getName()){
			students[courses[i]->getName()].push_back(student);
		}
	}
}
bool Lecturer::rateStudent(Student *student, Course *course)
{
	if (!student->isPassed(course->getName()))
	{
		cout << "Student did not passed this course!" << endl;
		Sleep(750);
		return false;
	}
	for (size_t i = 0; i < courses.size(); i++)
	{
		if (courses[i]->getName() == course->getName()) // if the lecturer has such course 
		{
			for (size_t j = 0; j < students[courses[i]->getName()].size(); j++) // 
			{
				string temp = students[courses[i]->getName()][j]->getName();
				if (temp == student->getName()) // is there is such student
				{
					srand(time(NULL));
					short mark = 1 + rand() % 5; // set a mark
					student->setMark(mark, course);
					archive->setMark(student, course, mark);
					return true;
				}
			}
		}
	}
	cout << "Error!" << endl;
	return false;
}
void menu()
{
	Archive *arc = new Archive;
	Course *math = new MathCourse;
	Course *eng = new EnglishCourse;
	Lecturer *l1 = new Lecturer("Petro Petrovych", arc);
	Lecturer *l2 = new Lecturer("Ivan Ivanovych", arc);
	Student *st1 = new Student("Kolya");
	Student *st2 = new Student("Petya");
	Student *st3 = new Student("Nikifor");
	l1->addCourse(math);
	l2->addCourse(eng);
	int k;
	while (true)
	{
		cout << "1. Teach Kolya English" << endl;
		cout << "2. Teach Kolya Math" << endl;
		cout << "3. Teach Petya English" << endl;
		cout << "4. Teach Petya Math" << endl;
		cout << "5. Teach Nikifor English" << endl;
		cout << "6. Teach Nikifor Math" << endl;
		cout << "7. Set Kolyas mark in English" << endl;
		cout << "8. Set Kolyas mark in Math" << endl;
		cout << "9. Set Petyas mark in English" << endl;
		cout << "10. Set Petyas mark in Math" << endl;
		cout << "11. Set Nikifors mark in English" << endl;
		cout << "12. Set Nikifors mark in Math" << endl;
		cout << "13. Show archive" << endl;
		cout << "0. Exit" << endl;
		cout << "->";
		cin >> k;
		switch (k)
		{
		case 1:
			st1->enterForCourse(eng);
			l2->addStudent(eng, st1);
			st1->passCourse(eng);
			Sleep(750);
			break;
		case 2:
			st1->enterForCourse(math);
			l1->addStudent(math, st1);
			st1->passCourse(math);
			Sleep(750);
			break;
		case 3:
			st2->enterForCourse(eng);
			l2->addStudent(eng, st2);
			st2->passCourse(eng);
			Sleep(750);
			break;
		case 4:
			st2->enterForCourse(math);
			l1->addStudent(math, st2);
			st2->passCourse(math);
			Sleep(750);
			break;
		case 5:
			st3->enterForCourse(eng);
			l2->addStudent(eng, st3);
			st3->passCourse(eng);
			Sleep(750);
			break;
		case 6:
			st3->enterForCourse(math);
			l1->addStudent(math, st3);
			st3->passCourse(math);
			Sleep(750);
			break;
		case 7:
			l2->rateStudent(st1, eng);
			break;
		case 8:
			l1->rateStudent(st1, math);
			break;
		case 9:
			l2->rateStudent(st2, eng);
			break;
		case 10:
			l1->rateStudent(st2, math);
			break;
		case 11:
			l2->rateStudent(st3, eng);
			break;
		case 12:
			l1->rateStudent(st3, math);
			break;
		case 13:
			arc->showArchive();
			system("pause");
			break;
		case 0:
			return;
		}
		system("cls");
	}
}