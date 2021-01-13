// twoswap.cpp -- specialization overrides a template
#include <iostream>

template <class Any>
void Swap(Any &a, Any &b);

struct job
{
    char name[40];
    double salary;
    int floor;
};

// explicit specialization
template <> void Swap<job>(job &j1, job &j2);
void show(job &j);

int main()
{
    using namespace std;
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    Swap(i, j);
    cout << "Now i, j = " << i << ", " << j << ".\n";

    job sue ={ "Susan Yaffee", 73000.60, 7 };
    job sidney ={ "Sidney Taffee", 78060.72, 9 };
    cout << "Before job swapping: \n";
    show(sue);
    show(sidney);
    Swap(sue, sidney);
    cout << "After job swapping: \n";
    show(sue);
    show(sidney);

    return 0;
}

template <class Any>
void Swap(Any &a, Any &b)   // general version
{
    Any temp;
    temp = a;
    a = b;
    b = temp;
}

// swaps just the salary and floor fields of a job structures

template <> void Swap<job>(job &j1, job &j2)  // specialization
{
    double t1;
    int t2;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}

void show(job &j)
{
    using namespace std;
    cout << j.name << ": $" << j.salary
        << " on floor " << j.floor << endl;
}
