

#include "ClassRoom.cpp"

enum DoctorsOfficeStates {
VACCINE_AVAILABLE = 0,
NO_VACCINE_AVAILABLE = 1
};

class DoctorsOffice:public Building
{
	private:
		unsigned int vaccine_capacity;
		
		unsigned int num_vaccine_remaining;

		double dollar_cost_per_vaccine;

	public:

		//constructors

		DoctorsOffice();

		DoctorsOffice(int in_id, double vaccine_cost, unsigned int vaccine_cap, Point2D in_loc);

		virtual ~DoctorsOffice();
		//public member functions

		void remove_vaccines(unsigned int delta_vaccines);

		bool HasVaccine();

		unsigned int GetNumVaccineRemaining();

		bool CanAffordVaccine(unsigned int vaccine, double budget);

		double GetDollarCost(unsigned int vaccine);

		unsigned int DistributeVaccine(unsigned int vaccine_needed);

		bool Update();

		void ShowStatus();



}; 

