#ifndef OCCURRENCE_H
#define OCCURRENCE_H

#include <iostream>
#include <vector>
#include "groupProject.h"

using namespace std;

class Occurrence
{
	string schoolYear;
	vector<groupProject> projects;
public:
	Occurrence(string schoolYear/*, vector<Student> studentsIN*/);
	//vector<Student> getStudents() const;
	vector<groupProject> getProjects() const;

};

#endif
