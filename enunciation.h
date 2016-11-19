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

};

class EnunciationResearch: public Enunciation
{
protected:
	vector<string> biblio;
public:
	EnunciationResearch(string title, string description);
	vector<string> getBiblio();
	void newBiblio(string biblio1);
	void setBiblio(vector<string> biblio);
	string getInfo();
	string getCode();
};

class EnunciationAnalysis: public Enunciation
{
protected:
	vector<string> repos;
public:
	EnunciationAnalysis(string title, string description);
	vector<string> getRepos();
	void newRepos(string repos1);
	void setRepos(vector<string> repos);
	string getInfo();
	string getCode();
};

class EnunciationDevelopment: public Enunciation
{
protected:
	vector<string> results;
public:
	EnunciationDevelopment(string title, string description);
	vector<string> getResults();
	void newResult(string result1);
	void setResult(vector<string> results);
	string getInfo();
	string getCode();
};


//void generateEnunciation();

//void saveEnunciation();


#endif /* ENUNCIATION_H */

