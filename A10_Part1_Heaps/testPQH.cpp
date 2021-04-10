// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 10

#include "PQ_Heap.h"
#include "heap.h"
#include <ctime>
#include <ctype.h>
#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <limits>

using namespace std;

// prototypes
void print_menu();
char get_command();
/*NOTE: this is an unused function. i was trying to create a way to verify the int input 
was an integar data type without using a string and doing an is digit at each index at the string*/
//bool is_integer(int number_input);

int main()
{

    priority_queue_heap<int> number_heap;
    priority_queue_heap<string> string_heap;
    /*When flag is true, the user will be allowed to use commands 1-7*/
    bool flag = false;
    char command;
    string queue_type = "";
    bool is_int_type = false;
    int number_input = -1;
    string string_input = "";

    do {
	print_menu();

	command = get_command();

	if(command == '0') {
	    flag = true;

	    cin.clear();
	    cin.sync();
	    cout << "Type 'int' or 'string'" << endl;
	    getline(cin, queue_type);

	    if(queue_type == "int") {
		cout << "You selected to work on the int priority queue." << endl;
		is_int_type = true;
	    }

	    if(queue_type == "string") {
		cout << "You selected to work on the string priority queue." << endl;
		is_int_type = false;
	    }

	    if((queue_type != "int") && (queue_type != "string")) {
			cout << "\n\n---You did not type 'int' or 'string'---\n\n";
			flag = false;
	    }
	} else if(!flag){
	    cout << "\n\n---You must select option 0 before you can use the other options.---\n\n";
	}

	/*user pressed 0 and typed correct data type*/
	if(flag) {
	    if(is_int_type) {
		switch(command) {
		case '1':
			
			while ((cout << "Enter in whole numbers:" << endl) && !(cin >> number_input)){
				cin >> number_input;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Error: Please enter a whole number greater than 0: " << endl;
				cout << number_input << " is not a valid integer data type." << endl;
				cout << "No data was added to the priority queue." << endl;
			}
			number_heap.enqueue(number_input);
			cout << number_input << " has been added to the priority queue." << endl;
			
		    break;

		case '2':
		    cout << "Dequeueing the highet value in the priority queue." << endl;
			number_heap.dequeue();
		    break;

		case '3':
		    cout << "Calling is_Full function." << endl;
			if(number_heap.is_full()){
				cout << "The priority queue is full." << endl;
			}
			else
			{
				cout << "The priority queue is not full." << endl;
			}
		    break;

		case '4':
		    cout << "Calling is_Empty function." << endl;
			if(number_heap.is_empty()){
				cout << "The priority queue is empty." << endl;
			}
			else
			{
				cout << "The priority queue is not empty." << endl;
			}
		    break;

		case '5':
		    cout << "Printing size of the priority queue." << endl;
			
			cout << "Size is: " << number_heap.size() << endl;
			
		    break;

		case '6':
		    cout << "Displaying the Front Element." << endl;
			cout << "Front element is: " << number_heap.front() << endl;
		    break;

		case '7':
		    cout << "Printing Queue Elements." << endl;
			number_heap.print_elements();
		    break;
		}
	    }

	    if(!is_int_type) {
		switch(command) {
		case '1':
		    cout << "Enter in a string." << endl;
		    cin.clear();
		    cin.sync();
		    getline(cin, string_input);
		    string_heap.enqueue(string_input);
		    break;

		case '2':
		    cout << "Dequeueing the highet value in the priority queue." << endl;
			string_heap.dequeue();
		    break;

		case '3':
		    cout << "Calling is_Full function." << endl;
			if(string_heap.is_full()){
				cout << "The priority queue is full." << endl;
			}
			else
			{
				cout << "The priority queue is not full." << endl;
			}
		    break;

		case '4':
		    cout << "Calling is_Empty function." << endl;
			if(string_heap.is_empty()){
				cout << "The priority queue is empty." << endl;
			}
			else
			{
				cout << "The priority queue is not empty." << endl;
			}
		    break;

		case '5':
		    cout << "Printing size of the priority queue." << endl;
			
			cout << "Size is: " << string_heap.size() << endl;
			
		    break;

		case '6':
		    cout << "Displaying the Front Element." << endl;
			cout << "Front element is: " << string_heap.front() << endl;
		    break;

		case '7':
		    cout << "Printing Queue Elements." << endl;
			string_heap.print_elements();
		    break;
		}
	    }
	}
    } while(command != '8');

    return EXIT_SUCCESS;
}

void print_menu()
{
    cout << "\n-----Press a number for the following menu option-----\n" << endl;
    cout << "0. Enter Queue Type (int or string)" << endl;
    cout << "1. Enqueue Element" << endl;
    cout << "2. Dequeue Element" << endl;
    cout << "3. Check is_Full" << endl;
    cout << "4. Check is_Empty" << endl;
    cout << "5. Print Size" << endl;
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



//bool is_integer(int number_input)
//{
//  return floor(number_input) == number_input;
//}