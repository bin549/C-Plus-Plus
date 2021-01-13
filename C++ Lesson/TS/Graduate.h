#include <iostream>
#include <string>

#include "./Birthday.h"
#include "./Student.h"
#include "./Graduate.h"
#include "./Person.h"
#include "./Teacher.h"
#include "./Assistant.h"

using namespace std;

enum Gender{Male, Female};

class Graduate : public Student
{
private:
	string advisor_;
public:
	Graduate() : Student(), advisor_("") {}
	Graduate(string name, Gender gender, Birthday birth, int score, string advisor) : Student(name, gender, birth, score), Person(name, gender, birth), advisor_(advisor) {}
	void Print();
	void PrintAdvisor();
};