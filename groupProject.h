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
	string textFile;
public:
	groupProject();
	groupProject(vector<Student> studentsIN, Person techerIN, string tFile);
	string getTextFile();
	bool addStudent(Student s);
	vector<Student> getStudents() const;
};

#endif
