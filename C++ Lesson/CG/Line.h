#include "./Point.h"

class Line
{
public:
	Line();
	Line(int x1, int x2, int y1, int y2);
	Line(Point& p1, Point& p2);
	double Length() const;
	void Show() const;
private:
	Point start_point_;
	Point end_point_;
	double length_;
};