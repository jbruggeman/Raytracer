#include "PixelMap.h"

PixelMap::PixelMap(double focal_distance, double height, double width, int vsize, int hsize):
	_focal_distance(focal_distance),  _height(height), _width(width), _vsize(vsize), _hsize(hsize) 
{
	_centre._x = 0;
	_centre._y = 0;
	_centre._z = 0;
}

Point* PixelMap::query_location(int row, int column) {
	if(row >= _vsize || column >= _hsize)
		return 0;

	double vdivisor = double(_vsize) - 1;
	double hdivisor = double(_hsize) - 1;

	double vstep = _height/vdivisor;
	double hstep = _width/hdivisor;

	double vcorner = -_height/2;
	double hcorner = -_width/2;
	
	Point* temp = new Point;
	temp->_x = _focal_distance;
	temp->_y = vcorner + double(row)*vstep;
	temp->_z = hcorner + double(column)*hstep;

	return temp;
}