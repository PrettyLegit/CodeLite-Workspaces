// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 2

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Rectangle.hpp"
using namespace std;
using namespace Main_Rectangle;

bool validateInput(double width, double height)
{
	if(width <= 0 || height <= 0)
	{
		cout << "Your number was less than or equal to 0. Try again." << endl;
		return false;
	}else
		{
		return true;
		}
}

int main()
{
	bool isInput = false;
	double user_width = 0.0;
	double user_height = 0.0;
	
	//output 1 for assignement 
	Rectangle myRectangle;
	
	cout << setw(10) << "myRectangle" << "\n-------" << endl;
	cout << setw(10) << "Width:\t" << myRectangle.getWidth() << endl;
	cout << setw(10) << "Height:\t" << myRectangle.getHeight() << endl;
	cout << setw(10) << "Area:\t" << myRectangle.getArea() << endl;
	cout << setw(10) << "Perimeter:\t" << myRectangle.getPerimeter() << endl;
	
	myRectangle.printRectangle("myRectangle");
	
	while(isInput == false)
	{
		cout << "\nEnter in a value for width " << endl;
		cin >> user_width;
		cin.clear();
		cout << "Enter in a value for height " << endl;
		cin >> user_height;
		cin.clear();
		isInput = validateInput(user_width, user_height);
	}
	
	//output 2 for assignemnt 
	Rectangle herRectangle(user_width, user_height);
	
	cout << setw(10) << "\nherRectangle" << "\n-------" << endl;
	cout << setw(10) << "Width:\t" << herRectangle.getWidth() << endl;
	cout << setw(10) << "Height:\t" << herRectangle.getHeight() << endl;
	cout << setw(10) << "Area:\t" << herRectangle.getArea() << endl;
	cout << setw(10) << "Perimeter:\t" << herRectangle.getPerimeter() << endl;
	
	herRectangle.printRectangle("herRectangle");
	//return EXIT_SUCCESS;
	return 0;
}
