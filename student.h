#ifndef STUDENT_H
#define STUDENT_H

class Student
{
private:
	int id;
	int static idgeneral;
	string name;
	vector<curricularUnit *> currUnits;
	vector<double> marks;
public:
	Student(string name);
	int getId() const;
	string getName() const;
	vector<curricularUnit *> getCurricularUnits();
	vector<double> getMarks();
	double getMark(curricularUnit *unit);
	double getMedia();
	void setName(string newName);
	void setCurricularUnit(curricularUnit *unit);
	void setMark(curricularUnit *unit, double mark);
};

#endif /* STUDENT_H */
