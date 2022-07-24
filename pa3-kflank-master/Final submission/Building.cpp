#include "Building.h"		

Building::Building() : GameObject('B') //Defualt constructor
{
	student_count = 0;

	display_code = 'B';

	cout<<"Building defualt constructed"<<endl;

}

Building::Building(char in_code , int in_id  ,  Point2D in_loc) : GameObject(in_loc, in_id, in_code)
{

student_count = 0;

id = in_id;

display_code = in_code;

location = in_loc;

cout<<"Building constructed"<<endl;

}



//Functions 


unsigned int Building::Getstudent_count()
{
	return student_count;
}

void Building::AddOneStudent()
{
	student_count = student_count+1;
}

void Building::RemoveOneStudent()
{
	student_count = student_count-1;
}

void Building::ShowStatus()
{
	cout<<display_code<<id<<" "<<"located at"<<location<<endl;

}

bool Building::ShouldBeVisible()
{
	return true;
}

Building::~Building()
{
	cout<<"Building destroyed"<<endl;
}