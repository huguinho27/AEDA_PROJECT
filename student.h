#ifndef STUDENT_H
#define STUDENT_H



#include <iostream>
#include <vector>
using namespace std;

class Person
{
protected:
	string name;
	vector<string> titleEnun;
public:
	Person();
	Person(string name);
	virtual ~Person(){};
	string getName() const;
	void setName(string newName);
};

class Student: public Person
{
	vector<double> marks;
public:
	Student();
	Student(string name);
	virtual ~Student(){};
	vector<double> getMarks();
	double getMark(string title);
	void setMark(double mark, string title);
	void addNewTitle(string title);
	string printInfoStudent();
};

class Professor: public Person{
public:
	Professor(string name);
	virtual ~Professor(){};
	string printInfoProfessor();
};

#endif /* STUDENT_H */
