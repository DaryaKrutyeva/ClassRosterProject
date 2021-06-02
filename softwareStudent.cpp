
#include "softwareStudent.h"
#include <iostream>
using namespace std;



SoftwareStudent::SoftwareStudent() {
	setDegree(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string email, int age, int* completionDays, Degree degree) {
	setDegree(SOFTWARE);
}

Degree SoftwareStudent::getDegree()
{
	return SOFTWARE;
}

void SoftwareStudent::setDegree(Degree degree)
{
	this->degree = SOFTWARE;
}
void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
	delete this;

}