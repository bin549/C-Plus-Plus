// sqrt.cpp -- using the sqrt() function

#include<iostream>
#include<cmath>

int main()
{
    using namespace std;

    double area;
    cout << "Enter the floor area, in square feet, of your home: ";
    cin >> area;
    double size;
    size = sqrt(area);
    cout << "That's the equivalent of a "
        << size
        << " feet to the size." << endl;
    cout << "How fascinating!" << endl;
    return 0;
}
