#include <iostream>
#include <string>
#include "./Teacher.h"
#include "./Graduate.h"
#include "./Birthday.h"

using namespace std;

class Assistant : public Teacher, public Graduate
{
private:
	string subject_;
public:
	Assistant();
	Assistant(string name, Gender gender, Birthday birth, int score, string advisor, string title, string subject) : Person(name, gender, birth), Teacher(name, gender, birth, title), Graduate(name, gender, birth, score, advisor), subject_(subject) {}
	void Print();
	void PrintSubject();
};
 