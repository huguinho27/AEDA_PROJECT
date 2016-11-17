#include "occurrence.h"

using namespace std;

Occurrence::Occurrence(){};

Occurrence::Occurrence(string schoolYear)
{
	this->schoolYear = schoolYear;
}

string Occurrence::getYear() const
{
	return schoolYear;
}
