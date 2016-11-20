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

/*Research*/
EnunciationResearch::EnunciationResearch(string title, string description) : Enunciation(title, description)
{
	vector<string> v;
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
	vector<string> v;
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
	vector<string> v;
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

/*void generateEnunciation()
{
	string line;
	ifstream myfile("enunciation.txt");

	if (!myfile)
	{
		cerr << "Unable to open file enunciation.txt";
		exit(1);
	}

	string title;
	string description;
	string year;
	vector<string> years;

	while (!myfile.eof())
	{
		stringstream linestream(line);

		getline(linestream, title, ';');

		getline(linestream, description, ';');

		while (getline(linestream, year, ';'))
		{
			years.push_back(year);
		}

		Enunciation(title, description);

	}
	myfile.close();
}

void saveEnunciation(Enunciation enun)
{
	ofstream myfile("enunciation.txt");
	string title = enun.getTitle();
	string description = enun.getDescription();
	vector<Occurrence> years = enun.getOccurrences()();
	unsigned int j = years.size();
	j--;
	if (myfile.is_open())
	{
		myfile << title << ";";
		myfile << description << ";";
		for (size_t i = 0; i < years.size(); i++)
		{
			myfile << years[i].getYear();

			if (i != j)
			{
				myfile << ";";
			}
		}
		myfile.close();
	} else
		cout << "Unable to open file enunciation.txt";
}




 void Transportes::fromFilesToVecItens()
 {
 itens.clear();
 ifstream inFile("itens.txt");

 if (!inFile)
 {
 cerr << "Unable to open file itens.txt";
 exit(1);
 }

 string line;
 int numfatura;
 double valor, peso;
 string nomedestino;

 while (!inFile.eof())
 {
 getline(inFile, line);
 if(line == "") continue;
 stringstream linestream(line);
 string data;

 linestream >> nomedestino;

 getline(linestream, data, ';');
 linestream >> valor;
 getline(linestream, data, ';');
 linestream >> peso;
 getline(linestream, data, ';');
 linestream >> numfatura;

 Destino d("", 0, 0, 0);
 Item i(nomedestino, valor, peso, numfatura, d);
 itens.push_back(i);
 }
 inFile.close();
 }
 */
