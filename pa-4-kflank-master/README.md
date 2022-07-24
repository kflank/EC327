Programming assignment #4 for introduction to softwatre engineering 


Using C++ this is a simple game that uses a GUI interface to play a COVID game.

Players will input commands into the command line to play,


**The rules of the game are as follows.**

Studetns must complete all of their assignments which can be completed by moving to classrooms and buying assignmetnts. 

each time a student moves they receive a random amount of money, but they will also lose antibodies.

If a studetn loses all of their antibodies they lose the game, but if they complete all of their assignemnts they win. 

A student is able to recover antobodies by moving to a doctors office and waiting until they reciver the desired amount of antibodies. 



**The input commands are as follows.**

• m ID x y
o "move": command Student ID to move to location (x, y)

• d ID1 ID2
o "move towards a DoctorsOffice": command Student ID1 to start heading to
DoctorsOffice ID2.

• c ID1 ID2
o “move towards a Classroom”: command Student ID1 to start heading towards
ClassRoom ID2.

• s ID
o "stop": command Student ID to stop doing whatever it is doing

• v ID vaccine_amount
o “buy vaccines”: command Student ID to buy vaccine_amount of vaccine at a
DoctorsOffice.

• a ID assignment_amount
o “complete assignment_amount assignments at a ClassRoom”: command
Student ID to complete assignment_amount of training units at a ClassRoom.

• g
o "go": advance one-time step by updating each object once.

• r
o "run": advance one-time step and update each object, and repeat until either the
update function returns true for at least one of the objects, or 5 time steps have
been done.

• q
o "quit": terminate the program
