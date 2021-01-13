#include <iostream>

class Birthday
{
private:
	int year_;
	int month_;
	int day_;
public: 
	Birthday() : year_(0), month_(0), day_(0){}
	Birthday(int year, int month, int day) : year_(year), month_(month), day_(day) {}
	friend std::ostream & operator<<(std::ostream & os, const Birthday & birth);
	void Print();
};
 