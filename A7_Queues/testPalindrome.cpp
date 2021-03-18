// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 7

#include <cassert>  // Provides assert
#include <cctype>   // Provides isalpha, toupper
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iomanip>  // setw
#include <iostream> // Provides cout, cin, peek
#include <locale>   //get line, i think
#include <queue>    // Provides the queue template class
#include <stack>    // Provides the stack template class
#include <string>
using namespace std;

// Prototypes
void print_menu();
// Postcondition: The menu has been written to cout.
char get_command();
// Postcondition: The user has been prompted for a character.
// The entered charatcer will be returned, translated to upper case.
void character_by_character();

// global variables

string userInput = " ";
string temp;
queue<char>::size_type mismatches = 0; // Mismatches between queue and stack

int main()
{
    queue<string> queue_strings;
    stack<string> stack_strings;
    char command;

    do {

	print_menu();
	command = toupper(get_command());

	switch(command) {
	case '1':
	    cin.clear();
	    cin.sync();
	    character_by_character();
	    break;

	case '2':

	    mismatches = 0;
	    temp = "";
	    cout << "Enter a sentence and I will see if it's a palindrome:" << endl;
	    cin.clear();
	    cin.sync();
	    getline(cin, userInput);

	    for(int i = 0; i <= userInput.length(); i++) {
		if(isalpha(userInput[i]) || (userInput[i] == '\'')) {
		    temp += userInput[i];
		} else {
		    // temp has reached delimeter
		    queue_strings.push(temp);
		    stack_strings.push(temp);
		    temp = "";
		}
	    }

	    while((!queue_strings.empty()) && (!stack_strings.empty())) {
		if(queue_strings.front() != stack_strings.top()) {
		    ++mismatches;
		}

		queue_strings.pop();
		stack_strings.pop();
	    }

	    cout << endl;
	    cout << setw(10) << "You selected:\t"
	         << "Option 2" << endl;
	    cout << setw(10) << "You entered:\t" << userInput << endl;
	    cout << setw(10) << "Judgement:\t";
	    if(mismatches == 0)
		cout << setw(10) << "That is a palindrome." << endl;
	    else
		cout << setw(10) << "That is not a palindrome." << endl;
	    break;
	}
    } while(command != '3');

    return EXIT_SUCCESS;
}

void print_menu()
{
    cout << "-----Press a number for the following menu option-----\n" << endl;
    cout << "1. Test character-by-character palindrome" << endl;
    cout << "2. Test word-by-word palindrome" << endl;
    cout << "3. Quit program" << endl;
}

char get_command()
{
    char command;

    cout << ">";
    cin >> command;

    return (toupper(command));
}

void character_by_character()
{
    queue<char> q;
    stack<char> s;
    char letter;

    mismatches = 0;
    temp = "";
    cout << "Enter a line and I will see if it's a palindrome:" << endl;

    while(cin.peek() != '\n') {
	cin >> letter;
	temp += letter;
	if(isalpha(letter)) {
	    q.push(toupper(letter));
	    s.push(toupper(letter));
	    //temp += letter;
	}
    }
    while((!q.empty()) && (!s.empty())) {
	if(q.front() != s.top())
	    ++mismatches;
	q.pop();
	s.pop();
    }
    cout << endl;
    cout << setw(10) << "You selected:\t"
         << "Option 1" << endl;
    cout << setw(10) << "You entered:\t" << temp << endl;
    cout << setw(10) << "Judgement:\t";
    if(mismatches == 0)
	cout << setw(10) << "That is a palindrome." << endl;
    else
	cout << setw(10) << "That is not a palindrome." << endl;
}
