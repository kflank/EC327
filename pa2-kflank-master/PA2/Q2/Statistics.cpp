#include <iostream>
#include <cmath>
#include "Statistics.h"
#include "FileFunctions.cpp"
#include "FileFunctions.h"


double getMedian(int *ptrArray, int size)
{	
	double sum = 0;
	double median;
	size  = size/2;
	if (size % 2 == 1)
	{
		for (int i = 0; i < size*2; i++)
		{
			sum = *(ptrArray + i) + sum;
		}

		median = sum/2;
	}

if (size % 2 == 0)
{
		median = *(ptrArray + size);
} 
cout<<"the median is: "<<median<<endl;
return median;
}



int getLargest(int *ptrArray, int size)
{

int max = *(ptrArray);
	for (int i = 0; i < size ; i++)
	{
		
		if ( *(ptrArray + i) > max)
		{
			max = *(ptrArray + i);
			
		}

	
	}	

cout<<"max is: "<<max<< endl;
return max;
}




