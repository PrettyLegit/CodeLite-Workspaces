// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 5

#include "node1_New.h"
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace main_savitch_5;

// PROTOTYPES for functions used by this test program:
void print_menu();
// Postcondition: The menu has been written to cout.

char get_command();
// Postcondition: The user has been prompted for a character.
// The entered charatcer will be returned, translated to upper case.

bool validateInput(int userInput);
void print_list(node* temp, node* head);

int main()
{
    int userInput;
    char command;

    node* head;
    node* previous;
    node* newHead;
    node* newTail;
    node* temp;
    node* newTemp;
    node* splitHead;

    node grades;
    node newGrades;
	//grades is for sort
    node split;
	//split is for split

    head = &grades;
    temp = head;
    previous = head;
	
	newTemp = newHead;
    newHead = &newGrades;
	
    splitHead = &split;

    do {
	print_menu();
	command = toupper(get_command());

	switch(command) {
	case '1':
	    cout << "Enter in a double" << endl;
	    cin >> userInput;

	    if(validateInput(userInput)) {
		list_head_insert(head, userInput);
	    }

	    break;
	case '2':
	    cout << "Enter in a double" << endl;
	    cin >> userInput;
	    if(validateInput(userInput)) {
		list_insert(previous, userInput);
	    }
	    break;
	case '3':
	    cout << "Enter in target value" << endl;
	    cin >> userInput;

	    if(validateInput(userInput)) {
		temp = list_search(head, userInput);
	    }
	    if(temp == NULL) {
		cout << "Target value not found";
	    } else {
		cout << "Target value found:" << temp->data() << endl;
	    }
	    break;
	case '4':
	    cout << "Enter in target value" << endl;
	    cin >> userInput;

	    if(validateInput(userInput)) {
		temp = list_search(head, userInput);
	    }
	    if(temp == NULL) {
		cout << "Target value not found";
	    } else {
		cout << "Target value found:" << temp->data() << endl;
	    }
	    break;
	case '5':
	    cout << "Enter in the position in the list you want to retrieve (starting at 1)" << endl;
	    cin >> userInput;

	    if(validateInput(userInput)) {
		temp = list_locate(head, userInput);
	    }
	    if(temp == NULL) {
		cout << "Value at position is empty" << endl;
	    } else {
		cout << "Value at position " << userInput << " is: " << temp->data() << endl;
	    }
	    break;
	case '6':
	    cout << "Enter in the position in the list you want to retrieve (starting at 1)" << endl;
	    cin >> userInput;

	    if(validateInput(userInput)) {
		temp = list_locate(head, userInput);
	    }
	    if(temp == NULL) {
		cout << "Value at position is empty" << endl;
	    } else {
		cout << "Value at position " << userInput << " is: " << temp->data() << endl;
	    }
	    break;
	case '7':
	    if(head->link() != NULL) {
		cout << "Before head is removed: " << endl;
		print_list(temp, head);

		list_head_remove(head);

		cout << "After head is removed: " << endl;
		print_list(temp, head);
	    } else {
		cout << "Empty Node";
	    }
	    break;
	case '8':
	    if(previous->link() != NULL) {
		cout << "Before previous node is removed: " << endl;
		print_list(temp, head);

		list_remove(previous);

		cout << "After head is removed: " << endl;
		print_list(temp, head);
	    } else {
		cout << "No nodes after previous node";
	    }
	    break;
	case '9':
	    cout << "Clearing all values in nodes" << endl;
	    list_clear(*&head);

	    cout << "Values after clearing" << endl;
	    print_list(temp, head);
	    break;
	case 'W':

	    list_copy(head, *&newHead, *&newTail);
	    cout << "New copy has been made: " << endl;
	    print_list(newTemp, newHead);
	    break;
	case 'E':
	    print_list(temp, head);
	    break;
	case 'R':
	    list_copy(head, *&newHead, *&newTail);
	    print_list(newTemp, newHead);
	    cout << "Removing duplicates..." << endl;
	    delete_reps(newHead);
	    print_list(newTemp, newHead);
	    break;
	case 'T':
	    cout << "Sorting the list into a new list..." << endl;
	    sort_list(head);
	    print_list(temp, head);
	    break;
	case 'Y':
	    cout << "Before split" << endl;
	    print_list(temp, head);
	    cout << "Enter a value in the list to split it" << endl;
	    cin >> userInput;

	    if(validateInput(userInput)) {
		temp = list_search(head, userInput);
		cout << "Line 184" << endl;
	    }
	    if(temp == NULL) {
		cout << "Target value not found";
	    }

	    split_list(head, splitHead, userInput);
	    cout << "After split" << endl;

	    cout << "List 1: ";
	    print_list(temp, head);
		
		newTemp = splitHead;
		newHead = splitHead;
	    cout << "List 2: ";
	    print_list(newTemp, newHead);
		break;
	    // system("PAUSE");
	}
    }while(command != 'Q');
	
return EXIT_SUCCESS;
}

void print_menu()
{
    cout << "\n"
         << "----------------- The Commands -----------------" << endl;
    cout << "1 - insert data at the head" << endl;
    cout << "2 - insert data after the previous pointer" << endl;
    cout << "3 - list search" << endl;
    cout << "4 - list search const" << endl;
    cout << "5 - list locate" << endl;
    cout << "6 - list locate const" << endl;
    cout << "7 - remove head node" << endl;
    cout << "8 - remove a node after the previous pointer" << endl;
    cout << "9 - clear all nodes" << endl;
    cout << "W - make a copy of the nodes" << endl;
    cout << "E - print list" << endl;
    cout << "R - delete repitions" << endl;
    cout << "T - sort the list" << endl;
    cout << "Y - split the list at a value" << endl;
    cout << "  -   -   -   -   -   -   -   -   -   -   -   -" << endl;
    cout << "Q - quit this interactive test program" << endl;
    cout << "-------------------------------------------------" << endl;
}

char get_command()
{
    char command;

    cout << ">";
    cin >> command;

    return (toupper(command));
}

bool validateInput(int userInput)
{
    if(cin.fail()) {
	cin.clear();
	return false;
    }
    return true;
}

void print_list(node* temp, node* head)
{
    cout << "List Values: ";
    for(temp = head; temp != NULL; temp = temp->link()) {
	cout << " " << temp->data() << " ";
    }
    cout << "\nList Length: " << (list_length(head)) << endl;
}

bool is_in_list(node* head, int userInput)
{

    return true;
}