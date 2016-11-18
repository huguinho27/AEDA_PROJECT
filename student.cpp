#include "student.h"
#include <iostream>
#include <sstream>

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
	return -1;
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

void Person::addNewTitle(string title)
{
	titleEnun.push_back(title);
}

void Student::addNewTitle(string title)
{
	titleEnun.push_back(title);
	marks.push_back(0);
}

string Student::printInfoStudent()
{
	stringstream ss;
	ss << name << "\n";
	for (unsigned int i = 0; i < titleEnun.size(); i++)
	{
		ss << titleEnun[i] << " - " << marks[i] << "\n";
	}
	return ss.str();
}

/* Professor */
Professor::Professor() {};

Professor::Professor(string name) : Person(name){}

string Professor::printInfoProfessor()
{
	stringstream ss;
	ss << name << "\n";
	for (unsigned int i = 0; i < titleEnun.size(); i++)
	{
		ss << titleEnun[i] << "\n";
	}
	return ss.str();
}
