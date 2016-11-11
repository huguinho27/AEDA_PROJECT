#include "groupProject.h"

groupProject::groupProject(){};

groupProject::groupProject(vector<Student> studentsIN, Enunciation enun, fstream file)
{
	students = studentsIN;
	enunciation = enun;
	textFile = file;
}

Enunciation groupProject::getEnunciation() const
{
	return enunciation;
}

fstream groupProject::getTextFile() const
{
	return textFile;
}
