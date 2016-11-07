#ifndef GROUPPROJECT_H
#define GROUPPROJECT_H
#include <fstream>
#include <iostream>
using namespace std;

class groupProject
{
	vector<Student> students;
	Enunciation enunciation;
	fstream textFile;
public:
	groupProject(vector<Student> studentsIN, Enunciation enun, fstream file);
	Enunciation getEnunciation() const;
	fstream getTextFile() const;
};
#endif
