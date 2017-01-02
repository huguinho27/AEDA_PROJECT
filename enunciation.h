#ifndef ENUNCIATION_H
#define ENUNCIATION_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "occurrence.h"

/** @defgroup Utils Utils
 * @{
 * Useful defined macros
 */

using namespace std;

class Enunciation
{
protected:
	string title, description;
	vector<Occurrence *> years;
public:
	/**
	 * @brief Default constructor of Enunciation class
	 */
	Enunciation();

	/**
	 * @brief Custom constructor of Enunciation class
	 * @param title Title of the enunciation
	 * @param description Description of that enunciation
	 */
	Enunciation(string title, string description);

	/**
	 * @return Gets the title of the enunciation
	 */
	string getTitle() const;

	/**
	 * @return The description of the enunciation
	 */
	string getDescription() const;

	/**
	 * @brief Sets a new title for the enunciation associated
	 * @param newTitle The new title
	 */
	void setTitle(string newTitle);

	/**
	 * @brief Sets a new description for the enunciation associated
	 * @param newDescription The new description
	 */
	void setDescription(string newDescription);

	/**
	 * @brief Adds a new year to the occurrences vector
	 * @param newYear Pointer to the new Occurrence to be added
	 */
	void addYear(Occurrence *newYear);

	/**
	 * @return The ocurrences of an enunciation
	 */
	vector<Occurrence *> getOccurrences() const;

	/**
	 * @brief Virtual function to get information of a certain enunciation
	 */
	virtual string getInfo();

	/**
	 * @brief Virtual function to get code of a certain enunciation
	 */
	virtual string getCode();

	/**
	 * @brief Virtual function to get addition of a certain enunciation
	 */
	virtual string getAddition();

	/**
	 * @brief Sorts occurrences
	 */
	void sortOccurrences();
};

class EnunciationResearch: public Enunciation
{
protected:
	string biblio;
public:
	/**
	 * @brief Custom constructor of EnunciationResearch class
	 * @param title Title of the enunciation
	 * @param description Description of that enunciation
	 */
	EnunciationResearch(string title, string description);

	/**
	 * @brief Virtual function to get addition of a certain enunciation
	 */
	string getAddition();

	/**
	 * @brief Sets a new biblio for the enunciation
	 * @param biblio The new string biblio to be set
	 */
	void setBiblio(string biblio);

	/**
	 * @return Information about an enunciation
	 */
	string getInfo();

	/**
	 * @return Code about an enunciation
	 */
	string getCode();
};

class EnunciationAnalysis: public Enunciation
{
protected:
	string repos;
public:
	/**
	 * @brief Custom constructor of EnunciationAnalysis class
	 * @param title Title of the enunciation
	 * @param description Description of that enunciation
	 */
	EnunciationAnalysis(string title, string description);

	/**
	 * @brief Virtual function to get addition of a certain enunciation
	 */
	string getAddition();

	/**
	 * @brief Sets a new repository for the enunciation
	 * @param repos The new repository
	 */
	void setRepos(string repos);

	/**
	 * @return Information about an enunciation
	 */
	string getInfo();

	/**
	 * @return Code about an enunciation
	 */
	string getCode();
};

class EnunciationDevelopment: public Enunciation
{
protected:
	string results;
public:
	/**
	 * @brief Custom constructor of EnunciationDevelopment class
	 * @param title Title of the enunciation
	 * @param description Description of that enunciation
	 */
	EnunciationDevelopment(string title, string description);

	/**
	 * @brief Virtual function to get addition of a certain enunciation
	 */
	string getAddition();

	/**
	 * @brief Sets a new result for the enunciation
	 * @param results The new results
	 */
	void setResult(string results);

	/**
	 * @return Information about an enunciation
	 */
	string getInfo();

	/**
	 * @return Code about an enunciation
	 */
	string getCode();
};

#endif /**@}*/

