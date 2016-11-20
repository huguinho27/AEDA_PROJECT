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
	void setTitle(string newTitle);
	void setDescription(string newDescription);
	void addYear(Occurrence newYear);
	vector <Occurrence> getOccurrences() const;
	virtual string getInfo();
	virtual string getCode();
	virtual string getAddition();
	void sortOccurrences();
	void newProj(string year, groupProject proj);

};

class EnunciationResearch: public Enunciation
{
protected:
	string biblio;
public:
	EnunciationResearch(string title, string description);
	string getAddition();
	void setBiblio(string biblio);
	string getInfo();
	string getCode();
};

class EnunciationAnalysis: public Enunciation
{
protected:
	string repos;
public:
	EnunciationAnalysis(string title, string description);
	string getAddition();
	void setRepos(string repos);
	string getInfo();
	string getCode();
};

class EnunciationDevelopment: public Enunciation
{
protected:
	string results;
public:
	EnunciationDevelopment(string title, string description);
	string getAddition();
	void setResult(string results);
	string getInfo();
	string getCode();
};

#endif /* ENUNCIATION_H */

