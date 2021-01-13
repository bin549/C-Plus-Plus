#include <iostream>
#include <string>
#include <iostream>

using namespace std;

class B
{
public:
	virtual void f1()
	{
		cout << "B:f1()" << endl;
	}
	virtual void f2()
	{
		cout << "B:f2()" << endl;
	}
	void g()
	{
		cout << "B:g()" << endl;
		f1();
		f2();
	}
};

class D : public B
{
public:
	virtual void f1()
	{
		cout << "D:f1()" << endl;
	}
	virtual void f3()
	{
		cout << "D:f3()" << endl;
	}
	void g()
	{
		cout << "D:g()" << endl;
		f1();
		f2();
	}
};

int main()
{
	D d;
	D *pd = &d;
	B *pb = &d;
	B b = d;

	/*
	b.f1();
	b.f2();
	b.g();
	*/

	/*
	pb->f1();
	pb->f2();
	pb->g();
	*/

	pd->f1();
	pd->f2();
	pd->f3();
	pd->g();

}