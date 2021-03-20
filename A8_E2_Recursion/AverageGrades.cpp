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
double findAverage(int* class_size_ptr, int input_size, int index, double average);

int main(int argc, char** argv)
{
    int* class_size_ptr = new int[1];

    int input_size = -1;
    int input_grades = -1;
    char command;
    double average = 0.00;

    do {

	print_menu();
	command = get_command();
	if(command == '1') {

		//we have to reset value here
		input_size = -1;
		class_size_ptr = new int[1];
		
	    while(input_size < 0) {
		cout << "Enter in an integer for the class size" << endl;
		cin.clear();
		cin >> input_size;
		if(input_size > 0) {
		    class_size_ptr = new int[input_size];
		} else {
		    cout << "\n\n---Enter integer greater than 0---\n\n" << endl;
		    
		}
	    }
	}
	if(command == '2') {

	    for(int i = 0; i < input_size; i++) {

		while(input_grades < 0) {
		    cout << "Enter in data for position: " << i << endl;
		    cin >> input_grades;
		    if(input_grades <= 100 && input_grades >= 0) {
			class_size_ptr[i] = input_grades;
		    } else {
			cout << "Check your inputs, and try again" << endl;
		    }
		}
		/*NOTE: we have to reset input_number back to -1
		 * so the while loop can validate next input*/
		input_grades = -1;
	    }
	}
	if(command == '3') {
		average = 0;
	    average = findAverage(class_size_ptr, input_size, 0, average);

	    cout << "You entered class size: " << input_size << endl;
	    cout << "You entered grades:     ";
	    for(int i = 0; i < input_size; i++) {
		cout << class_size_ptr[i] << " ";
	    }
	    cout << endl;
	    printf("class average:          %.2f\n", average);
	}
    } while(command != '4');

    return 0;
}

void print_menu()
{
    cout << "-----Press a number for the following menu option-----\n" << endl;
    cout << "1. Read class size" << endl;
    cout << "2. Read class grades" << endl;
    cout << "3. Compute class average" << endl;
    cout << "4. Quit program" << endl;
}

char get_command()
{

    char command;

    cout << ">";
    cin >> command;

    return (toupper(command));
}

double findAverage(int* ptr, int input_size, int index, double average)
{

    /*NOTE: input_size is 3... 0, 1, 2. So index at 3 will mean
        that we can stop adding values on line 90*/
    if(index == input_size) {
	average = average / ((double)input_size);
	return average;
    }

    average += (double)ptr[index];

    return findAverage(ptr, input_size, ++index, average);
}
