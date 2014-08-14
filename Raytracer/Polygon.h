#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"
#include "Color.h"

class Polygon { 
	public: 
		Polygon(const Point& center, const Color& color, bool);
		~Polygon();
		virtual Point closestIntersect(const Point& origin, const Point& directionVector) = 0;

		bool isLightSource() { return mIsLightSource; }
		Point center() { return mCenter; }
		Color color() { return mColor; }

	protected:
   		Point mCenter;
		Color mColor;
		bool mIsLightSource;
};

#endif /* POLYGON_H */