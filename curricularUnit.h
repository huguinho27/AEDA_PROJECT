/*#ifndef CURRICULARUNIT_H
#define CURRICULARUNIT_H

using namespace std;
#include <iostream>
#include <vector>

#include "enunciation.h"
#include "occurrence.h"

class curricularUnit
{
	string lectureTeacher;
	vector<Enunciation> enunciations;
	vector<Occurrence> occurrences;
public:
	curricularUnit();
	curricularUnit(string name, string lectureTeacher, float ECTSCredits);
	string getName() const;
	string getLectureTeacher() const;
	vector<Enunciation> getEnunciations() const;
	float getECTSCredits() const;
	int getNumberStudents() const;
	void setName(string newName);
	void addEnunciations(Enunciation e);
	void setLectureTeacher(string newTeacher);
};

#endif /* CURRICULARUNIT_H */
