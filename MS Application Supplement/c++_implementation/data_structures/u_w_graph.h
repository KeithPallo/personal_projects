#pragma once

#include <iostream>
#include <vector>

using namespace std;

// This graph represents an undirected weighted graph. In Homework 3, it is stated that the graph size does not need to change.
// However, I have laid out the foundations for a graph that would be dynamic in number of vertices. 
// I do so by using the built in vector template. I have completed this task to show my knowledge of utilizing 
// built in C++ templates. This representation of a graph would also allow you to have multiple graphs within
// one instance of the class. This would be useful if you wanted to have two distint "sets" of graphs.



class u_w_graph
{
private:

	// This edge represents an edge in the graph. The position within main_list will determine the "home" vertex. 
	// This can be accomplished because the user must input vertex indetities in the form of natural numbers.
	struct edge 
	{
		// Weight represents the weight of the undirected path in the graph to the next vertex
		int weight; 

		// edge_graph represents the edge that is connected to the "home" vertex. 
		// The "home" home vertex is determined by the index in the main_list
		int edge_graph; 
	};

	//This edge_list is a vector that contains edges
	struct edge_list 
	{
		vector<edge> edges; 
	};

	// This is the list where we store all of our pointers to different edge_list's. 
	// Hence, if a new edge_list were to be added, we could append it to our vert_list
	// effectively creating a new vertex in the graph. 
	struct main_list 
	{
		vector<edge_list*> vert_list;
	};


	//Create two edge pointers for usage in class functions
	
	// This "list" pointer will allow us to point to the main_list in the class. 
	// This holds our list of edgepointers, to our edge lists.
	main_list* core_list; 

	// This edge pointer is a utility pointer to allow us to look within each edge_list and determine associated information.
	edge* edge_point; 


	// Private function to determine the size of the graph
	void graph_size_p(main_list* cost_list); 

	// Private function to help with get_edge
	int find_edge(main_list*, int v, int v_2); 


public:
	
	// Public function to make a graph with n vertices. Initially, all of these vertices are not connected.
	void make_graph(int size); 

	// Public function to return the number of vertices in the current graph
	void graph_size(); 

	// Public function to set an edge between two vertices
	void set_edge(int v_1, int v_2, int weight);

	// Public function to get the weight of an edge between two vertices
	void get_edge(int v_1, int v_2); 

	// Public function to get the adjacent vertices of an indicated vertex.
	unsigned int* get_adjacent(int v); 
	
	// Depth first search has been implemented in python

};
