#include <iostream>
#include "student.h"
#include <iomanip>
#include"degree.h"
using namespace std;

Student::Student()
{
	this->studentID = "studentID";
	this->firstName = "firstName";
	this->lastName = "lastName";
	this->email = "email";
	this->age = 0;
	this->completionDays = new int[completionDaysArray];
	for (int i = 0; i < completionDaysArray; i++)
		this->completionDays[i] = 0;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int completionDays[], Degree degree)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->completionDays = new int[completionDaysArray];

	for (int i = 0; i < 3; i++)
		this->completionDays[i] = completionDays[i];

}

string Student::getStudentID(){

	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmail() {
	return email;
}
int Student::getAge() {
	return age;
}
int* Student::getCompletionDays()
{
	return completionDays;
}



void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmail(string email) {
	this->email = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setCompletionDays(int completionDays[]) {
	this->completionDays = new int[completionDaysArray];
	for (int i = 0; i < 3; ++i)
		this->completionDays[i] = completionDays[i];
}



void Student::print() {
	cout << getStudentID();
	cout << "\tFirst name: " << getFirstName(); 
	cout << "\tLast name: " << getLastName(); 
	cout << "\tAge: " << getAge(); 

	int* days = getCompletionDays();
	cout << "  Days spent on course: " << *days << ", " << *(days + 1) << ", " << *(days + 2) << "\t";



}


Student::~Student() {
	if (completionDays!= nullptr) {
		delete completionDays;
		completionDays = nullptr;
	}


}
