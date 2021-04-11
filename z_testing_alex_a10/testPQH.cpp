// Name: Alex Ingram
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 10

#include "PQ_Heap.h"
#include <iostream>
#include <ctime>
#include <ctype.h>
#include <string>

using namespace std;

void print_start();
// Postcondition: The start menu has been written to cout.

void print_menu();
// Postcondition: The menu has been written to cout.

char get_command();
// Postcondition: The user has been prompted for a character.
// The entered charatcer will be returned, translated to upper case.


int main() {
    char command;
    bool check;
    bool check0;
    priority_queue_heap<int> pq;
    priority_queue_heap<string> pqS;
    string input;
    do {
        print_menu();
        command = toupper(get_command());
        if (command != '0' && !check0) {
            cout << "Please do Option 0 before doing other commands" << endl;
        }
        else {
            switch (command) {
                case '0': {
                    string input;
                    cout << "Enter which type of queue you want to use: Int (1) or String (2)" << endl;
                    cin.ignore();
                    getline(cin, input);
                    if (input == "1") {
                        check = true;
                        check0 = true;
                    }
                    else {
                        check = false;
                        check0 = true;
                    }
                    break;
                }
                case '1':
                    cout << "Enter a value for the queue: " << endl;
                    cin.ignore();
                    getline(cin, input);
                    if (check == true) {
                        if (pq.is_full() == true) {
                            cout << "Priority Queue is full" << endl;
                        }
                        else {
                            pq.enqueue(stoi(input));
                        }
                    }
                    else {
                        if (pqS.is_full() == true) {
                            cout << "Priority Queue is full" << endl;
                        }
                        else {
                            pqS.enqueue(input);
                        }
                    }
                    break;
                case '2':
                    if (check == true) {
                        if (pq.is_empty() == true) {
                            cout << "Priority Queue is empty, nothing to remove" << endl;
                        }
                        else {
                            cout << "Removed top priority item: " << pq.dequeue() << endl;
                        }
                    }
                    else {
                        if (pqS.is_empty() == true) {
                            cout << "Priority Queue is empty, nothing to remove" << endl;
                        }
                        else {
                            cout << "Removed top priority item: " << pqS.dequeue() << endl;
                        }
                    }
                    break;
                case '3':
                    if (check == true) {
                        if (pq.is_full() == 1) {
                            cout << "Is queue full: True" << endl;
                        }
                        else {
                            cout << "Is queue full: False" << endl;
                        }
                    }
                    else {
                        if (pqS.is_full() == 1) {
                            cout << "Is queue full: True" << endl;
                        }
                        else {
                            cout << "Is queue full: False" << endl;
                        }
                    }
                    break;
                case '4':
                    if (check == true) {
                        if (pq.is_empty() == 1) {
                            cout << "Is queue empty: True" << endl;
                        }
                        else {
                            cout << "Is queue empty: False" << endl;
                        }
                    }
                    else {
                        if (pqS.is_empty() == 1) {
                            cout << "Is queue empty: True" << endl;
                        }
                        else {
                            cout << "Is queue empty: False" << endl;
                        }
                    }
                    break;
                case '5':
                    if (check == true) {
                        cout << "Size of queue: " << pq.h.getSize() << endl;
                    }
                    else {
                        cout << "Size of queue: " << pqS.h.getSize() << endl;
                    }
                    break;
                case '6':
                    if (check == true) {
                        cout << "Front element is: " << pq.front() << endl;
                    }
                    else {
                        cout << "Front element is: " << pqS.front() << endl;
                    }
                    break;
                case '7':
                    if (check == true) {
                        pq.h.check_heap();
                    }
                    else {
                        pqS.h.check_heap();
                    }
                    break;
                case '8':
                    break;
                default:
                    cout << "Invalid command." << endl;
                    break;
            }
        }
    }while (command != '8');

}

void print_menu()
{
    cout << "----------------- The Commands -----------------" << endl;
    cout << "0. Choose what type of queue you want to use" << endl;
    cout << "1. Enqueue Element" << endl;
    cout << "2. Dequeue Element" << endl;
    cout << "3. Check is_Full" << endl;
    cout << "4. Check is_Empty" << endl;
    cout << "5. Print Size" << endl;
    cout << "6. Display Front Element" << endl;
    cout << "7. Print Queue Elements" << endl;
    cout << "8. Quit program" << endl;
    cout << "-------------------------------------------------" << endl;
}

char get_command()
{
    char command;

    cout << ">";
    cin >> command;

    return (toupper(command));
}

