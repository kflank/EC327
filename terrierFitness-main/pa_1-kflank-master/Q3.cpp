#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;


//header file for function
string DecToHex(int);

//function to convet decimal to hexadecimal vlaue 
 string DecToHex(int dec_val){
	char hex_val[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; //initialize hex array
 	string hex_num = " ";
 	int r;
 	while (dec_val > 0){
 		r = dec_val % 16;
 		hex_num = hex_val[r] + hex_num;
 		dec_val = dec_val / 16;
 	} 
 return hex_num;
 }
 		


 		








int main(){
	int counter,diff;
	counter = 0;
	unsigned int num1,num2,n1,n2;
	string Hex1,Hex2;
	cout<< "enter a positive integers "<<endl;
	cin >> num1;
	cout<< "enter a positive integers "<<endl;
	cin >> num2;
	Hex1 = DecToHex(num1); //convert inputed numbers to Hex
	Hex2 = DecToHex(num2);
	n1 = Hex1.size() -1; //get the size of the hex strings (including -1 for null character)
	n2 = Hex2.size() -1;
	diff = abs(int(n1-n2));  //difference in lengths of hex 
	cout<<"hex 1 is "<<Hex1 <<endl;
	//cout << n1 <<endl;
	cout <<"hex 2 is "<< Hex2 <<endl;
	//cout << n2 <<endl;
	int loop_var;



if (n1>n2)
	loop_var = n2; 
else 
	loop_var = n1;
	cout<<"loop var is "<<loop_var<<endl;
for (int i = 0; i< loop_var; i++){
	cout<<"at index"<< i <<" "<<(Hex1[i] != Hex2[i])<<endl;

	if (Hex1[i] != Hex2[i]){
		counter++;  
		//cout <<counter<<endl;
	}
}





	

counter = counter + diff;
cout<< "diff is "<<diff<<endl;
cout <<"counter is "<<counter<<endl;
cout <<"The hamming distance between "<< num1 << " and  "<< num2 << " in Hex is "<< counter<<endl;

return 0;

}





