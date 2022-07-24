#include <iostream>
using namespace std;
#include "Virus.h"
#include "GameObject.h"

Virus::Virus(string name, double virulence, double resistance, double energy,bool variant, int id, Point2D in_loc):GameObject(in_loc, id, 'V')
{
    virulence=5.0;
    resistance=2.0;
    variant=false;
    energy=10.0;
}

void Virus:: infect(Student* s)
{
    /*s->GOTVIRUS= INFECTED;

     current_student=s;
     */
}

bool Virus:: get_variant()
{
    return variant;
}

double Virus:: get_virulence()
{
    return virulence;
}

double Virus:: get_resistance()
{
    return resistance;
}

double Virus:: get_energy()
{
    return energy;
}

bool Virus:: get_in_student()
{
    return is_in_student;
}

bool Virus:: Update()
{
    bool retval = 0;
    switch(this -> state)
    {
        case IN_ENVIRONMENT:
                retval = false;
                break;
        case DEAD:
            if(energy <= 0)
                retval = true;
            else
                retval = false;
            break;
        case IN_STUDENT:
            //if()
                retval = true;
            state = IN_STUDENT;
            //else
                retval = false;
            break;
    }
    return retval;
}
            /*if(energy=<0)
            {
                current_student->state= DEAD; 
            }
            if(current_student-> location== ) //when
            {
                state= IN_STUDENT;
            }*/

void Virus::ShowStatus()
{
    GameObject::ShowStatus();
    switch(state)
    {
        case IN_ENVIRONMENT:
            cout << "\t in view:" << endl;
            break;
        case DEAD:
            cout << "\t dead" << endl;
        case IN_STUDENT:
            cout << "\t in student" << endl;
    }
}

bool Virus:: IsAlive()
    {
        if (energy > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

bool Virus::ShouldBeVisible()
{
    bool visible = false;
    if(state != DEAD)
    {
        visible = true;
    }
    return visible;
}

   




