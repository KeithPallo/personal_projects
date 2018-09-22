#pragma once
#include <iostream>
#include <climits>

// For simplicity, this implementation of a min heap assumes that the data type is an integer.  

//In order to achieve the complexity times stated on page 2 of homework 4, the heap is represented as an array.
//This implementation uses classical representation of a min heap in an array. An example is shown below where the value
//inside the brackets represents the index that would be represented in the array


//						(0)
//                       | 
//               (1)-----------(2)                  
//          (3)-- |--(4)   (5)--|--(6)
//
//


using namespace std;

class min_binary_heap
{
private:
	
	int heap_max; //Maximum number of vertices the heap can hold
	int current_size; // Current number of vertices in the heap
	int *point; //Utility pointer to an array that will hold the values for our min heap

	int parent_index(int i); //Function to return the index of the parent to any node
	int left_vert(int i); // Function to return the index of the left vertex to any node
	int right_vert(int i); // Function to return the index of the right vertex to any node
	
	void min_heapify(int i); //Private function to restore the heap property
	void swap_place(int *a, int *b); //Private function to swap the order of two nodes within the heap

public:

	void create_min_heap(int heap_max); //Function to create a min heap of size n
	int getmin(); //Function to return the minimum integer within a head
	void insert_vertex(int value); // Function to insert a new vertex into the current heap
	void remove_min(); // Function to remove the minimum integer from the head (first/top vertext in the min heap)
	void display(); // Function to display the current heap


};

