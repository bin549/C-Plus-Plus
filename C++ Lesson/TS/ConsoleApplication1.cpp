// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Vector2.h"
#include <iostream>

using namespace VECTOR;
using namespace std;

int main() 
{
	cout << "+++++++++++Test+++++++++++" << endl;
	cout << "*-Vector 1-*" << endl;
	Vector2 v1 = Vector2(3, 4); 
	cout << v1 << endl;
	v1.Scale(10);
	cout << v1 << endl;
	Vector2 v2 = Vector2(1, 2);
	Vector2 v3 = v2;

	cout << "*-Vector 2-*" << endl;
	cout << v2 << endl;
	v2.Set(-2, 5);
	cout << v2 << endl;

	cout << "*-Vector 3-*" << endl;
	cout << v3 << endl;
	cout << v3.GetLength() <<endl;
	v3.Normalize();
	cout << v3 << endl;
	cout << v3.GetLength() << endl;

	cout << "*-Vector Stacic Method-*" << endl;
	cout << Vector2::Dot(v1, v2) << endl;
	cout << Vector2::Distance(v1, v2) << endl;
	cout << Vector2::Angle(v1, v2) << endl;
	cout << Vector2::SignedAngle(v1, v2) << endl;

	cout << "*-Vector Overloaded Operators Method-*" << endl;
	cout << v1+v2 << endl;
	cout << v1-v2 << endl;
	cout << -v2 << endl;
	cout << v1[0] << endl;
	cout << v1[1] << endl;
	v1[2];
	cout << v1*2 << endl;
	cout << 2*v1 << endl;
	cout << v1/2 << endl;
	cout << (v1==v2) << endl;
	cout << (v1!=v2) << endl;
}
