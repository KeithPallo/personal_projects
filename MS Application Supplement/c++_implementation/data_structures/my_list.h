#pragma once

#include <iostream>
#include "node.h"


//For simplicity, this header file contains all the information for the linked list structure / class.

class my_list {
private:

	// Create two pointers: Head and Tail
	node * head, *tail; 



public:
	my_list()
	{
		// Initialize both head and tail pointers to NULL
		head = NULL;
		tail = NULL;
	}



	void createnode(account value)
		// This function will add a new node to the end of the list
	{
		//Create a temporary new node. This temp node will become the last node in the list.
		node *temp = new node; 

		//Set the value of the new node to the desired data value
		temp->data = value; 

		// Set the pointer of the new node to null as we want the list to terminate
		temp->next = NULL; 

		// Check to see if the list is empty
		if (head == NULL) 
		{
			// If the list is empty, create the first node. Both the head and tail pointers 
			// will point to this single new node. The node itself, will point to NULL

			head = temp;
			tail = temp;
			temp = NULL;
		}

		// If the list is not empty, use the tail pointer to add our newly created temp node, and adjust accordingly
		else
		{   
			// Set the current "last nodes" pointer to point to the newly created temp node
			tail->next = temp; 

			// Set the current tail to point to the last node
			tail = temp;  
		}
	}



	void display()
		// This function will display all nodes in the current list
	{
		// Create a new temporary node
		node *temp = new node; 

		// Set the new node to the head node
		temp = head; 

		// Create a new account instance, to act as a "display" helper
		account current_account;

		// As long as the temp node is not at the end of the list"
		while (temp != NULL)
		{
			// Set the current_account to the account within the node
			current_account = temp->data;

			// Display the account information
			current_account.display();

			// Move the temp node to the next node in the linked list
			temp = temp->next; 

		}
	}



	void intert_start(account value)
		// This function will input a new node at the beginning of the list
	{
		
		//Create a new node
		node *temp = new node; 

		// Set the new node to contain the desired account data
		temp->data = value; 

		//Set the new node to point to the current head
		temp->next = head; 

		//Move the head pointer to point at the new node, which is the new head
		head = temp; 
	}



	void insert_position(int pos, account value)
		// This function inserts a node at a desired position in the current list.
		// The position value starts from position 1. 
		// Hence, if you insert a node at the the 2nd position, the node will come after the header node.
		// This function will not insert correctly at the beginning or the end of the list. User knowledge of this is assumed.
	{	
		// Three new nodes and pointers are created on the heap.

		// pre will be used to point the preceding node to temp
		node *pre = new node; 

		// cur will be used to point the new node to the next node in the list
		node *cur = new node; 

		// temp will be the newly inserted node
		node *temp = new node; 

		//Set cur to be the same as the head node using pointer head
		cur = head; 

		// Move the pre and cur until they are in the correct position. This means that pre should be pointing to 
		// the node that will come before our inserted node, and cur points to the node position it will take
		for (int i = 1; i<pos; i++) 
		{
			// pre moves one node over, to where current is
			pre = cur; 

			// current moves to the next node
			cur = cur->next;
		}

		// Now, cur is equal to the node we want to "push" in the list, and pre is equal to the node that will come before our
		// newly inserted node

		// Set the new nodes value to the desired account info
		temp->data = value;

		// Point the previous node to our new node
		pre->next = temp; 

		// Point the new node to the "current" node which will sit after our newly created node
		temp->next = cur; 

		// The new node is effectively inserted
	}

	void account_search(int i)
		// This function will search for an account id in the current linked list
	{
		//Create a new temporary node
		node *temp = new node; 

		//Set the temp node to the head node
		temp = head; 

		// Create a temporary account
		account current_account; 

		// Initialze a 0 integer
		int x = 0;


		// For all nodes in the list: 
		while (temp != NULL)
		{
			// Set the current account to the account being checked in the linked list
			current_account = temp->data; 

			// Check to see if the account id matches. If it does, print a statement letting the user
			// know the account information
			if (current_account.id == i)
			{
				cout << "The account information you were searching for is: " << endl;
				current_account.display();
				cout << endl;

				// Increment x to indicate the account  only if it has been found
				x ++;

			}

			// Move the temp node to the next node
			temp = temp->next; 

		

		}

		// If x is not incremented, this means the account was not found. Allert the user. 
		if (x == 0)
		{
			cout << "The account you were searching for is not in our records. Please check back with us at another time." << endl;
		}

	}
};

