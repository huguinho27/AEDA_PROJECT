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
	vector<curricularUnit *> currUnits;
public:
	Person(string name);
	virtual ~Person(){};
	int getId() const;
	string getName() const;
	vector<curricularUnit *> getCurricularUnits();
	void setName(string newName);
	virtual void setCurricularUnit(curricularUnit *unit);
};


class Student: public Person{
	vector<double> marks;
public:
	Student(string name);
	virtual ~Student(){};
	vector<double> getMarks();
	double getMark(curricularUnit *unit);
	double getMedia();
	void setCurricularUnit(curricularUnit *unit);
	void setMark(curricularUnit *unit, double mark);
};


class Professor: public Person{
public:
	Professor(string name);
	virtual ~Professor(){};
};


/*class CurricularUnitExists{
public:
	CurricularUnitExists(curricularUnit unit): nome(nm) {}
	string getNome() const { return nome; }
};*/
#endif /* STUDENT_H */
