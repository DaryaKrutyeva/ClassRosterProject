
#ifndef ROSTER_H
#define ROSTER_H
#include <string>
#include <iostream>
#include "student.h"
#include <list>

using namespace std;

const int numStudents = 5;

 string studentData[numStudents] = {
"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yah  oo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.blackcomcast.net,22,50,58,40,SECURITY",
"A5,Darya,Krutyeva,dkrutye@wguedu,24,16,20,30,SOFTWARE",
};


class Roster {
public:
	int capacity;
	int lastIndex;

	Student** classRosterArray;

	Roster();
	Roster(int capacity);

	void add(string datarow);
	void printAll();
	bool remove(string studentID);
	void printAverageDaysinCourse(string studentID);
	void printInvalidEmails();
	void printDegree(Degree degree);

	~Roster();

};



#endif
