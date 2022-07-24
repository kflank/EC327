#include "Vector2D.h"


using namespace std;


Vector2D::Vector2D() //default constructor set initial x and y to zero
{
	x = 0.0;
	y = 0.0;
}	

Vector2D::Vector2D(double in_x, double in_y) //constructor that specifies x and y
{
	x = in_x;
	y = in_y;
}	

//overloaded operators
Vector2D operator * (Vector2D v1, double d)
{

double x = v1.x * d;
double y = v1.y * d;

Vector2D vec_new;

vec_new.x = x;
vec_new.y = y;

return vec_new;
}


//vector / distacne 

Vector2D operator / (Vector2D v1, double d)
{

double x = v1.x / d;
double y = v1.y / d;

Vector2D vec_new;

vec_new.x = x;
vec_new.y = y;

return vec_new;
}



// stream operator <<

ostream& operator << (ostream& out , Vector2D v1)
{
	out << "<"<<v1.x<<", "<<v1.y<<" >";
	return out;
} 


 
