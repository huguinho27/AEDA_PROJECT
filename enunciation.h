#ifndef ENUNCIATION_H
#define ENUNCIATION_H


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "occurrence.h"

using namespace std;

class Enunciation
{
protected:
	string title, description;
	vector <Occurrence> years;
public:
	Enunciation();
	Enunciation(string title, string description);
	string getTitle() const;
	string getDescription() const;
	vector <Occurrence> getYears();
	void setTittle(string newTitle);
	void setDescription(string newDescription);
	void addYear(Occurrence newYear);

};

class EnunciationResearch: public Enunciation
{
	protected:
	string biblio;
	public:
	EnunciationResearch(string title, string description, string biblio);
	string getBiblio();
};

class EnunciationAnalysis: public Enunciation
{
	protected:
	string repos;
	public:
	EnunciationAnalysis(string title, string description, string repos);
	string getRepos();
};

class EnunciationDevelopement: public Enunciation
{

};


void generateEnunciation();

void saveEnunciation();


#endif /* ENUNCIATION_H */

