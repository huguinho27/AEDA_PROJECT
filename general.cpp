#include <iostream>
#include <vector>
#include <unistd.h>
#include <string>
#include "enunciation.h"

using namespace std;

class general
{
	vector<Enunciation> enunciations;
public:
	general();
	void MainMenu();
	bool verifyGetline(int init, int end, string input);
	void browseTechersStudentMenu();
	void browseEnunciationMenu();
	void displayLectureTeacher();
	void createEnunciationMenu();
	void listEnunciations();
	void findTeacher();
	void findStudent();
	void listStudents();
	void listTeachers();
	void addTeacher();
	void addStudent();
};

general::general()
{
}
;

/**
 * Checks if an input is a number and if it it between init and end values
 * @return true if ok, false if not
 */
bool general::verifyGetline(int init, int end, string input)
{
	bool goodInput = false;

	if (!goodInput)
	{
		bool number = true;

		for (unsigned int i = 0; i < input.length() && number; i++)
			if (!(input[i] >= '0' && input[i] <= '9'))
				number = false;

		if (number)
		{
			stringstream value_ss(input);
			int value;
			value_ss >> value;

			goodInput = (value >= init && value <= end);
		}
	}
	return goodInput;
}

void general::listEnunciations()
{
	return;
}

void general::createEnunciationMenu()
{
	return;
}

void general::findTeacher()
{
	return;
}

void general::findStudent()
{
	return;
}

void general::listStudents()
{
	return;
}

void general::listTeachers()
{
	return;
}

void general::addTeacher()
{
	return;
}

void general::addStudent()
{
	string input;
	system("cls");

	cout << "Please enter the name of the student\n";
	cout << ">> ";
	cin.clear();
	cin >> input;
	cout << "The student will be added to an existing group project with less than 3 members\n";
	sleep(1);

	Student s(input);
	bool ctrl = false;

	for (unsigned int i = 0; i < enunciations.size();i++)
	{
		for (unsigned int k = 0 ; k < enunciations[i].getOccurrences().size();k++)
		{
			vector<Occurrence> occ = enunciations[i].getOccurrences();
			for (unsigned int j = 0 ; i < occ[k].getGroupProjects().size();j++)
			{
				if (occ[k].getGroupProjects()[j].addStudent(s))
				{
					occ[k].getGroupProjects()[j].getStudents()[occ[k].getGroupProjects()[j].getStudents().size()-1].addNewTitle(enunciations[i].getTitle());
					ctrl = true;
				}
			}
		}
	}

	if (ctrl)
		cout << "The student was added with success\n";
	else
		cout << "Was not possible to add this student\n";
	sleep(1);
}

void general::browseTechersStudentMenu()
{
	string input;
	do
	{
		system("cls");

		cout << "STUDENTS/TEACHERS MANAGEMENT\n\n";
		cout << "1. Find a teacher\n";
		cout << "2. Find a student\n";
		cout << "3. List teachers\n";
		cout << "4. List students\n";
		cout << "5. Add a new teacher\n";
		cout << "6. Add a new student\n";
		cout << "7. Back to main menu\n";

		cout << ">> ";
		getline(cin, input);
		cin.clear();
	} while (!verifyGetline(1, 7, input));

	if (input == "1")
		findTeacher();
	else if (input == "2")
		findStudent();
	else if (input == "3")
		listTeachers();
	else if (input == "4")
		listStudents();
	else if (input == "5")
		addTeacher();
	else if (input == "6")
		addStudent();
	else if (input == "7")
		MainMenu();

	return;
}

void general::browseEnunciationMenu()
{
	string input;
	do
	{
		system("cls");

		cout << "ENUNCIATIONS MANAGEMENT\n\n";
		cout << "1. List Enunciations\n";
		cout << "2. Create an Enunciation\n\n";
		cout << "3. Back to main menu\n";

		cout << ">> ";
		getline(cin, input);
		cin.clear();
	} while (!verifyGetline(1, 2, input));

	if (input == "1")
		listEnunciations();
	else if (input == "2")
		createEnunciationMenu();
	else if (input == "3")
		MainMenu();

	return;
}

void general::MainMenu()
{
	string input;
	do
	{
		system("cls");
		cout << "ENUNCIATIONS MANAGEMENT OF FEUP\n\n";
		cout << "1. Browse Enunciations\n";
		cout << "2. Browse Students\n";
		cout << "3. Exit\n";

		cout << ">> ";
		getline(cin, input);
		cin.clear();
	} while (!verifyGetline(1, 3, input));

	if (input == "1")
		browseEnunciationMenu();
	else if (input == "2")
		browseTechersStudentMenu();
	else if (input == "3")
		exit(0);
}

int main()
{
	general g;
	g.MainMenu();
	return 0;
}
