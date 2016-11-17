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
	string getYear() const;
	vector<groupProject> getGroupProjects() const;
};

#endif
