// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 6

#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// PROTOTYPES for functions used by this test program:
void topToBottom(stack<int> temp_int);
// Postcondition: prints the stack

void bottomToTop(stack<double> double_stack);
// Postcondition: prints the stack

stack<string> flipStack(stack<string> string_stack);
// Postcondition: returns a flipped stack of a string data type

bool searchStack(stack<int> int_stack, int target_value);
// Postcondition: returns true if target value is in the stack

bool checkIfPalindrome(stack<char> char_stack);
// Postcondition: returns true if it is a palidrome

void print_menu();
// Postcondition: The menu has been written to cout.

char get_command();
// Postcondition: The user has been prompted for a character.
// The entered charatcer will be returned, translated to upper case.


int main()
{
	
stack<int> int_stack;
stack<double> double_stack;
stack<string> string_stack;
stack<char> char_stack;

//we need some temps to print our stack contents so we dont mess with orignal data
stack<int> temp_int;
stack<double> temp_double;
stack<string> temp_string;
stack<char> temp_char;

int int_input;
int target_value;
double double_input;
string string_input;
bool isSearch;
char char_input;
bool isPalindrome;
char command;

    do {
	print_menu();
	command = toupper(get_command());

	switch(command) {
	case '1':
		cout << "Enter type int data to push to the int stack" << endl;
		cin >> int_input;
		int_stack.push(int_input);
	    break;
		
	case '2':
		cout << "Enter type double data to push to the double stack" << endl;
		cin >> double_input;
		double_stack.push(double_input);
		break;
		
	case '3':
		cout << "Enter type string data to push to the string stack" << endl;
		cin >> string_input;
		string_stack.push(string_input);
		break;
		
	case '4':
		cout << "Enter type char data to push to the char stack" << endl;
		cin >> char_input;
		char_stack.push(char_input);
		break;
		
	case '5':
		if(int_stack.empty()){
		cout << "\n----------------Empty Stack----------------" << endl;
		break;
		}
		
		temp_int = int_stack;
		cout << "Testing function topToBottom stack:" << endl;
		cout << "Stack content: ";
		while(!temp_int.empty()){
			cout << temp_int.top() << " ";
			temp_int.pop();
		}
		cout << endl;
		
		cout << "Function output: ";
		topToBottom(int_stack);
		cout << endl;
		break;
		
	case '6':
		if(double_stack.empty()){
		cout << "\n----------------Empty Stack----------------" << endl;
		break;
		}
		
		temp_double = double_stack;
		cout << "Testing function bottomToTop stack:" << endl;
		cout << "Stack content: ";
		while(!temp_double.empty()){
			cout << temp_double.top() << " ";
			temp_double.pop();
		}
		cout << endl;
		
		cout << "Function output: ";
		bottomToTop(double_stack);
		cout << endl;
		break;
		
	case '7':
		if(string_stack.empty()){
		cout << "\n----------------Empty Stack----------------" << endl;
		break;
		}
		
		temp_string = string_stack;
		cout << "Testing function flipped stack:" << endl;
		
		//print before flip
		cout << "Stack contents before: " << endl;
		while(!temp_string.empty()){
		cout << temp_string.top() << " ";
		temp_string.pop();
		}
		cout << endl;
		
		//now we flip the stack and change string_stack
		string_stack = flipStack(string_stack);
		//putting values back in the stack
		temp_string = string_stack;

		cout << "Stack contents after: " << endl;
		while(!temp_string.empty()){
		cout << temp_string.top() << " ";
		temp_string.pop();
		}
		cout << endl;
		break;
		
	case '8':
		if(int_stack.empty()){
		cout << "\n----------------Empty Stack----------------" << endl;
		break;
		}
		
		temp_int = int_stack;
		cout << "Enter in a target value" << endl;
		cin >> target_value;
		
		isSearch = searchStack(int_stack, target_value);
		
		cout << "Testing function searchStack: " << endl;
		cout << "Stack content: ";
		while(!temp_int.empty()){
			cout << temp_int.top() << " ";
			temp_int.pop();
		}
		cout << "\nTarget value:	" << target_value << endl;
		cout << "Function output: ";
		if(isSearch == true){
			cout << "true" << endl;
		}else{
			cout << "false" << endl;
		}
		break;
		
	case '9':
		if(char_stack.empty()){
		cout << "\n----------------Empty Stack----------------" << endl;
		break;
		}
		
		temp_char = char_stack;
		isPalindrome = checkIfPalindrome(char_stack);
		cout << "Testing function of checkIfPalindrome:" << endl;
		cout << "Stack content: ";
		/*Note: after popping char stack will be empty, but checkIfPalindrome did its work before that
		 * */
		while(!temp_char.empty()){
			cout << temp_char.top() << " ";
			temp_char.pop();
		}
		
		cout << "\nFunction output: ";
		if(isPalindrome == true){
			cout << "true" << endl;
		}else{
			cout << "false" << endl;
		}
		break;
	}
    } while(command != 'Q');


    return EXIT_SUCCESS;
}

void topToBottom(stack<int> int_stack)
{
	while(!int_stack.empty()){
		cout << int_stack.top() << " ";
		int_stack.pop();
	}
}

void bottomToTop(stack<double> double_stack)
{
	stack<double> temp_stack;
	
	while(!double_stack.empty()){
	
	temp_stack.push(double_stack.top());
	double_stack.pop();
	}
	
	//printing the reverse of double stack
	while(!temp_stack.empty()){
		cout << temp_stack.top() << " ";
		temp_stack.pop();
	}
}

stack<string> flipStack(stack<string> string_stack)
{
	stack<string> temp;
	
	while(!string_stack.empty()){
		temp.push(string_stack.top());
		string_stack.pop();
	}
	
	string_stack = temp;
	
	return string_stack;
}

bool searchStack(stack<int> int_stack, int target_value)
{
	int value;
	//stack<int> temp;
	while(!int_stack.empty()){
		value = int_stack.top();
		
		if(value == target_value){
			return true;
		}else{
			int_stack.pop();
		}
	}
	return false;
}

bool checkIfPalindrome(stack<char> char_stack)
{
	stack<char> duplicate;
	stack<char> flipped;
	
	duplicate = char_stack;
	
	while(!duplicate.empty()){
		flipped.push(duplicate.top());
		duplicate.pop();
	}
	
	while(!flipped.empty()){
		if(flipped.top() != char_stack.top()){
			return false;
		}
		flipped.pop();
		char_stack.pop();
	}
	return true;
}

void print_menu()
{
    cout << "\n"
         << "----------------- The Commands -----------------" << endl;
    cout << "1 - Enter type int data to push to the int stack" << endl;
	cout << "2 - Enter type double data to push to the double stack" << endl;
	cout << "3 - Enter type string data to push to the string stack" << endl;
	cout << "4 - Enter type char data to push to the char stack" << endl;
	cout << "5 - Call the top to bottom function of int stack" << endl;
    cout << "6 - Call bottom to top function of double stack" << endl;
    cout << "7 - Call flip stack for string stack" << endl;
    cout << "8 - Call search stack function of int stack" << endl;
    cout << "9 - Call check if palindrome function for char stack" << endl;
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