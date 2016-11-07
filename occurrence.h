#ifndef OCCURRENCE_H
#define OCCURRENCE_H
#include "student.h"
#include "groupProject.h"
#include <iostream>

using namespace std;

class Occurrence
{
	string schoolYear;
	vector<Student> students; //change to person later
	vector<groupProject> projects;
public:
	Occurrence(string schoolYear, vector<Student> studentsIN);
	vector<Student> getStudents() const;
	vector<groupProject> getProjects() const;

};

#endif
