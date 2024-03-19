#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()
#include <assert.h>
#include <math.h>    // for math functions like sqrt() etc
#include "List.h"


class Square
{
public:
	explicit Square(int s = 0) : side{ s }
	{ }

	void setSide(int s = 1)
	{
		side = s;
	}
	int getSide() const
	{
		return side;
	}
	int getArea() const
	{
		return side * side;
	}
	int getPerimeter() const
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
	int side;
};

// Define an output operator for Square
ostream& operator<< (ostream& out, const Square& rhs)
{
	rhs.print(out);
	return out;
}



/**
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
