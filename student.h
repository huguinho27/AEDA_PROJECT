#ifndef STUDENT_H
#define STUDENT_H



#include <iostream>
#include <vector>
using namespace std;

class Person
{
protected:
	int id;
	string name;
	vector<string> titleEnun;
public:
	Person();
	Person(string name, int id);
	virtual ~Person(){};
	string getName() const;
	void setName(string newName);
	void setId(int id);
	int getId();
	virtual void addNewTitle(string title);
	virtual void deleteTitle(string title);
};

class Student: public Person
{
	vector<float> marks;
public:
	Student();
	Student(string name, int id);
	virtual ~Student(){};
	vector<float> getMarks();
	float getMark(string title);
	void setMark(float mark, string title);
	string printInfoStudent();
	void addNewTitle(string title);
	void deleteTitle(string title);
};

class Professor: public Person{
public:
	Professor();
	Professor(string name, int id);
	virtual ~Professor(){};
	string printInfoProfessor();
};

#endif /* STUDENT_H */
