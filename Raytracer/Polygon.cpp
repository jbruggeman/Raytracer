#include "Polygon.h"

Polygon::Polygon(const Point& center, const Color& color, bool isLightSource):
	mCenter(center), mColor(color), mIsLightSource(isLightSource)
{
}

Polygon::~Polygon() {
}
