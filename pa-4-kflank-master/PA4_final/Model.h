#ifndef MODEL_H
#define MODEL_H
#include "GameObject.h"
#include "Student.h"
#include "DoctorsOffice.h"
#include "ClassRoom.h"
#include "View.h"
#include "Virus.h"
#include <string>
#include <list>
#include <vector>

class Model
{
    private:
        int time;
        
        list <GameObject*> objectList;

        list <GameObject*> activeList;

        list <Student*> studentlist;

        list < DoctorsOffice *> doctorslist;

        list <ClassRoom*> classlist;

        
        list <Virus*> viruslist;

        View view; 
    
    public:
        //Constructor and Destructor
        Model();
        ~Model();



        Student*  GetStudentPtr(int id);
        DoctorsOffice* GetDoctorsOfficePtr(int id);
        ClassRoom* GetClassRoomPtr(int id);
        Virus* GetVirusPtr(int);

        bool Update();
        void Display(); //Removed the view address passed to the function because I made View a member of the class
        void ShowStatus();
};





#endif
