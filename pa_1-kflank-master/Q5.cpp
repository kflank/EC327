#include <iostream>
#include <string>
#include <cctype>
#include <stdio.h>

using namespace std;









int main(){



//converting symbol to ascii
int off = 5;
char new_ascii = 127;
char new_char;
while (off + (int) new_ascii > 127){ //Errror checking
 	cout <<"enter a single character (letter)"<<endl;
	cin >> new_ascii;
	cout <<"enter a non negative integer offset"<<endl;
	cin >> off;
//special case if offset = 0
	if (off == 0 && isalpha(new_ascii) ){
		if (isupper(new_ascii)){
			new_char = (char) ( new_ascii + 32);
			
			
		}
		else{
			new_char =  (char) ( new_ascii - 32);
		}
		
	
	}	

	else {
		new_char =  new_ascii + off;
		
	}
}


cout<<"new Character:"<<new_char<<endl; 



return 0;

}