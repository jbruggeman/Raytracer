#ifndef POLYGON_H
#define POLYGON_H

#include "Common.h"

class Polygon { 
	public: 
		Polygon(Point Center, Color, bool);
		~Polygon();
		virtual Point closestIntersect(Point p0, Point p1) = 0;

		bool isLightSource() { return mIsLightSource; }
		Point center() { return mCenter; }
		Color color() { return mColor; }

	protected:
   		Point mCenter;
		Color mColor;
		bool mIsLightSource;
};

#endif /* POLYGON_H */