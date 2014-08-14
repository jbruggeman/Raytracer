#include "Polygon.h"

Polygon::Polygon(Point center, Color color, bool isLightSource):
	mCenter(center), mColor(color), mIsLightSource(isLightSource)
{
}

Polygon::~Polygon() {
}
