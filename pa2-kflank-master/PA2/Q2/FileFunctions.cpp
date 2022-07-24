#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <sstream>

#include <algorithm>
#include <vector>

using namespace std;



void WriteRandomData(int N, int M, const char *filename)
{
	ofstream myFile;
	myFile.open(filename);
	cout<<"writing file"<<endl; 
	srand (time(NULL));
	int rand_num;
	for (int i = 0; i<= N-1; i++)
{ 		
		rand_num = rand() % M;  //random number between 0 and M
		myFile<<rand_num<<endl; 
		
}
	
myFile.close();



}

void ReadData(const char *filename, int &size, int myArray[])
{
	ifstream infile(filename);
	int a;
	int i = 0;
	while (infile >> a){
		myArray[i] = a;
		i++;

	}
	int *ptr = &size;
	(*ptr) = i;
	cout<<"reading file"<<endl;
	infile.close();
	cout<<"Array size is: "<<i<<endl;


}




