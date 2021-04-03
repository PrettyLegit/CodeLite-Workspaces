// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 9

#include "bst.h"
#include <cstdlib>
#include <iomanip>  // setw
#include <iostream> // Provides cout, cin, peek
#include <string>
#include <cmath>

using namespace std;

int insert_children_nodes(int length, int middle, int current, binary_search_tree<string>string_tree, string word_array[], int first_half);


int main()
{
	binary_search_tree<string> string_tree;
	
    string word_array[] = { "After", "Also", "any", "back", "because", "come", "day", "even", "first", "give", "how",
	"its", "look", "most", "new", "now", "only", "other", "our", "over", "than", "then", "these", "think", "two",
	"us", "use", "want", "way", "well", "work" };

	int length = sizeof(word_array)/sizeof(word_array[0]);
	int middle = round(length/2);
	int current;
	//if this is true then we it returns 1, then we can resuse the recursive function to find the right side of the root.
	int first_half = 0;

	current = 0;
	first_half = insert_children_nodes(length, middle, current, string_tree, word_array, first_half);
	
	//if first_half is 1, then we will insert to the right of the root
	if(first_half == 1){
		current = middle;
		insert_children_nodes(length, middle, current, string_tree, word_array, first_half);
	}
	
		//let's see the tree shape
	print(string_tree.get_root(), 0);
	
  	//let's check if tree is balanced or not
    cout << endl << "balanced? " << string_tree.is_balanced() << endl;
	
    return EXIT_SUCCESS;
}

int insert_children_nodes(int length, int middle, int current, binary_search_tree<string>string_tree, string word_array[], int first_half){
	
	//inserting left of root
	if(first_half == 0){

		if(current < middle){
			string_tree.insert(word_array[current]);
			cout<< string_tree << endl;
			return insert_children_nodes(length, middle, ++current, string_tree, word_array, first_half);
		}else{
			return 1;
		}
		
	if(first_half == 1){

		if(current < length){
			string_tree.insert(word_array[current]);
			cout<< string_tree << endl;
			return insert_children_nodes(length, middle, ++current, string_tree, word_array, first_half);
		}
		
		return 0;
	}
		
		
		
		
	}
	return 0;
}

/*
 * make an array with all those words
 * needs to be recursive
 *
 *
 * */
