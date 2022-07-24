#include <iostream>
#include <cmath>

using namespace std;


// Header files
double slope(double num1, double num2, double num3, double num4);
double intercept(double num1, double num2, double num3, double num4);



// function to find slope between 2 points 
double slope (double x1, double y1, double x2, double y2)
{
 double m;
 m = (y2-y1)/(x2-x1);

 return m;
}

//function to find intercept of two points

double intercept (double x1, double y1, double x2, double y2)
{
double m;
m = slope(x1,y1,x2,y2);

double b;
b = y1 - m*x1;
return b;
}







// main function 

int main(){
	double m,b1,top,bot;
double A,B,C;
double x1,x2,y1,y2,x3,y3,dist;
cout <<"enter x1"<<endl;    	//user inputs for points
cin >> x1; 
cout <<"enter y1"<<endl;
cin >> y1; 
cout <<"enter x2"<<endl;
cin >> x2;
cout <<"enter y2"<<endl;
cin >> y2;
cout <<"enter x3"<<endl;
cin >> x3;
cout <<"enter y3"<<endl;
cin >> y3;



m = slope(x1,y1,x2,y2);      //get the slope of inputed values
b1 = intercept(x1,y1,x2,y2); //get the y-intercept

A = m;      //Use the equation (|Ax +By +C|/(sqrt(A^2 + B^2)) to find distance 
B = -1;     
C = b1;

top = abs(A*x3 + B*y3 + C);    //numerator 
bot = sqrt(A*A +B*B);		   //denomenator 

dist = (top/bot); //calculate distacne 
cout<<"the shortest distacne for ("<<x3<<","<<y3<<") to the line composed of ("<<x1<<","<<y1<<") and ("<<x2<<","<<y2<<") is "<<dist<<endl;




return 0;
}