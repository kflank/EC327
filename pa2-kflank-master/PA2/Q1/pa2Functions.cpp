
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

extern const int ENTRIES = 10;
extern const double PI = 3.14159;





//R or r
double findSqrtValue(double first, double last, double delta)
{
	


 if (first +delta*(ENTRIES-1) < last ) // make it trhough 10 interations 
	{
		for (int i = 0; i <= ENTRIES-1; i++)
		{
			double root = sqrt(first);
			cout <<"square root of "<<first<<" is: "<<root<<endl;
			first = first + delta;
		}
	}
	else if (first +delta*(ENTRIES-1) > last) //doesn't make it through 10 iterations, finish with last
	{
		while (first <= last)
		{
			double root = sqrt(first);
			cout <<"square root of "<<first<<" is: "<<root<<endl;
			first = first + delta;
			if (first > last)
			{
				root = sqrt(last);
				cout <<"square root of "<<last<<" is: "<<root<<endl;

			}


		 
		}
	}
	
return 0;
}






//U or u area of a square given length input
double areaSquare(double first, double last, double delta)
{
	

	
	 if (first +delta*(ENTRIES-1) < last ) // if 10 interations is less than last 
	{
		for (int i = 0; i <= ENTRIES-1; i++)
		{
			double area = first*first;
			cout <<"the area of a square given length:  "<<first<<" is: "<<area<<endl;
			first = first + delta;
		}
	}
	else if (first +delta*(ENTRIES-1) > last) //doesn't make it through 10 iterations, finish with last
	{
		while (first <= last)
		{
			double area = first*first;
			cout <<"the area of a square given length:  "<<first<<" is: "<<area<<endl;
			first = first + delta;
			if (first > last)
			{
				area = last*last;
				cout <<"the area of a square given length:  "<<last<<" is: "<<area<<endl;
			}
		 
		}
	}
	
return 0;
}






//C or c area of a circle given radius input 
double areaCircle(double first, double last, double delta)
{
	

	
	 if (first +delta*(ENTRIES-1) < last ) // if 10 interations is less than last 
	{
		for (int i = 0; i <= ENTRIES-1; i++)
		{
			double area = first*first*PI;
			cout <<"the area of a square given length:  "<<first<<" is: "<<area<<endl;
			first = first + delta;
		}
	}
	else if (first +delta*(ENTRIES-1) > last) //doesn't make it through 10 iterations, finish with last
	{
		while (first <= last) 
		{
			double area = first*first;
			cout <<"the area of a square given length:  "<<first<<" is: "<<area<<endl;
			first = first + delta;
			if (first > last)
			{
				area = last*last;
				cout <<"the area of a square given length:  "<<last<<" is: "<<area<<endl;
			}
		 
		}
	}
	
return 0;
}





//E or e get even numbers between first and last ignore delta
int findNextEvenValue(int first, int last)
{
	

	
	
	 if (first % 2 == 0) 
	{
		for (int i = first; i <= last; i = i+2)
		{
			cout <<"the even numbers are: "<<first<<endl;
			first = first +i;
		}
	}
	else if (first % 2 != 0 ) //doesn't make it through 10 iterations, finish with last
	{
		first = first +1; 
		for (int i = first; i <= last; i = i+2)
		{
		
			cout <<"the even numbers are: "<<first<<endl;
			first = first +i;
		}
	}
	
return 0;
}





//D or d get odd numbers between first and last ignore delta
int findNextOddValue(int first, int last)
{
	

	
	 if (first % 2 == 0) 
	{
		first = first +1;
		for (int i = first; i <= last; i = i+2)
		{
			cout <<"the odd numbers are: "<<first<<endl;
			first = first +i;
		}
	}
	else if (first % 2 != 0 ) //doesn't make it through 10 iterations, finish with last
	{ 
		for (int i = first; i <= last; i = i+2)
		{
			cout <<"the odd numbers are: "<<first<<endl;
			first = first +i;
		}
	}
	
return 0;
}




//S or s sin of the value given double input 
double doMath_sin(double first, double last, double delta) //need to do this for cos in the same function 
{
	

	
	 if (first +delta*(ENTRIES-1) < last ) // if 10 interations is less than last 
	{
		for (int i = 0; i <= ENTRIES-1; i++)
		{
			double sin_value = sin(first);
			cout <<"the sin value of:  "<<first<<" is: "<<sin_value<<endl;
			first = first + delta;
		}
	}
	else if (first +delta*(ENTRIES-1) > last) //doesn't make it through 10 iterations, finish with last
	{
		while (first <= last) 
		{
			double sin_value = sin(first);
			cout <<"the sin value of:  "<<first<<" is: "<<sin_value<<endl;
			first = first + delta;
			if (first > last)
			{
				sin_value = sin(last);
				cout <<"the sin value of:  "<<last<<" is: "<<sin_value<<endl;
			}
		 
		}
	}
	
return 0;
}




//N or n cos of the value given double input 
double doMath_cos(double first, double last, double delta) //need to do this for cos in the same function 
{
	

	 if (first +delta*(ENTRIES-1) < last ) // if 10 interations is less than last 
	{
		for (int i = 0; i <= ENTRIES-1; i++)
		{
			double cos_value = cos(first);
			cout <<"the cos value of:  "<<first<<" is: "<<cos_value<<endl;
			first = first + delta;
		}
	}
	else if (first +delta*(ENTRIES-1) > last) //doesn't make it through 10 iterations, finish with last
	{
		while (first <= last) 
		{
			double cos_value = cos(first);
			cout <<"the cos value of:  "<<first<<" is: "<<cos_value<<endl;
			first = first + delta;
			if (first > last)
			{
				cos_value = cos(last);
				cout <<"the cos value of:  "<<last<<" is: "<<cos_value<<endl;
			}
		 
		}
	}
	
return 0;
}




//F or f for factorial
int factorial(int num)
{
int i = 1;
int fact = 1;

	if (num < 0) 
	{
	cout <<"No computation needed"<<endl;    //error check inputs
	}
	while (i<=num)
	{
		fact = fact * i;
		i++;
	}
	cout<<"the factiorial of "<<num<<" is: "<<fact<<endl;
	return fact;
}




//B or b for fibonacci 
int fibonacci(int n)
{
	int n1,n2,n3;
	n1 = 0;
	n2 = 1;
	if ( n < 0 ) 
	{
		cout <<"No computation needed n was less than 0"<<endl;    //error check inputs
	}

	 
	if (n == 0)
		n3 = 0;
	else if (n==1)
		n3  = 1;
	else {
		for (int i = 2; i < n; ++i)
		{
			n3 = n1 + n2;
			n1 = n2;
			n2 = n3;
    	}
	}		
cout<<"the fibonacci number at index "<<n<< " is: "<<n3<<endl;	
return 0;
}






double exponential(double first, double last, double delta) 
{
	if (delta <= 0 || first > last) 
	{
		cout <<"No computation needed"<<endl;    //error check inputs
	}

	
	else if (first +delta*(ENTRIES-1) < last ) // if 10 interations is less than last 
	{
		for (int i = 0; i <= ENTRIES-1; i++)
		{
			double exp_value = exp(first);
			cout <<"the exponential value of:  "<<first<<" is: "<<exp_value<<endl;
			first = first + delta;
		}
	}
	else if (first +delta*(ENTRIES-1) > last) //doesn't make it through 10 iterations, finish with last
	{
		while (first <= last) 
		{
			double exp_value = exp(first);
			cout <<"the exponential value of:  "<<first<<" is: "<<exp_value<<endl;
			first = first + delta;
			if (first > last)
			{
				exp_value = cos(last);
				cout <<"the exponential value of:  "<<last<<" is: "<<exp_value<<endl;
			}
		 
		}
	}
	
return 0;
}






double naturalLog(double first, double last, double delta) 
{
	if (delta <= 0 || first > last) 
	{
		cout <<"No computation needed"<<endl;    //error check inputs
	}

	else if (first +delta*(ENTRIES-1) < last ) // if 10 interations is less than last 
	{
		for (int i = 0; i <= ENTRIES-1; i++)
		{
			double log_value = log(first);
			cout <<"the logarithim value of:  "<<first<<" is: "<<log_value<<endl;
			first = first + delta;
		}
	}
	else if (first +delta*9 > last) //doesn't make it through 10 iterations, finish with last
	{
		while (first <= last) 
		{
			double log_value = log(first);
			cout <<"the logarithim value of:  "<<first<<" is: "<<log_value<<endl;
			first = first + delta;
			if (first > last)
			{
				log_value = log(last);
				cout <<"the logarithim value of:  "<<last<<" is: "<<log_value<<endl;
			}
		 
		}
	}
	
return 0;
}






double findNyanCatValue(double first, double last, double delta) //need to do this for cos in the same function 
{
	if (delta <= 0 || first > last) 
	{
		cout <<"No computation needed"<<endl;    //error check inputs
	}
// stop when first to last has been calculated or more than entries has been done
	
	else if (first +delta*(ENTRIES-1) < last ) // if 10 interations is less than last 
	{
		for (int i = 0; i <= ENTRIES-1; i++)
		{
			double myNum = pow((4 * first), first) + first + 10;
			cout <<"the Nyan cat value of:  "<<first<<" is: "<<myNum<<endl;
			first = first + delta;
		}
	}
	else if (first +delta*(ENTRIES-1) > last) //doesn't make it through 10 iterations, finish with last
	{
		while (first <= last) 
		{
			double myNum = pow((4 * first), first) + first + 10;
			cout <<"the Nyan cat value of:  "<<first<<" is: "<<myNum<<endl;
			first = first + delta;
			if (first > last)
			{
				myNum = pow((4 * first), first) + first + 10;
				cout <<"the Nyan cat value of:  "<<last<<" is: "<<myNum<<endl;
			}
		 
		}
	}
	
return 0;
}







double lucky(int first, int last, int delta) //need to do this for cos in the same function 
{
	srand (time(NULL));
	if (delta <= 0 || first > last) 
	{
		cout <<"No computation needed"<<endl;    //error check inputs
	}

	else if (first +delta*(ENTRIES-1) < last ) // if 10 interations is less than last 
	{
		for (int i = 0; i <= ENTRIES-1; i++)
		{
			int lucky_num = rand() % first;
			cout <<"the lucky value of:  "<<first<<" is: "<<lucky_num<<endl;
			first = first + delta;
		}
	}
	else if (first +delta*9 > last) //doesn't make it through 10 iterations, finish with last
	{
		while (first <= last) 
		{
			int lucky_num = rand() % first;
			cout <<"the lucky value of:  "<<first<<" is: "<<lucky_num<<endl;
			first = first + delta;
			if (first > last)
			{
				lucky_num = rand() % last;
				cout <<"the lucky value of:  "<<last<<" is: "<<lucky_num<<endl;
			}
		 
		}
	}
	
return 0;
}







void initialize()
{
	cout<<"EC327: Introduction to Software Engineering"<<endl;
	cout<<"Fall 2021"<<endl;
	cout<<"Programming assignmnet 2"<<endl;
	cout<<"Value of entries is: "<<ENTRIES<<endl; 
}





bool checkCode(char command)
{
	if (command != 'f' && command !='F' && command != 'B' && command != 'b' &&  command != 'R' && command != 'r' && command != 'U' && command != 'u' && command != 'C' && command != 'c' && command != 'E' && command != 'e' && command != 'K' && command != 'k' && command != 'S' && command != 's' && command != 'N' && command != 'n' && command != 'X' && command != 'x' && command != 'L' && command != 'l' && command != 'Y' && command != 'y' && command != 'D' && command != 'd' && command != 'I' && command != 'i' && command != 'O' && command != 'o' && command != 'Q' && command != 'q')
	{
		cout <<"invalid command code "<<endl;
	}

	return 0;
}







void outputRedirect(const char *filename, bool mode) 
{ 
	if (mode){
    ofstream ofs(filename);
    auto cout_buff = cout.rdbuf(); 
    cout.rdbuf(ofs.rdbuf()); 
      
	}
}




void outputReset(const char *filename)
{
ofstream ofs(filename);
auto cout_buff = cout.rdbuf(); 
cout.rdbuf(ofs.rdbuf()); 
cout.rdbuf(cout_buff);
}










void readDataFromFile(const char *);


void writeDataToFile(const char *);





