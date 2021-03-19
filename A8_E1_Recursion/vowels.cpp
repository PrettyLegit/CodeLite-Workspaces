// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 8

#include <stdio.h>
#include <iostream> // Provides cout, cin, peek
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <string> 
#include <iomanip>  // setw
#include <locale>   //get line, i think
using namespace std;

//Prototypes
void print_menu();
char get_command();
int calculate_vowels(string a, int count, int current_position);
bool isVowel(char a);
//int argc, char **argv
int main()
{
	char command;
	string user_input = " ";
	int results = 0;
	
	do
	{
	print_menu();
	command = get_command();
	
	if(command == '1'){
		cout << "Enter a string" << endl;
		cin.clear();
	    cin.sync();
	    getline(cin, user_input);
	}
	
	if(command == '2'){
		cout << "Computing the vowels" << endl;
		results = calculate_vowels(user_input, 0, 0);
		
		cout << "\n\n";
		cout << setw(1) << "You entered string: " << user_input << endl;
		cout << setw(1) << "Number of vowels:   " << results << endl; 
	}
	
	
	}while(command != '3');
	
	return EXIT_SUCCESS;
}

void print_menu(){
	cout << "-----Press a number for the following menu option-----\n" << endl;
    cout << "1. Read input string" << endl;
    cout << "2. Compute number of vowels" << endl;
    cout << "3. Quit program" << endl;
}

char get_command(){
	
	char command;

    cout << ">";
    cin >> command;

    return (toupper(command));
}

int calculate_vowels(string user_input, int count, int current_position){
	
	/* since the user_input will be at the end of the string
	 * this will check if the current position is the null terminator 
	 * */
	if(user_input[current_position] == '\0'){
		return count;
	}
	
	char temp = user_input[current_position];
	if(isVowel(toupper(temp))){
		++count;
	}
	return calculate_vowels(user_input, count, ++current_position);
}

bool isVowel(char temp){
	
	
	switch(temp){
		
		case 'A':
		return true;
		break;
		
		case 'E':
		return true;
		break;
		
		case 'I':
		return true;
		break;
		
		case 'O':
		return true;
		break;
		
		case 'U':
		return true;
		break;
		
	}
	return false;
}


