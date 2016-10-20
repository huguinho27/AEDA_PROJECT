#include "enunciation.h"

using namespace std;

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

void Enunciation::setTittle(string newTitle)
{
	title = newTitle;
}

void Enunciation::setDescription(string newDescription)
{
	description = newDescription;
}
