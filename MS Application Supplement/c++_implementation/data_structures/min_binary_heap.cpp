#include "min_binary_heap.h"

void min_binary_heap::swap_place(int *a, int *b)
//Private function to swap the order of two nodes within the heap
{
	//Classical swap - use a temporary integer to swap the two values.

	int temp = *a;
	*a = *b;
	*b = temp;

}

void min_binary_heap:: create_min_heap(int max)
//Function to create a min heap of size n
{
	current_size = 0; //
	heap_max = max; //
	point = new int[max]; //Creates an array of integers the size of the min heap. Because this implementation of min heap assumes that there is a max we can
	                      //use an array to accomplish this task. However, if we wanted to improve functionality to allow for dynamic heap size, we could use
	                      //a vector (c++ dynamic array) instead.
}


int min_binary_heap::getmin()
//Function to return the minimum integer within a head
{
	return point[0];  //Returns the first integer in our min heap, which will be equal to the minimum value of the heap due to it's inherent properties
}

//----------------------------------------------------------------------

int min_binary_heap::parent_index(int test)
//Function to return the index of the parent to any node
{
	return (test - 1) / 2; //The parent of an index will be equal to (test-1) / 2. 
	                       //This is because a heap always fills left to right, and each vertex has only two child nodes (left and right).
						   //This also allows us to find the left and right vertex in the same level of the heap using the two equations below. 
}

int min_binary_heap::left_vert(int i)
// Function to return the index of the left vertex to any node
{
	return (2 * i) + 1;
}


int min_binary_heap::right_vert(int i)
// Function to return the index of the right vertex to any node
{
	return (2 * i) + 2;
}

//--------------------------------------------------------------------

void min_binary_heap::insert_vertex(int value)
// Function to insert a new vertex into the current heap
{
	if (current_size == heap_max) //Check to see if the heap is full. If it is, instead of overriding a value, we return a statement to the user
	{
		cout << "The heap is full" << endl;

		return;
	}

	point[current_size] = value; //Add in the new element to the point array, which is the array representation of our heap

	int index = current_size; //Create an index that will allow us to look at the last element in the heap


	while (index != 0 && point[parent_index(index)] > point[index]) //Ensure that the heapify property is satisfied. This means that that the parent of the inserted integer is less than the child
	{
		swap_place(&point[index], &point[parent_index(index)]); // Keep swapping the two integers in the current index positions so that the property is satisfied

		index = parent_index(index); // Update the current index being examined, so that the loop can keep checking through all of the vertices
	}

	current_size++; //Since a vertex has been inserted, we increment the size by 1. This is used as a reference to determine if the heap is full at the beginning of the function
	
}


void min_binary_heap::min_heapify(int i)
//Private function to restore the heap property
{
	int check = i; //Set the check value to the current vertex being examined
	
	//If the right vertex is greater than the array index, and the array is less
	//than the current number of vertices, we recursively call the function on the right vertex.
	

	if (point[right_vert(i)] < point[check] && right_vert(i) < current_size) 
		check = right_vert(i);

	// Using the same methodology, if the left vertex is less than the array index, and the array is less
	// than the current number of vertices, we recursively call the function on the left vertex.

	if (point[left_vert(i)] < point[check] && left_vert(i) < current_size)
		check = left_vert(i);

	// Finally if check is not equal to input i, then we swap the locations of the current integer i
	// and the check function. Due to the recursive calls above, this loop below first enters
	// we one has arrived at a leaf node, because the left or right vertex calls would not have been valid.
	// This will essentially bubble up the appropriate min to the 0th index position in the array

	if (check != i)
	{
		swap_place(&point[check], &point[i]);
		min_heapify(check);
	}
}


void min_binary_heap::remove_min()
// Function to remove the minimum integer from the head (first/top vertext in the heap)
{
	point[0] = point[current_size - 1]; //Since we are removing a vertex from the heap, we have to override the value. Normally we would first
										//have to search for the min value in a data structure if there is no order, but here, we know that the 
										//top of the head is the min. So, we override the min heap head value with the last value in the heap
	
	current_size--; //Decrease the current size of the heap


	min_heapify(0); //Call the minheapify function. This will sort the heap so that the min heap property is satisfied

}


void min_binary_heap::display()
// Function to display the current heap
{
	int i = 0;

	if (current_size == 0) //If the heap is empty, we return a print statement to allert the user
	{		cout << "The heap is currently empty" << endl;
	return;
	}

	for (i; i < current_size; i++) //For the number of vertices in the heap, print the value and position 
	{
		cout << point[i] << " is the value for position " << i+1 << " in the current heap" << endl;
	}

}
