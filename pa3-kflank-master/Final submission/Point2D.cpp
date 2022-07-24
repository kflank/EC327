#include <cmath>
#include <cstdlib>
#include "Point2D.h"



using namespace std;


	

Point2D::Point2D() //default constructor set initial x and y to zero
{

 x = 0.0;
 y = 0.0;

}

Point2D::Point2D(double in_x, double in_y) //constructor that specifies x and y
{
	
 x = in_x;
 y = in_y;

}





double GetDistanceBetween(Point2D p1, Point2D p2)
{
	
	double x1 = p1.x;
	double x2 = p2.x;
	

	double y1 = p1.y;
	double y2 = p2.y;


	double dist = sqrt(pow((x2-x1),2) +  pow((y2-y1),2));
	cout<<"in get dist"<<endl;
return dist;
}




//overloaded operator for Point2D prints out (x,y)

ostream& operator << (ostream& out , Point2D p1)
{
	out << "("<<p1.x<<", "<<p1.y<<" )";
	return out;
} 


//addition operator p1+v1

Point2D operator + (Point2D p1, Vector2D v1)
{
	double x = p1.x + v1.x;
	double y = p1.y + v1.y;

	Point2D p_new;

	p_new.x = x;
	p_new.y = y;

return p_new;
}


//subtraction operator p1-p2

Vector2D operator - (Point2D p1, Point2D p2)
{
	double x;
	double y;

	x = p1.x - p2.x;
	y = p1.y - p2.y;

Vector2D new_vec;

new_vec.x = x;
new_vec.y = y;

return new_vec;
}

bool operator == (Point2D p1, Point2D p2)
{
	if (p1.x == p2.x && p1.y == p2.y)
		return true;
	else 
		return false;
}

