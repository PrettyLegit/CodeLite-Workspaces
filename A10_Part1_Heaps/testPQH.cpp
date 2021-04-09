// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 10

#include "heap.h"
#include "PQ_Heap.h"
#include <ctime>
#include <ctype.h>
#include <iostream>
#include <string>

using namespace std;

// prototypes
void print_menu();
char get_command();

int main()
{

	priority_queue_heap<int> number_heap;
	priority_queue_heap<string> string_heap;
    /*When flag is true, the user will be allowed to use commands 1-7*/
    bool flag = false;
    char command;
    string queue_type = "";
    bool is_int_type = false;
    int number_input = 0;
    string string_input = "";

    do {
		print_menu();
		
		command = get_command();

		if(command == '0') {
			flag = true;
			
			cin.clear();
			cin.sync();
			cout << "Type 'int' or 'string'" << endl;
			cin >> queue_type;
			

			if(queue_type == "int") {
				is_int_type = true;
			}

			if(queue_type == "string") {
				is_int_type = false;
			}

			if(queue_type != "int" || queue_type != "string") {
			cout << "\n\n---You did not type 'int' or 'string'---\n\n";
			flag = false;
			}
		} else 
		{
			cout << "\n\n---You must select option 0 before you can use the other options.---\n\n";
		}

		if(flag) {
			if(is_int_type) {
			switch(command) {
				case '1':
					cout << "Enter in whole numbers" << endl;
					cin.clear();
					cin.sync();
					cin >> number_input;
					if(isdigit(number_input)){
						number_heap.enqueue(number_input);
					}
					else
					{
						cout << number_input << " is not a valid integer data type." << endl;
						cout << "No data was added to the priority queue" << endl;
					}
					
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

			if(!is_int_type) {
			switch(command) {
			case '1':
				cout << "Enter in a string" << endl;
				cin.clear();
				cin.sync();
				getline(cin, string_input);
				string_heap.enqueue(string_input);
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
    cout << "1. Enter a string and process the data" << endl;
    cout << "4. Check is_Empty" << endl;
    cout << "1. Enter a string and process the data" << endl;
    cout << "5. Print Size" << endl;
    cout << "1. Enter a string and process the data" << endl;
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