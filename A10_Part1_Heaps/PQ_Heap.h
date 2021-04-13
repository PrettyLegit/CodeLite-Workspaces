// Name: Jimmy Nguyen
// Class: CS 3305
// Term: Spring 2021
// Instructor: Dr. Haddad
// Assignment: 10

#include "heap.h"
#ifndef PRIORITY_QUEUE_HEAP_H
#define PRIORITY_QUEUE_HEAP_H

template <class T>
class priority_queue_heap
{

public:
    priority_queue_heap()
    {
		
    }

    // Return true if priority queue is empty; otherwise return false
    bool is_empty() const;

    // Return true if priority queue is full; otherwise return false
    bool is_full() const;

    // Return (don't remove) the front element from the priority queue
    // Precondition: priority queue is not empty.
    T front();

    // return number of elements in the queue
    int size();

    // Remove the largest value from this priority queue and return it.
    // Precondition: priority queue is not empty.
    T dequeue();

    // Inserts the 'value' into the priority queue.
    // Precondition: priority queue is not full
    void enqueue(const T& value);

    void display_front();

    void print_elements();

private:
    heap<T> myHeap;
};

#include "PQ_Heap.template"

#endif // PRIORITY_QUEUE_HEAP_H
