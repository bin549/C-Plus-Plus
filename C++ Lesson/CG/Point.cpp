#include "./Point.h"

Point::Point() 
{
	x_ = 0;
	y_ = 0;
}

Point::Point(int x, int y)
{
	x_ = x;
	y_ = y;
}

int Point::get_x() const
{
	return x_;
}

int Point::get_y() const
{
	return y_;
}

double Point::Distance(const Point& point)
{
	return sqrt((x_ - point.x_)*(x_ - point.x_) + (y_ - point.y_)*(y_ - point.y_));
}

ostream& operator<<(ostream& os, const Point& point)
{
	os << "x: " << point.get_x() << "  ";
	os << "y: " << point.get_y() << "  ";
	return os;
}