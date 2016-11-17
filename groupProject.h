#ifndef GROUPPROJECT_H
#define GROUPPROJECT_H

#include <fstream>
#include <iostream>

#include "student.h"

using namespace std;

class groupProject
{
	Person teacher;
	vector<Student> students;
public:
	fstream textFile;
	groupProject();
	groupProject(vector<Student> studentsIN, Person techerIN);
	fstream getTextFile();
};

#endif
