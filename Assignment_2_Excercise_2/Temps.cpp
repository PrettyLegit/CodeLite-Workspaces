// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 2

#include <cstdio>
#include <iostream>
#include <iomanip>
#include "Temps.hpp"
using namespace std;
namespace Main_Temps{
	
	Temps::Temps(){
		
	}
	
	void Temps::setTemp(int i, double userInput)
	{
		dayArray[i] = userInput;
	}
	
	void Temps::Freezing()
	{
		for(int i = 0; i < Temps::length; i++)
		{
			if(dayArray[i] < 32)
			{
				switch(i)
				{
					case 0:
						cout << left << setw(10) << dayName[i] << right << setw(10)<< dayArray[i] << endl;
						break;
					case 1:
						cout << left << setw(10) << dayName[i] << right << setw(10)<< dayArray[i] << endl;
						break;
					case 2:
						cout << left << setw(10) << dayName[i] << right << setw(10)<< dayArray[i] << endl;
						break;
					case 3:
						cout << left << setw(10) << dayName[i] << right << setw(10)<< dayArray[i] << endl;
						break;
					case 4:
						cout << left << setw(10) << dayName[i] << right << setw(10)<< dayArray[i] << endl;
						break;
					case 5:
						cout << left << setw(10) << dayName[i] << right << setw(10)<< dayArray[i] << endl;
						break;
					case 6:
						cout << left << setw(10) << dayName[i] << right << setw(10)<< dayArray[i] << endl;
						break;
				}
			}
		}
	}
	
	int Temps::Warmest()
	{
		double max = dayArray[0];
		int indexLocation = 0;
		for(int i = 0; i < Temps::length; i++)
		{
			if(dayArray[i] > max)
			{
				max = dayArray[i];
			}
		}
		return max;
	}
	
	void Temps::printTemps()
	{
		for(int i = 0; i < Temps::length; i++)
		{
			cout << left << setw(10) << dayName[i] << right << setw(10) << dayArray[i] << endl;
		}
	}
	
	
}

