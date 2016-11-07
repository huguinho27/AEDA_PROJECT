#include "occurrence.h"
using namespace std;

Occurrence::Occurrence(string schoolYear, vector<Student> studentsIN)
{
	this->schoolYear = schoolYear;
	students = studentsIN;
}

vector<Student> Occurrence::getStudents() const
{
	return students;
}

vector<groupProject> Occurrence::getProjects() const
{
	return projects;
}
