#include "student.h"
#include <iostream>

using namespace std;

int Student::idgeneral = 1000;

Student::Student(string name){
	this->id = idgeneral;
	this->name = name;
	idgeneral++;
}

int Student::getId() const {
	return id;
}

string Student::getName() const {
	return name;
}

vector<curricularUnit *> Student::getCurricularUnits() {
	return currUnits;
}

vector<double> Student::getMarks() {
	return marks;
}

double Student::getMark(curricularUnit *unit) {
	for (unsigned int i=0; i<currUnits.size(); i++){
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

void Student::setName(string newNane) {
	name = newName;
}

void Student::setCurricularUnit(curricularUnit *unit) {
	//TODO exception CurricularUnitExists
	currUnits.push_back(unit);
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

