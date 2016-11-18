#ifndef OCCURRENCE_H
#define OCCURRENCE_H

#include <iostream>
#include <vector>
#include "groupProject.h"
using namespace std;

class Occurrence
{
	string schoolYear;
	vector<groupProject> projects;
public:
	Occurrence();
	Occurrence(string schoolYear);
	void setYear (string year);
	void newGroupProject(groupProject proj);
	string getYear() const;
	vector<groupProject> getGroupProjects() const;
	string printInfoOccurrence(string title);
};

#endif
