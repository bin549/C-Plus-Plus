#include <iostream>
#include <math.h> 

using namespace std;

const double PI = 3.1415926;

class Shape
{
public:
	virtual double Area() = 0;
};

class Shape2D : public Shape
{
public:
	virtual double Perimeter() = 0;
};

class Shape3D : public Shape
{
public:
	virtual double Volumn() = 0;
};

class Rectangle : public Shape2D
{
public:
	Rectangle() : a_(0), b_(0) {}
	Rectangle(double a, double b) : a_(a), b_(b) {}
	double Area()
	{
		return  a_ * b_;
	}
	double Perimeter()
	{
		return  (a_ + b_) * 2;
	}
private:
	double a_;
	double b_;
};

class Ellipse : public Shape2D
{
public:
	Ellipse() : a_(0), b_(0) {}
	Ellipse(double a, double b) : a_(a), b_(b) {}
	double Area()
	{
		return PI * a_ * b_;
	}
	double Perimeter()
	{
		return 2 * PI * b_ + 4 * (a_ - b_);
	}
private:
	double a_;
	double b_;
};

class Circle : public Shape2D
{
public:
	Circle() : r_(0) {}
	Circle(double r) : r_(r) {}
	double Area()
	{
		return PI * pow(r_, 2);
	}
	double Perimeter()
	{
		return 2 * PI * r_;
	}
private:
	double r_;
};

class Sphere : public Shape3D
{
public:
	Sphere() : r_(0) {}
	Sphere(double r) : r_(r) {}
	double Area()
	{
		return 4 * PI * pow(r_, 2);
	}

	double Volumn()
	{
		return (4 / (double)3) * PI * pow(r_, 3);
	}
private:
	double r_;
};

class Cylinder : public Shape3D
{
public:
	Cylinder() : r_(0), h_(0) {}
	Cylinder(double r, double h) : r_(r), h_(h) {}
	double Area()
	{
		return 2 * PI * r_ * (r_ + h_);
	}
	double Volumn()
	{
		return PI * pow(r_, 2) * h_;
	}
private:
	double r_;
	double h_;
};

class Cone : public Shape3D
{
public:
	Cone() : r_(0), h_(0) {}
	Cone(double r, double h) : r_(r), h_(h) {}
	double Area()
	{
		return  PI * r_ * (r_ + (sqrt(r_* h_)));
	}
	double Volumn()
	{
		return (1 / (double)3) * PI * pow(r_, 2) * h_;
	}
private:
	double r_;
	double h_;
};

class SumofShape
{
public:
	static double SumofArea(Shape* shape[], int n)
	{
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += shape[i]->Area();
		}
		return sum;
	}

	static double SumofPremeter(Shape* shape[], int n)
	{
		double sum = 0;
		Shape2D* shape2d;
		for (int i = 0; i < n; i++)
		{
			if (shape2d = dynamic_cast<Shape2D*>(shape[i]))
			{
				sum += shape2d->Perimeter();
			}

		}
		return sum;
	}

	static double SumofVolumn(Shape* shape[], int n)
	{
		double sum = 0;
		Shape3D* shape3d;
		for (int i = 0; i < n; i++)
		{
			if (shape3d = dynamic_cast<Shape3D*>(shape[i]))
				sum += shape3d->Volumn();
		}
		return sum;
	}
private:
	SumofShape() {}
};

int main()
{
	Rectangle rectangle(2, 3);
	Ellipse ellipse(8, 4);
	Circle circle(3);
	Sphere sphere(3);
	Cylinder cylinder(3, 5);
	Cone cone(3, 4);
	Shape* shape_array[] = { &rectangle, &ellipse, &circle, &sphere, &cylinder, &cone };
	double sum_of_area = SumofShape::SumofArea(shape_array, 6);
	double sum_of_premeter = SumofShape::SumofPremeter(shape_array, 6);
	double sum_of_volumn = SumofShape::SumofVolumn(shape_array, 6);
	cout << "面积总和：" << sum_of_area << "\n周长总和：" << sum_of_premeter << "\n体积总和：" << sum_of_volumn << endl;
	return 0;
}