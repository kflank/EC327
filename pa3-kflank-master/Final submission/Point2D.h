#include <cmath>
#include "Vector2D.cpp"




using namespace std;

class Point2D
{
public:
	double x;
	double y;

	Point2D(); //default constructor set initial x and y to zero

	
	Point2D(double , double); //constructor that specifies x and y
	

};


double GetDistanceBetween(Point2D, Point2D);


Vector2D operator-(Point2D, Point2D);

Point2D operator+(Point2D, Point2D);

ostream& operator<<(ostream&, Point2D);


