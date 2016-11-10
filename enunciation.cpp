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


void Enunciation::setTittle(string newTitle){
	title = newTitle;
}

void Enunciation::setDescription(string newDescription){
	description = newDescription;
}

void Enunciation::addYear(string newYear){
	years.push_back(newYear);
}



EnunciationResearch::EnunciationResearch(string title, string description, string biblio){
	this->title = title;
	this->description = description;
	this->biblio = biblio;
}


EnunciationAnalysis::EnunciationAnalysis(string title, string description, string repos){
	this->title = title;
	this->description = description;
	this->repos = repos;
}



