#include "bst.h"
#include <iostream>


bst::bst()
{
	// Initialize the root of the binary search tree to NUll. 
	root = NULL; 
}



bst::node_bst* bst::newleaf(account data)
// Public function to add a new leaf to the current binary search tree
{
	// Create a new instance of a node and a node pointer on the heap using the new function.
	node_bst* temp = new node_bst;  

	// Point both left and right pointers to Null. Since we do not know where the new leaf will be added, 
	// this may change once it is added to the tree.

	temp->left = NULL; 
	temp->right = NULL;
	temp->data = data;

	return temp;
}



void bst::addleaf(account data)
// Public function to add a new leaf to the current binary search tree
{
	add_to_bst(data, root); //Pass in the current root and the account info that we would like to add to the tree.
}



void bst::add_to_bst(account data, node_bst* point)
// Function to add a new leaf onto the bst
{
	// Checks to see if the new leaf is the first one in the bst.
	if (root == NULL) 
	{
		// If there are no nodes, make the current new leaf the root of the tree. Notice, since we have initialized the 
		// left and right pointers to be null, we do not need to change them.
		root = newleaf(data); 

	}

	// Check to see if the account id of the passed in note is greater than the the current "point node"
	else if (data.id > point->data.id) 
	{
		// Check to see if the "point node" has a node to it's right
		if (point->right != NULL) 
		{
			// If it does, since the node we are trying to add is larger, we recusively call the function using the 
			// right node as the "point node"

			add_to_bst(data, point->right); 

			// This will allow us to keep looking down the right side of the tree, given that is larger than the current node.
		}

		// Since there is no node to the right of the current point node, we add the current leaf into the right position
		// of the point node. 
		else 
		{
			//The new node becomes the right leaf of the current "point node"
			point->right = newleaf(data);  
		}
	}


	// Perform the same actions as the above statements, however, this applies to if the new node "data" is less than 
	// the current point node.

	else if (data.id < point->data.id)
	{
		if (point->left != NULL)
		{
			add_to_bst(data, point->left);
		}
		else
		{
			point->left = newleaf(data);
		}
	}

	// Since we have checked to see if the account id is less than or greater than the current "point node" id, it must be equal.
	// Since all account id's must be unique in this structure, we return a print statement indicating that there is an error. 

	else
	{
		cout << "This is a duplicative account identity. We may need to check the records." << endl;

	}
}


void bst::node_search(account value)
// Public function to search for a particular node value, which in this case is an account
{
	// Create a new node pointer that will point to the node that we search for using perform_node_search
	node_bst* temp = perform_node_search(value, root);

	// If the node pointer is NULL, that means the account we were searching for was not in the current bst.
	if (temp == NULL)
	{
		// Alert the user that the account is not in the bst.
		cout << "The account you entered is not stored in the tree." << endl; 
	}

	
	// Otherwise, return the account information to the user who made the call
	else 
	{
		cout << "The account has the following information. The account owner is " << temp->data.owner << " and the balance in USD is: " << temp->data.balance << endl;
	}

	
}



bst::node_bst* bst::perform_node_search(account value, node_bst* point)
// Private function to search for a particular node value, which in this case is of account data type
{

	// Check to see if the tree is empty. If the tree is empty, we return NULL using the else statement below. 
	// Since the tree is empty, we know what the node we are searching for cannot possibly be in the bst. 

	if (point != NULL) 
		// If not empty, perform the following:
	{
		// Check to see if the current node that "point" is actually pointing to, has the account id we are searching for
		if (point->data.id == value.id) 
		{
			// If it does, return the node pointer "point"
			return point; 
		}

		// If not, we look down the tree
		else 
		{
			// Check to see if the id we are looking for is greater than the current node of point. 
			// If it is, then we traverse down the right side of the current node that "point" is pointing to.
			if (value.id > point->data.id) 
			{
				//Recursively call the function to traverse down the right side of the tree
				return perform_node_search(value, point->right); 
			}

			// If the code is still running at this point, the current account id is less than the pointer, sp
			// we traverse down the left side of the node using the recursive call below


			else
			{
				//Recursively call the function to traverse down the right side of the tree
				return perform_node_search(value, point->left);
			}
		}

	}

	// Null return associate with empty tree check
	else
	{
		return NULL;
	}
}




void bst::print_in_order()
// Public function to print the bst in order
{
	// Call the public function using the node pointer root. This will allow
	// us to search from the top of the tree, and traverse in order. 

	print_1_private(root); 


}




void bst::print_1_private(node_bst* point)
//Private function to print the current bst
{
	// First check to see if the root is NULL. If the root is NULL, 
	// that means the current tree is empty, and print an error statement shown in the else loop
	if (root != NULL) 
	{
		// Check to see if there is a left or right child of the current node. Then recursively call the print function
		// until the node pointer arrives at the node at the bottom left of the tree.

		//Order is important in these two statements. We call left first to traverse down to the most left leaf. 

		if (point->left != NULL) 
		{
			print_1_private(point->left);

		}

		
		
		//The location of this print statement is important. It means that there is no left node, 
		// so the leaf is printed. We can do this because of the structure of the bst. 
		point->data.display();  

		// Now traverse down the to the right by recursively calling the function.

		if (point->right != NULL)
		{
			print_1_private(point->right);
		}

	}

	// Return associated with empty tree check
	else
	{
		//Error statement to indicate to the user that there are no nodes in the current tree
		cout << "There are no accounts in this tree." << endl; 
	}

}


