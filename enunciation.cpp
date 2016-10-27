#include "enunciation.h"

using namespace std;

Enunciation::Enunciation(string title, string description){
	this->title = title;
	this->description = description;
}

string Enunciation::getTitle() const{
	return title;
}

string Enunciation::getDescription() const{
	return description;
}


vector <string> Enunciation::getYears(){
	return years;
}

vector <vector <Student>> Enunciation::getStudentsByYear(){
	return studentsByYear;
}


void Enunciation::setTittle(string newTitle){
	title = newTitle;
}

void Enunciation::setDescription(string newDescription){
	description = newDescription;
}

void Enunciation::addYear(string newYear){
	years.push_back(newYear);
}

void Enunciation::addStudents(vector <Student> students){
	studentsByYear.push_back(students);
}

void Enunciation::addStudentsOfYear(string newYear, vector <Student> students){
	addYear(newYear);
	addStudents(students);
}

