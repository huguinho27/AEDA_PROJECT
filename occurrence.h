#ifndef OCCURRENCE_H
#define OCCURRENCE_H
#include <iostream>
#include <vector>
#include "groupProject.h"

/** @defgroup Utils Utils
 * @{
 * Useful defined macros
 */

using namespace std;

class Occurrence
{
	string schoolYear;
	vector<groupProject *> projects;
	string title;
	string type;
public:
	/**
	 * @brief Default constructor of Occurrence class
	 */
	Occurrence();

	/**
	 * @brief Custom constructor of Occurrence class
	 * @param schoolYear The year of the occurrence
	 */
	Occurrence(string schoolYear);

	/**
	 * @brief Sets a new year for the occurrence
	 * @param year The new year
	 */
	void setYear(string year);

	/**
	 * @brief Adds a new group project to the occurrence
	 * @param proj Pointer to the new grou project
	 */
	void newGroupProject(groupProject *proj);

	/**
	 * @brief Sets a new title for the enunciations
	 * @param title The new title
	 */
	void setTitle(string title);

	/**
	 * @brief Sets a new type for the enunciation
	 */
	void setType(string type);

	/**
	 * @return The year of the occurrence
	 */
	string getYear() const;

	/**
	 * @return The type of the occurrence
	 */
	string getType();

	/**
	 * @return The pointer to the vecotr of group projects
	 */
	vector<groupProject *> getGroupProjects() const;

	/**
	 * @return A string containing the information about this occurrence
	 */
	string printInfoOccurrence(string title);

	/**
	 * @brief Operator< of Occurrence
	 */
	bool operator<(const Occurrence &right);
};

#endif /**@}*/
