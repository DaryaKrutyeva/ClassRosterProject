#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include <string>
#include "degree.h"
using namespace std;
#include <iostream>

class Student
{


protected:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int* completionDays;
	Degree degree;


public:
	Student();
	
	Student(string studentID, string firstName, string lastName, string email, int age, int completionDays[], Degree degree);
	const static int completionDaysArray = 3;
	//Accessors//

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getCompletionDays();
	virtual Degree getDegree() = 0;


	//mutators//

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setCompletionDays(int completionDays[]);
	virtual void setDegree(Degree degree) = 0;
	void setAge(int age);
	virtual void print() = 0;

	~Student();
};
#endif
