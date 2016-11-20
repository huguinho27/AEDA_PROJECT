#include "groupProject.h"
#include <sstream>

groupProject::groupProject(){};

groupProject::groupProject(vector<Student> studentsIN)
{
	students = studentsIN;
	Professor p("no_teacher", 0);
	teacher = p;
	maxN = 99;
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

void groupProject::removeSudent(Student st, string title)
{
	st.deleteTitle(title);
	for (vector<Student>::iterator it = students.begin(); it != students.end(); it++)
	{
		if ((*it).getName() == st.getName())
		{
			students.erase(it);
			break;
		}
	}
}

void groupProject::setTeacher(Professor prof)
{
	teacher = prof;
}

void groupProject::setTextFile(string tFile)
{
	textFile = tFile;
}

void groupProject::setMaxNum(int num)
{
	maxN = num;
}

vector<Student> groupProject::getStudents() const
{
	return students;
}

string groupProject::getTextFile()
{
	return textFile;
}

Professor groupProject::getTeacher() const
{
	return teacher;
}

string groupProject::printInfoProject(string title)
{
	stringstream ss;
	ss << "Monitor: " << teacher.getName() << "\n \n";
	ss << "Students\n";
	for (unsigned int i=0; i<students.size(); i++)
	{
		ss << students[i].getName() << " - " << students[i].getMark(title) << "\n|";
	}
	ss << "\n Free places: " << (maxN - students.size()) << "\n";
	return ss.str();
}
