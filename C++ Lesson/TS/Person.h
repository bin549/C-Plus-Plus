#include <iostream>
#include <string>

#include "./Birthday.h"
#include "./Student.h"
#include "./Graduate.h"
#include "./Person.h"
#include "./Teacher.h"
#include "./Assistant.h"

using namespace std;

class Person
{
protected:
	string name_;
	Gender gender_;
	Birthday birth_;
public:
	Person() : name_(""), gender_(Male), birth_(1999, 1, 1) {}
	Person(string name, Gender gender, Birthday birth) : name_(name), gender_(gender), birth_(birth) {}
	void Print();
};
