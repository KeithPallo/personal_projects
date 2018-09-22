// Introduction:

// This main file contains all the relevant function calls for homeworks 1,2, 3 (in part), and 4.


#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <stdlib.h>
#include "bst.h"
#include "my_list.h"
#include "u_w_graph.h"
#include "min_binary_heap.h"



// Although not conventional when sharing files, for simplicity I have used std conventions throughout this file
using namespace std;



// Main function to run tests
int main(){
	
	//--------------------------------------------------------------------------------------------------------
	
	//Homework 1


	
	// Part 2 - Account Data Structure

	// Created files: account.h

	// Input the accounts outlines in the HW 1 Document.

	account Turing = { 0,"Alan Turing",16384};
	account Hopper = { 1,"Grace Hopper",32768};
	account Lovelace = { 2, "Ada Lovelace", 32 };
	account Parnas = { 3, "David Parnas", 2048 };
	account Liskov = { 4,"Barbara Liskov", 8192 };

	// Helper print statement
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << "Homework 1 Output:" << endl;
	cout << endl;


	// Display an example account: The example shown is Turing. 
	cout << "Testing of account display function:" << endl;
	Turing.display(); 
	cout << endl;

	// Credit an example account: The example shown is Turing. 
	cout << "Testing of account credit function. Turing will be credited 1000:" << endl;
	Turing.credit(1000);
	Turing.display();
	cout << endl;

	// Credit an example account: The example shown is Turing. 
	cout << "Testing of transfer function. Turing will transfer 1000 to Ada Lovelace:" << endl;
	cout << "First Ada Locelace's current account info is shown:" << endl;
	Lovelace.display();
	cout << endl;
	cout << "Ada Lovelace will now recieve 1000 from Turing. Both accounts are shown again below:" << endl;
	Turing.transfer(&Lovelace,1000);
	Lovelace.display();
	Turing.display();
	cout << endl;

	// Allows user to read outputs from H0omework 1 and continue upon action
	cout << endl;
	cout << "Enter any integer to continue to Homework 2 Outputs" << endl;
	cout << endl;
	int i;  
	cin >> i;
	cout << endl;
	cout << "---------------------------------------------------------------------------------------------------" << endl;



	//---------------------------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------------------------

	// Homework 2 Start

	// Helper print statement
	cout << "Homework 2 Output:" << endl;
	cout << endl;
	



	//---------------------------------------------------------------------------------------------------------

	// Part 1: Linked List


	// Created files: node.h, my_list.h 

	// Helper print statement

	cout << "Part 1 - Linked List Output:" << endl;
	cout << endl;

	// Create a new linked list object (specific to account data type)
	my_list linked_list_test; 

	// Add each of our accounts that were introduced in Homework 1 to the list
	linked_list_test.createnode(Turing);
	linked_list_test.createnode(Hopper);
	linked_list_test.createnode(Lovelace);
	linked_list_test.createnode(Parnas);
	linked_list_test.createnode(Liskov);

	// Display the current linked list
	cout << "This is the created linked list. Testing of display function:" << endl;
	linked_list_test.display(); 
	cout << endl;

	// Search the linked list
	cout << "Test search function for an account that is in the current linked list. Searching for account id 0:" << endl;
	linked_list_test.account_search(0);

	cout << "Test search function for an account that is not in the current linked list. Searching for account id 10:" << endl;
	linked_list_test.account_search(10);
	cout << endl;

	cout << "Test function to insert an account at a specified position. " << endl;
	cout << "Inserting at position 2 (after head) for account id 5, Clark Hinman. The new list in displayed:" << endl;
	account Hinman = { 5,"Clark Hinman", 1854 };
	linked_list_test.insert_position(2,Hinman);
	linked_list_test.display();
	cout << endl;

	// Allows user to examine outputs from part 1 from Homework 2.
	
	cout << endl;
	cout << "Enter any integer to continue to part 2 of Homework 2" << endl;
	cout << endl;
	cin >> i;
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	// --------------------------------------------------------------------------------------------------------------------

	cout << "Part 2 - Binary Search Tree Output:" << endl;

	// Part 2: Binary Search Tree


	// Created files: bst.h, bst.cpp

	// Create a new empty binary search tree
	bst first; 

	// Add leafs to the bst to test functionality
	first.addleaf(Turing);
	first.addleaf(Liskov);
	first.addleaf(Lovelace);
	cout << endl;

	// Print the bst
	cout << "This is the created binary search tree:" << endl;
	first.print_in_order();
	cout << endl;

	//Check to see if there is a duplicate account. In this case we will use Liskov
	cout << "Check to see if there is a duplicate account. Trying to add Liskov again: " << endl;
	first.addleaf(Liskov);
	cout << endl;

	//Search for two tpyes of nodes: One that is in the bst and one that is not. This demonstrates search functionality

	cout << "Searching for node that is in the tree. Searching for Liskov: " << endl;
	first.node_search(Liskov);
	cout << endl;
	
	cout << "Searching for node that is not in the tree. Searching for Parnas: " << endl;
	first.node_search(Parnas);
	cout << endl;

	// Allows user to examine outputs from part 2 from Homework 2.

	cout << endl;
	cout << "Enter any integer to continue to Homework 3" << endl;
	cout << endl;
	cin >> i;


	//--------------------------------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------------------


	//Homework 3 Start
 
	//Created files: u_w_graph.h, u_w_graph.cpp
	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << " Homework 3 Output:" << endl;
	cout << endl;

	// Create example Graph 1 from Homework 3
	u_w_graph first_graph;

	first_graph.make_graph(4);
	first_graph.set_edge(0, 1, 2);
	first_graph.set_edge(1, 2, 3);
	first_graph.set_edge(2, 3, 4);
	first_graph.set_edge(3, 0, 5);

	// Test created functions on Graph 1

	cout << "Graph 1 from Homework 3 has been created. Getting graph size: " << endl;
	first_graph.graph_size();
	cout << endl;

	cout << "Getting adjacents to vertex 3: " << endl;
	first_graph.get_adjacent(3);
	cout << endl;

	cout << "Getting edge weight between vertex 0 and vertex 3: " << endl;
	first_graph.get_edge(3, 0);
	cout << endl;

	// Depth First Search has been implemented in Python

	// Allows user to examine outputs from from Homework 3.

	cout << endl;
	cout << "Enter any integer to continue to Homework 4" << endl;
	cout << endl;
	cin >> i;

//----------------------------------------------

//Homework 4 Start

	//Created files: min_binary_heap.h, min_binary_heap.cpp

	cout << "---------------------------------------------------------------------------------------------------" << endl;
	cout << "Homework 4 Output:" << endl;
	cout << endl;

	// Create the min binary heap from the front page of HW 4. It is shown below:

	//                      (2)
	//                       |
	//                (3)---------(6)
	//				   |           |
	//             (7)---(5)   (8)---

	// Create min heap instance
	min_binary_heap heap;
	heap.create_min_heap(7);

	// Display the empty heap
	cout << "Test display function for empty heap:" << endl;
	heap.display();
	cout << endl;

	// Add in the values as stated above
	heap.insert_vertex(2);
	heap.insert_vertex(3);
	heap.insert_vertex(6);
	heap.insert_vertex(7);
	heap.insert_vertex(5);
	heap.insert_vertex(8);

	// Display the heap
	cout << "Integers were inserted into the heap. Retest display function for heap:" << endl;
	heap.display();
	cout << endl;

	// Test function to insert a new min

	cout << "Test insert function. An int value of 1 is inserted in the heap, and the heap is displayed:" << endl;
	heap.insert_vertex(1);
	heap.display();
	cout << endl;

	// Test adding an additional node, going beyond the max number of stored integers
	cout << "Test insert function for a full heap:" << endl;
	heap.insert_vertex(1);
	cout << endl;

	// Test removal of min
	cout << "Test remove min function for current heap. The min is removed and the heap is displayed:" << endl;
	heap.remove_min();
	heap.display();
	cout << endl;

	// End of this portion of the project!
	cout << "This is the end of the main script for the C++ portion of the data structure project." << endl;
	cout << "Move onto the Python segment to see additional solutions!" << endl;

 	cin >> i;



	return 0;


}