#pragma once

#include <iostream>
#include "account.h"

// This node is used in our linked list of accounts in the linked list portion of homework 2. 
// The structure could have been included in the header file of the linked list itself, but this
// external linking is to show a simple example of creating a class from multiple distint files.

struct node
{
	account data;    // Holds the account information within the node. 
	                 // These include: account Id, account owner, and the curremt balance of the account.
	
	node* next;      // Node pointer to next node in the linked list

};