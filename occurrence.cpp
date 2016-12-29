#include "occurrence.h"
#include <sstream>

using namespace std;

Occurrence::Occurrence(){};

Occurrence::Occurrence(string schoolYear)
{
	this->schoolYear = schoolYear;
}

void Occurrence::setYear(string year)
{
	schoolYear = year;
}

void Occurrence::newGroupProject(groupProject *proj)
{
	proj->setTitle(title);
	proj->setYear(schoolYear);
	proj->setType(type);
	projects.push_back(proj);
}

string Occurrence::getYear() const
{
	return schoolYear;
}

string Occurrence::getType()
{
	return type;
}

vector<groupProject *> Occurrence::getGroupProjects() const
{
	return projects;
}
 string Occurrence::printInfoOccurrence(string title)
 {
	 stringstream ss;
	 ss << schoolYear << "\n\n";
	 ss <<"Title: " << title << "\n\n";
	 for (unsigned int i=0; i<projects.size(); i++)
	 {
		 ss << (i+1) << " - ";
		 for (unsigned int j=0; j<projects[i]->getStudents().size(); j++)
		 {
			 ss << projects[i]->getStudents()[j]->getName() << "; ";
		 }
		 ss << "\n";
	 }
	 return ss.str();
 }

 bool Occurrence::operator<(const Occurrence &right)
 {
	 return schoolYear > right.getYear();
 }
