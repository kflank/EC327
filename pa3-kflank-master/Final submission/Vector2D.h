#include <iostream>

using namespace std;

class Vector2D
{
public:
	double x; //x displacement 
	double y; //y displacement 

Vector2D(); //default constructor set initial x and y to zero
	

Vector2D(double , double); //constructor that specifies x and y
	
};



Vector2D operator * (Vector2D , double); 

Vector2D operator / (Vector2D v1, double d);

ostream& operator << (ostream& out , Vector2D v1);


