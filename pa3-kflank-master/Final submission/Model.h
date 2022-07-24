#include "View.cpp"




class Model: public View
{
	private:
		int time ;

		GameObject* object_ptrs[10];

		int num_objects;

		Student* student_ptrs[10];

		int num_students;

		DoctorsOffice* office_ptrs[10];

		int num_offices;

		ClassRoom* class_ptrs[10];

		int num_classes;

	public:
		//constructors 
		Model();

		~Model();

		int GetTime();

		Student * GetStudentPtr(int id);

		DoctorsOffice * GetDoctorsOfficePtr(int id);

		ClassRoom * GetClassRoomPtr(int id);

		bool Update();

		void Display(View& view); 

		void ShowStatus(); 

};


 