
#include "securityStudent.h"
#include <iostream>
using namespace std;



SecurityStudent::SecurityStudent() {
	setDegree(SECURITY);
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string email, int age, int* completionDays, Degree degree) {
	setDegree(SECURITY);
}

Degree SecurityStudent::getDegree()
{
	return SECURITY;
}

void SecurityStudent::setDegree(Degree degree)
{
	this->degree = SECURITY;
}
void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << "\n";
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
	delete this;

}