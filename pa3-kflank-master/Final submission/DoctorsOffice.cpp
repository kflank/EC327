#include "DoctorsOffice.h"


DoctorsOffice::DoctorsOffice() :Building()
{
	vaccine_capacity = 100;

	num_vaccine_remaining = vaccine_capacity;

	dollar_cost_per_vaccine = 5;

	state = VACCINE_AVAILABLE;

	display_code = 'D';

	cout<<"DoctorsOffice constructed"<<endl;

}



DoctorsOffice::DoctorsOffice(int in_id, double vaccine_cost, unsigned int vaccine_cap, Point2D in_loc) :Building('D', in_id, in_loc)
{
	id = in_id;

	location = in_loc;

	dollar_cost_per_vaccine = vaccine_cost;

	vaccine_capacity = vaccine_cap;

	cout<<"DoctorsOffice constructed"<<endl;

	state = VACCINE_AVAILABLE;

	vaccine_capacity = 100;

	num_vaccine_remaining = vaccine_capacity;

}
DoctorsOffice:: ~DoctorsOffice()
{
	cout<<"DoctorsOffice destroyed"<<endl;
}
//public member functions 

bool DoctorsOffice::HasVaccine()
{
	return  num_vaccine_remaining != 0;
	
}


unsigned int DoctorsOffice::GetNumVaccineRemaining()
{
	return num_vaccine_remaining;
}


bool DoctorsOffice::CanAffordVaccine(unsigned int vaccine, double budget)
{
	return budget > dollar_cost_per_vaccine;
}


double DoctorsOffice::GetDollarCost(unsigned int vaccine)
{
	return vaccine * dollar_cost_per_vaccine;
}
//Fix this **
unsigned int DoctorsOffice::DistributeVaccine(unsigned int vaccine_needed)
{
	unsigned int doc_remain = num_vaccine_remaining;
	if (num_vaccine_remaining >= vaccine_needed)
	{
		doc_remain = num_vaccine_remaining - vaccine_needed;
		return vaccine_needed;
	}

	else 
	{
		num_vaccine_remaining = 0;
		return doc_remain;
	}

}


void DoctorsOffice::remove_vaccines(unsigned int delta_vaccine)
{
num_vaccine_remaining -= delta_vaccine;
}


bool DoctorsOffice::Update()
{	

	if (num_vaccine_remaining <= 0)
	{
		state = NO_VACCINE_AVAILABLE;
		display_code = 'd';
		cout<<"DoctorsOffice "<<id<<" has ran out of vaccines"<<endl;
		return true;
	}
	else 
		return false;
}

void DoctorsOffice::ShowStatus()
{
	cout<<"DoctorsOffice Status"<<endl;
	Building::ShowStatus();
	cout<<"Dollars per vaccine: "<<dollar_cost_per_vaccine<<endl;
	cout<<"has "<<num_vaccine_remaining<<" vaccines remaining"<<endl;

}