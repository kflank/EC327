#include "GameCommand.h"


void DoMoveCommand(Model & model, int student_id, Point2D p1)
{	
	Student* S = model.GetStudentPtr(student_id);
		if ((S->GetId()) == student_id)
		{
			S->StartMoving(p1);
			cout<<"moving student "<< S->Getname()<<" to "<<p1<<endl;
		}
		else 
		{
			cout<<"enter a valid game command "<<endl;
		}
}





void DoMoveToDoctorCommand(Model & model, int student_id, int office_id)
{	
		Student* S = model.GetStudentPtr(student_id);
		DoctorsOffice* D = model.GetDoctorsOfficePtr(office_id);
		if (S->GetId() == student_id  &&  D->GetId() == office_id)
		{
			Point2D doc_loc = D->GetLocation();
			cout<<"moving student "<< S->Getname()<<" to doctors office "<<office_id<<endl;
			S->StartMoving(doc_loc);
		}
		else 
		{
			cout<<"enter a valid game command "<<endl;
		}
	

}



void DoMoveToClassCommand(Model & model, int student_id, int class_id)
{
	Student* S = model.GetStudentPtr(student_id);
	ClassRoom* C = model.GetClassRoomPtr(class_id);

		if (C->GetId() == class_id &&  S->GetId() == student_id)
		{
			cout<<"moving student "<< S->Getname()<<" to Classroom office "<<class_id<<endl;
			Point2D class_loc = C->GetLocation();
			cout<<"class loc is"<<class_loc<<endl;
			cout<<"in moving to class"<<endl;
			S->StartMoving(class_loc);
			
		}
		else 
		{
			cout<<"enter a valid game command "<<endl;
		}
}



void DoStopCommand(Model & model, int student_id)
{
	Student* S = model.GetStudentPtr(student_id);

		if ( S->GetId() == student_id)
		{
			S->Stop();
			cout<<"Stopping "<< S->Getname()<<endl;
		}
		else 
		{
			cout<<"enter a valid game command "<<endl;
		}
	

}

void DoLearningCommand(Model & model, int student_id, unsigned int assignments)
{
		Student* S = model.GetStudentPtr(student_id);
		if (S->GetId() == student_id)
		{
			S->StartLearning(assignments);
			cout<<"Teaching "<< S->Getname()<<endl;
		}
		else 
		{
			cout<<"enter a valid game command "<<endl;
		}


}

void DoRecoverInOfficeCommand(Model& model, int student_id, unsigned int vaccine_needs)
{
	
	Student* S = model.GetStudentPtr(student_id);
	
	if (S->GetId() == student_id)
	{
		cout<<"in recover"<<endl;
		S->StartRecoveringAntibodies(vaccine_needs);
		cout<<"recovering "<<S->Getname()<<" antibodies"<<endl;
	}
	else 
	{
		cout<<"enter a valid command"<<endl;
	}


}

//void DoGoCommand(Model& model, View& view);

//void DoRunCommand(Model& model, View& view);



void Command()
{

	cout<<"enter game command"<<endl;
	char com;
	cin >> com;
	int student_id;
	int doc_id; 
	int class_id;  
	unsigned int vaccine_needs;
	unsigned int assignments;
	Model model;
	Point2D p;
	int x;
	int y;
	
	
		switch (com)
		{
			case 'm':
				cout<<"enter student id to move "<<endl;
				cin >> student_id;
				cout<<"enter x coordinate to move the student to"<<endl;
				cin >>x;
				cout<<"enter y coordinate to move student to"<<endl;
				cin >>y;
				p.x = x;
				p.y = y;
				DoMoveCommand(model, student_id, p);
			
			case 'd':
				cout<<"enter student id to move "<<endl;
				cin >> student_id;
				cout<<"enter doctors office id to move to"<<endl;
				cin>> doc_id;
				DoMoveToDoctorCommand(model, student_id, doc_id);

			case 'c':
				cout<<"enter student id to move "<<endl;
				cin >> student_id;
				cout<<"enter class id to move to"<<endl;
				cin>> class_id;
				DoMoveToDoctorCommand(model, student_id, class_id);



			case 's':
				cout<<"enter student id to stop "<<endl;
				DoStopCommand(model, student_id);

			case 'v':
				cout<<"enter student id to recover vaccines"<<endl;
				cin>>student_id;
				cout<<"enter # of vaccines to buy"<<endl;
				cin>>vaccine_needs;
				DoRecoverInOfficeCommand(model, student_id, vaccine_needs);

			case 'a':
				cout<<"enter student id to learn "<<endl;
				cin>> student_id;
				cout<<"enter number of assignments to complete"<<endl;
				cin>> assignments;
				DoLearningCommand(model, student_id, assignments);


			case 'g': //add when view is done 


			case 'r': // add when view is done 




			case 'q':
				exit(1); 


			default:
				cout<<"enter a valid game command"<<endl;


		}
	
}









