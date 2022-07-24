#include <iostream>
#include <string>

using namespace std;



int main(){
	int j;
string input; 
cout <<"enter a number string with values 0 through 9"<<endl;
cin >> input;

bool pal = true;
int n = input.length();
for (int i = 0; i< n; i++){
	if (input[i] != input[n-i-1]){
	pal = false;
	break;
	}
} 	//end of for loop

if (pal)
cout<<"The number  " <<input <<  "  is a palindrome"<<endl;
else {
	cout<<"The number  " <<input <<  "  is not a palindrome"<<endl;
     }
 
return 0;
}
