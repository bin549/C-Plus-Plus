#include <iostream>
#include "./Student.h"

std::ostream& operator<<(std::ostream& os, const Student::Gender& gender)
{
    if (gender == Student::Male)
        os << "Male";
    if (gender == Student::Female)
        os << "Female";
    return os;
}

Student::Student()
{
    name_ = NULL;
    gender_ = Male;
}

Student::Student(const char* name, Gender gender)
{
    name_ = new char[strlen(name) + 1];
    strcpy(name_, name);
    gender_ = gender;
}

Student::Student(const Student& student)
{
    name_ = new char[strlen(student.name_) + 1];
    strcpy(name_, student.name_);
    gender_ = student.gender_;
}

Student& Student::operator= (const Student& student)
{
    name_ = new char(strlen(student.name_) + 1);
    strcpy(name_, student.name_);
    gender_ = student.gender_;
    return *this;
}

Student::~Student()
{
    delete[] name_;
}

void Student::Show()const
{
    std::cout << "Name: " << name_ << std::endl << "Gender:" << gender_ << std::endl;
}