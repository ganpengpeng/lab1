#pragma once
#include <iostream>

typedef struct  point
{
	double x, y;
	point() :x(0), y(0) {}
	point(double a, double b) :x(a), y(b) {}
	const point& point::operator=(const point &s)
	{
		x = s.x;
		y = s.y;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream & out, const point & p)
	{
		std::cout << "(" << p.x << ',' << p.y << ')';
		return out;
	}
}point;
typedef struct double_p
{
	point a, b;
	double distance;
	double_p() :a(0, 0), b(0, 0), distance(0) {}
	double_p(point a, point b, double dis) :a(a), b(b), distance(dis) {}
	friend std::ostream& operator<<(std::ostream & out, const double_p & d)
	{
		std::cout << "(" << d.a.x << ',' << d.a.y << ')' << " " << '(' << d.b.x << ',' << d.b.y << ')';
		return out;
	}
}double_point;