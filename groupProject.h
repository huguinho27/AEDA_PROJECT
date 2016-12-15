#ifndef GROUPPROJECT_H
#define GROUPPROJECT_H

#include <fstream>
#include <iostream>
#include <tr1/unordered_set>
#include "BST.h"

#include "student.h"

using namespace std;

class groupProject
{
	Professor teacher;
	vector<Student *> students;
	string textFile;
	int maxN;
public:
	groupProject();
	groupProject(vector<Student *> studentsIN);
	bool addStudent(Student *st);
	void removeSudent(Student *st, string title);
	void setTeacher(Professor *prof);
	void setTextFile(string tFile);
	void setMaxNum(int num);
	void setMark(Student *st, int mark, string title);
	vector<Student *> getStudents() const;
	string getTextFile();
	Professor getTeacher() const;
	string printInfoProject(string title);
	int getMax();
};

#endif
