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


void generateEnunciation(){
	string line;
	ifstream myfile ("enunciation.txt");
	if (!myfile)
	{
		cerr << "Unable to open file enunciation.txt";
		exit(1);
	}
	string title;
	string description;
	string year;
	vector <string> years;

	while (!myfile.eof())
		{
			getline(myfile, line);
			stringstream linestream(line);
			string data;

			linestream >> title;

			getline(linestream, data, ';');
			linestream >> description;
			while (getline(linestream, data, ';')){
			linestream >> year;
			years.push_back(year);
			}
		}
	myfile.close();
}


void saveEnunciation(Enunciation enun){
	ofstream myfile ("enunciation.txt");
	string title = enun.getTitle();
	string description = enun.getDescription();
	vector <string> years = enun.getYears();
	  if (myfile.is_open())
	  {
	    myfile << title << ";";
	    myfile << description << ";";
	    for (size_t i = 0; i < years.size(); i++){
	    	myfile << years[i];
	    	unsigned int j = years.size();
	    	j--;
	    	if (i != j){
	    		myfile << ";";
	    	}
	    }
	    myfile.close();
	  }
	  else cout << "Unable to open file enunciation.txt";
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
