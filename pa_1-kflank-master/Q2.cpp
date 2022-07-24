#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
	int min,max,num;
	min = 0;          //establish min and max for the random function
	max = 2;
	srand(time(NULL));  //reset the psudo random 
	num  = rand()  % 3; //random number between 0 and 2
	int selection;


//Create conditional statements for all 9 possible outcomes

	cout <<"Choose Rock(0), Paper(1), or Scissors(2):"<<endl;
	cin >> selection;

	if (selection == 0 & num == 0){               //tie for Rock
		cout <<"computer chooses: Rock"<<endl;
		cout<<"you tie"<<endl;
	}
	else if (selection == 1 & num == 1){    	//tie for Paper         
		cout <<"computer chooses: Paper"<<endl;
		cout<<"you tie"<<endl;
	}
	else if (selection == 2 & num == 2){		//tie for Scissors
		cout <<"computer chooses: Scissors"<<endl;
		cout<<"you tie"<<endl;
	}
	else if (selection == 1 & num == 0){		//Choose paper, computer chooses Rock
		cout <<"computer chooses Rock"<<endl;
		cout <<"You Win!"<<endl;
	}
	else if (selection == 0 & num == 2){		//Choose Rock, computer chooses Scissors
		cout <<"computer chooses Scissors"<<endl;
		cout <<"You Win!"<<endl;
	}
	else if (selection == 2 & num == 1){		//Choose Scissors, computer chooses Paper
		cout <<"computer chooses Paper"<<endl;
		cout <<"You Win!"<<endl;
	}
	else if (selection == 0 & num==1){			//Choose Rock, computer chooses Paper
		cout<< "computer chooses Paper"<<endl;
		cout<<"You lose!"<<endl;	
	}
	else if (selection == 1 & num==2){			//Choose Paper, computer chooses Scissors
		cout<< "computer chooses Scissors"<<endl;
		cout<<"You lose!"<<endl;	
	}
	else if (selection == 2 & num== 0){			//Choose Scissors, computer chooses Rock
		cout<< "computer chooses Paper"<<endl;
		cout<<"You lose!"<<endl;	
	}
else 
return 0;
}