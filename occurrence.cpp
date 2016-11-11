#include "occurrence.h"

using namespace std;

Occurrence::Occurrence(){};

Occurrence::Occurrence(string schoolYear/*, vector<Student> studentsIN*/)
{
	this->schoolYear = schoolYear;
}

vector<groupProject> Occurrence::getProjects() const
{
	return projects;
}
