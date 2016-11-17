#include "groupProject.h"

groupProject::groupProject(){};

groupProject::groupProject(vector<Student> studentsIN, Person teacherIN, string tFile)
{
	students = studentsIN;
	teacher = teacherIN;
	textFile = tFile;
}

bool groupProject::addStudent(Student s)
{
	if (students.size() < 3)
	{
		students.push_back(s);
		return true;
	}
	return false;
}

vector<Student> groupProject::getStudents() const
{
	return students;
}
