#include "groupProject.h"

groupProject::groupProject(){};

groupProject::groupProject(vector<Student> studentsIN, Professor teacherIN, string tFile, unsigned int num)
{
	students = studentsIN;
	teacher = teacherIN;
	textFile = tFile;
	maxN = num;
}

bool groupProject::addStudent(Student st)
{
	if (students.size() < maxN)
	{
		students.push_back(st);
		return true;
	}
	return false;
}

/*void groupProject::removeStudent(Student st)
{

}*/

vector<Student> groupProject::getStudents() const
{
	return students;
}
