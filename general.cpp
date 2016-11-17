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
	void browseOccurrences();
	void createEnunciationMenu();
	void listEnunciations();

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

void general::browseOccurrences()
{
	return;
}

void general::browseTechersStudentMenu()
{
	string input;
	do
	{
		system("cls");

		cout << "STUDENTS/TEACHERS MANAGEMENT\n\n";
		cout << "1. Find a teacher\n";
		cout << "2. Find a studennd a teact\n\n";
		cout << "3. List the teacher\n";
		cout << "4. Add teacher\n";
		cout << ". Back to main menu\n";

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
		cout << "3. Browse Occurrences\n\n";
		cout << "4. Exit\n";

		cout << ">> ";
		getline(cin, input);
		cin.clear();
	} while (!verifyGetline(1, 3, input));

	if (input == "1")
		browseEnunciationMenu();
	else if (input == "2")
		browseTechersStudentMenu();
	else if (input == "3")
		browseOccurrences();
	else if (input == "4")
		exit(0);
}

int main()
{
	general g;
	g.MainMenu();
	return 0;
}
