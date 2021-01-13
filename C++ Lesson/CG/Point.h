
#include <iostream>
using namespace std;

class Point
{
public:
	Point();
	Point(int x, int y);
	int get_x() const;
	int get_y() const;
	double Distance(const Point& point);
	friend ostream& operator<<(ostream& os, const Point& point);
private:
	int x_;
	int y_;
};


 