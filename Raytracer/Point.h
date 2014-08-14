#ifndef POINT_H
#define POINT_H

class Point {
	public:
		static double point_distance(Point p1, Point p2);
		static double dot_product(Point p1, Point p2);
		static double calc_illumination(Point p1, Point p2);

	public:
		Point();
		Point(double x, double y, double z);
 
	public:
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