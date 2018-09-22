
#include <iostream>
#include "u_w_graph.h"



void u_w_graph::graph_size_p(main_list* cost_list)
// Private function to determine the size of the graph
{
	// Since this class uses the core_list to hold all of the edgelists the 
	// number of total vertices is simply equal to the length of the vert_list vector
	// We can easily use the built in template size function to determine the length

	cout << core_list->vert_list.size() << endl; 

}



void u_w_graph::graph_size()
// Public function to return the number of vertices in the current graph
{
	// Call the private version, passing in the current core_list
	// If one wanted to further support multiple graphs in this class, then they would have
	// to create a way for the user to access which "core_list" they would be passing in

	graph_size_p(core_list);
}



void u_w_graph::make_graph(int size)
// Public function to make a graph with n vertices. Initially, all of these vertices are not connected.
{
	// Create a new instance of main_list on the heap using function "new"
	// New must be used as this class is to "live" in memory as long as the 
	// class is created

	main_list* temp_list = new main_list;  

	// Resize the temporary list to indicate the desired amount of vertices
	temp_list->vert_list.resize(size); 

	// Point the core_list pointer to the newly created master_list instance
	core_list = temp_list; 

}



void u_w_graph::set_edge(int v_1, int v_2, int weight)
// Set an edge between two vertices
{
	// Create the appropriate edge for the first vertex.
	// Since this implementation uses a modified version of the adjacency list representation, 
	// edges must be added for both vertices that the user has input

	//First, update the information for vertex "v_1"

	//Check to see if the corresponding core_list index is empty
	if (core_list->vert_list[v_1] == NULL) 
	{
		// If it is empty, first create a new edgelist to hold the edges of this vertex

		//Create new edge_list and edge_list pointer temp
		edge_list *temp = new edge_list; 

		//Create a new edge and edge pointer temp_1
		edge *temp_1 = new edge; 

		// Set the edge parameters. Again, since the edge_lists position within the vertex list is going to determine the 
		//"home" or "from" vertex we only need to set one "pointer" value, which is the edge_graph

		temp_1->edge_graph = v_2; 
		temp_1->weight = weight;

		// Add the new edge to the edgelist
		temp->edges.push_back(*temp_1); 

		// Add the edgelist pointer to the vertexlist
		core_list->vert_list[v_1] = temp; 
	}

	else
	{
		// In this case, there is already an edgelist for the vertex v_1. In other words, there is at least one undirected path
		// to another vertex from v_1. So we do not need to create a new edgelist, but all other steps are the same

		// Create new edge
		edge *temp_2 = new edge; 

		// Set the appropiate direction of the edge
		temp_2->edge_graph = v_2; 

		// Set the appropriate weight
		temp_2->weight = weight; 

		// Add the edge to the current vertexlist (core_list)
		core_list->vert_list[v_1]->edges.push_back(*temp_2); 

	}

	// Apply the same methodology for the second vertex edge that must be added. 
	// All line breaks and comments have been removed to improve readability

	if (core_list->vert_list  [v_2] == NULL)
	{
		edge_list *temp2 = new edge_list;
		edge *temp_2 = new edge;
		temp_2->edge_graph = v_1;
		temp_2->weight = weight;
		temp2->edges.push_back(*temp_2);
		core_list->vert_list[v_2] = temp2;
	}
	else
	{
		edge *temp_2 = new edge;
		temp_2->edge_graph = v_1;
		temp_2->weight = weight;
		core_list->vert_list[v_1]->edges.push_back(*temp_2);
	}
}



int u_w_graph::find_edge(main_list* point, int v, int v_2)
// Private function to help with get_edge
{
	// Using points, return the appropriate weight. Order does not matter here
	// so only one weight must be accessed
	return point->vert_list[v]->edges[v_2].edge_graph; 

}


	
	void u_w_graph::get_edge(int v_1, int v_2)
	// Get the weight of an edge between two vertices
	{
		// Check to see if there is an edgelist for the matching index in our mainlist
		if (core_list->vert_list[v_1] == NULL) 
		{
			// Since there is no edgelist we know that an edge does not exist
			// Only need to check one edgelist because they each edge must be in both adjacency lists
			cout << "The edge does not exist." << endl; 
		 }

		else
		{
			// Define constants to be used in loops below
			unsigned int i = 0;
			int x = 0;
			bool test = true;

				// While loop allows iteration based on the side of the edgelist. 
				// Hence only check the edgelist if there are nodes present, and 
				// also only only check n number of times where n is the number of edges in the list

				while (i < core_list->vert_list[v_1]->edges.size()) 
				{
					// Checks to see if there is an edge for the appropriate two vertices
					if (core_list->vert_list[v_1]->edges[x].edge_graph == v_2) 
					{
						// Prints if there is such edge
						cout << "The weight of the edge is " << core_list->vert_list[v_1]->edges[x].weight << endl; 

						// Changes test boolean to false so the print statement below will not be shown
						test = false; 
					}
					
					// Iterators to ensure that the correct number of edges are being checked within the edgelist
					i++; 
					x++;
				}

				// Print statement if no edges are found between the two nodes
				if (test == true) 
				{ 
					cout << "The edge does not exist" << endl;
				}
		}
	}



	unsigned int* u_w_graph::get_adjacent(int v)
	// Get the adjacent vertices of an indicated vertex.
	{
		// Determines the size of the edgelist for the vertex that is input
		unsigned i = core_list->vert_list[v]->edges.size(); 

		// If the length is 0, then we return Null
		if (i == 0) 
		{
			return NULL;
		}

		else
		{
			// Create an empty array that is the size of the number of edges in the vertex on the heap
			unsigned* arr = new unsigned[i]; 

			// Initial print statement
			cout << "The vertices adjacent to this vertex are: " << endl; 

			// Initializes constant to append the appropriate number of integers to the array
			unsigned x = 0; 

				while (x < i)
				{
					// Check to see if the append value is a valid edge
					if (core_list->vert_list[v]->edges[x].edge_graph != v)
					{
						// Append the appropriate edge indicators to the array
						arr[x] = core_list->vert_list[v]->edges[x].edge_graph; 

						// Print statement to indicate the values in the array what will be returned
						cout << core_list->vert_list[v]->edges[x].edge_graph << " " << endl; 
					}
					x++;
				}

			return arr;
		}
		

	}

	

