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
size_t hash1(int key_value);
void intialize_empty_table(int Table[][2]);
void print_table(int Table[][2]);

int main()
{
    int keys[] = { 1234, 8234, 7867, 1009, 5438, 4312, 3420, 9487, 5418, 5299, 5078, 8239, 1208, 5098, 5195, 5329, 4543,
	3344, 7698, 5412, 5567, 5672, 7934, 1254, 6091, 8732, 3095, 1975, 3843, 5589, 5439, 8907, 4097, 3096, 4310,
	5298, 9156, 3895, 6673, 7871, 5787, 9289, 4553, 7822, 8755, 3398, 6774, 8289, 7665, 5523 };
	
	int Table[50][2];
	size_t const CAPACITY_X = 50;
	size_t const CAPACITY_Y = 2;
	char command;
	size_t hash_value;
	
	
	do
	{
		print_menu();
		command = get_command();
		
		if(command == '1')
		{
			intialize_empty_table(Table);
			
			for(size_t row = 0; row < CAPACITY_X; row++)
			{
				for(size_t column = 0; column < CAPACITY_Y; column++)
				{
					
					//hash_value = hash1(keys[row]);
					//cout << hash_value << endl;
				} 
			}
			
			hash_value = hash1(keys[0]);
			
			cout << "Printing" << endl;
			print_table(Table);
		}
		
		if(command == '2')
		{
			
		}
		
		if(command == '3')
		{
			
		}
		
		
		
	}while(command != '0');
    return EXIT_SUCCESS;
}

size_t hash1(int key_value)
{
	size_t hash_value;
	
	hash_value = key_value % 100;
	cout << hash_value << endl;
	
	return hash_value;
}

//fill in hash table with -1 to indicate unused
void intialize_empty_table(int Table[][2])
{
	size_t column = 0;
	for(size_t row = 0; row < 50; row++)
	{
		Table[row][column] = -1;
	}
	
}

void print_table(int Table[][2])
{
	size_t column = 0;
	
	cout << "Index\t" << "Key\t" << "Probes\t" << endl;
	cout << "-------------------------------" << endl;
	for(size_t row = 0; row < 50; row++)
	{
		cout << row << "\t";
		cout << Table[row][column] << "\t";
		//missing probes
		cout << endl;
	}
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
