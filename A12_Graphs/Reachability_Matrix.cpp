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

char get_command();
void print_menu();
void print_2x2_matrix(int matrix[2][2]);
void print_3x3_matrix(int matrix[3][3]);
void print_4x4_matrix(int matrix[4][4]);

int main(){
	
	char command;
	int node_number;
	int user_input;
	
	do{
		
		printMenu();
		command = get_command;
		
	}while(command != '0');
	
	cout << "Input node number" << endl;
	//cin >> node_number
	
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
		
		int boundary_row = 0;
		int boundary_column = 0;
		
		int A1_matrix[2][2];
		int A2_matrix[2][2];
		//A1_matrix will copy input_matrix
		for(int row = 0; row < node_number; row++){
			for(int column = 0; column < node_number; column++){
				A1_matrix[row][column] = input_matrix[row][column];
			}
		}
	
		
		/*We will perform matrix multiplication for A2*/
		for(int row = 0; row < node_number; row++){
			for(int column = 0; column < node_number; column++){
				A2_matrix[row][column] = 0;
				boundary_row = A1_matrix[row][column];
				
				/*down column will control the movement down a column. 
				 * this implies that it is really moving down the rows one column at a time
				 * the name should be less confusing now with this comment*/
				for(int down_column = 0; down_column < node_number; down_column++){
					boundary_column = A1_matrix[down_column][column];
					A2_matrix[row][column] += boundary_row * boundary_column;
				}
				
			}
		}
		
		cout << "A2" << endl;
		print_2x2_matrix(A2_matrix);
	}
	
	if(node_number == 3)
	{
		int A1_matrix[3][3];
		int A2_matrix[3][3];
		int A3_matrix[3][3];
		
		int boundary_row = 0;
		int boundary_column = 0;
		
		
		//A1_matrix will copy input_matrix
		for(int row = 0; row < node_number; row++){
			for(int column = 0; column < node_number; column++){
				A1_matrix[row][column] = input_matrix[row][column];
			}
		}
	
		/*We will perform matrix multiplication for A2*/
		for(int row = 0; row < node_number; row++){
			for(int column = 0; column < node_number; column++){
				A2_matrix[row][column] = 0;
				boundary_row = A1_matrix[row][column];
				
				/*down column will control the movement down a column. 
				 * this implies that it is really moving down the rows one column at a time
				 * the name should be less confusing now with this comment*/
				for(int down_column = 0; down_column < node_number; down_column++){
					boundary_column = A1_matrix[down_column][column];
					A2_matrix[row][column] += boundary_row * boundary_column;
				}
				
			}
		}
		
		/*We will perform matrix multiplication for A3*/
		for(int row = 0; row < node_number; row++){
			for(int column = 0; column < node_number; column++){
				A2_matrix[row][column] = 0;
				boundary_row = A2_matrix[row][column];
				
				/*down column will control the movement down a column. 
				 * this implies that it is really moving down the rows one column at a time
				 * the name should be less confusing now with this comment*/
				for(int down_column = 0; down_column < node_number; down_column++){
					boundary_column = A1_matrix[down_column][column];
					A3_matrix[row][column] += boundary_row * boundary_column;
				}
				
			}
		}
		
		
	}
	
	if(node_number == 4)
	{
		int A1_matrix[node_number][node_number];
		int A2_matrix[node_number][node_number];
	
		int A3_matrix[node_number][node_number];
		int A4_matrix[node_number][node_number];
		//matrix_multiplication(input_matrix, A2_matrix, node_number);
	}
	
	//printing outputs
	
	//print_matrix(*input_matrix[node_number], node_number);

	
	return EXIT_SUCCESS;
}

void print_menu()
{
    cout << "\n-----Press a number for the following menu option-----\n" << endl;
    cout << "0. Exit Program" << endl;
    cout << "1. Enter graph data" << endl;
    cout << "2. Print Outputs" << endl;
}

char get_command()
{
    char command;

    cout << ">";
    cin >> command;

    return (toupper(command));
}

void print_2x2_matrix(int A2_matrix[2][2]){
	for(int row = 0; row < 2; row++){
		for(int column = 0; column < 2; column++){
			cout << A2_matrix[row][column] << " ";
		}
		cout << endl;
		}
}+++

