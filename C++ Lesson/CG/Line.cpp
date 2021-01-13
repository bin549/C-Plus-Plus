#include "./Line.h"

Line::Line()
{
	Point start_point_ = Point();
	Point end_point_ = Point();
	length_ = 0;
}

Line::Line(int x1, int x2, int y1, int y2)
{
	start_point_ = Point(x1, y1);
	end_point_ = Point(x2, y2);
	length_ = end_point_.Distance(start_point_);
}

Line::Line(Point& p1, Point& p2)
{
	start_point_ = Point(p1);
	end_point_ = Point(p2);
	length_ = end_point_.Distance(start_point_);
}
double Line::Length() const 
{
	return length_;
}

void Line::Show() const
{
	cout << "Point:" << endl;
	cout << "start_point_: " << start_point_ << "  ";
	cout << "end_point_: " << end_point_ << "  ";
	cout << "length_: " << length_ << endl;
}
