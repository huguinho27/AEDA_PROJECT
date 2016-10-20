#ifndef ENUNCIATION_H
#define ENUNCIATION_H

using namespace std;

#include <iostream>

class Enunciation
{
protected:
	string title, description;
public:
	Enunciation(string title, string description);
	string getTitle() const;
	string getDescription() const;
	void setTittle(string newTitle);
	void setDescription(string novaDescription);
};

#endif /* ENUNCIATION_H */
