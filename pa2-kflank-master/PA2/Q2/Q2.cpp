#include "Statistics.cpp"



int main()
{


int arraySize;
int Array[1000];

ofstream myFile("data.txt");
myFile.close();

WriteRandomData(5, 10, "data.txt");



ReadData("data.txt", arraySize, Array);


ostringstream os;
int numArray[arraySize*2];
int * ptr = DoubleAndReverse(Array, arraySize);
for (int i=0; i<arraySize*2; i++){
	//create string buffer 
	numArray[i] = *(ptr + i);
	os <<" "<< *(ptr + i);
	//cout<<"double and reversed is [ "<<*(ptr + i)<<" ]";

}
string str(os.str());
cout <<"Doubled and reverese is ["<<str<<"]"<<endl;


int max;
double median;

 

median = getMedian(Array, arraySize);

max  = getLargest(Array, arraySize);



}

int * DoubleAndReverse (int *list, int size)
{
	
	 int *doubleArray = new int[2*size]; //points to array in the heap
	
	for (int i = 0; i < size; i++) 
	{
		doubleArray[i] = list[i]; //fill in the first half
		

	}     
	for (int i = size ; i < size*2; i++)
	{
		doubleArray[i] = list[2*size -1 -i]; //fill in the second half in reverse order
		
	}


		


return doubleArray; 


}
