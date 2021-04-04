// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 9

#include "bst.h"
#include <cmath>
#include <cstdlib>
#include <iomanip>  // setw
#include <iostream> // Provides cout, cin, peek
#include <string>

using namespace std;

//prototypes
void insert_children_nodes(binary_search_tree<string>& myTree, string word_array[], int length);

int main()
{
    binary_search_tree<string> myTree;

    string word_array[] = { "after", "also", "any", "back", "because", "come", "day", "even", "first", "give", "how",
	"its", "look", "most", "new", "now", "only", "other", "our", "over", "than", "then", "these", "think", "two",
	"us", "use", "want", "way", "well", "work" };

    // int length = sizeof(word_array) / sizeof(word_array[0]);
    int length = 31;

    insert_children_nodes(myTree, word_array, length);

    cout << myTree << endl;

    // let's see the tree shape
    print(myTree.get_root(), 0);

    // let's check if tree is balanced or not
    cout << endl << "balanced? " << myTree.is_balanced() << endl;

    return EXIT_SUCCESS;
}

void insert_children_nodes(binary_search_tree<string>& myTree, string word_array[], int length)
{

    if(length == 1) {
	myTree.insert(word_array[0]);
    } else {

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
