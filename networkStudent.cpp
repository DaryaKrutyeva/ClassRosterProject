#pragma once

#include "networkStudent.h"
#include <iostream>
using std::cout;




NetworkStudent::NetworkStudent() {
	setDegree(NETWORK);
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string email, int age, int* completionDays, Degree degree) {
	setDegree(NETWORK);
}

Degree NetworkStudent::getDegree()
{
	return NETWORK;
}

void NetworkStudent::setDegree(Degree degree)
{
	this->degree = NETWORK;
}
void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORK" << "\n";
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
	delete this;

}