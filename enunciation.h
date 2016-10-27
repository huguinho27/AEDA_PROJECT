#ifndef ENUNCIATION_H
#define ENUNCIATION_H

using namespace std;
#include <iostream>

class Enunciation
{
protected:
	string title, description;
	vector <string> years;
	vector <vector <Student>> studentsByYear;
public:
	Enunciation(string title, string description);
	string getTitle() const;
	string getDescription() const;
	vector <string> getYears();
	vector <vector <Student>> getStudentsByYear();
	void setTittle(string newTitle);
	void setDescription(string newDescription);
	void addYear(string newYear);
	void addStudents(vector <Student> students);
	void addStudentsOfYear(string newYear, vector <Student> students);
};



#endif /* ENUNCIATION_H */

