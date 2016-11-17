#include "groupProject.h"

groupProject::groupProject(){};

groupProject::groupProject(vector<Student> studentsIN, Person teacherIN)
{
	students = studentsIN;
	teacher = teacherIN;
	//textFile = fileIN;
}
