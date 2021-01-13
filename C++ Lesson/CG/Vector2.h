#pragma once


#include <iostream>

using namespace std;


namespace VECTOR
{
	class Vector2
	{
	private:
		double length_;
		void SetLength();
	public:
		double x_;
		double y_;
		Vector2() : x_(0), y_(0) { SetLength(); };
		Vector2(double x, double y) : x_(x), y_(y) { SetLength(); }
		Vector2(const Vector2& vector);
		Vector2& operator=(const Vector2& vector);
		~Vector2();
		void Set(double x, double y);
		double GetLength();
		void Normalize();
		void Scale(double factor);
		static double Dot(const Vector2& lhs, const Vector2& rhs);
		static double Angle(const Vector2& lhs, const Vector2& rhs);
		static double SignedAngle(const Vector2 from, const Vector2 to);
		static double Distance(const Vector2 from, const Vector2 to);
		double& operator[](int index);
		friend std::ostream& operator<<(std::ostream& os, const Vector2& rhs);
		friend std::istream& operator>>(std::istream& is, const Vector2& rhs);
		friend Vector2 operator+(const Vector2& lhs, const Vector2& rhs);
		friend Vector2 operator-(const Vector2& lhs, const Vector2& rhs);
		friend Vector2 operator-(const Vector2& lhs);
		friend Vector2 operator*(const Vector2& lhs, const double factor);
		friend Vector2 operator*(const double factor, const Vector2& rhs);
		friend Vector2 operator/(const Vector2& lhs, const double factor);
		friend bool operator==(const Vector2& lhs, const Vector2& rhs);
		friend bool operator!=(const Vector2& lhs, const Vector2& rhs);
	};
}
