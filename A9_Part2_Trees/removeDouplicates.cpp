// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 9

#include "bst.h"
#include <algorithm>
#include <cstdlib>
#include <iomanip>  // setw
#include <iostream> // Provides cout, cin, peek
#include <string>

using namespace std;

// prototypes
void print_menu();
char get_command();
void insert_children_nodes(binary_search_tree<string>& myTree, string* word_array, int length);
void print_node(string data);

int main()
{

    char command;
    //string user_input = "this is a test for the test in the program that does no test";
    string user_input = "";
    string* word_array = new string[1];
    // 1 because it is arrays are zero indexed
    int size = 1;

    do {
		
	print_menu();
	cin.clear();
	cin.sync();
	command = get_command();
	if(command == '1') {
		
		cin.clear();
		cin.sync();
	    cout << "Enter a sentence" << endl;
		
	    getline(cin, user_input);

	    cout << "\nOriginal text:" << endl;
	    cout << user_input << endl;
		
	    for(int i = 0; i < user_input.length(); i++) {
		if(user_input[i] == ' ') {
		    size++;
		}
	    }

	    word_array = new string[size];

	    int current_position = 0;

	    for(int i = 0; i < size; i++) {

		while(user_input[current_position] != ' ' && user_input[current_position] != '\0') {

		    word_array[i] += user_input[current_position];
		    current_position++;
		}

		if(user_input[current_position] == ' ') {
		    current_position++;
		}
	    }
	    sort(word_array, word_array + size);

	    // creating the binary search tree to insert
	    binary_search_tree<string> myTree;

	    insert_children_nodes(myTree, word_array, size);

	    // cout << myTree << endl;

	    // let's see the tree shape
	    // print(myTree.get_root(), 0);

	    // let's check if tree is balanced or not
	    // cout << endl << "balanced? " << myTree.is_balanced() << endl;

	    cout << "\nProcessed data:" << endl;
	    inorder(print_node, myTree.get_root());
	    cout << "\n\n";
	}

    } while(command != '2');

    return EXIT_SUCCESS;
}

void insert_children_nodes(binary_search_tree<string>& myTree, string* word_array, int length)
{
    if(length == 1) {
	myTree.insert(word_array[0]);
    } else {

	if((length / 2) != 0) {
	    int mid = length / 2;

	    myTree.insert(word_array[mid]);
	    int left_length = 0;
	    int right_length = 0;
	    string* left_child_ptr = new string[mid];
	    string* right_child_ptr = new string[mid];

	    for(int i = 0; i < mid; i++) {
		left_child_ptr[i] = word_array[i];
		left_length++;
	    }

	    for(int k = mid + 1; k < length; k++) {
		int index = k - (mid + 1);
		right_child_ptr[index] = word_array[k];
		right_length++;
	    }

	    insert_children_nodes(myTree, left_child_ptr, left_length);
	    insert_children_nodes(myTree, right_child_ptr, right_length);
	}
    }
}

void print_node(string data)
{
    cout << data << " ";
}

void print_menu()
{
    cout << "\n-----Press a number for the following menu option-----\n" << endl;
    cout << "1. Enter a string and process the data" << endl;
    cout << "2. Quit program" << endl;
}

char get_command()
{
    char command;

    cout << ">";
    cin >> command;

    return (toupper(command));
}