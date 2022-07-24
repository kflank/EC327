#ifndef VIRUS_H
#define VIRUS_H
#include "Student.h"

enum VirusStates {
    IN_ENVIRONMENT = 0,
    DEAD = 1,
    IN_STUDENT = 2
};
class Student; //Extra credit??: forward declaration of student class
class Virus:public GameObject //Inherit GameObject
{
    private:
        unsigned int student_count;

    public:
        Virus(string, double, double, double, bool, int, Point2D);
        void infect(Student* s);
        bool get_variant();
        double get_virulence();
        double get_resistance();
        double get_energy();
        bool get_in_student();
        bool Update();
        void ShowStatus();
        bool IsAlive();
    bool ShouldBeVisible();

    protected:
        double virulence;
        double resistance;
        bool variant;
        double energy;
        bool is_in_student;
        string name;
        Student* current_student;
};

#endif








