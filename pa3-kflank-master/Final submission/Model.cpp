#include "Model.h"

Model::Model() : View()
{
	time = 0;

	Point2D S1(5,1);
	Point2D S2(10,1);
	Point2D D1(1,20);
	Point2D D2(10,20);
	Point2D C1(0,0);
	Point2D G2(5,5);

	student_ptrs[0] = new Student("Homer", 1, 'S', 2, S1);

	student_ptrs[1] = new Student("Marge", 2, 'S', 1, S2);

	office_ptrs[0] = new DoctorsOffice(1, 1.0, 100, D1);

	office_ptrs[1] = new DoctorsOffice(2, 2.0, 200, D2);

	class_ptrs[0] = new ClassRoom(10, 1, 2, 3, 1,C1);

	class_ptrs[1] = new ClassRoom(20, 5, 7.5, 4, 2, G2);//figure out how to have G2 as display code 
	

	object_ptrs[0] = student_ptrs[0];

	object_ptrs[1] = student_ptrs[1];

	object_ptrs[2] = office_ptrs[0];

	object_ptrs[3] = office_ptrs[1];

	object_ptrs[4] = class_ptrs[0];

	object_ptrs[5] = class_ptrs[1];


	num_offices = 2;

	num_classes = 2;

	num_students = 2;

	num_objects = 6;

	cout<<"model constructed"<<endl;

}

Student * Model::GetStudentPtr(int id)
{

	for (int i = 0; i < 2; i++)
	{

		if ((student_ptrs[i]->GetId()) == id)
		{
			cout<<"in model"<<endl;
		return student_ptrs[i];
		}
		
	

	}
	return 0;
}

DoctorsOffice * Model :: GetDoctorsOfficePtr(int id)
{

	for (int i = 0; i < 2; i++)
	{

		if ((office_ptrs[i]->GetId()) == id)
		{
			return office_ptrs[i];
		}
		
		
	}
	
	return 0;
}



ClassRoom * Model::GetClassRoomPtr(int id)
{

	for (int i = 0; i < 2; i++)
	{

		if ((class_ptrs[i]->GetId()) == id)
		{
		return class_ptrs[i];
		}
		
	}
		return 0;
}


int Model::GetTime()
{
return time;
}



bool Model::Update()
{
	time = time + 1;

	bool is_updated = false;

	for (int i = 0; i<6; i++)
	{
		is_updated = is_updated || object_ptrs[i]->Update();
	}

	if (class_ptrs[0]->GetNumAssignmentsRemaining() + class_ptrs[1]->GetNumAssignmentsRemaining() == 0)
	{
		cout<<"Game Over: You Win! All assignments are done"<<endl;
		exit(1);//exit function
	}

	if (student_ptrs[0]->IsInfected() && student_ptrs[1]->IsInfected())
	{
		cout<<"Game over: should have worn a mask... :("<<endl;
		exit(1);//exit function
	}
	return is_updated;

}


void Model::ShowStatus()
{

	cout<<"time: "<<GetTime()<<endl;

	for (int i = 0; i<6; i++)
	{
		object_ptrs[i]->ShowStatus();
	}


}

Model::~Model()
{
	cout<<"Model Destructed"<<endl;
}


void Model::Display(View& view)
{
	cout<<time<<endl;
	 view.Clear();
	 for (int i = 0; i < num_objects; i++)
	 {
	 	if (object_ptrs[i] -> ShouldBeVisible())
	 	{
	 		object_ptrs[i] -> ShowStatus();
	 	}
	 }
	 view.Draw();
}
