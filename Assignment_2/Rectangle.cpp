// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 2

// Rectangle.cpp
// CLASS IMPLEMENTED: Rectangle (see Rectangle.hpp for documentation)
#include <cassert>
#include <iostream>
#include "Rectangle.hpp"

using namespace std;
namespace Main_Rectangle
{
	
	Rectangle::Rectangle()
	{
		width = 1.00;
		height = 1.00;
	}
	
	Rectangle::Rectangle(double user_width, double user_height)
	{
		width = user_width;
		height = user_height;
	}
	
	void Rectangle::printRectangle(string objectName)
	{
		cout << "\nRectangle " << objectName << " is " << getWidth() << " wide and " << getHeight() << " high." << endl;
	}
	
}

