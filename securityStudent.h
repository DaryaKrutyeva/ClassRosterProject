#pragma once
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;
class SecurityStudent : public Student {
public:
	SecurityStudent();
	SecurityStudent(string studentID, string firstName, string lastName, string email, int age, int* completionDays, Degree degree);

	Degree getDegree();
	void print();
	void setDegree(Degree degree);
	~SecurityStudent();
};
