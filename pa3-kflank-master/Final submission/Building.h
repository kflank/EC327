#include "GameObject.cpp"




class Building: public GameObject 
{
	

	private: 
		unsigned int student_count;

	public:

		Building(char, int, Point2D);

		Building();

		virtual ~Building();


		unsigned int Getstudent_count(); //made this

		bool ShouldBeVisible();

		void AddOneStudent();

		void RemoveOneStudent();

		void ShowStatus();

};

