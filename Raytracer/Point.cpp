#include "Point.h"
#include <iostream>

using namespace std;

const double PI = 3.141592653589;

Point::Point():
	mValid(false)
{
}

Point::Point(double x, double y, double z):
	mX(x), mY(y), mZ(z), mValid(true)
{
}
		
Point& Point::operator+=(const Point &rhs) {
	mX += rhs.x();
	mY += rhs.y();
	mZ += rhs.z();

	return *this;
}
		
Point& Point::operator-=(const Point &rhs) {
	mX -= rhs.x();
	mY -= rhs.y();
	mZ -= rhs.z();

	return *this;
}

const Point Point::operator+(const Point &rhs) {
	Point result = *this;
	result += rhs;
	return result;
}

const Point Point::operator-(const Point &rhs) {
	Point result = *this;
	result -= rhs;
	return result;
}

void Point::print() {
	cout << "X: " << mX << " Y: " << mY << " Z: " << mZ << endl;
}

double Point::point_distance(Point p1, Point p2) { 
	return sqrt(pow((p1.x() - p2.x()),2) + pow((p1.y() - p2.y()),2) + pow((p1.z() - p2.z()),2));
}

double Point::dot_product(Point p1, Point p2) { 
	return p1.x()*p2.x() + p1.y()*p2.y() + p1.z()*p2.z();
}

double Point::calc_illumination(Point p1, Point p2) { 
	double dp =  dot_product(p1, p2);
	double mag_p1 = sqrt(pow((p1.x()),2) + pow((p1.y()),2) + pow((p1.z()),2));
	double mag_p2 = sqrt(pow((p2.x()),2) + pow((p2.y()),2) + pow((p2.z()),2));

	double rad = acos(dp/(mag_p1*mag_p2));

	double illum_factor = ((PI/2.0) - rad)/( PI/2.0);

	if(illum_factor < 0) {
		return 0;
	}

	return illum_factor;
}