// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 3
#include "sequence1.h"
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#pragma
using namespace std;
using namespace main_savitch_3;

typedef double value_type;
typedef size_t size_type;

static const size_type CAPACITY = 30;

sequence::sequence()
{
    current_index = 0; // starts at 0
    used = 0;
    itemTrue = false;
}

void sequence::start()
{
    // this prevents them from printing when you are not using the sequence to hold values
    if(used <= 0) {
	itemTrue = false;
	cout << "\n***There is no data***\n" << endl;
    } else {
	itemTrue = true;
    }

    current_index = 0;
}

void sequence::advance()
{
    // Precondition: is_item returns true.
    // Postcondition: If the current item was already the last item in the
    // sequence, then there is no longer any current item. Otherwise, the new
    // current item is the item immediately after the original current item.
    //cout << itemTrue << endl;
    // system("pause");
    // assert(is_item());
    if(is_item()) {
		if(used <= current_index + 1) {
			itemTrue = false;
		} else {
			current_index++;
		}
    }else{
		cout << "\n***There is no data***\n" << endl;
	}
}

void sequence::insert(const value_type& entry)
{
    //     Precondition: size( ) < CAPACITY.
    //     Postcondition: A new copy of entry has been inserted in the sequence
    //     before the current item. If there was no current item, then the new entry
    //     has been inserted at the front of the sequence. In either case, the newly
    //     inserted item is now the current item of the sequence.

    assert(used < CAPACITY);
    if(!is_item()) {
	current_index = 0;
    }
    used++;

    for(size_type i = used; i > current_index; i--) {
	data[i] = data[i - 1];
    }

    data[current_index] = entry;
    itemTrue = true;
}

void sequence::attach(const value_type& entry)
{
    // Precondition: size( ) < CAPACITY.
    // Postcondition: A new copy of entry has been inserted in the sequence after
    // the current item. If there was no current item, then the new entry has
    // been attached to the end of the sequence. In either case, the newly
    // inserted item is now the current item of the sequence.
    // Precondition: size( ) < CAPACITY

    assert(used < CAPACITY);
    if(!itemTrue) {
	current_index = used;
	data[current_index] = entry;
	used++;

	// cout << itemTrue <<endl;
    }

    else {
	used++;
	current_index++;
	for(size_type i = used; i > current_index; i--) {
	    data[i] = data[i - 1];
	}
	data[current_index] = entry;
    }

    itemTrue = true;
}

void sequence::remove_current()
{
    // Precondition: is_item returns true.
    // Postcondition: The current item has been removed from the sequence, and the
    // item after this (if there is one) is now the new current item.
    //
    // This function is allowed to only set itemTruth to FALSE!

    assert(itemTrue);
    for(size_type i = current_index; i < used; i++) {
	data[i] = data[i + 1];
    }
    used--;
    if(used <= current_index) {
	itemTrue = false;
    }
}

sequence::value_type sequence::current() const
{
    return data[current_index];
}

sequence::size_type sequence::size() const
{
    return used;
}

bool sequence::is_item() const
{
    //     Postcondition: A true return value indicates that there is a valid
    //     "current" item that may be retrieved by activating the current
    //     member function (listed below). A false return value indicates that
    //     there is no valid current item.
    return itemTrue;
}
