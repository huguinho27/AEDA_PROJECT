#include "enunciation.h"
#include "occurrence.h"
#include "insertionSort.h"

using namespace std;

Enunciation::Enunciation()
{
}
;

Enunciation::Enunciation(string title, string description)
{
	this->title = title;
	this->description = description;
}

string Enunciation::getTitle() const
{
	return title;
}

string Enunciation::getDescription() const
{
	return description;
}

void Enunciation::setTitle(string newTitle)
{
	title = newTitle;
}

void Enunciation::setDescription(string newDescription)
{
	description = newDescription;
}

void Enunciation::addYear(Occurrence newYear)
{
	years.push_back(newYear);
}

vector <Occurrence> Enunciation::getOccurrences() const
{
	return years;
}

string Enunciation::getInfo()
{
	insertionSort(years);

	stringstream ss;
	ss << "Title: " << title << "\n" << "Description: " << description << "\n"
			<< "Years used: " << "\n";
	for (unsigned int i = 0; i < years.size(); i++)
	{
		if (i == years.size()-1)
		{
			ss << years.size() << " - " <<years[i].getYear() << ".\n";
			break;
		}
		ss << i+1 << " - " << years[i].getYear() << ",\n";
	}
	return ss.str();
}

string Enunciation::getCode()
{
	return "0";
}

void Enunciation::sortOccurrences()
{
	insertionSort(years);
}

string Enunciation::getAddition(){return "";};

/*Research*/
EnunciationResearch::EnunciationResearch(string title, string description) : Enunciation(title, description)
{

}

string EnunciationResearch::getAddition()
{
	return biblio;
}

void EnunciationResearch::setBiblio(string biblio)
{
	this->biblio = biblio;
}

string EnunciationResearch::getInfo()
{
	stringstream ss;
	ss << "Enunciation type: Research\n" << Enunciation::getInfo() << "\n";
	ss << "Bibliographical references: " << biblio << "\n";
	return ss.str();
}

string EnunciationResearch::getCode()
{
	return "1";
}

/*Analysis*/
EnunciationAnalysis::EnunciationAnalysis(string title, string description) : Enunciation(title, description)
{
}

string EnunciationAnalysis::getAddition()
{
	return repos;
}

void EnunciationAnalysis::setRepos(string repos)
{
	this->repos = repos;
}

string EnunciationAnalysis::getInfo()
{
	stringstream ss;
	ss << "Enunciation type: Analysis\n" << Enunciation::getInfo() << "\n";
	ss << "Data repositories: " << repos << "\n";
	return ss.str();
}

string EnunciationAnalysis::getCode()
{
	return "2";
}

/*Development*/

EnunciationDevelopment::EnunciationDevelopment(string title, string description) : Enunciation(title, description)
{

}

string EnunciationDevelopment::getAddition()
{
	return results;
}

void EnunciationDevelopment::setResult(string results)
{
	this->results = results;
}

string EnunciationDevelopment::getInfo()
{
	stringstream ss;
	ss << "Enunciation type: Development\n" << Enunciation::getInfo() << "\n";
	ss << "Data repositories: " << results << "\n";
	return ss.str();
}

string EnunciationDevelopment::getCode()
{
	return "3";
}
