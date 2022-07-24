#include "pa2Functions.cpp"
#include "pa2Functions.h"

//using namespace std;




int main()
{

bool mode = false;
initialize();

double first,last,delta,func_output;
char command;

	while (command != 'q' && command != 'Q')
	{
		
		cout<<"please enter your command code: "<<endl;
		cin >> command;
		checkCode(command);
		
		if (command == 'i' || command == 'I')
			mode = true;


		if (command == 'f' || command == 'F' || command == 'B' || command == 'b')
		{
				
				cout<<"enter first value"<<endl;
				cin >> first;
		}

		else if (command =='K' || command == 'k' || command == 'R' || command == 'r' || command == 'U' || command == 'u' || command == 'C' || command == 'c' || command == 'S' || command == 's' || command == 'N' || command == 'n' || command == 'X' || command == 'x' || command == 'L' || command == 'l' || command == 'Y' || command == 'y')
		{
			cout<<"please enter command parameters"<<endl;
			cout<<"enter first value"<<endl;
			cin >>first;
			cout<<"enter last value"<<endl;
			cin >> last;
			cout<<"enter delta value"<<endl;
			cin >> delta;
			if (delta <= 0 || first > last) 
			{
				cout <<"No computation needed"<<endl;    //error check inputs
			}
		}

		else if (command == 'E' || command == 'e' || command == 'D' || command == 'd' )
		{
			cout<<"please enter command parameters"<<endl;
			cout<<"enter first value"<<endl;
			cin >>first;
			cout<<"enter last value"<<endl;
			cin >> last;
			if (first > last) 
			{
				cout <<"No computation needed"<<endl;    //error check inputs
			}
		
		}

		


		if (command == 'R' || command == 'r')
		{
		outputRedirect("PA2Q1_writefile.txt", mode);
		findSqrtValue(first,last,delta);
		outputReset("PA2Q1_writefile.txt");
		}

		else if(command == 'B' || command == 'b')
		{
		outputRedirect("PA2Q1_writefile.txt", mode);
		fibonacci(first); 
		outputReset("PA2Q1_writefile.txt");
		}

		else if (command == 'F' || command == 'f')
		{
			outputRedirect("PA2Q1_writefile.txt", mode);
			factorial(first);
			outputReset("PA2Q1_writefile.txt");
		}

		else if (command == 'U' || command == 'u')
		{
			outputRedirect("PA2Q1_writefile.txt", mode);
			areaSquare(first, last, delta);
			outputReset("PA2Q1_writefile.txt");
		}

		else if (command == 'C' || command == 'c')
		{

		outputRedirect("PA2Q1_writefile.txt", mode);
		areaCircle(first, last, delta);
		outputReset("PA2Q1_writefile.txt");
		}

		else if (command == 'E' || command == 'e')
		{
			outputRedirect("PA2Q1_writefile.txt", mode);
			findNextEvenValue(first , last);
			outputReset("PA2Q1_writefile.txt");
		}

		else if (command == 'K' || command == 'k')
		{
			outputRedirect("PA2Q1_writefile.txt", mode);
			lucky(first, last, delta);
			outputReset("PA2Q1_writefile.txt");
		}

		else if (command == 'S' || command == 's')
		{
			outputRedirect("PA2Q1_writefile.txt", mode);
			 doMath_sin(first, last, delta);
			 outputReset("PA2Q1_writefile.txt");
		}

		else if (command == 'N' || command == 'n')
		{
			outputRedirect("PA2Q1_writefile.txt", mode);
			 doMath_cos(first, last, delta);
			 outputReset("PA2Q1_writefile.txt");
		}

		else if (command == 'X' || command == 'x')
		{
		outputRedirect("PA2Q1_writefile.txt", mode);
		 exponential(first, last, delta);
		 outputReset("PA2Q1_writefile.txt");
		}

		else if (command == 'L' || command == 'l')
		{
		outputRedirect("PA2Q1_writefile.txt", mode);
		 naturalLog(first, last, delta);
		 outputReset("PA2Q1_writefile.txt");
		}

		else if (command == 'Y' || command == 'y')
		{
			outputRedirect("PA2Q1_writefile.txt", mode);
		 findNyanCatValue(first, last, delta);
		 outputReset("PA2Q1_writefile.txt");
		}

		else if (command == 'D' || command == 'd')
		{
			outputRedirect("PA2Q1_writefile.txt", mode);
			 findNextOddValue(first, last);
			 outputReset("PA2Q1_writefile.txt");
		}




		 if (command == 'O' || command == 'o')
		{

			//need to make 

		}



	}//end of while statement 
 //end of else 

return 0;
}














