#include <iostream>
#include <bitset>


using namespace std;




void printRohmbus(int n);



int main()
{
cout<<"enter a value between 1 and 9"<<endl;
int n;
cin >> n;
if (n <1 || n>9){
	cout<<"your number is out of range"<<endl;
}
		
		for (int i =1; i<=n; i++){

			//cout<<"i is: "<<i<<endl;
			printRohmbus(i);
		
		}
	return 0;
}



void printRohmbus(int n)
{
	if (n == 1)
		cout<<"   "<<n<<"   ";

	else {
		printRohmbus(n-1);
		cout<<"   "<<n<<"   "<<endl;
	}
for (int i = n-1; i < 1; i--)
{
	//cout<<i;
	if (i==1)
	{
		//cout<<endl;
	}

}

}

	

		//we print n as long as we have already printed n-1
	







