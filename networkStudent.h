#pragma once
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;
class NetworkStudent : public Student {
public:
	NetworkStudent();
	NetworkStudent(string studentID, string firstName, string lastName, string email, int age, int* completionDays, Degree degree);

	Degree getDegree();
	void print();
	void setDegree(Degree degree);
	~NetworkStudent();
};
