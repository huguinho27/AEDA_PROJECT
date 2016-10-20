#include "student.h"
#include <iostream>

Student::Student(double mark)
{
	if (mark > 20 || mark < 0)
		return;
	this->mark = mark;
}

double Student::getMark() const
{
	return mark;
}
