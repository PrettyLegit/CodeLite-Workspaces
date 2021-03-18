// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 5

// FILE: node1_New.cxx
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.
#include "node1_New.h"
#include <cassert> // Provides assert
#include <cstdlib> // Provides NULL and size_t
#include <iostream>
using namespace std;

namespace main_savitch_5
{
size_t list_length(const node* head_ptr)
// Library facilities used: cstdlib
{
    const node* cursor;
    size_t answer;

    answer = 0;
    for(cursor = head_ptr; cursor != NULL; cursor = cursor->link()){
		++answer;
	}
		

    return answer;
}

void list_head_insert(node*& head_ptr, const node::value_type& entry)
{
    //     Precondition: head_ptr is the head pointer of a linked list.
    //     Postcondition: A new node containing the given entry has been added at
    //     the head of the linked list; head_ptr now points to the head of the new,
    //     longer linked list.
    head_ptr = new node(entry, head_ptr);
}

void list_insert(node* previous_ptr, const node::value_type& entry)
{
    //     Precondition: previous_ptr points to a node in a linked list.
    //     Postcondition: A new node containing the given entry has been added
    //     after the node that previous_ptr points to.
    node* insert_ptr;

    insert_ptr = new node(entry, previous_ptr->link());
    previous_ptr->set_link(insert_ptr);
}

node* list_search(node* head_ptr, const node::value_type& target)
// Library facilities used: cstdlib
{
    node* cursor;

    for(cursor = head_ptr; cursor != NULL; cursor = cursor->link()) {
	if(target == cursor->data()) {
	    return cursor;
	}
    }
    return NULL;
}

const node* list_search(const node* head_ptr, const node::value_type& target)
// Library facilities used: cstdlib
{
    const node* cursor;

    for(cursor = head_ptr; cursor != NULL; cursor = cursor->link()) {
	if(target == cursor->data()) {
	    return cursor;
	}
    }
    return NULL;
}

node* list_locate(node* head_ptr, size_t position)
// Library facilities used: cassert, cstdlib
{
    //     Precondition: head_ptr is the head pointer of a linked list, and
    //     position > 0.
    //     Postcondition: The pointer returned points to the node at the specified
    //     position in the list. (The head node is position 1, the next node is
    //     position 2, and so on). If there is no such position, then the null
    //     pointer is returned.
    node* cursor;
    size_t i;

    assert(0 < position);
    cursor = head_ptr;
    for(i = 1; (i < position) && (cursor != NULL); i++) {
	cursor = cursor->link();
    }
    return cursor;
}

const node* list_locate(const node* head_ptr, size_t position)
// Library facilities used: cassert, cstdlib
{
    //     Precondition: head_ptr is the head pointer of a linked list, and
    //     position > 0.
    //     Postcondition: The pointer returned points to the node at the specified
    //     position in the list. (The head node is position 1, the next node is
    //     position 2, and so on). If there is no such position, then the null
    //     pointer is returned.
    const node* cursor;
    size_t i;

    assert(0 < position);
    cursor = head_ptr;
    for(i = 1; (i < position) && (cursor != NULL); i++) {
	cursor = cursor->link();
    }
    return cursor;
}

void list_head_remove(node*& head_ptr)
{
    node* remove_ptr;

    if(head_ptr->link() != NULL) {
	remove_ptr = head_ptr;
	head_ptr = head_ptr->link();
	delete remove_ptr;
    }
}

void list_remove(node* previous_ptr)
{
    //     Precondition: previous_ptr points to a node in a linked list, and this
    //     is not the tail node of the list.
    //     Postcondition: The node after previous_ptr has been removed from the
    //     linked list.
    node* remove_ptr;

    remove_ptr = previous_ptr->link();
    previous_ptr->set_link(remove_ptr->link());
    delete remove_ptr;
}

void list_clear(node*& head_ptr)
// Library facilities used: cstdlib
{
    while(head_ptr != NULL) {
	list_head_remove(head_ptr);
    }
}

void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
// Library facilities used: cstdlib
{
    //     Precondition: source_ptr is the head pointer of a linked list.
    //     Postcondition: head_ptr and tail_ptr are the head and tail pointers for
    //     a new list that contains the same items as the list pointed to by
    //     source_ptr. The original list is unaltered.
    head_ptr = NULL;
    tail_ptr = NULL;

    // Handle the case of the empty list.
    if(source_ptr == NULL)
	return;

    // Make the head node for the newly created list, and put data in it.
    list_head_insert(head_ptr, source_ptr->data());
    tail_ptr = head_ptr;

    // Copy the rest of the nodes one at a time, adding at the tail of new list.
    source_ptr = source_ptr->link();
    while(source_ptr != NULL) {
	list_insert(tail_ptr, source_ptr->data());
	tail_ptr = tail_ptr->link();
	source_ptr = source_ptr->link();
    }
}

void delete_reps(node* newHead)
{
    node newGrades;

    node *head, *current, *dup;

    head = newHead;
    node* temp;

    /* Pick elements one by one */
    while((head != NULL) && (head->link() != NULL)) {

	current = head;

	/* Compare the picked element with rest
  of the elements */
	while(current->link() != NULL) {
	    /* If duplicate then delete it */
	    if(head->data() == ((current->link())->data())) {
		dup = current->link();
		temp = current->link();
		current->set_link(temp->link());
		delete(dup);
	    } else {
		current = current->link();
	    }
	}
	head = head->link();
    }
}

void sort_list(node* head_ptr)
{
    node* temp;
    node* head;
    node* current;
	node* value;
	
    head = head_ptr;
    while((head != NULL) && (head->link() != NULL)) {

	current = head;

	/* Compare the picked element with rest
  of the elements */
	while(current->link() != NULL) {

	    if(head_ptr->data() > ((current->link())->data())) {
		value = current->link();
		temp = current->link();
		current->set_link(temp->link());
		list_head_insert(temp, value->data());
	    } else {
		current = current->link();
	    }
	}
	head = head->link();
    }
}

void split_list(node* head_ptr, node* splitHead, node::value_type split_value)
{

    node* temp;
    node* head;
	node* head2;
    node* current;

    head = head_ptr;
    while((head != NULL) && (head->link() != NULL)) {

	current = head;

	/* Compare the picked element with rest
  of the elements */
	while(current->link() != NULL) {

	    if(current->data() == split_value) {
		
		head2 = current;
		
	    } 
	}
	current = head_ptr;
	while(current->link() != head2){
		current->link();
	}
	current->set_link(NULL);
    }
	splitHead = head2;
}
}