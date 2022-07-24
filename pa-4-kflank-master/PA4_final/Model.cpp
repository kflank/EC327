#include <iostream>
#include <vector>
#include <list>
#include "GameObject.h"
#include "Student.h"
#include "ClassRoom.h"
#include "DoctorsOffice.h"
#include "View.h"
#include "Model.h"
#include "Virus.h"

using namespace std;

//Constructor
Model::Model()
{
    time = 0;

    Virus* V1 = new Virus("Delta varient", 5.0, 2.0, 10.0, false, 1, Point2D(10,12));
    Virus* V2 = new Virus("Alpha varient", 5.0, 2.0, 10.0, false, 2, Point2D(15,5));

    this -> viruslist.push_back(V1);
    this -> viruslist.push_back(V2);


    Student* S1 = new Student("Homer", 1, 'S', 2, Point2D(5, 1));
    Student* S2 = new Student("Marge", 2, 'S', 1, Point2D(10, 1));

    this -> studentlist.push_back(S1);
    this -> studentlist.push_back(S1);


    ClassRoom* C1 = new ClassRoom(10, 1, 2, 3, 1, Point2D(0, 0));
    ClassRoom* C2 = new ClassRoom(20, 5, 7.5, 4, 2, Point2D(5, 5));

    this -> classlist.push_back(C1);
    this -> classlist.push_back(C2);


    DoctorsOffice* D1 = new DoctorsOffice(1, 1, 100, Point2D(1, 20));
    DoctorsOffice* D2 = new DoctorsOffice(2, 2, 200, Point2D(10, 20));

    this -> doctorslist.push_back(D1);
    this -> doctorslist.push_back(D2);



//initialize lists 
    this -> objectList.push_back(S1);
    this -> objectList.push_back(S2);
    this -> objectList.push_back(D1);
    this -> objectList.push_back(D2);
    this -> objectList.push_back(C1);
    this -> objectList.push_back(C2);
    this -> objectList.push_back(V1);
    this -> objectList.push_back(V2);
   

    //actiive list 

    this -> activeList.push_back(S1);
    this -> activeList.push_back(S2);
    this -> activeList.push_back(C1);
    this -> activeList.push_back(C2);
    this -> activeList.push_back(D1);
    this -> activeList.push_back(D2);
    this -> objectList.push_back(V1);
    this -> objectList.push_back(V2);

    

    cout<<"Model Default constructed"<<endl;
   
}


//Destructor
Model::~Model()
{
    list <GameObject *> :: iterator i;
    for (i = this -> objectList.begin(); i != this -> objectList.end(); i++)
    {
          delete *i;
    }
}


//Member functions
Student * Model::GetStudentPtr(int id)
{
    list <Student *>::iterator i;
    for (i = this -> studentlist.begin(); i != this -> studentlist.end(); i++)
    {
        if ( (*i) -> GetId() == id)
        {
            return *i;
        }
    }
    return 0;
}


DoctorsOffice * Model::GetDoctorsOfficePtr(int id)
{
    list <DoctorsOffice *>:: iterator i;
    for (i = this -> doctorslist.begin(); i != this -> doctorslist.end(); i++)
    {
        if ((*i) -> GetId() == id)
        {
            return *i;
        }
    }
    return 0;
}

ClassRoom * Model::GetClassRoomPtr(int id)
{
    list <ClassRoom*>::iterator i;
    
    for (i = this -> classlist.begin(); i != this -> classlist.end(); i++)
    {
        if ((*i) -> GetId() == id)
        {
            return *i;
        }
    }
    return NULL;
}


Virus * Model::GetVirusPtr(int id)
{
    list <Virus *>::iterator i;
    for (i = viruslist.begin(); i != viruslist.end(); i++)
    {
        if ( (*i) -> GetId() == id)
        {
            return *i;
        }
    }
    return 0;
}

bool Model::Update()
{
    time++;

    bool updateHapend = false;
    list <GameObject *>::iterator i1;
    for (i1 = this -> objectList.begin(); i1 != this -> objectList.end(); i1++)
    {
        if ( (*i1) -> Update() )
        {
            updateHapend = true;
        }
    }

    //Checking if won
    list <ClassRoom *>::iterator i2;
    unsigned int sumAssignmentsRemaining = (*i2) -> GetNumAssignmentsRemaining();

    for (i2 = this -> classlist.begin(); i2 != this-> classlist.end(); i2++)
    {
        sumAssignmentsRemaining += (*i2) -> GetNumAssignmentsRemaining();
    }
    if (sumAssignmentsRemaining == 0)
    {
        cout << "GAME OVER: You win! All assignments done!" << endl;
        ShowStatus();
        exit(0);
        return true;
    }
    
    //Check if lost
    list <Student *>::iterator i3;
    bool allStudentsInfected = true;
    for (i3 = this -> studentlist.begin(); i3 != this -> studentlist.end(); i3++)
    {
        allStudentsInfected = allStudentsInfected && (*i3) -> IsInfected();
    }

    if (allStudentsInfected)
    {
        cout << "GAME OVER: You lose! All of your Students are infected!" << endl;
        ShowStatus();
        exit(0);
        return true; //Assume that losing is a change
    }

    // game continues
    return updateHapend;
}

void Model::Display()
{
    list <Student *>::iterator i1;
    view.Clear();
    
    for (i1 = this -> studentlist.begin(); i1 != this -> studentlist.end(); i1++)
    {
        if ( (*i1) -> ShouldBeVisible())
        {
            view.Plot(*i1);
        }
    }

    list <ClassRoom *>::iterator i2;
    for (i2 = this -> classlist.begin(); i2 != this-> classlist.end(); i2++)
    {
        view.Plot(*i2);
    }

    list <DoctorsOffice *>::iterator i3;
    for (i3 = this-> doctorslist.begin(); i3 != this -> doctorslist.end(); i3++)
    {
        view.Plot(*i3);
    }
    list <Virus *>::iterator i4;
    for (i4 = this-> viruslist.begin(); i4 != this -> viruslist.end(); i4++)
    {
        view.Plot(*i4);
    }

    view.Draw();
}

void Model::ShowStatus()
{
    cout << "Time: " << time << endl;

list <GameObject *>::iterator i;
    for (i = this -> objectList.begin(); i != this -> objectList.end(); i++)
    {
        (*i) -> ShowStatus();
    }
}


