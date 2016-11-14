#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

#include <iostream>
#include <vector>
#include "enunciation.h"
#include "curricularUnit.h"

class Person{
protected:
	int id;
	int static idgeneral;
	string name;
	vector<string> currUnits;
public:
	Person(string name);
	virtual ~Person(){};
	int getId() const;
	string getName() const;
	vector<string> getCurricularUnits();
	void setName(string newName);
	virtual void setCurricularUnit(string unit);
};


class Student: public Person{
	vector<double> marks;
public:
	Student(string name);
	virtual ~Student(){};
	vector<double> getMarks();
	double getMark(string unit);
	double getMedia();
	void setCurricularUnit(string unit);
	void setMark(string unit, double mark);
};


class Professor: public Person{
public:
	Professor(string name);
	virtual ~Professor(){};
};


class CurricularUnitExists{
	string unit;
public:
	CurricularUnitExists(string unit): unit(unit) {}
};

class NoCurricularUnit{
	string unit;
public:
	NoCurricularUnit(string unit): unit(unit) {}
};



#endif /* STUDENT_H */
