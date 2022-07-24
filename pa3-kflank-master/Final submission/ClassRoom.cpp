#include "ClassRoom.h"

ClassRoom::ClassRoom(): Building()
{
	display_code = 'C';

	state = NOT_PASSED;

	max_number_of_assignments = 10;

	num_assignments_remaining = max_number_of_assignments;

	antibody_cost_per_assignment = 1;

	dollar_cost_per_assignment = 1.0;

	credits_per_assignment = 2;

	cout<<"ClassRoom default constructed"<<endl;


}

ClassRoom::ClassRoom(unsigned int max_assign, unsigned int antibody_cost, double dollar_cost, unsigned int crd_per_assign, int in_id, Point2D in_loc): Building('C', in_id, in_loc)
{
	id = in_id;

	max_number_of_assignments = max_assign;

	antibody_cost_per_assignment = antibody_cost; //check this with prof

	credits_per_assignment = crd_per_assign;

	dollar_cost_per_assignment = dollar_cost;

	location = in_loc;

	num_assignments_remaining = max_number_of_assignments;

	cout<<"ClassRoom constructed"<<endl;

	//**
	//initialize the rest of the vars to default - ask what this means 

}

ClassRoom::~ClassRoom()
{
	cout<<"ClassRoom destoryed"<<endl;
}


void ClassRoom::remove_assignments(unsigned int delta_assignment)
{
num_assignments_remaining -= delta_assignment;
}

// Public member functions 


unsigned int ClassRoom::Getcredits_per_assignment() //made this 
{
	return credits_per_assignment;
}

unsigned int ClassRoom::Getantibody_cost_per_assignment() //made this 
{
	return antibody_cost_per_assignment;
} 

double ClassRoom::GetDollarCost(unsigned int unit_qty)
{
	return unit_qty*dollar_cost_per_assignment;
}

unsigned int ClassRoom::GetAntibodyCost(unsigned int unit_qty)
{
	return antibody_cost_per_assignment*unit_qty;
}

unsigned int ClassRoom::GetNumAssignmentsRemaining()
{
	return num_assignments_remaining; //check this 
}

bool ClassRoom::isAbleToLearn(unsigned int unit_qty, double budget, unsigned int antibodies)
{
	if (budget >= unit_qty*dollar_cost_per_assignment && antibodies >= antibody_cost_per_assignment*unit_qty)
		return true;
	else 
		return false;
}
//** not sure 
unsigned int ClassRoom::TrainStudents(unsigned int assignment_units) //ask if assignment_units means amount of assignments requested to complete?
{
	unsigned int value;
	if (num_assignments_remaining >= assignment_units)
	{
		value = num_assignments_remaining - assignment_units;
	}
	else 
	{
		value = num_assignments_remaining;
	}

return value;

}

bool ClassRoom::Update()
{
	if (num_assignments_remaining == 0)
	{
		state = PASSED;
		display_code = 'c';
		cout<<display_code<<" "<<id<<"has been passed"<<endl;
		return true;
	}	
	return false;
}

bool ClassRoom::passed()
{
	return num_assignments_remaining == 0;
		

}

void ClassRoom::ShowStatus()
{
	cout<<"ClassRoomStatus: "<<endl;
	Building::ShowStatus();
	cout<<"Max number of assignments: "<<max_number_of_assignments<<endl;
	cout<<"Antibody cost per assignment: "<<antibody_cost_per_assignment<<endl;
	cout<<"Dollar per assignment: "<<dollar_cost_per_assignment<<endl;
	cout<<"Credits per assignment: "<<credits_per_assignment<<endl;
	cout<<num_assignments_remaining<<" assignments are remaining for this classroom"<<endl;
}
