#pragma once

#include <string>
#include <iostream>

using namespace std;

class Student
{
private:
	string name_;
	int score_;

public:
	enum SortType
	{
		BY_NAME,
		BY_SCORE
	};
	static SortType sort_type;
	Student() : name_(""), score_(0){};
	Student(string name, int score) : name_(name), score_(score){};
	Student(const Student &stu);
	Student &operator=(const Student &stu);
	~Student();
	friend std::ostream &operator<<(std::ostream &os, const Student &stu);
	bool operator>(const Student &stu2);
	bool operator<(const Student &stu2);
};

Student::Student(const Student &stu)
{
	name_ = stu.name_;
	score_ = stu.score_;
}

Student &Student::operator=(const Student &stu)
{
	name_ = stu.name_;
	score_ = stu.score_;
	return *this;
}

Student::~Student()
{
}

std::ostream &operator<<(std::ostream &os, const Student &stu)
{
	os << "Name:" << stu.name_ << "\tScore:" << stu.score_ << endl;
	;
	return os;
}

bool Student::operator>(const Student &stu2)
{
	if (sort_type == BY_NAME)
		return this->name_ > stu2.name_;
	else
		return this->score_ > stu2.score_;
}

bool Student::operator<(const Student &stu2)
{
	if (sort_type == BY_NAME)
		return this->name_ < stu2.name_;
	else
		return this->score_ < stu2.score_;
}