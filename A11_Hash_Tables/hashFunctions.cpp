// Name: Jimmmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 11

#include <cassert>
#include <cmath>
#include <ctime>
#include <ctype.h>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// prototypes
void print_menu();
char get_command();
void HF1(int keys[50], int Table[50][2], size_t CAPACITY_X, size_t CAPACITY_Y);
void HF2(int keys[50], int Table[50][2], size_t CAPACITY_X, size_t CAPACITY_Y);
void HF3(int keys[50], int Table[50][2], size_t CAPACITY_X, size_t CAPACITY_Y);
void intialize_empty_table(int Table[50][2]);
void print_table(int Table[50][2], size_t const CAPACITY_X, size_t const CAPACITY_Y);
void sumProbes(int Table[50][2], size_t const CAPACITY_X);

int main()
{
    int keys[] = { 1234, 8234, 7867, 1009, 5438, 4312, 3420, 9487, 5418, 5299, 5078, 8239, 1208, 5098, 5195, 5329,
	4543, 3344, 7698, 5412, 5567, 5672, 7934, 1254, 6091, 8732, 3095, 1975, 3843, 5589, 5439, 8907, 4097, 3096,
	4310, 5298, 9156, 3895, 6673, 7871, 5787, 9289, 4553, 7822, 8755, 3398, 6774, 8289, 7665, 5523 };

    int Table[50][2];
    size_t const CAPACITY_X = 50;
    size_t const CAPACITY_Y = 2;
    char command;

    do {
	print_menu();
	command = get_command();

	if(command == '1') {
	    intialize_empty_table(Table);
	    HF1(keys, Table, CAPACITY_X, CAPACITY_Y);
	    print_table(Table, CAPACITY_X, CAPACITY_Y);
	    sumProbes(Table, CAPACITY_X);
	}

	if(command == '2') {
		intialize_empty_table(Table);
		HF2(keys, Table, CAPACITY_X, CAPACITY_Y);
		print_table(Table, CAPACITY_X, CAPACITY_Y);
	    sumProbes(Table, CAPACITY_X);
	}

	if(command == '3') {
		intialize_empty_table(Table);
		HF3(keys, Table, CAPACITY_X, CAPACITY_Y);
		print_table(Table, CAPACITY_X, CAPACITY_Y);
	    sumProbes(Table, CAPACITY_X);
	}
    } while(command != '0');
    return EXIT_SUCCESS;
}

void HF1(int keys[50], int Table[50][2], size_t CAPACITY_X, size_t CAPACITY_Y)
{
    size_t hash_value = 0;
    int key_value = 0;

    size_t current = 0;
    size_t probe_index = 0;
    size_t probe_counter = 0;
    bool isLooking = true;
	
	for(current = 0; current < CAPACITY_X; current++)
	{
		// getting the key value for the first index and then hashing it.
	key_value = keys[current];
	hash_value = key_value % 50;
	probe_counter = 0;
	/*NOTE: probe counter will start out as 0 for every time the we hash a new value. When we probe,
	then probe_counter will increment and be stored in Table[Hash_value][1]
	note that in the else statement where the probe happens, hash_value is replaced in Table[probe_index][1]*/

	// if the table at the hash value index is empty, then we can put the key value in that spot
	if(Table[hash_value][0] == -1) {
	    Table[hash_value][0] = key_value;
	    Table[hash_value][1] = probe_counter;
	} else {
	    // else the hash value is occupied, then we now start probing from the current position to the next position.
	    probe_index = hash_value;
	    isLooking = true;
		
	    while(isLooking) {
			
		// if he probe has reach the end of the Table, then start the probe_index at index 0
		if(probe_index+1 > CAPACITY_X) {
		    probe_index = 0;
		}
			
		if(Table[probe_index][0] == -1) {
		    Table[probe_index][0] = keys[current];
			Table[probe_index][1] = probe_counter;
		    isLooking = false;
		}else
		{
			probe_index++;
			probe_counter++;
		}
	    }
	}
	}
}

void HF2(int keys[50], int Table[50][2], size_t CAPACITY_X, size_t CAPACITY_Y){
	
	size_t hash_value = 0;
    int key_value = 0;

    size_t current = 0;
    size_t probe_index = 0;
    size_t probe_counter = 0;
    bool isLooking = true;
	
    for(current = 0; current < CAPACITY_X; current++)
	{
	// getting the key value for the first index and then hashing it.
	key_value = keys[current];
	hash_value = key_value % 50;
	probe_counter = 0;
	/*NOTE: probe counter will start out as 0 for every time the we hash a new value. When we probe,
	then probe_counter will increment and be stored in Table[Hash_value][1]
	note that in the else statement where the probe happens, hash_value is replaced in Table[probe_index][1]*/

	// if the table at the hash value is empty, then we can put the key value in that spot
	if(Table[hash_value][0] == -1) {
	    Table[hash_value][0] = key_value;
	    Table[hash_value][1] = probe_counter;
	} else {
	    // if the hash value is occupied, then we now start probing from the current position to the next position.
	    probe_index = hash_value;
	    isLooking = true;
		
	    while(isLooking) 
		{
			// if he probe has reach the end of the Table, then start the probe at index 0
			if(probe_index+1 > CAPACITY_X) {
				probe_index = probe_index % CAPACITY_X; 
			}
			if(Table[probe_index][0] == -1) {
				Table[probe_index][0] = keys[current];
				Table[probe_index][1] = probe_counter;
				isLooking = false;
			}else
			{
					probe_index = hash_value;
					probe_counter++;
					probe_index = probe_index + (probe_counter * probe_counter);
			}
			
	    }
	}
    }
}

void HF3(int keys[50], int Table[50][2], size_t CAPACITY_X, size_t CAPACITY_Y)
{
    size_t hash_value = 0;
    int key_value = 0;

    size_t current = 0;
    size_t probe_index = 0;
    size_t probe_counter = 0;
	size_t original_value; //original hash value before double hashing
    bool isLooking = true;
	
	for(current = 0; current < CAPACITY_X; current++)
	{
		// getting the key value for the first index and then hashing it.
	key_value = keys[current];
	hash_value = key_value % 50;
	original_value = hash_value;
	probe_counter = 0;
	/*NOTE: probe counter will start out as 0 for every time the we hash a new value. When we probe,
	then probe_counter will increment and be stored in Table[Hash_value][1]
	note that in the else statement where the probe happens, hash_value is replaced in Table[probe_index][1]*/

	// if the table at the hash value is empty, then we can put the key value in that spot
	if(Table[hash_value][0] == -1) {
	    Table[hash_value][0] = key_value;
	    Table[hash_value][1] = probe_counter;
	} else {
	    // else the hash value is occupied, then we now start probing from the current position to the next position.
	    probe_index = hash_value;
	    isLooking = true;
		
	    while(isLooking) {
			
		// if he probe has reach the end of the Table, then start the probe at index 0
		probe_index = probe_index % CAPACITY_X;
			
		if(Table[probe_index][0] == -1) {
		    Table[probe_index][0] = keys[current];
			Table[probe_index][1] = probe_counter;
		    isLooking = false;
		}else
		{
			if(!(probe_counter > 50)){
				probe_counter++;
				probe_index = 30 - (hash_value % 25);
				probe_index = original_value + (probe_counter*probe_index);
			}else{
				cout << "Unable to hash the key " << key_value << endl;
				break;
			}
			
		}
	    }
	}
	}

}

// fill in hash table with -1 to indicate unused
void intialize_empty_table(int Table[50][2])
{
    for(size_t row = 0; row < 50; row++) {

	Table[row][0] = -1;
	Table[row][1] = 0;
    }
}

void print_table(int Table[50][2], size_t const CAPACITY_X, size_t const CAPACITY_Y)
{
    cout << "\nIndex\t"
         << "Key\t"
         << "Probes\t" << endl;
    cout << "-------------------------------" << endl;
    for(size_t row = 0; row < CAPACITY_X; row++) {
	cout << row << "\t";
	for(size_t column = 0; column < CAPACITY_Y; column++) {
	    cout << Table[row][column] << "\t";
	}
	cout << endl;
    }
}

void sumProbes(int Table[50][2], size_t const CAPACITY_X)
{
    size_t sum = 0;

    for(size_t row = 0; row < CAPACITY_X; row++) {
	sum += Table[row][1];
    }

    cout << "\nSUM OF PROBES IS: " << sum;
	cout << endl;
}
void print_menu()
{
    cout << "\n-----Press a number for the following menu option-----\n" << endl;
    cout << "0. Exit Program" << endl;
    cout << "1. Run HF1 (Division method with Linear Probing)" << endl;
    cout << "2. Run HF2 (Division method with Quadratic Probing)" << endl;
    cout << "3. Run HF3 (Division method with Double Hashing)" << endl;
}

char get_command()
{
    char command;

    cout << ">";
    cin >> command;

    return (toupper(command));
}
