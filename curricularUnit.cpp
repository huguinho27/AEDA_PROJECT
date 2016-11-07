#include "curricularUnit.h"

using namespace std;

curricularUnit::curricularUnit(string name, string lectureTeacher, Student s, float ECTSCredits)
{
	this->name = name;
	this->lectureTeacher = lectureTeacher;
	this->ECTSCredits = ECTSCredits;
	students.push_back(s);
}

string curricularUnit::getName() const
{
	return name;
}

Person curricularUnit::getLectureTeacher() const
{
	return lectureTeacher;
}

vector<Student> curricularUnit::getStudents() const
{
	vector<Student> end;
	for (unsigned int i = 0; i < occurences.size();i++)
	{
		for (unsigned int k = 0; k < occurences[i].getStudents().size();k++)
		{
			end.push_back(occurences[i].getStudents()[k]);
		}
	}
	return end;
}

vector<Enunciation> curricularUnit::getEnunciations() const
{
	return enunciations;
}

float curricularUnit::getECTSCredits() const
{
	return ECTSCredits;
}

int curricularUnit::getNumberStudents() const
{
	return students.size();
}

void curricularUnit::setName(string newName)
{
	name = newName;
}

void curricularUnit::addEnunciations(Enunciation e)
{
	enunciations.push_back(e);
}

void curricularUnit::addEnunciations(vector<Enunciation> multipleEnun)
{
	for (unsigned int i = 0; i < multipleEnun.size();i++)
	{
		enunciations.push_back(multipleEnun[i]);
	}
}

void curricularUnit::setLectureTeacher(string newTeacher)
{
	lectureTeacher = newTeacher;
}
