#include "student.h"
#include <iostream>

using namespace std;

/* Person */

Person::Person()
{
}
;

Person::Person(string name)
{
	this->name = name;
}

string Person::getName() const
{
	return name;
}

void Person::setName(string newName)
{
	name = newName;
}

/* Student */

Student::Student()
{
}
;

Student::Student(string name) :
		Person(name)
{
}

vector<double> Student::getMarks()
{
	return marks;
}

double Student::getMark(string title)
{
	for (unsigned int i = 0; i < titleEnun.size(); i++)
	{
		if (titleEnun[i] == title)
		{
			return marks[i];
		}
	}
}

void Student::setMark(double mark, string title)
{
	for (unsigned int i = 0; i < titleEnun.size(); i++)
	{
		if (titleEnun[i] == title)
		{
			marks[i] = mark;
		}
	}
}

void Student::addNewTitle(string title)
{
	titleEnun.push_back(title);
	marks.push_back(0);
}

/* Professor */

Professor::Professor(string name) : Person(name){}
