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

int main()
{
    char command;
    int node_number;
    int user_input;

	int **input_matrix;
	int **reachability_matrix;

    do {

		print_menu();
		command = get_command();
		
		if(command == '1') {
			node_number = -1;
			
			do {
				cout << "Choose a the following node options." << endl;
				cout << "1. for a graph with one node." << endl;
				cout << "2. for a graph with two nodes." << endl;
				cout << "3. for a graph with three nodes." << endl;
				cout << "4. for a graph with four nodes." << endl;
				cout << "5. for a graph with five nodes." << endl;
				cin >> node_number;

				if(node_number != 1 && node_number != 2 && node_number != 3 && node_number != 4 && node_number != 5) 
				{
					cout << "\nInvalid selection, try again.\n" << endl;
					node_number = -1;
				}
			} while(node_number == -1);
			
			//int input_matrix[node_number][node_number];
			input_matrix = new int*[node_number];
			for(int i = 0; i < node_number; i++){
				input_matrix[i] = new int[node_number];
			}
			
			for(int row = 0; row < node_number; row++) {
				for(int column = 0; column < node_number; column++) {
					cout << "Enter A1 [" << row << ", " << column << "]" << endl;
					cin >> user_input;
					input_matrix[row][column] = user_input;
				}
			}
			
			//intializing reachability_matrix with 0's
			reachability_matrix = new int*[node_number];
			for(int i = 0; i < node_number; i++){
				reachability_matrix[i] = new int[node_number];
			}
			for(int row = 0; row < node_number; row++) {
				for(int column = 0; column < node_number; column++) {
					reachability_matrix[row][column] = 0;
				}
			}
		}
		if(command == '2') {
			
			if(node_number == 1) {
				int boundary_row = 0;
				int boundary_column = 0;
				int A1_matrix[1][1];
				// A1_matrix will copy input_matrix
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
						A1_matrix[row][column] = input_matrix[row][column];
					}
				}
				//setting reachability_matrix will 0's
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
						reachability_matrix[row][column] = 0;
					}
				}
				
				//adding A1_matrix to reachability_matrix
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						reachability_matrix[row][column] += A1_matrix[row][column];
					}
				}
				/*printing/calcuting outputs
				 * 
				 * */
				//Input Matrix:
				cout<< endl;
				cout << "Input Matrix:" << endl;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						cout << input_matrix[row][column] << "\t";
					}
					cout << endl;
				}
				
				//Reachability Matrix:
				cout<< endl;
				cout << "Reachability Matrix:" << endl;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						cout << reachability_matrix[row][column] << "\t";
					}
					cout << endl;
				}
				
				//In Degrees:
				int node1_in_degree = 0; //node 1 is in the zero index in the 2D array
				cout<< endl;
				cout << "Out-degrees:" << endl;
				for(int row = 0; row < node_number; row++){
						node1_in_degree += A1_matrix[row][0];
				}
				cout << "Node 1 in-degree is " << node1_in_degree << endl;
				
				//Out-Degrees:
				int node1_out_degree = 0; //node 1 is in the zero index in the 2D array
				cout<< endl;
				cout << "In-degrees:" << endl;
				for(int column = 0; column < node_number; column++){
					node1_out_degree += A1_matrix[0][column];
				}
				cout << "Node 1 in-degree is " << node1_out_degree << endl;
				
				//Total Number of self-loops:
				int self_loops = 0;
				cout << endl;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						if(row == column){
							self_loops += A1_matrix[row][column];
						}
					}
				}
				cout << "Total number of self-loops: " << self_loops << endl;
				
				//Total number of cycles of length 1 edges: 
				int cycle_length_1 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						if(row == column){
							cycle_length_1 += A1_matrix[row][column];
						}
					}
				}
				cout << "Total number of cycles of length 1 edges: " << cycle_length_1 << endl;
				
				//Total number of paths of length 1 edge: 
				int path_length_1 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						path_length_1 += A1_matrix[row][column];
					}
				}
				cout << "Total number of paths of length 1 edge: " << path_length_1 << endl;
				
//				//Total number of paths of length 1 edge: 
//				int path_length_1 = 0;
//				for(int row = 0; row < node_number; row++){
//					for(int column = 0; column < node_number; column++){
//						path_length_1 += A1_matrix[row][column];
//					}
//				}
//				cout << "Total number of paths of length 1 edges: " << path_length_1 << endl;
				
				//Total number of paths of length 1 to 1 edges: 
				int path_length_1to1 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						path_length_1to1 += reachability_matrix[row][column];
					}
				}
				cout << "Total number of paths of length 1 to 1 edges: " << path_length_1to1 << endl;
				
				//Total number of cycles of length 1 to 2 edges: 
				int cycles_length_1to1 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						if(row == column){
							cycles_length_1to1 += reachability_matrix[row][column];
						}
					}
				}
				cout << "Total number of cycles of length 1 to 1 edges: " << cycles_length_1to1 << endl;
			}
			
			if(node_number == 2) {
				int boundary_row = 0;
				int boundary_column = 0;
				int A1_matrix[2][2];
				int A2_matrix[2][2];
				// A1_matrix will copy input_matrix
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
						A1_matrix[row][column] = input_matrix[row][column];
					}
				}
				/*We will perform matrix multiplication for A2*/
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
						A2_matrix[row][column] = 0;
						/*down column will control the movement down a column.
						 * this implies that it is really moving down the rows one column at a time
						 * the name should be less confusing now with this comment*/
						for(int down_column = 0; down_column < node_number; down_column++) {
							boundary_row = A1_matrix[row][down_column];
							boundary_column = A1_matrix[down_column][column];
							A2_matrix[row][column] += boundary_row * boundary_column;
						}
					}
				}
				//setting reachability_matrix will 0's
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
						reachability_matrix[row][column] = 0;
					}
				}
				
				//adding A1_matrix to reachability_matrix
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						reachability_matrix[row][column] += A1_matrix[row][column];
					}
				}
				//adding A2_matrix to reachability_matrix
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						reachability_matrix[row][column] += A2_matrix[row][column];
					}
				}
				/*printing/calcuting outputs
				 * 
				 * */
				//Input Matrix:
				cout<< endl;
				cout << "Input Matrix:" << endl;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						cout << input_matrix[row][column] << "\t";
					}
					cout << endl;
				}
				
				//Reachability Matrix:
				cout<< endl;
				cout << "Reachability Matrix:" << endl;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						cout << reachability_matrix[row][column] << "\t";
					}
					cout << endl;
				}
				
				//In Degrees:
				int node1_in_degree = 0; //node 1 is in the zero index in the 2D array
				int node2_in_degree = 0;
				cout<< endl;
				cout << "Out-degrees:" << endl;
				for(int row = 0; row < node_number; row++){
						node1_in_degree += A1_matrix[row][0];
						node2_in_degree += A1_matrix[row][1];
				}
				cout << "Node 1 in-degree is " << node1_in_degree << endl;
				cout << "Node 2 in-degree is " << node2_in_degree << endl;
				
				//Out-Degrees:
				int node1_out_degree = 0; //node 1 is in the zero index in the 2D array
				int node2_out_degree = 0;
				cout<< endl;
				cout << "In-degrees:" << endl;
				for(int column = 0; column < node_number; column++){
					node1_out_degree += A1_matrix[0][column];
					node2_out_degree += A1_matrix[1][column];
				}
				cout << "Node 1 in-degree is " << node1_out_degree << endl;
				cout << "Node 2 in-degree is " << node2_out_degree << endl;
				
				//Total Number of self-loops:
				int self_loops = 0;
				cout << endl;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						if(row == column){
							self_loops += A1_matrix[row][column];
						}
					}
				}
				cout << "Total number of self-loops: " << self_loops << endl;
				
				//Total number of cycles of length 2 edges: 
				int cycle_length_2 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						if(row == column){
							cycle_length_2 += A2_matrix[row][column];
						}
					}
				}
				cout << "Total number of cycles of length 2 edges: " << cycle_length_2 << endl;
				
				//Total number of paths of length 1 edge: 
				int path_length_1 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						path_length_1 += A1_matrix[row][column];
					}
				}
				cout << "Total number of paths of length 1 edge: " << path_length_1 << endl;
				
				//Total number of paths of length 2 edge: 
				int path_length_2 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						path_length_2 += A2_matrix[row][column];
					}
				}
				cout << "Total number of paths of length 2 edges: " << path_length_2 << endl;
				
				//Total number of paths of length 1 to 2 edges: 
				int path_length_1to2 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						path_length_1to2 += reachability_matrix[row][column];
					}
				}
				cout << "Total number of paths of length 1 to 2 edges: " << path_length_1to2 << endl;
				
				//Total number of cycles of length 1 to 2 edges: 
				int cycles_length_1to2 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						if(row == column){
							cycles_length_1to2 += reachability_matrix[row][column];
						}
					}
				}
				cout << "Total number of cycles of length 1 to 2 edges: " << cycles_length_1to2 << endl;
			}
			
			if(node_number == 3) {
				int A1_matrix[3][3];
				int A2_matrix[3][3];
				int A3_matrix[3][3];

				int boundary_row = 0;
				int boundary_column = 0;

				// A1_matrix will copy input_matrix
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
						A1_matrix[row][column] = input_matrix[row][column];
					}
				}
				/*We will perform matrix multiplication for A2*/
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
						A2_matrix[row][column] = 0;
						/*down column will control the movement down a column.
						 * this implies that it is really moving down the rows one column at a time
						 * the name should be less confusing now with this comment*/
						for(int down_column = 0; down_column < node_number; down_column++) {
							boundary_row = A1_matrix[row][down_column];
							boundary_column = A1_matrix[down_column][column];
							A2_matrix[row][column] += boundary_row*boundary_column;
						}
						
					}
				}
				
				cout << "a2 Matrix:" << endl;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						cout << A2_matrix[row][column] << "\t";
					}
					cout << endl;
				}
				
				/*We will perform matrix multiplication for A3*/
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
						A3_matrix[row][column] = 0;
						/*down column will control the movement down a column.
						 * this implies that it is really moving down the rows one column at a time
						 * the name should be less confusing now with this comment*/
						for(int down_column = 0; down_column < node_number; down_column++) {
							boundary_row = A2_matrix[row][down_column];
							boundary_column = A1_matrix[down_column][column];
							A3_matrix[row][column] += boundary_row * boundary_column;
						}
					}
				}
				
				cout << "a3 Matrix:" << endl;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						cout << A3_matrix[row][column] << "\t";
					}
					cout << endl;
				}
				
				//setting reachability_matrix will 0's
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
						reachability_matrix[row][column] = 0;
					}
				}
				
				//adding A1_matrix to reachability_matrix
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						reachability_matrix[row][column] += A1_matrix[row][column];
					}
				}
				//adding A2_matrix to reachability_matrix
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						reachability_matrix[row][column] += A2_matrix[row][column];
					}
				}
				//adding A3_matrix to reachability_matrix
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						reachability_matrix[row][column] += A3_matrix[row][column];
					}
				}
				/*printing/calcuting outputs
				 * 
				 * */
				//Input Matrix:
				cout<< endl;
				cout << "Input Matrix:" << endl;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						cout << input_matrix[row][column] << "\t";
					}
					cout << endl;
				}
				
				//Reachability Matrix:
				cout<< endl;
				cout << "Reachability Matrix:" << endl;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						cout << reachability_matrix[row][column] << "\t";
					}
					cout << endl;
				}
				
				//In Degrees:
				int node1_in_degree = 0; //node 1 is in the zero index in the 2D array
				int node2_in_degree = 0;
				int node3_in_degree = 0;
				cout<< endl;
				cout << "Out-degrees:" << endl;
				for(int row = 0; row < node_number; row++){
						node1_in_degree += A1_matrix[row][0];
						node2_in_degree += A1_matrix[row][1];
						node3_in_degree += A1_matrix[row][2];
				}
				cout << "Node 1 in-degree is " << node1_in_degree << endl;
				cout << "Node 2 in-degree is " << node2_in_degree << endl;
				cout << "Node 3 in-degree is " << node3_in_degree << endl;
				
				//Out-Degrees:
				int node1_out_degree = 0; //node 1 is in the zero index in the 2D array
				int node2_out_degree = 0;
				int node3_out_degree = 0;
				cout<< endl;
				cout << "In-degrees:" << endl;
				for(int column = 0; column < node_number; column++){
					node1_out_degree += A1_matrix[0][column];
					node2_out_degree += A1_matrix[1][column];
					node3_out_degree += A1_matrix[2][column];
				}
				cout << "Node 1 in-degree is " << node1_out_degree << endl;
				cout << "Node 2 in-degree is " << node2_out_degree << endl;
				cout << "Node 3 in-degree is " << node3_out_degree << endl;
				
				//Total Number of self-loops:
				int self_loops = 0;
				cout << endl;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						if(row == column){
							self_loops += A1_matrix[row][column];
						}
					}
				}
				cout << "Total number of self-loops: " << self_loops << endl;
				
				//Total number of cycles of length 3 edges: 
				int cycle_length_3 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						if(row == column){
							cycle_length_3 += A3_matrix[row][column];
						}
					}
				}
				cout << "Total number of cycles of length 3 edges: " << cycle_length_3 << endl;
				
				//Total number of paths of length 1 edge: 
				int path_length_1 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						path_length_1 += A1_matrix[row][column];
					}
				}
				cout << "Total number of paths of length 1 edge: " << path_length_1 << endl;
				
				//Total number of paths of length 3 edge: 
				int path_length_3 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						path_length_3 += A3_matrix[row][column];
					}
				}
				cout << "Total number of paths of length 3 edges: " << path_length_3 << endl;
				
				//Total number of paths of length 1 to 3 edges: 
				int path_length_1to3 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						path_length_1to3 += reachability_matrix[row][column];
					}
				}
				cout << "Total number of paths of length 1 to 3 edges: " << path_length_1to3 << endl;
				
				//Total number of cycles of length 1 to 3 edges: 
				int cycles_length_1to3 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						if(row == column){
							cycles_length_1to3 += reachability_matrix[row][column];
						}
					}
				}
				cout << "Total number of cycles of length 1 to 3 edges: " << cycles_length_1to3 << endl;
			}

			if(node_number == 4) {
				int A1_matrix[4][4];
				int A2_matrix[4][4];
				int A3_matrix[4][4];
				int A4_matrix[4][4];

				int boundary_row = 0;
				int boundary_column = 0;

				// A1_matrix will copy input_matrix
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
					A1_matrix[row][column] = input_matrix[row][column];
					}
				}
				/*We will perform matrix multiplication for A2*/
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
						A2_matrix[row][column] = 0; // Filling A2_matrix with 0's.
						/*down column will control the movement down a column.
						 * this implies that it is really moving down the rows one column at a time
						 * the name should be less confusing now with this comment*/
						for(int down_column = 0; down_column < node_number; down_column++) {
							boundary_row = A1_matrix[row][down_column];
							boundary_column = A1_matrix[down_column][column];
							A2_matrix[row][column] += boundary_row * boundary_column;
						}
					}
				}
				/*We will perform matrix multiplication for A3*/
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
					A3_matrix[row][column] = 0; // Filling A3_matrix with 0's.
					/*down column will control the movement down a column.
					 * this implies that it is really moving down the rows one column at a time
					 * the name should be less confusing now with this comment*/
						for(int down_column = 0; down_column < node_number; down_column++) {
							boundary_row = A2_matrix[row][down_column];
							boundary_column = A1_matrix[down_column][column];
							A3_matrix[row][column] += boundary_row * boundary_column;
						}
					}
				}
				/*We will perform matrix multiplication for A4*/
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
						A4_matrix[row][column] = 0; // Filling A4_matrix with 0's.
						/*down column will control the movement down a column.
						 * this implies that it is really moving down the rows one column at a time
						 * the name should be less confusing now with this comment*/
						for(int down_column = 0; down_column < node_number; down_column++) {
							boundary_row = A3_matrix[row][down_column];
							boundary_column = A1_matrix[down_column][column];
							A4_matrix[row][column] += boundary_row * boundary_column;
						}
					}
				}
				//setting reachability_matrix will 0's
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
						reachability_matrix[row][column] = 0;
					}
				}
				
				//adding A1_matrix to reachability_matrix
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						reachability_matrix[row][column] += A1_matrix[row][column];
					}
				}
				//adding A2_matrix to reachability_matrix
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						reachability_matrix[row][column] += A2_matrix[row][column];
					}
				}
				//adding A3_matrix to reachability_matrix
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						reachability_matrix[row][column] += A3_matrix[row][column];
					}
				}
				//adding A4_matrix to reachability_matrix
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						reachability_matrix[row][column] += A4_matrix[row][column];
					}
				}
				
				/*printing/calcuting outputs
				 * 
				 * */
				//Input Matrix:
				cout<< endl;
				cout << "Input Matrix:" << endl;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						cout << input_matrix[row][column] << "\t";
					}
					cout << endl;
				}
				
				//Reachability Matrix:
				cout<< endl;
				cout << "Reachability Matrix:" << endl;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						cout << reachability_matrix[row][column] << "\t";
					}
					cout << endl;
				}
				
				//In Degrees:
				int node1_in_degree = 0; //node 1 is in the zero index in the 2D array
				int node2_in_degree = 0;
				int node3_in_degree = 0;
				int node4_in_degree = 0;
				cout<< endl;
				cout << "Out-degrees:" << endl;
				for(int row = 0; row < node_number; row++){
						node1_in_degree += A1_matrix[row][0];
						node2_in_degree += A1_matrix[row][1];
						node3_in_degree += A1_matrix[row][2];
						node4_in_degree += A1_matrix[row][3];
				}
				cout << "Node 1 in-degree is " << node1_in_degree << endl;
				cout << "Node 2 in-degree is " << node2_in_degree << endl;
				cout << "Node 3 in-degree is " << node3_in_degree << endl;
				cout << "Node 4 in-degree is " << node4_in_degree << endl;
				
				//Out-Degrees:
				int node1_out_degree = 0; //node 1 is in the zero index in the 2D array
				int node2_out_degree = 0;
				int node3_out_degree = 0;
				int node4_out_degree = 0;
				cout<< endl;
				cout << "In-degrees:" << endl;
				for(int column = 0; column < node_number; column++){
					node1_out_degree += A1_matrix[0][column];
					node2_out_degree += A1_matrix[1][column];
					node3_out_degree += A1_matrix[2][column];
					node4_out_degree += A1_matrix[3][column];
				}
				cout << "Node 1 in-degree is " << node1_out_degree << endl;
				cout << "Node 2 in-degree is " << node2_out_degree << endl;
				cout << "Node 3 in-degree is " << node3_out_degree << endl;
				cout << "Node 4 in-degree is " << node4_out_degree << endl;
				
				//Total Number of self-loops:
				int self_loops = 0;
				cout << endl;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						if(row == column){
							self_loops += A1_matrix[row][column];
						}
					}
				}
				cout << "Total number of self-loops: " << self_loops << endl;
				
				//Total number of cycles of length 4 edges: 
				int cycle_length_4 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						if(row == column){
							cycle_length_4 += A4_matrix[row][column];
						}
					}
				}
				cout << "Total number of cycles of length 4 edges: " << cycle_length_4 << endl;
				
				//Total number of paths of length 1 edge: 
				int path_length_1 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						path_length_1 += A1_matrix[row][column];
					}
				}
				cout << "Total number of paths of length 1 edge: " << path_length_1 << endl;
				
				//Total number of paths of length 4 edge: 
				int path_length_4 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						path_length_4 += A4_matrix[row][column];
					}
				}
				cout << "Total number of paths of length 4 edges: " << path_length_4 << endl;
				
				//Total number of paths of length 1 to 4 edges: 
				int path_length_1to4 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						path_length_1to4 += reachability_matrix[row][column];
					}
				}
				cout << "Total number of paths of length 1 to 4 edges: " << path_length_1to4 << endl;
				
				//Total number of cycles of length 1 to 4 edges: 
				int cycles_length_1to4 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						if(row == column){
							cycles_length_1to4 += reachability_matrix[row][column];
						}
					}
				}
				cout << "Total number of cycles of length 1 to 4 edges: " << cycles_length_1to4 << endl;
			}
			
			if(node_number == 5) {
				int A1_matrix[5][5];
				int A2_matrix[5][5];
				int A3_matrix[5][5];
				int A4_matrix[5][5];
				int A5_matrix[5][5];
				
				int boundary_row = 0;
				int boundary_column = 0;

				// A1_matrix will copy input_matrix
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
					A1_matrix[row][column] = input_matrix[row][column];
					}
				}
				/*We will perform matrix multiplication for A2*/
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
						A2_matrix[row][column] = 0; // Filling A2_matrix with 0's.
						/*down column will control the movement down a column.
						 * this implies that it is really moving down the rows one column at a time
						 * the name should be less confusing now with this comment*/
						for(int down_column = 0; down_column < node_number; down_column++) {
							boundary_row = A1_matrix[row][down_column];
							boundary_column = A1_matrix[down_column][column];
							A2_matrix[row][column] += boundary_row * boundary_column;
						}
					}
				}
				/*We will perform matrix multiplication for A3*/
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
					A3_matrix[row][column] = 0; // Filling A3_matrix with 0's.
					/*down column will control the movement down a column.
					 * this implies that it is really moving down the rows one column at a time
					 * the name should be less confusing now with this comment*/
						for(int down_column = 0; down_column < node_number; down_column++) {
							boundary_row = A2_matrix[row][down_column];
							boundary_column = A1_matrix[down_column][column];
							A3_matrix[row][column] += boundary_row * boundary_column;
						}
					}
				}
				/*We will perform matrix multiplication for A4*/
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
						A4_matrix[row][column] = 0; // Filling A4_matrix with 0's.
						/*down column will control the movement down a column.
						 * this implies that it is really moving down the rows one column at a time
						 * the name should be less confusing now with this comment*/
						for(int down_column = 0; down_column < node_number; down_column++) {
							boundary_row = A3_matrix[row][down_column];
							boundary_column = A1_matrix[down_column][column];
							A4_matrix[row][column] += boundary_row * boundary_column;
						}
					}
				}
				/*We will perform matrix multiplication for A5*/
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
						A5_matrix[row][column] = 0; // Filling A4_matrix with 0's.
						/*down column will control the movement down a column.
						 * this implies that it is really moving down the rows one column at a time
						 * the name should be less confusing now with this comment*/
						for(int down_column = 0; down_column < node_number; down_column++) {
							boundary_row = A4_matrix[row][down_column];
							boundary_column = A1_matrix[down_column][column];
							A5_matrix[row][column] += boundary_row * boundary_column;
						}
					}
				}
				//setting reachability_matrix will 0's
				for(int row = 0; row < node_number; row++) {
					for(int column = 0; column < node_number; column++) {
						reachability_matrix[row][column] = 0;
					}
				}
				
				//adding A1_matrix to reachability_matrix
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						reachability_matrix[row][column] += A1_matrix[row][column];
					}
				}
				//adding A2_matrix to reachability_matrix
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						reachability_matrix[row][column] += A2_matrix[row][column];
					}
				}
				//adding A3_matrix to reachability_matrix
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						reachability_matrix[row][column] += A3_matrix[row][column];
					}
				}
				//adding A4_matrix to reachability_matrix
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						reachability_matrix[row][column] += A4_matrix[row][column];
					}
				}
				//adding A5_matrix to reachability_matrix
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						reachability_matrix[row][column] += A5_matrix[row][column];
					}
				}
				
				/*printing/calcuting outputs
				 * 
				 * */
				//Input Matrix:
				cout<< endl;
				cout << "Input Matrix:" << endl;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						cout << input_matrix[row][column] << "\t";
					}
					cout << endl;
				}
				
				//Reachability Matrix:
				cout<< endl;
				cout << "Reachability Matrix:" << endl;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						cout << reachability_matrix[row][column] << "\t";
					}
					cout << endl;
				}
				
				//In Degrees:
				int node1_in_degree = 0; //node 1 is in the zero index in the 2D array
				int node2_in_degree = 0;
				int node3_in_degree = 0;
				int node4_in_degree = 0;
				int node5_in_degree = 0;
				cout<< endl;
				cout << "Out-degrees:" << endl;
				for(int row = 0; row < node_number; row++){
						node1_in_degree += A1_matrix[row][0];
						node2_in_degree += A1_matrix[row][1];
						node3_in_degree += A1_matrix[row][2];
						node4_in_degree += A1_matrix[row][3];
						node5_in_degree += A1_matrix[row][4];
				}
				cout << "Node 1 in-degree is " << node1_in_degree << endl;
				cout << "Node 2 in-degree is " << node2_in_degree << endl;
				cout << "Node 3 in-degree is " << node3_in_degree << endl;
				cout << "Node 4 in-degree is " << node4_in_degree << endl;
				cout << "Node 5 in-degree is " << node5_in_degree << endl;
				
				//Out-Degrees:
				int node1_out_degree = 0; //node 1 is in the zero index in the 2D array
				int node2_out_degree = 0;
				int node3_out_degree = 0;
				int node4_out_degree = 0;
				int node5_out_degree = 0;
				cout<< endl;
				cout << "In-degrees:" << endl;
				for(int column = 0; column < node_number; column++){
					node1_out_degree += A1_matrix[0][column];
					node2_out_degree += A1_matrix[1][column];
					node3_out_degree += A1_matrix[2][column];
					node4_out_degree += A1_matrix[3][column];
					node5_out_degree += A1_matrix[4][column];
				}
				cout << "Node 1 in-degree is " << node1_out_degree << endl;
				cout << "Node 2 in-degree is " << node2_out_degree << endl;
				cout << "Node 3 in-degree is " << node3_out_degree << endl;
				cout << "Node 4 in-degree is " << node4_out_degree << endl;
				cout << "Node 5 in-degree is " << node5_out_degree << endl;
				
				//Total Number of self-loops:
				int self_loops = 0;
				cout << endl;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						if(row == column){
							self_loops += A1_matrix[row][column];
						}
					}
				}
				cout << "Total number of self-loops: " << self_loops << endl;
				
				//Total number of cycles of length 5 edges: 
				int cycle_length_5 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						if(row == column){
							cycle_length_5 += A5_matrix[row][column];
						}
					}
				}
				cout << "Total number of cycles of length 5 edges: " << cycle_length_5 << endl;
				
				//Total number of paths of length 1 edge: 
				int path_length_1 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						path_length_1 += A1_matrix[row][column];
					}
				}
				cout << "Total number of paths of length 1 edge: " << path_length_1 << endl;
				
				//Total number of paths of length 5 edge: 
				int path_length_5 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						path_length_5 += A5_matrix[row][column];
					}
				}
				cout << "Total number of paths of length 5 edges: " << path_length_5 << endl;
				
				//Total number of paths of length 1 to 3 edges: 
				int path_length_1to5 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						path_length_1to5 += reachability_matrix[row][column];
					}
				}
				cout << "Total number of paths of length 1 to 5 edges: " << path_length_1to5 << endl;
				
				//Total number of cycles of length 1 to 5 edges: 
				int cycles_length_1to5 = 0;
				for(int row = 0; row < node_number; row++){
					for(int column = 0; column < node_number; column++){
						if(row == column){
							cycles_length_1to5 += reachability_matrix[row][column];
						}
					}
				}
				cout << "Total number of cycles of length 1 to 5 edges: " << cycles_length_1to5 << endl;
			}
			
		}
	} while(command != '0');

	//ALL THIS GARBAGE. MEMORY LEAK BE GONE
	for(int i = 0; i < node_number; i++){
		delete input_matrix[i];
		delete reachability_matrix[i];
	}
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
