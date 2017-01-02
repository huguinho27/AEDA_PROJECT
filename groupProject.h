#ifndef GROUPPROJECT_H
#define GROUPPROJECT_H
#include <fstream>
#include <iostream>
#include <tr1/unordered_set>
#include "BST.h"
#include "student.h"

/** @defgroup Utils Utils
 * @{
 * Useful defined macros
 */


using namespace std;

class groupProject
{
	Professor teacher;
	vector<Student *> students;
	string textFile;
	int maxN;
	string title;
	string year;
	string type;
	string status; //nf - not finished; f - finished; ev - evaluated
public:
	/**
	 * @brief Default constructor for the group project class
	 */
	groupProject();

	/**
	 * @brief Custom constructor for the group project class
	 * @param studentsIN The vector of students
	 */
	groupProject(vector<Student *> studentsIN);

	/**
	 * @brief Adds a new student to the group project
	 * @param st The pointer to the new student to be added
	 */
	bool addStudent(Student *st);

	/**
	 * @brief Removes a student from the group project
	 * @param st The pointer to the student
	 * @param title Title of the enunciation to be removed
	 */
	void removeSudent(Student *st, string title);

	/**
	 * @brief Sets a new teacher as tutor
	 * @param prof Pointer to the new teacher
	 */
	void setTeacher(Professor *prof);

	/**
	 * @brief Sets a new text file
	 * @param tFile New text file to be set
	 */
	void setTextFile(string tFile);

	/**
	 * @brief Sets a new maximum number of students
	 * @param num The new maximum number of students
	 */
	void setMaxNum(int num);

	/**
	 * @brief Sets a mark to a student
	 * @param st The student to evaluate
	 * @param mark The mark to evaluate the student
	 * @param title The title of the enunciation
	 */
	void setMark(Student *st, int mark, string title);

	/**
	 * @brief Sets a new title
	 * @param title The new title
	 */
	void setTitle(string title);

	/**
	 * @brief Sets a new year
	 * @param year The new year
	 */
	void setYear(string year);

	/**
	 * @brief Sets a new type for the group project
	 * @param type The new type
	 */
	void setType(string type);

	/**
	 * @brief Sets a new status for the group project
	 * @param newSt The new status
	 */
	void setStatus(string newSt);

	/**
	 * @return The status of the group project
	 */
	string getStatus() const;

	/**
	 * @return The title of the group project
	 */
	string getTitle() const;

	/**
	 * @return The year of the group project
	 */
	string getYear() const;

	/**
	 * @return The type of the group project
	 */
	string getType() const;

	/**
	 * @return The vector of students of the group project
	 */
	vector<Student *> getStudents() const;

	/**
	 * @return The text file of the group project
	 */
	string getTextFile();

	/**
	 * @return The teacher of the group project
	 */
	Professor getTeacher() const;

	/**
	 * @brief The information about a certain group project
	 */
	string printInfoProject(string title);

	/**
	 * @return The maximum number of students on a group project
	 */
	int getMax();

	/**
	 * @brief Operator< of group project
	 */
	bool operator <(const groupProject *right) const;

	/**
	 * @brief Operator== of group project
	 */
	bool operator ==(const groupProject *right) const;
};

#endif /**@}*/
