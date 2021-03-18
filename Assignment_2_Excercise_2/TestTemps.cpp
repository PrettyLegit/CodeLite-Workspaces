// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 2

#include "Temps.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
using namespace Main_Temps;

bool validateInput(double userInput)
{
    if(!(userInput <= 120) || !(userInput >= -40)) {
	cout << "Your number needs to be within 120 F and -40 F" << endl;
	return false;
    } else {
	return true;
    }
}

int main()
{
    bool isInput = false;
    double userInput = 0;

    // this is for the set temp functionality
    int chosenDay = -1;
    string menuKey = "W";
    double resetInput = -1;

    Temps t1;

    // getting data
    for(int i = 0; i < t1.length; i++) {
	// cout << "Enter in a temperature value for " << t1.dayName[i] << " " << endl;
	isInput = false;
	while(isInput == false) {
	    cout << "Enter in a temperature value for " << t1.dayName[i] << " " << endl;
	    cin >> userInput;
	    // validate input sends userInputs and returns true if the number is good
	    isInput = validateInput(userInput);
	}

	t1.setTemp(i, userInput);
    }

    // printing the info
    t1.printTemps();

    // this is the set temp functionality

    while(menuKey != "Q") {
	isInput = false;
	chosenDay = -1;
	userInput = resetInput;

	cout << "Please choose from the following menu:\nPress (A) to overwrite the temperature for a selected day"
	     << "\nPress (Q) to to quit program." << endl;

	cin >> menuKey;

	if(menuKey == "Q") {
	    break;
	}
	if(menuKey == "A") {
	    while((chosenDay > 6) || (chosenDay < 0)) {
		cout << "\n\n\nEnter in a day of the week you would like to change... 0-6 (Monday-Friday)" << endl;
		cin >> chosenDay;
	    }

	    while(isInput == false) {
		cout << "\n\n\nEnter in a temperature value for " << t1.dayName[chosenDay] << " " << endl;
		cin >> userInput;
		isInput = validateInput(userInput);
	    }
	    t1.setTemp(chosenDay, userInput);

	    cout << "Processing...Changed!" << endl;
	    t1.printTemps();
	}
    }
    cout << "\nNumber of freezing days is..." << endl;
    t1.Freezing();

    cout << "\nThe warmest day of the week was..." << t1.Warmest() << endl;
}
