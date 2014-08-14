#ifndef POINT_H
#define POINT_H

class Point {
    public:
		Point();
		Point(double x, double y, double z);
 
		double x() const { return mX; } 
		double y() const { return mY; }
		double z() const { return mZ; }

		bool valid() const { return mValid; }

		void print();
	
	private:
   		double mX;
   		double mY;
		double mZ;

		bool mValid;
};

#endif /* POINT_H */