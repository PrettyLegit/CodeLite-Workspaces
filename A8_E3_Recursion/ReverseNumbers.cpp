// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 8
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iomanip>  // setw
#include <iostream> // Provides cout, cin, peek
#include <locale>   //get line, i think
#include <stdio.h>
#include <string>

using namespace std;

// Prototypes
void print_menu();
char get_command();
void reverse(int* numbers, int* temp, int index, int ARRAY_SIZE);

int main(int argc, char** argv)
{
    int ARRAY_SIZE = 5;
    int* numbers = new int[ARRAY_SIZE];
	int* temp = new int[ARRAY_SIZE];

    char command;
    int input_number = -1;

    do {

	print_menu();
	command = get_command();

	if(command == '1') {
	    for(int i = 0; i < ARRAY_SIZE; i++) {

		while(input_number < 0) {
		    cout << "Enter in positive integers for array at position: " << i << endl;
		    cin >> input_number;
		    if(input_number >= 0) {
			numbers[i] = input_number;
		    } else {
			cout << "The number you entered was not a positive number" << endl;
		    }
		}
		/*NOTE: we have to reset input_number back to -1
		 * so the while loop can validate next input*/
		input_number = -1;
	    }
	}
	if(command == '2') {
	    cout << "Entered numebrs before reversal: ";
	    for(int i = 0; i < ARRAY_SIZE; i++) {
		cout << numbers[i] << "  ";
	    }

	    cout << endl;
	}
	if(command == '3') {

	    /*NOTE: We have to do ARRAY_SIZE-1 because the size is 5 but index is 4*/
	    reverse(numbers, temp, 0, ARRAY_SIZE);
	    cout << "Entered numbers after reversal: ";
	    for(int i = 0; i < ARRAY_SIZE; i++) {
		cout << numbers[i] << "  ";
	    }

	    cout << endl;
	}
    } while(command != '4');

    return 0;
}

void print_menu()
{
    cout << "-----Press a number for the following menu option-----\n" << endl;
    cout << "1. Read 5 positive integers" << endl;
    cout << "2. Print array before reversal" << endl;
    cout << "3. Print array after reversal" << endl;
    cout << "4. Quit program" << endl;
}

char get_command()
{

    char command;

    cout << ">";
    cin >> command;

    return (toupper(command));
}

void reverse(int* numbers, int* temp, int index, int ARRAY_SIZE)
{
	
    int digit_reverse = 0;
    int data = 0;
    int remainder = 0;

    if(index <= ARRAY_SIZE) {
		
	    data = numbers[index];

	    while(data != 0) {

		remainder = data % 10;

		digit_reverse = ((digit_reverse * 10) + remainder);

		data /= 10;
	    }

	    temp[index] = digit_reverse;
		
		return reverse(numbers, temp, ++index, ARRAY_SIZE);
}
	//Note: 5 < 5 terminate
   for(int i = 0; i < ARRAY_SIZE; i++){
	   numbers[i] = temp[i];
   }
}
