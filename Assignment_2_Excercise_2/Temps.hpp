// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 2

#include <string>
#ifndef TEMPS_HPP
#define TEMPS_HPP

namespace Main_Temps{
	

class Temps
{
public:
	Temps();
	void setTemp(int i, double userInput);
	void Freezing();
	int Warmest();
	void printTemps();
	const int length = *(&dayArray + 1) - dayArray;
	const std::string dayName[7] = {"Monday", "Tuesday", "Wednesday", "Thrusday", "Friday", "Saturday", "Sunday"};
private:
	double dayArray[7];
	
};

}

#endif // TEMPS_HPP
