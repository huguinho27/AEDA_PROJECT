#ifndef CURRICULARUNIT_H
#define CURRICULARUNIT_H

using namespace std;
#include <iostream>
#include <vector>
#include "enunciation.h"
#include "student.h"

class curricularUnit
{
	string name, lectureTeacher;
	vector<Student> students;
	vector<Enunciation> enunciations;
	float ECTSCredits;
public:
	curricularUnit(string name, string lectureTeacher, Student s, float ECTSCredits);
	string getName() const;
	string getLectureTeacher() const;
	vector<Student> getStudents() const;
	vector<Enunciation> getEnunciations() const;
	float getECTSCredits() const;
	int getNumberStudents() const;
	void setName(string newName);
	void addEnunciations(Enunciation e);
	void addEnunciations(vector<Enunciation> multipleEnun);
	void setLectureTeacher(string newTeacher);
};

#endif /* CURRICULARUNIT_H */
