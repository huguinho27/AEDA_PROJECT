#include "enunciation.h"
#include "occurrence.h"
#include "insertionSort.h"
//#include "algorithm"

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

/*Research*/
EnunciationResearch::EnunciationResearch(string title, string description) : Enunciation(title, description)
{
	vector<string> v;
	this->biblio = v;
}

vector<string> EnunciationResearch::getBiblio()
{
	return biblio;
}

void EnunciationResearch::setBiblio(vector<string> biblio)
{
	this->biblio = biblio;
}

void EnunciationResearch::newBiblio(string biblio1)
{
	biblio.push_back(biblio1);
}

string EnunciationResearch::getInfo()
{
	stringstream ss;
	ss << "Enunciation type: Research\n" << Enunciation::getInfo() << "\n";
	ss << "Bibliographical references:\n";
	for (unsigned int i = 0; i<biblio.size(); i++)
	{
		if (i == biblio.size()-1)
		{
			ss << biblio.size() << " - " <<biblio[i] << ".\n";
		}
		ss << i+1 << " - " << biblio[i] << ";\n";
	}
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
	this->repos = v;
}

vector<string> EnunciationAnalysis::getRepos()
{
	return repos;
}

void EnunciationAnalysis::newRepos(string repos1)
{
	repos.push_back(repos1);
}

void EnunciationAnalysis::setRepos(vector<string> repos)
{
	this->repos = repos;
}

string EnunciationAnalysis::getInfo()
{
	stringstream ss;
	ss << "Enunciation type: Analysis\n" << Enunciation::getInfo() << "\n";
	ss << "Data repositories:\n";
	for (unsigned int i = 0; i<repos.size(); i++)
	{
		if (i == repos.size()-1)
		{
			ss << repos.size() << " - " <<repos[i] << ".\n";
		}
		ss << i+1 << " - " << repos[i] << ";\n";
	}
	return ss.str();
}

string EnunciationAnalysis::getCode()
{
	return 2;
}

/*Development*/
EnunciationDevelopment::EnunciationDevelopment(string title, string description) : Enunciation(title, description)
{
	vector<string> v;
	this->results = v;
}

vector<string> EnunciationDevelopment::getResults()
{
	return results;
}

void EnunciationDevelopment::newResult(string result1)
{
	results.push_back(result1);
}

void EnunciationDevelopment::setResult(vector<string> results)
{
	this->results = results;
}

string EnunciationDevelopment::getInfo()
{
	stringstream ss;
	ss << "Enunciation type: Development\n" << Enunciation::getInfo() << "\n";
	ss << "Data repositories:\n";
	for (unsigned int i = 0; i<results.size(); i++)
	{
		if (i == results.size()-1)
		{
			ss << results.size() << " - " <<results[i] << ".\n";
		}
		ss << i+1 << " - " << results[i] << ";\n";
	}
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



/*
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
