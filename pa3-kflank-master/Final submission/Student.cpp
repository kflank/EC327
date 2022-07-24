#include "Student.h"
#include <cmath>


Student::Student() : GameObject('S')//defualt constructor 
{
	//Point2D location = GetLocation();
	speed = 5.0;
	state = STOPPED;
	display_code = 'S';
	antibodies = 3; //not specfied so set to 3 for all constructors 
	credits = 0;
	dollars = 0;
	cout<<"student default constructed"<<endl;
}

Student::Student(char in_code) :GameObject('S')
{
	//Point2D location = GetLocation();
	speed = 5.0;
	state = STOPPED;
	display_code = in_code;
	antibodies = 3;
	credits = 0;
	dollars = 0;
	cout<<"student constructed"<<endl;
}

Student::Student(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) :GameObject('S')
{
	//Point2D location = GetLocation();
	speed = in_speed;
	name = in_name;
	state = STOPPED;
	display_code = in_code;
	id = in_id;
	antibodies = 3;
	credits = 0;
	dollars = 0;
	cout<<"student constructed"<<endl;

}


string Student::Getname()
{
	return name; 
}


Student::~Student()
{
	cout<<"Student destroyed"<<endl;
}

void Student::SetupDestination(Point2D dest)
	{
		destination = dest;
		cout<<"in set up destination"<<endl;
		delta = (destination - location) * (speed/ GetDistanceBetween(destination, location));
		/*
		if (location == (*current_class).GetLocation()) //remove a student from classroom if they are leaving a classroom
		{
			(*current_class).RemoveOneStudent(); 
		}
		if (location == (*current_office).GetLocation()) //remove a student from doc offcie  they leave a doctors offcie 
		{
			(*current_class).RemoveOneStudent(); 
		}
		cout<<"in second of destination"<<endl;
*/
	}




void Student::StartMoving(Point2D dest)
{
	SetupDestination(dest);
	state = MOVING;
	
	if (location == dest)
	{
		cout<<display_code<<id<<": "<<"I'm already there. See?"<<endl;
		/*
		if (location == (*current_class).GetLocation())
		{	
			cout<<"in set up dest real"<<endl;
			(*current_class).AddOneStudent(); //add a student to classroom if they enter 
		}

		else if (location == (*current_office).GetLocation())
		{		
			(*current_office).RemoveOneStudent(); //Add a student to an office if it enters doc office 
		}

		*/

	}

	if (state == INFECTED)
	{
		cout<<display_code<<id<<": i am infected. I may move but you cannot see me."<<endl;
	}
	else 
	{
		cout<<display_code<<id<<" On my way."<<endl;
	}
}

void Student::StartMovingToClass(ClassRoom* classr)
{

		if (state == INFECTED)
		{
			cout<<" "<<display_code<<id<<" I'm infected so I can't move to class"<<endl;
		}
		else if (state == IN_CLASS)
		{
			cout<<" "<<display_code<<id<<"I'm already at the classroom!"<<endl;
		}
		
		cout<<" "<<display_code<<id<<"On my way to class"<<(*classr).GetId()<<endl;

		current_class = classr;

		SetupDestination((*current_class).GetLocation());

		state = MOVING_TO_CLASS;
}
	


	void Student::StartMovingToDoctor(DoctorsOffice* office)
	{
		
		Point2D doc_loc = (*office).GetLocation();
		SetupDestination(doc_loc);
		state = MOVING_TO_DOCTOR;

		if (state == INFECTED)
		{
			cout<<" "<<display_code<<id<<"I am infected, I should have gone to the doctor's.."<<endl;
		}
		else if (state == IN_CLASS)
		{
			cout<<" "<<display_code<<id<<"I'm already at the classroom"<<endl;
		}
		else 
		{
			cout<<" "<<display_code<<id<<"On my way to class"<<(*office).GetId()<<endl;
		}
	}

	void Student::StartLearning(unsigned int num_assignments)
	{
		if (state == INFECTED)
		{
			cout<<display_code<<id<<" I am infected so no more school for me"<<endl;
		}
		else if (state != STUDYING_IN_CLASS || state != IN_CLASS)  
		{
			cout<<display_code<<id<<"I can only learn in a classroom"<<endl;
		}
		else if (dollars < (*current_class).GetDollarCost(num_assignments))
		{
			cout<<display_code<<id<<" Not enough money for school"<<endl;
		}
		else if ((*current_class).GetNumAssignmentsRemaining() == 0)
		{
			cout<<display_code<<id<<" Cannot learn! This class has no more assignments"<<endl;
		}
		else if (antibodies < (*current_class).Getantibody_cost_per_assignment())
		{
			cout<<"not enough antibodies to learn"<<endl;
		} 
		else
		{
		//int tot_num_assignments = (*current_class).GetNumAssignmentsRemaining();
		
		state = STUDYING_IN_CLASS;


		
		cout<<display_code<<"started to learn at the classroom "<<(*current_class).GetId()<<" with "<<num_assignments<<" assignments"<<endl;
		
		credits = (*current_class).Getcredits_per_assignment() * num_assignments;
		
		//tot_num_assignments = (*current_class).GetNumAssignmentsRemaining() - num_assignments; //ask Prof densmore about how to update this 
		
		assignments_to_buy = num_assignments; //ask prof about this 
		}

	}

	void Student::StartRecoveringAntibodies(unsigned int num_vaccines)
	{
		cout<<"in recovring "<<endl;
		if (dollars < (*current_office).GetDollarCost(num_vaccines))
		{
			cout<<display_code<<id<<" Not enough money to recover antibodies"<<endl;
		}

		else if ((*current_office).GetNumVaccineRemaining() == 0)
		{
			cout<<display_code<<id<<" Cannot recover! No vaccine remaining"<<endl;
		}

		else if (state != AT_DOCTORS)
		{
			cout<<display_code<<id<<" I can only recover antibodies at a doctors offcie"<<endl;
		}

		else
		{
			state = RECOVERING_ANTIBODIES;
			
			cout<<display_code<<id<<" started recovering "<<num_vaccines<<"Vaccines at Doctors's Office "<<(*current_office).GetId()<<endl;


			int tot_num_vaccines = (*current_office).GetNumVaccineRemaining() - num_vaccines; //ask what I am supposed to do with this 

			vaccines_to_buy = num_vaccines;

			//(*current_office).num_vaccine_remaining = tot_num_vaccines;
		}

	}

	void Student::Stop()
	{
		state = STOPPED;

		cout<<display_code<<id<<": stopping"<<endl;

	}

	bool Student::IsInfected()
	{
		return antibodies == 0;
	}

	bool Student::ShouldBeVisible()
	{
		return state != INFECTED;
	}

	void Student::ShowStatus()
	{
		cout<<" "<<name<<" status:"<<endl;
		GameObject::ShowStatus();
		cout<<state<<endl;
		cout<<"antiboides: "<<antibodies<<endl;
		cout<<"dollars "<<dollars<<endl;
		cout<<"credits "<<credits<<endl;

		if (antibodies == 0)
		{
			cout<<name<<" is out of antibodies and can't moce"<<endl;
		}
		if (state == STOPPED)
		{
			cout<<"stopped"<<endl;
		}  
		if (state == MOVING)
		{
			cout<<"moving at speed "<<speed<<"to destination "<<destination<<"at steps of"<<delta<<endl;
		}
		if (state == MOVING_TO_CLASS)
		{
			cout<<"heading to classroom "<<(*current_class).GetId()<<"At speed of "<<speed<<" in steps of "<<delta<<endl;
		}
		if (state == MOVING_TO_DOCTOR)
		{
			cout<<"heading to Doctors Office "<<(*current_office).GetId()<<"At speed of "<<speed<<" in steps of "<<delta<<endl;
		}
		if (state == IN_CLASS)
		{
			cout<<"Inside Classroom "<<(*current_class).GetId()<<endl;
		}
		if (state == AT_DOCTORS)
		{
			cout<<"Inside Doctor's Office "<<(*current_office).GetId()<<endl;
		}
		if (state == STUDYING_IN_CLASS)
		{
			cout<<"Studying in classroom "<<(*current_class).GetId()<<endl;
		}
		if (state == RECOVERING_ANTIBODIES)
		{
			cout<<"Recovering antibodies in Doctor's office"<<(*current_office).GetId()<<endl;
		}
	}

	

bool Student::Update()
{
    if (state == MOVING || state == MOVING_TO_CLASS || state == MOVING_TO_DOCTOR)
    {
        antibodies = antibodies -1;
        dollars = dollars + GetRandomAmountOfDollars();
    }

    if (antibodies == 0)
    {
    	state = INFECTED;
    }

    switch (state)
    {
    case STOPPED:
        
        return false;

    case MOVING:
        	UpdateLocation();
        	if(location == destination)
        	{
        		state = STOPPED;
        		return true;
        	}
        
        else
        {
            state = MOVING;
            return false;
        }    
      


    case  MOVING_TO_CLASS:

         UpdateLocation();

        if (location == destination)
        {
            state= IN_CLASS;
            return true;
        }

        else
        {
           state = MOVING_TO_CLASS;
        }

        break;

    case  MOVING_TO_DOCTOR:
          UpdateLocation();

        if(location == destination)
        {
            state= AT_DOCTORS;
            return true;
        }
        else
        {
           state = MOVING_TO_DOCTOR;
        }
        break;   

    case  IN_CLASS:
        	return false;
        	break; 

    case  AT_DOCTORS:
        return false;
        break; 

    case  STUDYING_IN_CLASS:
        antibodies = antibodies - (*current_class).GetAntibodyCost(assignments_to_buy);
        dollars= dollars - (*current_class).GetDollarCost(assignments_to_buy);
        credits = credits + (*current_class).TrainStudents(assignments_to_buy);
        (*current_class).remove_assignments(assignments_to_buy);
        cout<<"** "<<name<<" completed "<<assignments_to_buy<<" assignment(s)!**"<<endl;
        cout<<"** "<<name<<" gained "<<credits<<" credit(s)!**"<<endl;
        state = IN_CLASS;
        return true;
        break; 

    case  RECOVERING_ANTIBODIES:
        antibodies = antibodies + vaccines_to_buy*5;
        dollars = dollars - (*current_office).GetDollarCost(vaccines_to_buy);
        (*current_office).remove_vaccines(vaccines_to_buy);
        cout<<"** " <<name<<" recovered "<< antibodies<< " antibodies! "<<endl;
        cout<<"** " <<name<<"bought "<< vaccines_to_buy<< "vaccine(s)! "<<endl; 
        state = AT_DOCTORS;
        return true;
        break;                         
    
      default:
        break;
    }
}




	bool Student:: UpdateLocation()
{
   if (fabs(destination.x - location.x ) <= destination.x && fabs(destination.y - location.y) <= destination.y)
   {
       location = destination;
       cout<<"arrived"<<endl;
       return true;
   }
   else
   {
       location = location + delta;
       cout<<"moved"<<endl;
       return false;
   }

    if(location == destination)
    {
    cout<<" "<<display_code<<id<<"I'm there"<<endl;
    return true;
    }
    else
    {
    cout<<" "<<display_code<<id<<"step.."<<endl;
    return false;
    }
}




double GetRandomAmountOfDollars()
{
return rand() % 3;
}





