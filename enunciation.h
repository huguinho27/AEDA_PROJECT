#ifndef ENUNCIATION_H
#define ENUNCIATION_H

using namespace std;
#include <iostream>
#include "student.h"
#include <vector>

class Enunciation
{
protected:
	string title, description;
	vector <string> years;

public:
	Enunciation(string title, string description);
	string getTitle() const;
	string getDescription() const;
	vector <string> getYears();
	void setTittle(string newTitle);
	void setDescription(string newDescription);
	void addYear(string newYear);

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



#endif /* ENUNCIATION_H */

