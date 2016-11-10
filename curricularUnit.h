#ifndef CURRICULARUNIT_H
#define CURRICULARUNIT_H

using namespace std;
#include <iostream>
#include <vector>
#include "enunciation.h"
#include "occurrence.h"

class curricularUnit
{
	string name;
	float ECTSCredits;
	//Person lectureTeacher;
	vector<Enunciation> enunciations;
	vector<Occurrence> occurrences;
public:
	curricularUnit(string name, /*Person lectureTeacher,*/ float ECTSCredits);
	string getName() const;
	//Person getLectureTeacher() const;
	vector<Enunciation> getEnunciations() const;
	float getECTSCredits() const;
	int getNumberStudents() const;
	void setName(string newName);
	void addEnunciations(Enunciation e);
	void addEnunciations(vector<Enunciation> multipleEnun);
	void setLectureTeacher(string newTeacher);
};

#endif /* CURRICULARUNIT_H */
