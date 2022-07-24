#include "GameObject.h"




	
	GameObject::GameObject(char in_code) //constructor for ....
	{
		display_code = in_code;

		id = 1;

		state = '0';

		cout<<"GameObject constructed"<<endl;
	} 



	GameObject::GameObject(Point2D in_loc , int in_id, char in_code) // cosntructor for ... 
	{
		location = in_loc;

		id = in_id;

		display_code = in_code;

		cout<<"GameObject constructed"<<endl;

	}


bool GameObject::Update()
{
	return false;
}

bool GameObject::ShouldBeVisible()
{
	return true;
}


GameObject::~GameObject()
{
	cout<<"GameObject destroyed"<<endl;
}

	Point2D GameObject::GetLocation()
	{
		return location;
	}

	int GameObject::GetId()
	{
		return id;
	}

	char GameObject::GetState()
	{
		return state;
	}

	void GameObject::ShowStatus()
	{
		cout<<display_code<<"_"<<id<<"_"<<location<<endl;
	}

	void GameObject::DrawSelf(char * ptr)
	{
		*ptr = display_code;

		*(ptr+1) = '0' + id;
	}
