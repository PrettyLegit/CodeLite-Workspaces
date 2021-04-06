// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 10

#include "heap.h"
#include <iostream>
#include <ctime>
#include <ctype.h>
#include <string>

using namespace std;

// prototypes
void print_menu();
char get_command();


int main() {
	
	/*When flag is true, the user will be allowed to use commands 1-7*/
	bool flag = false;
	char command;
	
	do
	{
		print_menu;
		get_command;
		
		if(command == 0){
			flag = true;
			
		}
		else
		{
			cout << "You must enter a Queue Type before you can use 
		}
		
		if(flag)
		{
			 switch(command)
			 {
				 case '1':
				 break;
				 
				 case '2':
				 break;
				 
				 case '3':
				 break;
				 
				 case '4':
				 break;
				 
				 case '5':
				 break;
				 
				 case '6':
				 break;
				 
				 case '7':
				 break;
			 }
		}
		
	}while(command != '8');
	print_menu;
	
	
    return EXIT_SUCCESS;
}

void print_menu()
{
    cout << "\n-----Press a number for the following menu option-----\n" << endl;
    cout << "0. Enter Queue Type (int or string)" << endl;
    cout << "1. Enqueue Element" << endl;
	cout << "2. Dequeue Element" << endl;
    cout << "3. Check is_Full" << endl;cout << "1. Enter a string and process the data" << endl;
    cout << "4. Check is_Empty" << endl;cout << "1. Enter a string and process the data" << endl;
    cout << "5. Print Size" << endl;cout << "1. Enter a string and process the data" << endl;
    cout << "6. Display Front Element" << endl;
	cout << "7. Print Queue Element" << endl;
    cout << "8. Quit program" << endl;
}

char get_command()
{

    char command;

    cout << ">";
    cin >> command;

    return (toupper(command));
}