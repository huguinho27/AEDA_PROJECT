#include "groupProject.h"

groupProject::groupProject(){};

groupProject::groupProject(Enunciation enun)
{
	//students = studentsIN;
	enunciation = enun;
}

Enunciation groupProject::getEnunciation() const
{
	return enunciation;
}
