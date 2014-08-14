#include "Point.h"
#include <iostream>

using namespace std;

Point::Point():
	mValid(false)
{
}

Point::Point(double x, double y, double z):
	mX(x), mY(y), mZ(z), mValid(true)
{
}

void Point::print() {
	cout << "X: " << mX << " Y: " << mY << " Z: " << mZ << endl;
}