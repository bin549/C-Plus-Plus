#include <iostream>
#include <string>

#include "./Birthday.h"
#include "./Student.h"
#include "./Graduate.h"
#include "./Person.h"
#include "./Teacher.h"
#include "./Assistant.h"

using namespace std;

class Teacher : virtual public Person
{
private:
	string title_;
public:
	Teacher() : Person(), title_("") {}
	Teacher(string name, Gender gender, Birthday birth, string title) : Person(name, gender, birth), title_(title) {}
	void Print();
	void PrintTitle();
};