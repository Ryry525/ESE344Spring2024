#pragma once
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
ostream& operator<< (ostream& out, const Rectangle& rhs)
{
	rhs.print(out);
	return out;
}


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
// Define an output operator for Square
ostream& operator<< (ostream& out, const Square& rhs)
{
	rhs.print(out);
	return out;
}

/*
* Return the maximum item in array a.
* Assumes a.size( ) > 0.
* Comparable objects must provide operator< and operator=
*/
template <typename Comparable>
const Comparable& findMax(const vector<Comparable>& a)
{
	int maxIndex = 0;

	for (int i = 1; i < a.size(); ++i)
		if (a[maxIndex] < a[i])
			maxIndex = i;

	return a[maxIndex];
}