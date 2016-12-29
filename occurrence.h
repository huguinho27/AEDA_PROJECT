#ifndef OCCURRENCE_H
#define OCCURRENCE_H

#include <iostream>
#include <vector>
#include "groupProject.h"
using namespace std;

class Occurrence
{
	string schoolYear;
	vector<groupProject *> projects;
	string title;
	string type;
public:
	Occurrence();
	Occurrence(string schoolYear);
	void setYear (string year);
	void newGroupProject(groupProject *proj);
	void setTitle(string title);
	void setType(string type);
	string getYear() const;
	string getType();
	vector<groupProject *> getGroupProjects() const;
	string printInfoOccurrence(string title);
	bool operator< (const Occurrence &right);
};

#endif
