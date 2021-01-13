#include "pch.h"
#include "Vector2.h"
#include <iostream>
#include <cmath> 

namespace VECTOR
{
	void Vector2::SetLength()
	{
		length_ = sqrt(x_*x_ + y_ * y_);
	}

	Vector2::Vector2(const Vector2& vector)
	{
		x_ = vector.x_;
		y_ = vector.y_;
		SetLength(); 
	}
	
	Vector2::~Vector2() 
	{
	}

	Vector2& Vector2::operator=(const Vector2& vector)
	{
		if (this != &vector)
		{
			x_ = vector.x_;
			y_ = vector.y_;
			SetLength();
		}
		return *this;
	}

	void Vector2::Set(double x, double y)
	{
		x_ = x;
		y_ = y;
		SetLength();
	}

	double Vector2::GetLength()
	{
		return length_;
	}

	void Vector2::Normalize()
	{
		x_ = x_ / length_;
		y_ = y_ / length_;
		length_ = 1;
	}

	void Vector2::Scale(double factor)
	{
		x_ *= factor;
		y_ *= factor;
		SetLength();
	}

	double Vector2::Dot(const Vector2& lhs, const Vector2& rhs)
	{
		return lhs.x_ * rhs.x_ + lhs.y_ * rhs.y_;
	}

	double Vector2::Angle(const Vector2& lhs, const Vector2& rhs)
	{
		double productValue = (lhs.x_ * rhs.x_) + (lhs.y_ * rhs.y_);
		double lhs_val = sqrt(lhs.x_ * lhs.x_ + lhs.y_ * lhs.y_);
		double rhs_val = sqrt(rhs.x_ * rhs.x_ + rhs.y_ * rhs.y_);
		double cosValue = productValue / (lhs_val * rhs_val);
		double angle = acos(cosValue) * 180 / 3.14;
		return angle;
	}

	double Vector2::SignedAngle(const Vector2 from, const Vector2 to)
	{
		double angle = atan2(from.x_, from.y_) - atan2(to.x_, to.y_);
		angle = angle * 180.0 / 3.14;
		return angle;
	}

	double Vector2::Distance(const Vector2 from, const Vector2 to)
	{
		double dx = from.x_ - to.x_;
		double dy = from.y_ - to.y_;
		return sqrt(dx*dx + dy * dy);
	}

	double& Vector2::operator[](int index)
	{
		double val = 0;
		if (index == 0)
			val = x_;
		else if (index == 1)
			val = y_;
		else
		{
			cout << "The index must be 0 or 1!" << endl;
		}
		return val;
	}

	std::ostream& operator<<(std::ostream& os, const Vector2& rhs)
	{
		os << "(x,y) = (" << rhs.x_ << "," << rhs.y_ << ")";
		return os;
	}

	std::istream& operator>>(std::istream& is, Vector2& rhs)
	{
		is >> rhs.x_ >> rhs.y_;
		return is;
	}

	Vector2 operator+(const Vector2& lhs, const Vector2& rhs)
	{
		return Vector2(lhs.x_ + rhs.x_, lhs.y_ + rhs.y_);
	}

	Vector2 operator-(const Vector2& lhs, const Vector2& rhs)
	{
		return Vector2(lhs.x_ - rhs.x_, lhs.y_ - rhs.y_);
	}

	Vector2 operator-(const Vector2& lhs)
	{
		return Vector2(-lhs.x_ , -lhs.y_);
	}

	Vector2 operator*(const Vector2& lhs, const double factor)
	{
		return Vector2(lhs.x_ * factor, lhs.y_ * factor);
	}

	Vector2 operator*(const double factor, const Vector2& rhs)
	{
		return rhs * factor;
	}

	Vector2 operator/(const Vector2& lhs, const double factor)
	{
		return Vector2(lhs.x_ / factor, lhs.y_ / factor);
	}

	bool operator==(const Vector2& lhs, const Vector2& rhs)
	{
		return (lhs.x_==rhs.x_ && lhs.y_==rhs.y_);
	}

	bool operator!=(const Vector2& lhs, const Vector2& rhs)
	{
		return !(lhs==rhs);
	}

}