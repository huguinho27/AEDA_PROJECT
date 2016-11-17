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
	void browseGroupProjectMenu();
	void browseTechersStudentMenu();
	void browseEnunciationMenu();
	void browseCurricularMenu();
	void listStudentTeacher();
	void listEnunciations();
	void displayLectureTeacher();
	void displayGroupProjects();
};

general::general(){};

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

void general::browseGroupProjectMenu()
{
	return;
}

void general::browseTechersStudentMenu()
{
	return;
}

void general::browseEnunciationMenu()
{
	return;
}

void general::listStudentTeacher()
{
	return;
}

void general::listEnunciations()
{
	return;
}

void general::displayLectureTeacher()
{
	return;
}

void general::displayGroupProjects()
{
	return;
}

void general::browseCurricularMenu()
{
	string input;
	do
	{
		system("cls");

		cout << "CURRICULAR UNITS MANAGEMENT\n\n";
		cout << "1. List Students of a Curricular Unit\n";
		cout << "2. List Enunciations of this Curricular Unit\n";
		cout << "3. Show Lecture Teacher\n";
		cout << "4. Show Group Projects\n";
		cout << "5. Back to Main Menu\n";

		cout << ">> ";
		getline(cin, input);
		cin.clear();
	} while (!verifyGetline(1, 5, input));

	if (input == "1")
		listStudentTeacher();
	else if (input == "2")
		listEnunciations();
	else if (input == "3")
		displayLectureTeacher();
	else if (input == "4")
		displayGroupProjects();
	else if (input == "5")
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
		cout << "1. Browse Curricular Units\n";
		cout << "2. Browse Enunciations\n";
		cout << "3. Browse Teachers / Students\n";
		cout << "4. Browse Group Projects\n";
		cout << "5. Exit Program\n";

		cout << ">> ";
		getline(cin, input);
		cin.clear();
	} while (!verifyGetline(1, 5, input));

	if (input == "1")
		browseCurricularMenu();
	else if (input == "2")
		browseEnunciationMenu();
	else if (input == "3")
		browseTechersStudentMenu();
	else if (input == "4")
		browseGroupProjectMenu();
	else if (input == "5")
		exit(0);
}

int main()
{
	general g;
	g.MainMenu();
	return 0;
}
