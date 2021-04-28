// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 12

#include <cassert>
#include <cmath>
#include <ctime>
#include <ctype.h>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

void matrix_multiplication(int **input_matrix, int **A_matrix, int size);

int main(){
	
	int node_number = 4;
	
	//int **graph;
	int user_input;
	
	cout << "Input node number" << endl;
	//cin >> matrix_size;
	
	int input_matrix[node_number][node_number];
	
	
	
	for(int row = 0; row < node_number; row++){
		for(int column = 0; column < node_number; column++){
			cout << "Enter A1 [" << row << ", " << column << "]" << endl;
			cin >> user_input;
			input_matrix[row][column] = user_input;
		}
	}
	
	if(node_number == 2)
	{
		int A1_matrix[node_number][node_number];
		
		
		for(int row = 0; row < node_number; row++){
			for(int column = 0; column < node_number; column++){
				
			}
		}
	
		int A2_matrix[node_number][node_number];
		
		for(int row = 0; row < node_number; row++){
			for(int column = 0; column < node_number; column++){
				A1_matrix[row][column] = input_matrix[row][column];
			}
		}
		
		
	}
	
	if(node_number == 3)
	{
		int A1_matrix[node_number][node_number];
		int A2_matrix[node_number][node_number];
		
		int A3_matrix[node_number][node_number];
	}
	
	if(node_number == 4)
	{
		int A1_matrix[node_number][node_number];
		int A2_matrix[node_number][node_number];
	
		int A3_matrix[node_number][node_number];
		int A4_matrix[node_number][node_number];
		//matrix_multiplication(input_matrix, A2_matrix, node_number);
	}
	
	return EXIT_SUCCESS;
}

//A_matrix can be A2, A3, or A4 depending on our nodes
void matrix_multiplication(int **input_matrix, int **A_matrix, int size)
{
	
}

