#include "roster.h"
#include "student.h"
#include "degree.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include <iostream>

using namespace std;

int main() {
	cout << "C867 Scripting and Programming Applications" << endl;
	cout << "Written in C++ by Darya Krutyeva" << endl;
	cout << "Student ID: #001110500" << endl;

	//roster
	Roster * classRoster = new Roster(numStudents);

	for (int i = 0; i < numStudents; ++i)
	{
		classRoster->add(studentData[i]);
	}

	
	cout << "CURRENT ROSTER" << endl;
	classRoster->printAll();
	cout << endl;

	cout << "Invalid Email Addresses" << endl;
	classRoster->printInvalidEmails();
	cout << endl;

	classRoster->printDegree(Degree::SOFTWARE);
	cout << endl;


	cout << "Removing A3:" << endl;

	classRoster->remove("A3");
	cout << endl;
	
	cout << "Average days to complete classes" << endl;
	for (int i = 0; i <= numStudents; i++) {
		classRoster->printAverageDaysinCourse(classRoster->classRosterArray[i]->getStudentID());
	}
	cout << endl;

	

	system("pause");
	return 0;
}

Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}
Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student*[capacity];
}


void Roster::add(string row) {
	if (lastIndex < capacity) {
		lastIndex++;
		int darray[Student::completionDaysArray];
		
		if (row.substr(row.length() - 7, 7) == "NETWORK")
		{
			this->classRosterArray[lastIndex] = new NetworkStudent();
			classRosterArray[lastIndex]->setDegree(NETWORK);
		}
		else if (row.substr(row.length() - 8, 8) == "SOFTWARE")
		{
			this->classRosterArray[lastIndex] = new SoftwareStudent();
			classRosterArray[lastIndex]->setDegree(SOFTWARE);
		}
		else if (row.substr(row.length() - 8, 8) == "SECURITY")
		{
			this->classRosterArray[lastIndex] = new SecurityStudent();
			classRosterArray[lastIndex]->setDegree(SECURITY);
		}
		
		//Student ID
		int rhs = studentData[lastIndex].find(",");
		classRosterArray[lastIndex]->setStudentID(studentData[lastIndex].substr(0, rhs));

		//First Name
		int lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));
		
		//Last Name
		
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(lhs, rhs - lhs));
		
		//email
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setEmail(studentData[lastIndex].substr(lhs, rhs - lhs));
		//age

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setAge(stoi(studentData[lastIndex].substr(lhs, rhs - lhs)));
		
		//completion
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		darray[0] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));
		//completion
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		darray[1] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));
		//completion

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		darray[2] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

		//set days
		classRosterArray[lastIndex]->setCompletionDays(darray);


	}

}

void Roster::printAll()
{
	for (int i = 0; i <= this->lastIndex; i++) {
		(this->classRosterArray)[i]->print();
	}
}

bool Roster::remove(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			Student* stu = classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			(classRosterArray[lastIndex]) = stu;
			lastIndex--;

		}
	}
	return found;
}
void Roster::printAverageDaysinCourse(string studentID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			int* d = classRosterArray[i]->getCompletionDays();
			cout << "Average days to complete course " << studentID << " is " << (d[0] + d[1] + d[2]) / 3 << "\n";

		}
	}


}
void Roster::printInvalidEmails()
{
	
	for (int i = 0; i <= lastIndex; i++) {
		string email = classRosterArray[i]->getEmail();
		if (email.find("@") == string::npos) cout << "Invalid email, " <<classRosterArray[i]-> getEmail() << " " << "must contain @ symbol" << email << endl;
		if (email.find(".") == string::npos) cout << "Invalid email, " << classRosterArray[i]->getEmail()<< " " << "must contain . symbol" << email << endl;
		if (email.find(" ") != string::npos) cout << "Invalid email, " << classRosterArray[i]->getEmail() << " "<< "cannot contain spaces" << email << endl;
	
	
	}


}

void Roster::printDegree(Degree degree)
{
	cout << "Printing " << degreeStrings[degree] << " students \n";
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getDegree() == degree) this->classRosterArray[i]->print();
	}
}
Roster::~Roster()
{
	for (int i = 0; i < numStudents; i++)
	{
		delete this->classRosterArray[i];
	}
	delete this;
}

