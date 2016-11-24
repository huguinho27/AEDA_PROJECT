#include "student.h"
#include <iostream>
#include <sstream>
#include "sequentialSearch.h"

using namespace std;

/* Person */

Person::Person()
{
}
;

Person::Person(string name, int id)
{
	this->name = name;
	this->id = id;
}

string Person::getName() const
{
	return name;
}

void Person::setName(string newName)
{
	this->name = newName;
}

void Person::setId(int id)
{
	this->id = id;
}

int Person::getId()
{
	return id;
}

void Person::deleteTitle(string title)
{
	int i = sequentialSearch(titleEnun, title);
	titleEnun.erase(titleEnun.begin()+i);
}

/* Student */

Student::Student()
{
}
;

Student::Student(string name, int id) :
		Person(name, id)
{
}

vector<int> Student::getMarks()
{
	return marks;
}

int Student::getMark(string title)
{
	int i = sequentialSearch(titleEnun, title);
	return marks[i];
}

void Student::setMark(int mark, string title)
{
	unsigned int i = sequentialSearch(titleEnun, title);
	marks[i] = mark;
}

void Person::addNewTitle(string title)
{
	bool ctrl = false;
	for (unsigned int i = 0 ; i < titleEnun.size();i++)
	{
		if (titleEnun[i] == title)
			ctrl = true;
	}

	if (!ctrl)
		titleEnun.push_back(title);
}

void Student::addNewTitle(string title)
{
	Person::addNewTitle(title);
	marks.push_back(0);
}

void Student::deleteTitle(string title)
{
	for (unsigned int i=0; i<titleEnun.size(); i++)
	{
		if ((titleEnun[i]) == title)
		{
			titleEnun.erase(titleEnun.begin()+i);
			marks.erase(marks.begin()+i);
			break;
		}
	}
}

string Student::printInfoStudent()
{
	stringstream ss;
	ss << id << "\t" << name << "\n";
	for (unsigned int i = 0; i < titleEnun.size(); i++)
	{
		ss << titleEnun[i] << " - " << marks[i] << "\n";
	}
	return ss.str();
}

/* Professor */
Professor::Professor() {};

Professor::Professor(string name, int id) : Person(name, id){}

string Professor::printInfoProfessor()
{
	stringstream ss;
	ss << id << "\t" <<name << "\n";
	for (unsigned int i = 0; i < titleEnun.size(); i++)
	{
		ss << titleEnun[i] << "\n";
	}
	return ss.str();
}
