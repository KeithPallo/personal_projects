#pragma once

#include <iostream>
#include "account.h" // Include the account class from Homework 1.

using namespace std;

class bst
{
private: 
	
	// Construction of the node within this version of a binary search tree. 
	// Within this case, the node data is the account information from Homework 1.

	struct node_bst
	{
		account data;
		node_bst* left;
		node_bst* right;

	};

	// Create two pointers that will be used in the implementation of the binary search tree

	// Node pointer root node
	node_bst *root;

	// Node pointer to node newleaf
	node_bst* newleaf(account data); 

	// Function to add a new leaf onto the bst
	void add_to_bst(account data, node_bst* point); 

	// Private function to search for a particular node value, which in this case is an account
	node_bst* perform_node_search(account value, node_bst* point); 

	// Private function to print the current bst
	void print_1_private(node_bst* point); 

public:

	bst();

	// Since we do not want to pass the node pointer type to the main script, I have created public functions 
	// that call their private counter parts. These functions do however require that the user knows the 
	// account data type - as they will be adding them into the current bst. 

	// Public function to add a new leaf to the current binary search tree
	void addleaf(account value); 
	
	// Public function to search for a particular node value, which in this case is an account
	void node_search(account value); 

	//Public function to print the bst in order
	void print_in_order();
	
						   

	
	
	
};

