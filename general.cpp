#include <iostream>
#include <vector>
#include <unistd.h>
#include <string>
#include "enunciation.h"
#include "insertionSort.h"

using namespace std;

class general
{
	vector<Enunciation> enunciations;
	vector<Enunciation> unused_enunciation;
	vector<Student> students;
	vector<Professor> professors;
	int static personId;
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
	void storeALLEnunciationsInFile();
	void storeUnusedEnunciationsInFile();
	void readALLEnunciationsFromFile();
	void readPeopleFromFile();
	void readProjectsFromFile();
	void readUnusedEnunciationsFromFile();
	int newId();
	void storePeopleInFile();
	void storeProjectsInFile();
	vector<Enunciation> sortEnunciations();
};

int general::personId = 1000;

int general::newId()
{
	for (unsigned int i = 0; i < students.size(); i++)
	{
		if (students[i].getId() == personId)
		{
			personId++;
			newId();
		}
	}
	for (unsigned int i = 0; i < professors.size(); i++)
	{
		if (professors[i].getId() == personId)
		{
			personId++;
			newId();
		}
	}
	return personId;
}

general::general()
{
}
;

void general::readUnusedEnunciationsFromFile()
{
	string line;
	string fName = "unused_enunciation.txt";
	ifstream myfile(fName.c_str());

	if (!myfile)
	{
		cerr << "Unable to open file " << fName;
		exit(1);
	}

	string title, description, year, code;
	vector<string> years;

	while (!myfile.eof())
	{
		stringstream linestream(line);

		getline(linestream, code, ';');

		getline(linestream, title, ';');

		getline(linestream, description, ';');

		if (code == "0")
		{
			Enunciation r(title, description);
			unused_enunciation.push_back(r);
		} else if (code == "1")
		{
			EnunciationResearch r(title, description);
			unused_enunciation.push_back(r);
		} else if (code == "2")
		{
			EnunciationAnalysis r(title, description);
			unused_enunciation.push_back(r);
		} else if (code == "3")
		{
			EnunciationDevelopment r(title, description);
			unused_enunciation.push_back(r);
		}

	}
	myfile.close();
}

void general::readALLEnunciationsFromFile()
{
	string line;
	string fName = "enunciation.txt";
	ifstream myfile(fName.c_str());

	if (!myfile)
	{
		cerr << "Unable to open file " << fName;
		exit(1);
	}

	string title, description, year, code;
	vector<string> years;

	while (!myfile.eof())
	{
		stringstream linestream(line);

		getline(linestream, code, ';');

		getline(linestream, title, ';');

		getline(linestream, description, ';');

		while (getline(linestream, year, ';'))
		{
			years.push_back(year);
		}

		if (code == "0")
		{
			Enunciation r(title, description);
			for (unsigned int i = 0; i < years.size(); i++)
			{
				Occurrence o(years[i]);
				r.addYear(o);
			}
			enunciations.push_back(r);
		} else if (code == "1")
		{
			EnunciationResearch r(title, description);
			for (unsigned int i = 0; i < years.size(); i++)
			{
				Occurrence o(years[i]);
				r.addYear(o);
			}
			enunciations.push_back(r);
		} else if (code == "2")
		{
			EnunciationAnalysis r(title, description);
			for (unsigned int i = 0; i < years.size(); i++)
			{
				Occurrence o(years[i]);
				r.addYear(o);
			}
			enunciations.push_back(r);
		} else if (code == "3")
		{
			EnunciationDevelopment r(title, description);
			for (unsigned int i = 0; i < years.size(); i++)
			{
				Occurrence o(years[i]);
				r.addYear(o);
			}
			enunciations.push_back(r);
		}

	}
	myfile.close();
	readUnusedEnunciationsFromFile();
}

void general::readPeopleFromFile()
{
	string line;
	string fName = "people.txt";
	ifstream myfile(fName.c_str());

	if (!myfile)
	{
		cerr << "Unable to open file " << fName;
		exit(1);
	}

	string status;
	string sId;
	int id;
	string name;
	stringstream convert;

	while (!myfile.eof())
	{
		stringstream linestream(line);
		getline(linestream, status, ';');
		getline(linestream, sId, ';');
		getline(linestream, name, ';');
		convert << sId;
		convert >> id;
		if (status == "1")
		{
			Student st(name, id);
			students.push_back(st);
		} else if (status == "2")
		{
			Professor pr(name, id);
			professors.push_back(pr);
		} else
			cerr << "Unknown person";

	}
	myfile.close();
}

void general::readProjectsFromFile()
{
	string line;
	ifstream myfile("projects.txt");

	if (!myfile)
	{
		cerr << "Unable to open file projects.txt";
		exit(1);
	}

	string title;
	string year;
	string sNumMax, sIdProf, sIdSt, sMark;
	int numMax, idProf, idSt;
	float mark;

	while (!myfile.eof())
	{
		stringstream convMax, convP;
		vector<Student> stud;
		stringstream linestream(line);
		getline(linestream, title, ';');
		getline(linestream, year, ';');
		getline(linestream, sNumMax, ';');
		convMax << sNumMax;
		convMax >> numMax;
		getline(linestream, sIdProf, ';');
		convP << sIdProf;
		convP >> idProf;
		while (getline(linestream, sIdSt, ';'))
		{
			stringstream convS, convM;
			convS << sIdSt;
			convS >> idSt;
			getline(linestream, sMark, ';');
			convM << sMark;
			convM >> mark;
			for (unsigned int i = 0; i < students.size(); i++)
			{
				if (students[i].getId() == idSt)
				{
					students[i].addNewTitle(title);
					students[i].setMark(mark, title);
					stud.push_back(students[i]);
					break;
				}
			}
		}

		groupProject gp(stud);
		for (unsigned int i = 0; i < professors.size(); i++)
		{
			if (professors[i].getId() == idProf)
			{
				professors[i].addNewTitle(title);
				gp.setTeacher(professors[i]);
				break;
			}
		}
		gp.setMaxNum(numMax);
		for (unsigned int i = 0; i < enunciations.size(); i++)
		{
			if (enunciations[i].getTitle() == title)
			{
				for (unsigned int j = 0; j < enunciations[i].getOccurrences().size(); j++)
				{
					if (enunciations[i].getOccurrences()[j].getYear() == year)
					{
						enunciations[i].getOccurrences()[j].newGroupProject(gp);
						break;
					}
				}
				break;
			}
		}

	}
	myfile.close();
}

void general::storeUnusedEnunciationsInFile() {
	string fName = "unused_enunciations.txt";
	ofstream myfile(fName.c_str());
	myfile.clear();
	string title;
	string description;
	string code;

	if (myfile.is_open()) {
		for (unsigned int i = 0; i < unused_enunciation.size(); i++) {
			code = unused_enunciation[i].getCode();
			title = unused_enunciation[i].getTitle();
			description = unused_enunciation[i].getDescription();
			myfile << code << ";";
			myfile << title << ";";
			myfile << description << ";\n";
		}
		myfile.close();
	} else
		cout << "Unable to open file " << fName << "\n";
}

void general::storeALLEnunciationsInFile() {
	string fName = "enunciation.txt";
	ofstream myfile(fName.c_str());
	myfile.clear();
	string title;
	string description;
	string code;

	if (myfile.is_open()) {
		for (unsigned int i = 0; i < enunciations.size(); i++) {
			code = enunciations[i].getCode();
			title = enunciations[i].getTitle();
			description = enunciations[i].getDescription();
			myfile << code << ";";
			myfile << title << ";";
			myfile << description << ";";

			if (enunciations[i].getOccurrences().size() != 0) {
				for (unsigned int j = 0; j < enunciations[i].getOccurrences().size(); j++) {
					myfile << enunciations[i].getOccurrences()[j].getYear() << ";";
					}
				}
			myfile << "\n";
			}
		myfile.close();
	}
	else
		cout << "Unable to open file " << fName << "\n";
	storeUnusedEnunciationsInFile();
}

void general::storePeopleInFile()
{
	string fName = "people.txt";
	ofstream myfile(fName.c_str());
	myfile.clear();
	int id;
	string name;

	if (myfile.is_open())
	{
		for (unsigned int i=0; i<students.size(); i++)
		{
			id = students[i].getId();
			name = students[i].getName();
			myfile << "1;" << id << ";" << name << ";\n";
		}
		for (unsigned int i=0; i<professors.size(); i++)
		{
			id = professors[i].getId();
			name = professors[i].getName();
			myfile << "2;" << id << ";" << name << ";\n";
		}
		myfile.close();
	}
	else
		cout << "Unable to open file " << fName << "\n";
}

void general::storeProjectsInFile()
{
	string fName = "projects.txt";
	ofstream myfile(fName.c_str());
	myfile.clear();
	string title, year;
	int idPr, idSt, maxN;
	float mark;

	if (myfile.is_open())
	{
		for (unsigned int i=0; i<enunciations.size(); i++)
		{
			title = enunciations[i].getTitle();
			for (unsigned int j=0; j<enunciations[i].getOccurrences().size(); j++)
			{
				year = enunciations[i].getOccurrences()[j].getYear();
				for (unsigned int k=0; k<enunciations[i].getOccurrences()[j].getGroupProjects().size(); k++)
				{
					idPr = enunciations[i].getOccurrences()[j].getGroupProjects()[k].getTeacher().getId();
					maxN = enunciations[i].getOccurrences()[j].getGroupProjects()[k].getMax();
					myfile << title << ";" << year << ";" << maxN << ";" << idPr << ";";
					for (unsigned int l=0; l<enunciations[i].getOccurrences()[j].getGroupProjects()[k].getStudents().size(); l++)
					{
						idSt = enunciations[i].getOccurrences()[j].getGroupProjects()[k].getStudents()[l].getId();
						mark = enunciations[i].getOccurrences()[j].getGroupProjects()[k].getStudents()[l].getMark(title);
						myfile << idSt << ";" << mark << ";";
					}
					myfile << "\n";
				}
			}
		}
		myfile.close();
	}
	else
		cout << "Unable to open file " << fName << "\n";
}

/**
 * Checks if an input is a number and if it it between init and end values
 * @return true if ok, false if not
 */
bool general::verifyGetline(int init, int end, string input)
{
	if (input == "back")
		return true;
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

	bool good = true;

	for (unsigned int i = 0; i < date.size(); i++)
	{
		if (i == 4)
		{
			if (date[i] != '-')
				return false;
		} else if (date[i] < '0' || date[i] > '9')
		{
			return false;
		}
	}

	if (part1 > part2)
		return false;
	return good;
}

void general::createNewOccurrence()
{
	string currYear;
	bool has_only_digits;

	do
	{
		system("cls");
		cout << "What's the current year?\n";
		cin >> currYear;
		has_only_digits = (currYear.find_first_not_of("0123456789") == string::npos);


	}while (!has_only_digits);

	vector<Enunciation> en = sortEnunciations();

	for (unsigned int i = 0; i < en.size(); i++)
	{
		for (unsigned int j = 0; j < enunciations.size(); j++)
		{
			if (enunciations[j].getTitle() == en[i].getTitle())
			{
				/*Occurrence o()
				enunciations[j].addYear()*/
			}
		}
	}
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
		EnunciationResearch d(title, description);
		unused_enunciation.push_back(d);
	} else if (input == "2")
	{
		EnunciationAnalysis d(title, description);
		unused_enunciation.push_back(d);
	} else if (input == "3")
	{
		EnunciationDevelopment d(title, description);
		unused_enunciation.push_back(d);
	} else if (input == "4")
	{
		Enunciation d(title, description);
		unused_enunciation.push_back(d);
	}

	if (unused_enunciation.size() > (unsigned int) control)
		cout << "Enunciation added with success\n";
	else
		cout << "Error while adding enunciation\n";

	sleep(2);
	MainMenu();
	return;
}

void general::findTeacher() //DONE, I THINK
{
	string input;
	bool ctrl = false;

	do
	{
		do
		{
			system("cls");

			cout << "Search teacher by name or id? (0: name ; 1: id) OR " "back" " to return to menu\n";
			cout << ">> ";
			cin.clear();
			cin >> input;
			cout << "\n";
		} while (!verifyGetline(0, 1, input));

		if (input == "back")
		{
			ctrl = true;
		} else
		{
			for (unsigned int i = 0; i < professors.size(); i++)
			{
				if (input == "0")
				{
					if (professors[i].getName() == input)
					{
						professors[i].printInfoProfessor();
						ctrl = true;
					}
				} else if (input == "1")
				{
					if (professors[i].getId() == atoi(input.c_str()))
					{
						professors[i].printInfoProfessor();
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

	system("pause");
	MainMenu();
	return;
}

vector<Enunciation> general::sortEnunciations()
{
	int yearsAgo, minNumStu, counter;
	vector<Enunciation> end;

	system("cls");

	cout << "From how many years ago do you wish to use enunciations?\n";
	cin >> yearsAgo;
	cout << "What's the minimum number of group projects an enunciation must have NOT to be chosen for next occurrence?\n";
	cin >> minNumStu;

	for (unsigned int i = 0; i < enunciations.size(); i++)
	{
		counter = 0;
		enunciations[i].sortOccurrences();

		counter += enunciations[i].getOccurrences()[0].getGroupProjects().size();

		if (counter < minNumStu)
			end.push_back(enunciations[i]);
		else if (atoi(enunciations[i].getOccurrences()[0].getYear().c_str()) - atoi(enunciations[i].getOccurrences()[1].getYear().c_str()) >= yearsAgo)
			end.push_back(enunciations[i]);
	}

	cout << "Enunciations approved are the following\n";
	for (unsigned int i = 0; i < end.size(); i++)
	{
		end[i].getInfo();
		cout << "--------------------------------------------\n";
	}
	system("pause");
	return end;
}

void general::findStudent()
{
	string input;
	bool ctrl = false;

	do
	{
		do
		{
			system("cls");

			cout << "Search student by name or id? (0: name ; 1: id) OR " "back" " to return to menu\n";
			cout << ">> ";
			cin.clear();
			cin >> input;
			cout << "\n";
		} while (!verifyGetline(0, 1, input));

		if (input == "back")
		{
			ctrl = true;
		} else
		{
			for (unsigned int i = 0; i < students.size(); i++)
			{
				if (input == "0")
				{
					if (students[i].getName() == input)
					{
						students[i].printInfoStudent();
						ctrl = true;
					}
				} else if (input == "1")
				{
					if (students[i].getId() == atoi(input.c_str()))
					{
						students[i].printInfoStudent();
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

	system("pause");
	MainMenu();
	return;
}

void general::listStudents()
{
	system("cls");
	for (unsigned int i = 0; i < students.size(); i++)
	{
		students[i].printInfoStudent();
		cout << "--------------------------------------------\n";
	}
	system("pause");
	MainMenu();
	return;
}

void general::listTeachers()
{
	system("cls");
	for (unsigned int i = 0; i < professors.size(); i++)
	{
		professors[i].printInfoProfessor();
		cout << "--------------------------------------------\n";
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

	Professor s(input, newId());
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
	sleep(1);

	Student s(input, newId());

	int ctrl = students.size();
	students.push_back(s);

	if (ctrl < students.size())
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
	else if (input == "3")
		createNewOccurrence();
	else if (input == "4")
		exit(0);
}

int main()
{
	general g;
	g.MainMenu();
	return 0;
}
