#include "Point2D.cpp"



class GameObject
{
protected: 

	Point2D location;  //loaction of object

	int id; //Object ID

	char display_code;  //how object is represented in the veiw

	char state; //state of the object, more info provided in each derived class


public:
	
	GameObject(char); //constructor for ....
	
	virtual bool Update() = 0;

	GameObject(Point2D, int, char); // cosntructor for ... 
	
	virtual ~GameObject();

	Point2D GetLocation();

	int GetId();

	char GetState();

	virtual void ShowStatus();

	virtual bool ShouldBeVisible();

	void DrawSelf(char * ptr);
	
};



	



