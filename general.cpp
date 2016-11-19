#include <iostream>
#include <vector>
#include <unistd.h>
#include <string>
#include "enunciation.h"

using namespace std;

class general
{
	vector<Enunciation> enunciations;
	vector<Enunciation> unused_enunciation;
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
	void createNewOccurrence();
	bool checkGoodDateInput(string date);
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

bool general::checkGoodDateInput(string date)
{
	if (date.size() != 9)
		return false;

	string part1;
	part1.append(date.begin(), date.begin() + 4);
	string part2;
	part2.append(date.begin() + 5, date.end());

	//cout << part1 << " " << part2;

	bool good = true;

	for (unsigned int i = 0; i < date.size(); i++)
	{
		cout << i << " " << date[i] <<  "\n";
		if (i == 5)
		{
			cout << i << " " << date[i] <<  "\n";
			if (date[i] != '-')
				good = false;
		} else if (date[i] < '0' || date[i] > '9')
		{
			cout << i << " " << date[i] <<  "\n";
			good = false;
			//break;
		}
	}
	return good;
}

void general::createNewOccurrence()
{
	/*do
	 {*/

}

void general::listEnunciations()
{
	system("cls");
	for (unsigned int i = 0; i < enunciations.size(); i++)
	{
		enunciations[i].getInfo();
		cout << "--------------------------------------------\n";
	}
	system("pause");
	MainMenu();
	return;
}

void general::createEnunciationMenu()
{
	int control = unused_enunciation.size();
	string title, description, input;
	system("cls");

	cout << "Please enter the title for the new enunciation\n";
	cout << ">> ";
	cin.clear();
	cin >> title;

	cout << "Please enter the description for the new enunciation\n";
	cout << ">> ";
	cin.clear();
	cin >> description;

	do
	{
		system("cls");

		cout << "What's the type of enunciation you wish to create?\n";
		cout << "1. Research\n";
		cout << "2. Analysis\n";
		cout << "3. Development\n";
		cout << "4. Other\n";
		cout << ">> ";
		getline(cin, input);
		cin.clear();

	} while (!verifyGetline(1, 4, input));

	if (input == "1")
	{
		EnunciationResearch d(title, description, "");
		unused_enunciation.push_back(d);
	} else if (input == "2")
	{
		EnunciationAnalysis d(title, description, "");
		unused_enunciation.push_back(d);
	} else if (input == "3") //TODO: UNCOMMENT THIS LATER
	{
		//EnunciationDevelopement d(title,description);
		//unused_enunciation.push_back(d);
	} else if (input == "4")
	{
		Enunciation d(title, description);
		unused_enunciation.push_back(d);
	}

	if (unused_enunciation.size() > control)
		cout << "Enunciation added with success\n";
	else
		cout << "Error while adding enunciation\n";

	sleep(2);
	MainMenu();
	return;
}

void general::findTeacher()
{
	string input;
	bool ctrl;
	do
	{
		system("cls");
		cout << "Please enter the name of the teacher OR " "back" " to return to main menu\n";
		cout << ">> ";
		cin.clear();
		cin >> input;
		cout << "\n";

		if (input == "back")
		{
			break;
			ctrl = true;
		}
		ctrl = false;

		for (unsigned int i = 0; i < enunciations.size(); i++)
		{
			for (unsigned int j = 0; j < enunciations[i].getOccurrences().size(); j++)
			{
				for (unsigned int k = 0; k < enunciations[i].getOccurrences()[j].getGroupProjects().size(); k++)
				{
					vector<groupProject> grp = enunciations[i].getOccurrences()[j].getGroupProjects();
					for (unsigned int h = 0; h < grp[k].getStudents().size(); h++)
					{
						if (grp[k].getStudents()[h].getName() == input)
							ctrl = true;
					}
				}
			}
		}

		if (!ctrl)
		{
			cout << " '" << input << "'" << " was not found in the system.\n";
			cout << "Try again.";
			sleep(2);
		}

	} while (!ctrl);

	MainMenu();
	return;
}

void general::findStudent()
{
	string input;
	bool ctrl;
	do
	{
		system("cls");
		cout << "Please enter the name of the student OR " "back" " to return to main menu\n";
		cout << ">> ";
		cin.clear();
		cin >> input;
		//sleep(1);
		cout << "\n";

		if (input == "back")
		{
			break;
			ctrl = true;
		}
		ctrl = false;

		for (unsigned int i = 0; i < enunciations.size(); i++)
		{
			for (unsigned int j = 0; j < enunciations[i].getOccurrences().size(); j++)
			{
				vector<Occurrence> occ = enunciations[i].getOccurrences();
				for (unsigned int k = 0; k < occ[j].getGroupProjects().size(); k++)
				{
					for (unsigned int h = 0; h < occ[j].getGroupProjects()[k].getStudents().size(); h++)
					{
						if (occ[j].getGroupProjects()[k].getStudents()[h].getName() == input)
						{
							ctrl = true;
							occ[j].getGroupProjects()[k].getStudents()[h].printInfoStudent();
						}
					}
				}
			}
		}

		if (!ctrl)
		{
			cout << " '" << input << "'" << " was not found in the system.\n";
			cout << "Try again.";
			sleep(2);
		}

	} while (!ctrl);

	MainMenu();
	return;
}

void general::listStudents()
{
	system("cls");
	for (unsigned int i = 0; i < enunciations.size(); i++)
	{
		for (unsigned int j = 0; j < enunciations[i].getOccurrences().size(); j++)
		{
			for (unsigned int k = 0; k < enunciations[i].getOccurrences()[j].getGroupProjects().size(); k++)
			{
				for (unsigned int h = 0; h < enunciations[i].getOccurrences()[j].getGroupProjects()[k].getStudents().size(); h++)
				{
					enunciations[i].getOccurrences()[j].getGroupProjects()[k].getStudents()[h].printInfoStudent();
					cout << "--------------------------------------------\n";
				}
			}
		}
	}
	system("pause");
	MainMenu();
	return;
}

void general::listTeachers()
{
	system("cls");
	for (unsigned int i = 0; i < enunciations.size(); i++)
	{
		for (unsigned int j = 0; j < enunciations[i].getOccurrences().size(); j++)
		{
			for (unsigned int k = 0; k < enunciations[i].getOccurrences()[j].getGroupProjects().size(); k++)
			{
				enunciations[i].getOccurrences()[j].getGroupProjects()[k].getTeacher().printInfoProfessor();
				cout << "--------------------------------------------\n";
			}
		}
	}
	system("pause");
	MainMenu();
	return;
}

void general::addTeacher()
{
	string input;
	system("cls");

	cout << "Please enter the name of the teacher\n";
	cout << ">> ";
	cin.clear();
	cin >> input;
	cout << "The teacher will be added to an existing group project with no assigned monitor.\n";
	sleep(1);

	Professor s(input);
	bool ctrl = false;

	for (unsigned int i = 0; i < enunciations.size(); i++)
	{
		for (unsigned int k = 0; k < enunciations[i].getOccurrences().size(); k++)
		{
			vector<Occurrence> occ = enunciations[i].getOccurrences();
			for (unsigned int j = 0; i < occ[k].getGroupProjects().size(); j++)
			{
				if (occ[k].getGroupProjects()[j].getTeacher().getName() == "no_teacher")
				{
					occ[k].getGroupProjects()[j].setTeacher(s);
					ctrl = true;
				}
			}
		}
	}

	if (ctrl)
		cout << "The teacher was added with success\n";
	else
	{
		cout << "Was not possible to add this teacher\n";
		cout << "Returning to main menu";
	}
	sleep(2);
	MainMenu();
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

	for (unsigned int i = 0; i < enunciations.size(); i++)
	{
		for (unsigned int k = 0; k < enunciations[i].getOccurrences().size(); k++)
		{
			vector<Occurrence> occ = enunciations[i].getOccurrences();
			for (unsigned int j = 0; i < occ[k].getGroupProjects().size(); j++)
			{
				if (occ[k].getGroupProjects()[j].addStudent(s))
				{
					occ[k].getGroupProjects()[j].getStudents()[occ[k].getGroupProjects()[j].getStudents().size() - 1].addNewTitle(enunciations[i].getTitle());
					ctrl = true;
				}
			}
		}
	}

	if (ctrl)
		cout << "The student was added with success\n";
	else
	{
		cout << "Was not possible to add this student\n";
		cout << "Returning to main menu";
	}
	sleep(2);
	MainMenu();
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
	} while (!verifyGetline(1, 3, input));

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
		cout << "2. Browse Students / Teachers\n";
		cout << "3. Create new Occurrence\n";
		cout << "4. Exit\n";

		cout << ">> ";
		getline(cin, input);
		cin.clear();
	} while (!verifyGetline(1, 4, input));

	if (input == "1")
		browseEnunciationMenu();
	else if (input == "2")
		browseTechersStudentMenu();
	else if (input == "4")
		createNewOccurrence();
	else if (input == "4")
		exit(0);
}

int main()
{
	general g;
	if (g.checkGoodDateInput("2015-2016"))
		cout << "ta fixe";
	else
		cout << "nao ta fixe";
	//g.MainMenu();
	return 0;
}
