#pragma once
#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
#include <assert.h>
#include <math.h>    // for math functions like sqrt() etc

using namespace std;
class Rectangle
{
private:
	double length;
	double width;
public:
	explicit Rectangle(double l = 0, double w = 0) : length{ l }, width{ w }
	{ }
	//accessor functions
	double getLenght() const
	{
		return length;
	}
	double getWidth() const
	{
		return width;
	}
	//mutator functions
	void setLength(double l) { length = l; }
	void setWidth(double w) { width = w; }

	double getArea() const
	{
		return length * width;
	}
	double getPerimeter() const
	{
		return 2 * (length + width);
	}
	void print(ostream& out = cout) const
	{
		out << "(rectangle " << getLenght() << " " << getWidth() << ")" << endl;
	}


	bool operator< (const Rectangle& rhs) const
	{
		return getArea() < rhs.getArea();
	}

};


class Square
{
public:
	explicit Square(double s = 0.0) : side{ s }
	{ }

	void setSide(double s = 1.0)
	{
		side = s;
	}
	double getSide() const
	{
		return side;
	}
	double getArea() const
	{
		return side * side;
	}
	double getPerimeter() const
	{
		return 4 * side;
	}

	void print(ostream& out = cout) const
	{
		out << "(square " << getSide() << ")" << endl;
	}
	bool operator< (const Square& rhs) const
	{
		return getSide() < rhs.getSide();
	}

private:
	double side;
};
