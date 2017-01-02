#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <vector>

/** @defgroup Utils Utils
 * @{
 * Useful defined macros
 */

using namespace std;

class Person
{
protected:
	int id;
	string name;
	vector<string> titleEnun;
public:
	/**
	 * @brief Default constructor for Person class
	 */
	Person();

	/**
	 * @brief Custom constructor for the person class
	 * @param name Name of the person
	 * @param id Id of the person
	 */
	Person(string name, int id);

	/**
	 * @brief Destructor of Person class
	 */
	virtual ~Person()
	{
	}
	;

	/**
	 * @return The name of the person
	 */
	string getName() const;

	/**
	 * @brief Sets a new name for the person
	 * @param newName The new name
	 */
	void setName(string newName);

	/**
	 * @brief Sets a new id for the person
	 * @param id The new id for the person
	 */
	void setId(int id);

	/**
	 * @return The id of a person
	 */
	int getId();

	/**
	 * @brief Adds a new title to the person
	 * @param title The new title to be added
	 */
	virtual void addNewTitle(string title);

	/**
	 * @brief Delete a title from a perosn
	 * @param title The title to be deleted
	 */
	virtual void deleteTitle(string title);
};

class Student: public Person
{
	vector<int> marks;
public:
	/**
	 * @brief Default constructor for class Student
	 */
	Student();

	/**
	 * @brief Custom constructor for the class Student
	 * @param name The name of the student
	 * @param id The id of the student
	 */
	Student(string name, int id);

	/**
	 * @brief Destructor of Student
	 */
	virtual ~Student()
	{
	}
	;

	/**
	 * @return Vector of marks of the student
	 */
	vector<int> getMarks();

	/**
	 * @return The mark of the student on a certain title(g.p.)
	 * @param title Title of the enunciation
	 */
	int getMark(string title);

	/**
	 * @brief Sets a mark for a student on a certain title
	 * @param mark Mark to be added
	 * @param title Title of the enunciation
	 */
	void setMark(int mark, string title);

	/**
	 * @return String containing the info of the student
	 */
	string printInfoStudent();

	/*
	 * @brief Adds a new title to the student
	 */
	void addNewTitle(string title);

	/**
	 * @brief Deletes a title from the student
	 */
	void deleteTitle(string title);
};

class Professor: public Person
{
public:
	/**
	 * @brief Default constructor for class Student
	 */
	Professor();

	/**
	 * @brief Custom constructor for the professor class
	 * @param name The name of the professor
	 * @param id Id for the new professor
	 */
	Professor(string name, int id);

	/**
	 * @brief Destructor
	 */
	virtual ~Professor()
	{
	}
	;

	/**
	 * @return String containing the info of the professor
	 */
	string printInfoProfessor();
};

#endif /**@}*/
