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
	virtual void addNewTitle(string title);
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
	string printInfoStudent();
	void addNewTitle(string title);
};

class Professor: public Person{
public:
	Professor();
	Professor(string name);
	virtual ~Professor(){};
	string printInfoProfessor();
};

#endif /* STUDENT_H */
