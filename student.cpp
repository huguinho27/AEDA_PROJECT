#include "student.h"
#include <iostream>

using namespace std;

/* Person */

int Person::idgeneral = 1000;

Person::Person(string name){
	this->id = idgeneral;
	idgeneral++;
	this->name = name;
}

int Person::getId() const {
	return id;
}

string Person::getName() const {
	return name;
}

vector<curricularUnit *> Person::getCurricularUnits() {
	return currUnits;
}

void Person::setName(string newName) {
	name = newName;
}

void Person::setCurricularUnit(curricularUnit *unit) {
	//TODO exception CurricularUnitExists
	currUnits.push_back(unit);
}

/* Student */

Student::Student(string name): Person(name){}

vector<double> Student::getMarks() {
	return marks;
}

double Student::getMark(curricularUnit *unit) {
	for (unsigned int i=0; i< currUnits.size(); i++){
		if (currUnits[i]==unit) {
			return marks[i];
		}
		//TODO exception NoCurricularUnit
	}
}

double Student::getMedia() {
	double sum=0;
	int num=0;
	for (unsigned int i=0; i<marks.size(); i++){
		if (marks[i] > 0) {
			sum += marks[i];
			num++;
		}
	}
	return (sum/num);
}

void Student::setCurricularUnit(curricularUnit *unit){
	Person::setCurricularUnit(unit);
	marks.push_back(0);
}

void Student::setMark(curricularUnit *unit, double mark){
	for (unsigned int i=0; i<currUnits.size(); i++){
		if (currUnits[i]== unit){
			marks[i]=mark;
		}
		//TODO exception NoCurricularUnit
	}
}

/* Professor */

Professor::Professor(string name): Person(name){}
