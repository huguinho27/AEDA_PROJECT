#ifndef GROUPPROJECT_H
#define GROUPPROJECT_H

#include <fstream>
#include <iostream>

#include "enunciation.h"

using namespace std;

class groupProject
{
	Enunciation enunciation;
public:
	fstream textFile;
	groupProject();
	groupProject(Enunciation enun);
	Enunciation getEnunciation() const;
	//fstream getTextFile() const;
};

#endif
