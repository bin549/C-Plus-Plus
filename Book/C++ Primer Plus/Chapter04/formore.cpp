// formore.cpp -- more looping with for
// auto:me
#include <iostream>
using namespace std;
const int ArSize = 16;
int main()
{
    double factorials[ArSize];
    factorials[0] = factorials[1] = 1.0;
    for (int i = 2; i < ArSize; i++)
        factorials[i] = i * factorials[i-1];
    for (int i = 0; i < ArSize; i++)
        cout << i << "! = " << factorials[i] << endl;
    return 0;
}
