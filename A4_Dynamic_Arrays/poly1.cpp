// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 4
#include "poly1.h"
#include <algorithm>     //this allows for a deep copy of an array
#include <bits/stdc++.h> //this allows us to use exponent
#include <stdio.h>
using namespace std;
namespace main_savitch_3
{

polynomial::polynomial()
{
    //     POSTCONDITION: This polynomial has been created with all zero
    //     coefficients.
    coefPtr = new double[current_array_size];
    for(int i = 0; i < current_array_size; i++) {
	assign_coef(0, i);
    }
}

polynomial::polynomial(double a0)
{
    coefPtr = new double[current_array_size];
    assign_coef(a0, 0);
    for(int i = 1; i < current_array_size; i++) {
	coefPtr[i] = 0;
    }
}

polynomial::polynomial(const polynomial& source)
{
    //     POSTCONDITION: This polynomial has been created as a copy of the source.
    coefPtr = new double[source.current_array_size];
    current_array_size = source.current_array_size;
    // using copy, if this doesnt work we will use a for loop
    copy(source.coefPtr, source.coefPtr + current_array_size, coefPtr);
}
polynomial::~polynomial()
{
    //     POSTCONDITION: This polynomial has been deleted from memeory.
    delete[] coefPtr;
    current_array_size = 0;
}

void polynomial::add_to_coef(double amount, unsigned int k)
{
    //     POSTCONDITION: Adds the given amount to the coefficient of the
    //     specified exponent k.
    coefPtr[k] += amount;
}

void polynomial::assign_coef(double coefficient, unsigned int k)
{
    //     POSTCONDITION: Sets the coefficient for the specified exponent k.
    coefPtr[k] = coefficient;
}

void polynomial::clear()
{
    //     void clear( )
    //     POSTCONDITION: All coefficients of this polynomial are set to zero.
    for(size_t i = 0; i < current_array_size; i++) {
	coefPtr[i] = 0;
    }
}

void polynomial::reserve(size_t number)
{
    //     POSTCONDITION: The size of the array for coefficients has been changed to
    //     the requested number (but not less that the size needed to store the
    //     current non-zero coefficients). In effect, this guarantees that member
    //     functions will not need to allocate new memory for exponents through
    //     at least number-1.

    double* larger_array;

    if(number == current_array_size) {
	return; // the allocated memory is already the right size
    }

    if(number < current_array_size) {
	number = current_array_size; // can't allocate less than we are using
    }

    larger_array = new double[number];
    copy(coefPtr, coefPtr + current_array_size, larger_array);
    delete[] coefPtr;
    coefPtr = larger_array;
    current_array_size = number;
}
// MODIFICATION OPERATORS
polynomial& polynomial::operator=(const polynomial& source)
{
    //     POSTCONDITION: This polynomial is exactly the same as the
    //     parameter. The return value is a reference to this polynomial.
    if(this == &source) {
	return *this;
    }

    else {
	delete[] coefPtr;
	coefPtr = new double[source.current_array_size];
	current_array_size = source.current_array_size;
	for(int i = 0; i < current_array_size; i++) {
	    coefPtr[i] = source.coefPtr[i];
	}
    }
    // lowkey might not be done
    return *this;
}

// CONSTANT MEMBER FUNCTIONS
double polynomial::coefficient(unsigned int k) const
{
    //   double coefficient(unsigned int k) const
    //     POSTCONDITION: Returns coefficient at specified exponent k.
    //    if(k <= current_array_size) {
    //	return coefPtr[k];
    //    } else {
    //	return coefPtr[k - 1];
    //    }

    if(k > current_array_size - 1) {
	return 0;
    } else {
	return coefPtr[k];
    }
}
unsigned int polynomial::degree() const
{
    //     POSTCONDITION: The function returns the value of the largest exponent
    //     with a non-zero coefficient.
    //     If all coefficients are zero, then the function returns zero.
    //    if(coefPtr[current_array_size] == 0) {
    //	return 0;
    //    } else {
    //	return current_array_size;
    //    }
    // cout << "current array size" << current_array_size << endl;
    int largest_exponent = 0;

    for(int i = 0; i < current_array_size; i++) {
	if(coefPtr[i] != 0) {
	    largest_exponent = i;
	}
    }

    return largest_exponent;
}

unsigned int polynomial::next_term(unsigned int k) const
{
    //     POSTCONDITION: The function returns the exponent of the next term
    //     with a non-zero coefficient after specified exponent k.

    if(k > current_array_size) {
	return 0;
    }

    for(int i = k; i < current_array_size; i++) {
	if(coefPtr[i] != 0) {
	    k = i;
	}
    }
    return k;
}
// EVALUATION MEMBER FUNCTIONS
double polynomial::eval(double x) const
{
    //     POSTCONDITION: The return value is the value of this polynomial with the
    //     given value for the variable x.
    double answer;

    for(size_t k = 0; k < current_array_size; k++) {
	answer += coefPtr[k] * (pow(x, k));
    }
    return answer;
}

// NON-MEMBER BINARY OPERATORS

/*NOTE from Student:
 * I believe the code could've been better in this section: NON-MEMBER BINARY OPERATORS
 * because i notice that i am checking if one objects degree is less than, greater than, equal to
 * in order to prevent the pointer in the for loop to look at some illegal value
 * i did try setting polynomial object with the lower degree to have the same degree as the bigger one
 * it makes sense because all you would do is add together 0.
 * but i could not access the reserve function to try and impletment this. I would be cool to know if
 * you know of a better impletmentation over office hours.
 * */
polynomial operator+(const polynomial& p1, const polynomial& p2)
{
    //     POSTCONDITION: return-value is a polynomial with each coefficient
    //     equal the sum of the coefficients of p1 & p2 for any given
    //     exponent.
    int size1 = p1.degree();
    int size2 = p2.degree();
    if(size1 > size2) {
	polynomial answer(p1);
	for(int i = 0; i < size1 + 1; i++) {
	    answer.add_to_coef(p2.coefficient(i), i);
	}
	return answer;
    }

    else if(size2 > size1) {
	polynomial answer(p2);
	for(int i = 0; i < size2 + 1; i++) {
	    answer.add_to_coef(p1.coefficient(i), i);
	}
	return answer;
    }

    else {
	polynomial answer(p1);
	for(int i = 0; i < size1 + 1; i++) {
	    answer.add_to_coef(p2.coefficient(i), i);
	}
	return answer;
    }
}

polynomial operator-(const polynomial& p1, const polynomial& p2)
{
    //     POSTCONDITION: return-value is a polynomial with each coefficient
    //     equal the difference of the coefficients of p1 & p2 for any given
    //     exponent.
    int size1 = p1.degree();
    int size2 = p2.degree();
    if(size1 > size2) {
	polynomial answer(p1);
	for(int i = 0; i < size1 + 1; i++) {
	    answer.add_to_coef(-(p2.coefficient(i)), i);
	}
	return answer;
    }

    else if(size2 > size1) {
	polynomial answer(p2);
	int number = 0;
	for(int i = 0; i < size1 + 1; i++) {
	    number = p1.coefficient(i) - p2.coefficient(i);
	    answer.assign_coef(number, i);
	}
	for(int i = size1 + 1; i < size2 + 2; i++) {
	    number = -1 * (answer.coefficient(i));
	    answer.assign_coef(number, i);
	}
	return answer;
    }

    else {
	polynomial answer(p1);
	for(int i = 0; i < size1 + 1; i++) {
	    answer.add_to_coef(-(p2.coefficient(i)), i);
	}
	return answer;
    }
}
}
