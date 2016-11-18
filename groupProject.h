#ifndef GROUPPROJECT_H
#define GROUPPROJECT_H

#include <fstream>
#include <iostream>

#include "student.h"

using namespace std;

class groupProject
{
	Professor teacher;
	vector<Student> students;
	string textFile;
	unsigned int maxN;
public:
	groupProject();
	groupProject(vector<Student> studentsIN, Professor teacherIN, string tFile, unsigned num);
	bool addStudent(Student st);
	void removeSudent(Student st);
	void setTeacher(Professor prof);
	void setTextFile(string tFile);
	void setMark(Student st, double mark);
	void setMaxNum(unsigned int num);
	vector<Student> getStudents() const;
	string getTextFile();
	Professor getTeacher() const;
	unsigned int getNum() const;
};

#endif
