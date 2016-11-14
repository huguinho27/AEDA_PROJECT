#include <iostream>
#include <vector>
#include "student.h"
#include "curricularUnit.h"

using namespace std;

class general
{
	vector<Student> students;
	vector<curricularUnit> currs;
public:
	general();
	void MainMenu();
};

general::general(){};

void general::MainMenu()
{
	int option;
	cout << "ENUNCIATIONS MANAGEMENT OF FEUP\n\n";
	cout << "1. Browse Curricular Units\n";
	cout << "2. Browse Enunciations\n";
	cout << "3. Browse Teachers/Students\n";
	cout << "4. Browse Group Projects\n";
	cout << "5. Exit";
	cin.clear();
	cin >> option;

	switch (option)
	{
	case 1:
		//cout << "2" << endl;
		break;
	}
}

int main()
{
	general g;
	g.MainMenu();
	return 0;
}
