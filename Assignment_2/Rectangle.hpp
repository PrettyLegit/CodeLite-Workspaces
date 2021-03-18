// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 2

#include <string>
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

namespace Main_Rectangle
{

class Rectangle
{
	public:
	//CONSTRUCTORS
	Rectangle();
	Rectangle(double width, double height);
	
	//MODIFICATION MEMBER FUNCTIONS
	double const getArea()
	{
		return (width * height);
	}
	
	double const getPerimeter()
	{
		return (width + height) * 2;
	}
	
	void printRectangle(std::string objectName);
	//CONSTANT MEMBER FUNCTIONS 
	double getWidth() const{
		return width;
	}
	
	double getHeight() const{
		return height;
	}
	
	private:
		double width;
		double height;

};

}

#endif // RECTANGLE_HPP
