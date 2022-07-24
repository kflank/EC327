//#ifndef ClassRoom_h
//#define ClassRoom_h

#include "Building.cpp"

//#endif
enum ClassRoomStates 
{
NOT_PASSED = 0,
PASSED = 1
};

class ClassRoom:  public Building 
{
	private:
		unsigned int num_assignments_remaining;

		unsigned int max_number_of_assignments;

		unsigned int antibody_cost_per_assignment;

		double dollar_cost_per_assignment;

		unsigned int credits_per_assignment;

	public: 

		//constructors

		ClassRoom();

		ClassRoom(unsigned int max_assign, unsigned int antibody_cost, double dollar_cost, unsigned int crd_per_assign, int in_id, Point2D in_loc);

		~ClassRoom();
		
		//public member Functions 

		unsigned int Getantibody_cost_per_assignment(); //made this 

		double GetDollarCost(unsigned int unit_qty);

		unsigned int GetAntibodyCost(unsigned int unit_qty);

		unsigned int GetNumAssignmentsRemaining();

		void remove_assignments(unsigned int delta_assignment);

		bool isAbleToLearn(unsigned int unit_qty, double budget, unsigned int antibodies);

		unsigned int TrainStudents(unsigned int assignment_units);
		
		unsigned int Getcredits_per_assignment(); //made this 

		bool Update();

		bool passed();

		void ShowStatus();


};

//#endif