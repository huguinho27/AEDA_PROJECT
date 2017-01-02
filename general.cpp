#include <iostream>
#include <vector>
#include <unistd.h>
#include <string>
#include <queue>
#include <ctime>
#include "enunciation.h"
#include "insertionSort.h"
#include "groupProject.h"

using namespace std;
struct groupProjectHash
{
	int operator()(const groupProject *gp) const
	{
		int v;
		stringstream ss;
		for (unsigned int i = 0; i < gp->getStudents().size(); i++)
			ss << (gp->getStudents()[i]->getId()-1000);
		string ids = ss.str();
		v = atoi(ids.c_str());
		return v;
	}

	bool operator()(const groupProject *gp1, const groupProject *gp2) const
	{
		return gp1 == gp2;
	}
};
typedef tr1::unordered_set<groupProject*, groupProjectHash, groupProjectHash> tabHProject;
typedef priority_queue<groupProject *> HEAP_GP;

class general
{
	vector<Enunciation *> enunciations;
	vector<Enunciation *> unused_enunciation;
	vector<Student *> students;
	vector<Professor *> professors;
	int static personId;

	//2nd part
	BST<groupProject *> gProjects;
	tabHProject oldGP;
	HEAP_GP notValuatedGP;

public:
	general() :
			gProjects(new groupProject())
	{
	}
	;
	void MainMenu();
	bool verifyGetline(int init, int end, string input);
	void browseTechersStudentMenu();
	void browseEnunciationMenu();
	void createEnunciationMenu();
	void listEnunciations(vector<Enunciation *> le);
	void findTeacher();
	void findStudent();
	void listStudents();
	void listTeachers();
	void addTeacher();
	void addStudent();
	void createNewOccurrence(string title, string year);
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
	void sortByNumberStudentsEnunciations();
	void enunciationShow(Enunciation *en);
	void yearShow(Occurrence *year, string title);
	void projectShow(groupProject *pr, string title, Occurrence *year);
	void listUnusedEnunciations();

	//2nd part
	void listBSTEnunciationsByType();
	void evaluateEnunciations();
	void findLastProject();
	void browseGPMenu();
	void moveOldProjects();
	string getOldYear();
	void listOldByTopic();
	void listOldByType();
};

int general::personId = 1000;

int general::newId()
{
	for (unsigned int i = 0; i < students.size(); i++)
	{
		if (students[i]->getId() == personId)
		{
			personId++;
			newId();
		}
	}
	for (unsigned int i = 0; i < professors.size(); i++)
	{
		if (professors[i]->getId() == personId)
		{
			personId++;
			newId();
		}
	}
	return personId;
}

string general::getOldYear()
{
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	int year;
	int month;
	year = timePtr->tm_year + 1900;
	month = timePtr->tm_mon + 1;
	stringstream ss;
	if (month > 8)
	{
		ss << year - 5 << "/" << year - 4;
	}
	else
	{
		ss << year - 6 << "/" << year - 5;
	}
	return ss.str();
}

void general::moveOldProjects()
{
	BSTItrIn<groupProject *> it(gProjects);
	string year = getOldYear();
	while (!it.isAtEnd())
	{
		if (it.retrieve()->getYear() <= year)
		{
			groupProject *gp = it.retrieve();
			oldGP.insert(gp);
			gProjects.remove(gp);
		}
		it.advance();
	}
}

void general::listOldByTopic()
{
	moveOldProjects();
	string input;
	system("cls");
	cout << "Group projects for which assignment do you wish to display? (enter the title)\n";
	getline(cin, input);
	cin.clear();

	if (oldGP.empty())
	{
		cout << "No group projects to show, size = 0\n";
		system("pause");
		return;
	}
	else
	{
		vector<string> end;
		tabHProject::iterator it = oldGP.begin();
		while (it != oldGP.end())
		{
			if ((*it)->getTitle() == input)
			{
				end.push_back((*it)->printInfoProject(input));
				end.push_back("--------------------------------------------\n");
			}
			it++;
		}
		if (end.empty())
		{
			cout << "No group projects for this assignment\n";
			system("pause");
			return;
		}

		for (unsigned int i = 0; i < end.size(); i++)
			cout << end[i];

		cout << "Write 'back' to go back to previous menu\n";
		cout << ">> ";
		getline(cin, input);
		cin.clear();
		if (input == "back") browseGPMenu();
	}
}

void general::listOldByType()
{
	moveOldProjects();
	string input;
	do
	{
		system("cls");
		cout << "What is the type of assignment you wish to display? ( 1 - research, 2 - analysis, 3 - development, 9 - general)\n";
		getline(cin, input);
		cin.clear();

		if (input != "1" && input != "2" && input != "3" && input != "9" && input != "back")
		{
			cout << "Wrong code. Available types are: 1 - research, 2 - analysis, 3 - development, 9 - general\n";
			system("pause");
		} else
			break;

	} while (true);

	if (input == "back") {browseGPMenu(); return;}

	if (oldGP.empty())
	{
		cout << "No group projects to show, size = 0\n";
		system("pause");
		return;
	}
	else
	{
		vector<string> end;
		tabHProject::iterator it = oldGP.begin();
		while (it != oldGP.end())
		{
			if ((*it)->getType() == input)
			{
				end.push_back((*it)->printInfoProject((*it)->getTitle()));
				end.push_back("--------------------------------------------\n");
			}
			it++;
		}
		if (end.empty())
		{
			cout << "No group projects for this type\n";
			system("pause");
			return;
		}

		for (unsigned int i = 0; i < end.size(); i++)
			cout << end[i];

		cout << "Write 'back' to go back to previous menu\n";
		cout << ">> ";
		getline(cin, input);
		cin.clear();
		if (input == "back") browseGPMenu();
	}
}

void general::findLastProject()
{
	string input;
	system("cls");
	cout << "The most recent work for which assignment do you wish to display? (enter the title)\n";
	getline(cin, input);
	cin.clear();
	bool control = false;
	bool found = false;

	BSTItrIn<groupProject *> it(gProjects);
	if (it.isAtEnd())
	{
		cout << "No group projects to show, size = 0\n";
		control = true;
		system("pause");
		return;
	}

	while (!it.isAtEnd())
	{
		if (it.retrieve()->getTitle() == input)
		{
			cout << it.retrieve()->printInfoProject(it.retrieve()->getTitle());
			control = true;
			found = true;
			break;
		}
		it.advance();
	}
	if (it.isAtEnd() && (!control))
	{
		cout << "There is not any project for this assignment\n";
	}

	if (found) cout << "Write 'open' to open project's menu\n";
	cout << "Write 'back' to go back to previous menu\n";
	cout << ">> ";
	getline(cin, input);
	cin.clear();
	if (input == "back") browseGPMenu();
	else if (input == "open") projectShow(it.retrieve(), it.retrieve()->getTitle(), NULL);
}

void general::listBSTEnunciationsByType()
{
	string input;
	do
	{
		system("cls");
		cout << "What is the type of assignment you wish to display? ( 1 - research, 2 - analysis, 3 - development, 9 - general)\n";
		getline(cin, input);
		cin.clear();

		if (input != "1" && input != "2" && input != "3" && input != "9" && input != "back")
		{
			cout << "Wrong code. Available types are: 1 - research, 2 - analysis, 3 - development, 9 - general\n";
			system("pause");
		} else
			break;

	} while (true);

	if (input == "back") {browseGPMenu(); return;}

	vector<string> end;
	BSTItrIn<groupProject *> it(gProjects);
	if (it.isAtEnd())
	{
		cout << "No group projects to show, size = 0\n";
		system("pause");
		return;
	}

	while (!it.isAtEnd())
	{
		if (it.retrieve()->getType() == input)
		{
			end.push_back(it.retrieve()->printInfoProject(it.retrieve()->getTitle()));
			end.push_back("--------------------------------------------\n");
		}
		it.advance();
	}

	if (end.empty())
	{
		cout << "No group projects for assignments of type " << input << " to show\n";
		system("pause");
		return;
	}

	for (unsigned int i = 0; i < end.size(); i++)
		cout << end[i];

	cout << "Write 'back' to go back to previous menu\n";
	cout << ">> ";
	getline(cin, input);
	cin.clear();
	if (input == "back") browseGPMenu();
}

void general::enunciationShow(Enunciation *en)
{
	string input;
	do
	{
		system("cls");
		cout << en->getInfo();

		cout << "\n" << "Choose an option:\n";
		cout << "1. Open occurrence\n";
		cout << "2. New occurrence\n";
		cout << "Write 'back' to go back to previous menu\n";
		cout << ">> ";
		getline(cin, input);
		cin.clear();
	} while (!verifyGetline(1, 2, input));

	if (input == "1")
	{
		cout << "\nEnter the number of occurrence (e.g. 1)\n";
		cout << ">> ";

		getline(cin, input);
		cin.clear();

		unsigned int n = atoi(input.c_str());

		cout << "n: " << n << endl;

		if ((n - 1) >= en->getOccurrences().size())
		{
			cout << "No info of that occurrence\n";
			sleep(2);
			browseEnunciationMenu();
			return;
		}
		yearShow(en->getOccurrences()[n - 1], en->getTitle());
	} else if (input == "2")
	{
		cout << "\nEnter the year (e.g. 2014/2015)\n";
		cout << ">> ";
		getline(cin, input);
		cin.clear();
		createNewOccurrence(en->getTitle(), input);
	}

	if (input == "back")
		browseEnunciationMenu();
}

void general::yearShow(Occurrence *year, string title)
{
	string input;

	do
	{
		system("cls");
		cout << year->printInfoOccurrence(title);
		cout << "\n" << "Choose an option:\n";
		cout << "1. Open a group project\n";
		cout << "2. New group project\n";
		cout << "Write 'back' to go back to previous menu\n";
		cout << ">> ";
		getline(cin, input);
		cin.clear();
	} while (!verifyGetline(1, 2, input));

	if (input == "1")
	{
		string input;
		cout << "\n" << "Enter the number of group (e.x. 1)\n";
		cout << ">> ";
		getline(cin, input);
		cin.clear();
		unsigned int n = atoi(input.c_str());
		projectShow(year->getGroupProjects()[n - 1], title, year);
	} else if (input == "2")
	{
		groupProject *p = new groupProject();
		p->setTitle(title);
		p->setYear(year->getYear());
		p->setType(year->getType());
		p->setStatus("nf");
		gProjects.insert(p);
		year->newGroupProject(p);
		yearShow(year, title);
	}

	if (input == "back")
	{
		for (unsigned int i = 0; i < enunciations.size(); i++)
		{
			if (enunciations[i]->getTitle() == title)
			{
				enunciationShow(enunciations[i]);
			}
		}
	};

}

void general::projectShow(groupProject *pr, string title, Occurrence *year)
{

	string input;
	do
	{
		system("cls");
		cout << pr->printInfoProject(title);

		cout << "\n";
		cout << "1. Add a student\n";
		cout << "2. Remove student\n";
		cout << "3. Set teacher\n";
		cout << "4. Set maximum number of student\n";
		cout << "5. Set text file\n";
		if (pr->getStatus() == "nf")
		{
			cout << "6. Finish project\n";
		}
		cout << "Write 'back' to go back to previous menu\n";
		cout << ">> ";
		getline(cin, input);
		cin.clear();
	} while (!verifyGetline(1, 6, input));

	if (input == "1")
	{
		string inp;
		cout << "Enter the id of student\n";
		cout << ">> ";
		getline(cin, inp);
		cin.clear();
		for (unsigned int i = 0; i < students.size(); i++)
		{
			if (students[i]->getId() == atoi(inp.c_str()))
			{
				students[i]->addNewTitle(title);
				pr->addStudent(students[i]);
				break;
			}
		}
		projectShow(pr, title, year);
	} else if (input == "2")
	{
		string inp;
		cout << "Enter the id of student\n";
		cout << ">> ";
		getline(cin, inp);
		cin.clear();
		for (unsigned int i = 0; i < pr->getStudents().size(); i++)
		{
			if (pr->getStudents()[i]->getId() == atoi(inp.c_str()))
			{
				pr->removeSudent(pr->getStudents()[i], title);
				break;
			}
			if (students[i]->getId() == atoi(inp.c_str()))
			{
				students[i]->deleteTitle(title);
				break;
			}
		}
		projectShow(pr, title, year);
	} else if (input == "3")
	{
		string inp;
		cout << "Enter the id of professor\n";
		cout << ">> ";
		getline(cin, inp);
		cin.clear();
		for (unsigned int i = 0; i < professors.size(); i++)
		{
			if (professors[i]->getId() == atoi(inp.c_str()))
			{
				professors[i]->addNewTitle(title);
				pr->setTeacher(professors[i]);
				break;
			}
		}
		projectShow(pr, title, year);
	} else if (input == "4")
	{
		string inp;
		cout << "Enter the maximum number of students\n";
		cout << ">> ";
		getline(cin, inp);
		cin.clear();
		pr->setMaxNum(atoi(inp.c_str()));
		projectShow(pr, title, year);
	} else if (input == "5")
	{
		string inp;
		cout << "Enter the name of text file\n";
		cout << ">> ";
		getline(cin, inp);
		cin.clear();
		pr->setTextFile(inp);
		pr->setStatus("f");
		projectShow(pr, title, year);
	} else if (input == "6")
	{
		pr->setStatus("f");
		notValuatedGP.push(pr);
		projectShow(pr, title, year);
	} else if (input == "back")
	{
		if (year != NULL) yearShow(year, title);
		else browseGPMenu();
	}

}

void general::readUnusedEnunciationsFromFile()
{
	string line;
	string fName = "unused_enunciations.txt";
	ifstream myfile(fName.c_str());

	if (!myfile)
	{
		cerr << "Unable to open file " << fName;
		exit(1);
	}

	string title, description, year, code, addition;
	vector<string> years;

	while (!myfile.eof())
	{
		getline(myfile, line);
		stringstream linestream(line);

		getline(linestream, code, ';');

		getline(linestream, title, ';');

		getline(linestream, description, ';');

		getline(linestream, addition, ';');

		if (code == "0")
		{
			Enunciation *r = new Enunciation(title, description);
			unused_enunciation.push_back(r);
		} else if (code == "1")
		{
			EnunciationResearch *r = new EnunciationResearch(title, description);
			r->setBiblio(addition);
			unused_enunciation.push_back(r);
		} else if (code == "2")
		{
			EnunciationAnalysis *r = new EnunciationAnalysis(title, description);
			r->setRepos(addition);
			unused_enunciation.push_back(r);
		} else if (code == "3")
		{
			EnunciationDevelopment *r = new EnunciationDevelopment(title, description);
			r->setResult(addition);
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

	string title, description, year, code, addition;

	while (!myfile.eof())
	{
		getline(myfile, line);
		stringstream linestream(line);
		vector<string> years;
		getline(linestream, code, ';');
		getline(linestream, title, ';');
		getline(linestream, description, ';');
		getline(linestream, addition, ';');

		while (getline(linestream, year, ';'))
		{
			years.push_back(year);
		}

		if (code == "9")
		{
			Enunciation *r = new Enunciation(title, description);
			for (unsigned int i = 0; i < years.size(); i++)
			{
				Occurrence *o = new Occurrence(years[i]);
				o->setTitle(title);
				o->setType(code);
				r->addYear(o);
			}
			enunciations.push_back(r);
		} else if (code == "1")
		{
			EnunciationResearch *r = new EnunciationResearch(title, description);
			r->setBiblio(addition);
			for (unsigned int i = 0; i < years.size(); i++)
			{
				Occurrence *o = new Occurrence(years[i]);
				o->setTitle(title);
				o->setType(code);
				r->addYear(o);
			}
			enunciations.push_back(r);
		} else if (code == "2")
		{
			EnunciationAnalysis *r = new EnunciationAnalysis(title, description);
			r->setRepos(addition);
			for (unsigned int i = 0; i < years.size(); i++)
			{
				Occurrence *o = new Occurrence(years[i]);
				o->setTitle(title);
				o->setType(code);
				r->addYear(o);
			}
			enunciations.push_back(r);
		} else if (code == "3")
		{
			EnunciationDevelopment *r = new EnunciationDevelopment(title, description);
			r->setResult(addition);
			for (unsigned int i = 0; i < years.size(); i++)
			{
				Occurrence *o = new Occurrence(years[i]);
				o->setTitle(title);
				o->setType(code);
				r->addYear(o);
			}
			enunciations.push_back(r);
		}

	}
	myfile.close();
	readUnusedEnunciationsFromFile();
	return;
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
	string name;
	stringstream convert;

	while (!myfile.eof())
	{
		getline(myfile, line);
		stringstream linestream(line);
		getline(linestream, status, ';');
		getline(linestream, sId, ';');
		getline(linestream, name, ';');

		if (status == "1")
		{
			Student *st = new Student(name, atoi(sId.c_str()));
			students.push_back(st);
		} else if (status == "2")
		{
			Professor *pr = new Professor(name, atoi(sId.c_str()));
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

	string title, textF;
	string year, stat;
	string sNumMax, sIdProf, sIdSt, sMark;

	while (!myfile.eof())
	{
		vector<Student *> stud;

		getline(myfile, line);
		stringstream linestream(line);

		getline(linestream, title, ';');
		getline(linestream, year, ';');
		getline(linestream, sNumMax, ';');
		getline(linestream, textF, ';');
		getline(linestream, stat, ';');
		getline(linestream, sIdProf, ';');

		while (getline(linestream, sIdSt, ';'))
		{
			getline(linestream, sMark, ';');

			for (unsigned int i = 0; i < students.size(); i++)
			{
				if (students[i]->getId() == atoi(sIdSt.c_str()))
				{
					students[i]->addNewTitle(title);
					students[i]->setMark(atoi(sMark.c_str()), title);
					stud.push_back(students[i]);
				}
			}
		}

		groupProject *gp = new groupProject(stud);
		if (atoi(sIdProf.c_str()) != 0)
		{
			for (unsigned int i = 0; i < professors.size(); i++)
			{
				if (professors[i]->getId() == atoi(sIdProf.c_str()))
				{
					professors[i]->addNewTitle(title);
					gp->setTeacher(professors[i]);
				}
			}
		}
		gp->setMaxNum(atoi(sNumMax.c_str()));
		gp->setTextFile(textF);
		gp->setTitle(title);
		gp->setYear(year);
		gp->setStatus(stat);
		for (unsigned int i = 0; i < enunciations.size(); i++)
		{
			if (enunciations[i]->getTitle() == title)
			{
				for (unsigned int j = 0; j < enunciations[i]->getOccurrences().size(); j++)
				{
					if (enunciations[i]->getOccurrences()[j]->getYear() == year)
					{
						gp->setType(enunciations[i]->getCode());
						gProjects.insert(gp);
						if (stat == "f")
							notValuatedGP.push(gp);
						enunciations[i]->getOccurrences()[j]->newGroupProject(gp);
					}
				}
			}
		}
	}
	myfile.close();
}

void general::storeUnusedEnunciationsInFile()
{
	string fName = "unused_enunciations.txt";
	ofstream myfile(fName.c_str());
	myfile.clear();
	string title;
	string description;
	string code;
	string addition;

	if (myfile.is_open())
	{
		for (unsigned int i = 0; i < unused_enunciation.size(); i++)
		{
			code = unused_enunciation[i]->getCode();
			title = unused_enunciation[i]->getTitle();
			description = unused_enunciation[i]->getDescription();
			addition = unused_enunciation[i]->getAddition();
			myfile << code << ";";
			myfile << title << ";";
			myfile << description << ";";
			myfile << addition << ";";
			if ((i + 1) < unused_enunciation.size())
				myfile << "\n";
		}
		myfile.close();
	} else
		cout << "Unable to open file " << fName << "\n";
}

void general::storeALLEnunciationsInFile()
{
	string fName = "enunciation.txt";
	ofstream myfile(fName.c_str());
	myfile.clear();
	string title;
	string description;
	string code;
	string addition;

	if (myfile.is_open())
	{
		for (unsigned int i = 0; i < enunciations.size(); i++)
		{
			code = enunciations[i]->getCode();
			title = enunciations[i]->getTitle();
			description = enunciations[i]->getDescription();
			addition = enunciations[i]->getAddition();
			myfile << code << ";";
			myfile << title << ";";
			myfile << description << ";";
			myfile << addition << ";";

			if (enunciations[i]->getOccurrences().size() != 0)
			{
				for (unsigned int j = 0; j < enunciations[i]->getOccurrences().size(); j++)
				{
					myfile << enunciations[i]->getOccurrences()[j]->getYear() << ";";
				}
			}
			if ((i + 1) < enunciations.size())
				myfile << "\n";
		}
		myfile.close();
	} else
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
		for (unsigned int i = 0; i < students.size(); i++)
		{
			id = students[i]->getId();
			name = students[i]->getName();
			myfile << "1;" << id << ";" << name << ";\n";
		}
		for (unsigned int i = 0; i < professors.size(); i++)
		{
			id = professors[i]->getId();
			name = professors[i]->getName();
			myfile << "2;" << id << ";" << name << ";";
			if ((i + 1) < professors.size())
				myfile << "\n";
		}
		myfile.close();
	} else
		cout << "Unable to open file " << fName << "\n";
}

void general::storeProjectsInFile()
{
	string fName = "projects.txt";
	ofstream myfile(fName.c_str());
	myfile.clear();
	string title, year, textF, stat;
	int idPr, idSt, maxN, mark;

	if (myfile.is_open())
	{
		for (unsigned int i = 0; i < enunciations.size(); i++)
		{
			title = enunciations[i]->getTitle();
			for (unsigned int j = 0; j < enunciations[i]->getOccurrences().size(); j++)
			{
				year = enunciations[i]->getOccurrences()[j]->getYear();
				for (unsigned int k = 0; k < enunciations[i]->getOccurrences()[j]->getGroupProjects().size(); k++)
				{
					idPr = enunciations[i]->getOccurrences()[j]->getGroupProjects()[k]->getTeacher().getId();
					maxN = enunciations[i]->getOccurrences()[j]->getGroupProjects()[k]->getMax();
					textF = enunciations[i]->getOccurrences()[j]->getGroupProjects()[k]->getTextFile();
					stat = enunciations[i]->getOccurrences()[j]->getGroupProjects()[k]->getStatus();
					myfile << title << ";" << year << ";" << maxN << ";" << textF << ";" << stat << ";" << idPr << ";";
					for (unsigned int l = 0; l < enunciations[i]->getOccurrences()[j]->getGroupProjects()[k]->getStudents().size(); l++)
					{
						idSt = enunciations[i]->getOccurrences()[j]->getGroupProjects()[k]->getStudents()[l]->getId();
						mark = enunciations[i]->getOccurrences()[j]->getGroupProjects()[k]->getStudents()[l]->getMark(title);
						myfile << idSt << ";" << mark << ";";
					}
					if (((i + 1) == enunciations.size()) && ((i + 1) == enunciations[i]->getOccurrences().size())
							&& ((k + 1) == enunciations[i]->getOccurrences()[j]->getGroupProjects().size()))
					{
					} else
						myfile << "\n";
				}
			}
		}
		myfile.close();
	} else
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

void general::listEnunciations(vector<Enunciation *> le)
{

	string input;

	do
	{
		system("cls");
		for (unsigned int i = 0; i < le.size(); i++)
		{
			cout << i + 1 << " - " << le[i]->getTitle() << "\n";
		}
		cout << "\n" << "Enter the number of assignment to open it or 'back' to go back to previous menu\n";
		cout << ">> ";
		getline(cin, input);
		cin.clear();

	} while (!verifyGetline(1, le.size(), input));

	if (input == "back")
	{
		browseEnunciationMenu();
		return;
	}
	unsigned int n = atoi(input.c_str());
	enunciationShow(le[n - 1]);

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
	getline(cin, title);

	cout << "Please enter the description for the new enunciation\n";
	cout << ">> ";
	cin.clear();
	getline(cin, description);

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
		EnunciationResearch *d = new EnunciationResearch(title, description);
		unused_enunciation.push_back(d);
	} else if (input == "2")
	{
		EnunciationAnalysis *d = new EnunciationAnalysis(title, description);
		unused_enunciation.push_back(d);
	} else if (input == "3")
	{
		EnunciationDevelopment *d = new EnunciationDevelopment(title, description);
		unused_enunciation.push_back(d);
	} else if (input == "4")
	{
		Enunciation *d = new Enunciation(title, description);
		unused_enunciation.push_back(d);
	}

	if (unused_enunciation.size() > (unsigned int) control)
		cout << "Enunciation added with success\n";
	else
		cout << "Error while adding enunciation\n";

	cin.clear();
	cout << "\nPress any key to go back\n";
	cin.get();
	browseEnunciationMenu();
	return;

}

void general::createNewOccurrence(string title, string year)
{
	Occurrence *o = new Occurrence(year);
	o->setTitle(title);
	bool check = false;
	for (unsigned int i = 0; i < unused_enunciation.size(); i++)
	{
		if (unused_enunciation[i]->getTitle() == title)
		{
			Enunciation *d = unused_enunciation[i];
			o->setType(d->getCode());
			d->addYear(o);
			enunciations.push_back(d);
			unused_enunciation.erase(unused_enunciation.begin() + i);
			check = true;
		}
	}
	if (!check)
	{
		for (unsigned int i = 0; i < enunciations.size(); i++)
		{
			if (enunciations[i]->getTitle() == title)
			{
				o->setType(enunciations[i]->getCode());
				enunciations[i]->addYear(o);
				check = true;
			}
		}
	}
	if (!check)
		cout << "Enunciation was not found!\n";
	yearShow(o, title);
}

void general::findTeacher()
{
	string input, name, id;
	bool ctrl = false;

	do
	{
		do
		{
			system("cls");

			cout << "Search teacher by name or id? (0: name ; 1: id) OR " "back" " to return to menu\n";
			cout << ">> ";
			cin.clear();
			getline(cin, input);
			cout << "\n";
		} while (!verifyGetline(0, 1, input));

		if (input == "0")
		{
			cout << "Please insert the name of the teacher.\n";
			cout << ">> ";
			cin.clear();
			getline(cin, name);
		} else if (input == "1")
		{
			cout << "Please insert the id of the teacher.\n";
			cout << ">> ";
			cin.clear();
			getline(cin, id);
		}

		if (input == "back")
		{
			ctrl = true;
			browseTechersStudentMenu();
		} else
		{
			for (unsigned int i = 0; i < professors.size(); i++)
			{
				if (input == "0")
				{
					if (professors[i]->getName() == name)
					{
						cout << professors[i]->printInfoProfessor();
						ctrl = true;
					}
				} else
				{
					if (professors[i]->getId() == atoi(id.c_str()))
					{
						cout << professors[i]->printInfoProfessor();
						ctrl = true;
					}
				}

			}
		}

		if (!ctrl)
		{
			if (input == "0")
			{
				cout << " '" << name << "'" << " was not found in the system.\n";
				cout << "Try again.\n";
				sleep(2);
			} else if (input == "1")
			{
				cout << " '" << id << "'" << " was not found in the system.\n";
				cout << "Try again.\n";
				sleep(2);
			}

		}

	} while (!ctrl);

	cin.clear();
	cout << "\nPress any key to go back\n";
	cin.get();
	browseTechersStudentMenu();
	return;
}

void general::sortByNumberStudentsEnunciations()
{
	int minNumStu, counter;
	string yearsAgo;
	vector<Enunciation *> end;

	system("cls");

	cout << "Enter the latest acceptable year when the enunciation was proposed (e.g. 1999/2000)\n";
	cin.clear();
	getline(cin, yearsAgo);

	cout << "What is the maximum number of group projects for an enunciation?\n";
	cin.clear();
	cin >> minNumStu;

	for (unsigned int i = 0; i < enunciations.size(); i++)
	{
		counter = 0;
		enunciations[i]->sortOccurrences();
		if (enunciations[i]->getOccurrences()[0]->getYear() <= yearsAgo)
		{
			for (unsigned int j = 0; j < enunciations[i]->getOccurrences().size(); j++)
			{
				counter += enunciations[i]->getOccurrences()[j]->getGroupProjects().size();
			}

			if (counter <= minNumStu)
				end.push_back(enunciations[i]);
		}
	}

	listEnunciations(end);
}

void general::findStudent()
{
	string input, name, id;
	bool ctrl = false;

	do
	{
		do
		{
			system("cls");

			cout << "Search student by name or id? (0: name ; 1: id) OR " "back" " to return to menu\n";
			cout << ">> ";
			cin.clear();
			getline(cin, input);
			cout << "\n";
		} while (!verifyGetline(0, 1, input));

		if (input == "0")
		{
			cout << "Please enter the name of the student.\n";
			cout << ">> ";
			cin.clear();
			getline(cin, name);
		} else if (input == "1")
		{
			cout << "Please enter the ids of the student.\n";
			cout << ">> ";
			cin.clear();
			getline(cin, id);
		}

		if (input == "back")
		{
			ctrl = true;
			browseTechersStudentMenu();
			return;
		} else
		{
			for (unsigned int i = 0; i < students.size(); i++)
			{
				if (input == "0")
				{
					if (students[i]->getName() == name)
					{
						cout << students[i]->printInfoStudent();
						ctrl = true;
					}
				} else if (input == "1")
				{
					if (students[i]->getId() == atoi(id.c_str()))
					{
						cout << students[i]->printInfoStudent();
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

	cin.clear();
	cout << "\nPress any key to go back\n";
	cin.get();
	browseTechersStudentMenu();

	return;
}

void general::listStudents()
{
	system("cls");
	for (unsigned int i = 0; i < students.size(); i++)
	{
		cout << students[i]->printInfoStudent();
		cout << "--------------------------------------------\n";
	}

	cin.clear();
	cout << "\nPress any key to go back\n";
	cin.get();
	browseTechersStudentMenu();

	return;
}

void general::listTeachers()
{
	system("cls");
	for (unsigned int i = 0; i < professors.size(); i++)
	{
		cout << professors[i]->printInfoProfessor();
		cout << "--------------------------------------------\n";
	}

	cin.clear();
	cout << "\nPress any key to go back\n";
	cin.get();
	browseTechersStudentMenu();

	return;
}

void general::addTeacher()
{
	string input, name;
	system("cls");

	cout << "Please enter the name of the professor\n";
	cout << ">> ";
	cin.clear();
	cin >> name;

	Professor *s = new Professor(name, newId());
	professors.push_back(s);
	cout << "The professor " << name << " was added with success\n";

	cin.clear();
	cout << "\nPress any key to go back\n";
	cin.get();
	browseTechersStudentMenu();
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

	Student *s = new Student(input, newId());

	unsigned int ctrl = students.size();
	students.push_back(s);

	if (ctrl < students.size())
		cout << "The student was added with success\n";
	else
	{
		cout << "Was not possible to add this student\n";
	}

	cin.clear();
	cout << "\nPress any key to go back\n";
	cin.get();
	browseTechersStudentMenu();
}

void general::browseTechersStudentMenu()
{
	string input;
	do
	{
		system("cls");

		cout << "STUDENTS/TEACHERS MANAGEMENT\n\n";
		cout << "1. Find a professor\n";
		cout << "2. Find a student\n";
		cout << "3. List professors\n";
		cout << "4. List students\n";
		cout << "5. Add a new professor\n";
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
	else if (input == "7" || input == "back")
		MainMenu();

	return;
}

void general::listUnusedEnunciations()
{
	system("cls");

	for (unsigned int i = 0; i < unused_enunciation.size(); i++)
	{
		cout << unused_enunciation[i]->getInfo();
		cout << "--------------------------------------------\n";
	}

	system("pause");
	MainMenu();
	return;
}

void general::evaluateEnunciations()
{
	if (notValuatedGP.size() == 0)
	{
		cout << "No group projects to evaluate\n";
		system("pause");
		return;
	}

	groupProject *gp = notValuatedGP.top();
	string input;
	string id, mark;
	system("cls");
	cout << gp->printInfoProject(gp->getTitle()) << "\n";

	cout << "Enter the id of student to evaluate\n";
	cout << "Write 'finish' to finish evaluation of this group project and to go to the next one\n";
	cout << "Write 'back' to go back to previous menu\n";
	cout << ">> ";
	getline(cin, input);
	cin.clear();

	if (input == "back")
	{
		browseGPMenu();
	} else if (input == "finish")
	{
		gp->setStatus("ev");
		notValuatedGP.pop();
		evaluateEnunciations();
	}
	else
	{
		id = input;
		cout << "Enter the mark\n";
		cout << ">> ";
		getline(cin, mark);
		cin.clear();

		for (unsigned int i = 0; i < gp->getStudents().size(); i++)
		{
			if (gp->getStudents()[i]->getId() == atoi(id.c_str()))
			{
				gp->setMark(gp->getStudents()[i], atoi(mark.c_str()), gp->getTitle());
				break;
			}
			if (students[i]->getId() == atoi(id.c_str()))
			{
				students[i]->setMark(atoi(mark.c_str()), gp->getTitle());
				break;
			}
		}
		evaluateEnunciations();
	}
}

void general::browseEnunciationMenu()
{
	string input;
	do
	{
		system("cls");

		cout << "ASSIGNMENT MANAGEMENT\n\n";
		cout << "1. List all assignments\n";
		cout << "2. Create new assignment\n";
		cout << "3. Filter assignments \n";
		cout << "4. Show unused assignments\n";
		cout << "5. Back to main menu\n";

		cout << ">> ";
		getline(cin, input);
		cin.clear();
	} while (!verifyGetline(1, 5, input));

	if (input == "1")
	{
		vector<Enunciation *> el = unused_enunciation;
		for (unsigned int i = 0; i < enunciations.size(); i++)
		{
			el.push_back(enunciations[i]);
		}
		listEnunciations(el);
	}
	else if (input == "2")
		createEnunciationMenu();
	else if (input == "3")
		sortByNumberStudentsEnunciations();
	else if (input == "4")
		listEnunciations(unused_enunciation);
	else if (input == "5" || input == "back")
		MainMenu();

	return;
}

void general::browseGPMenu()
{
	string input;
	do
	{
		system("cls");

		cout << "GROUP PROJECTS MANAGEMENT\n\n";
		cout << "1. List group projects by type\n";
		cout << "2. Find the most recent group project for assignment\n";
		cout << "3. Evaluate group projects\n";
		cout << "4. List old group projects by type\n";
		cout << "5. List old group projects by title\n";
		cout << "6. Back to main menu\n";

		cout << ">> ";
		getline(cin, input);
		cin.clear();
	} while (!verifyGetline(1, 6, input));

	if (input == "1")
		listBSTEnunciationsByType();
	else if (input == "2")
		findLastProject();
	else if (input == "3")
		evaluateEnunciations();
	else if (input == "4")
		listOldByType();
	else if (input == "5")
		listOldByTopic();
	else if (input == "6" || input == "back")
		MainMenu();

	return;
}

void general::MainMenu()
{
	string input;
	do
	{
		system("cls");
		cout << "ASSIGNMENTS MANAGEMENT OF FEUP\n\n";
		cout << "1. Browse Assignments\n";
		cout << "2. Browse Students / Teachers\n";
		cout << "3. Browse Group Projects\n";
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
		browseGPMenu();
	else if (input == "4")
		return; //MUST BE 'RETURN' OTHERWISE FILES WOULD NOT BE UPDATED!!
}

int main()
{
	general g;
	g.readALLEnunciationsFromFile();
	g.readPeopleFromFile();
	g.readProjectsFromFile();
	g.moveOldProjects();
	g.MainMenu();
	g.storeALLEnunciationsInFile();
	g.storePeopleInFile();
	g.storeProjectsInFile();
	return 0;
}
