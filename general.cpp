/*#include "curricularUnit.h"
 #include "enunciation.h"
 #include "student.h"*/
#include <iostream>

using namespace std;

class general
{
	/*vector<curricularUnit> curricularUnits;
	vector<Enunciation> enunciations;
	vector<Student> students;*/
public:
	general();
	void MainMenu();

};

void general::MainMenu()
{
	int option;
	cout << "ENUNCIATIONS MANAGEMENT OF FEUP\n";
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
		cout << "ola\n";
		//CurricularUnitInterface();
		break;
	}
}
int main()
{
	general g;
	g.MainMenu();
	return 0;
}
