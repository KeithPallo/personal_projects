from graph import graph
from kruskal import graph_mst
from disjoint_set import disjoint_set

# ----------------------------------------------------------------------------------------------------------------

# Homework 3 Start

print("Homework 3 start ----------------------------------------------------------------------------------------")
print()

# Created Files: graph.py

# First we create a graph. Since we have created graph 1 from the homework in C++ using the adjacency list
# representation, I will create graph 2 (right hand sight) of overview and run all relevant functions.

# Create a graph with the appropriate number of vertices
graph_2 = graph(6)

# Set all appropriate edges with the corresponding weights

graph_2.set_edge(0,1,5)
graph_2.set_edge(1,2,1)
graph_2.set_edge(1,3,1)
graph_2.set_edge(2,4,2)
graph_2.set_edge(2,5,7)
graph_2.set_edge(3,4,4)
graph_2.set_edge(3,5,6)


# Get the graphs size
print(" The size of graph_2 is " + str(graph_2.graph_size()))
print()

# Get the weight of a created edge
print(" The weight of the edge between vertices 2 and 5 of graph_2 is " + str(graph_2.get_edge(2,5)))
print()

# Get the weight of an edge that does not exist
print(" The weight of the edge between vertices 2 and 0 of graph_2 is " + str(graph_2.get_edge(2,0)))
print()

# Display all adjacent vertices for an example vertex. I have chosen vertex 2 given it's number of connections
print(" The adjacent vertices to vertex 2 in graph_2 are "  + str(graph_2.get_adjacent(2)))
print()

# Perform a depth first search on a vertex. I have provided 2 examples
print(" The vertices visited in a depth first search from vertex 0 are ")
graph_2.depth_first(0)
print()

print(" The vertices visited in a depth first search from vertex 3 are ")
graph_2.depth_first(3)
print()


# Homework 4 Start -----------------------------------------------------------------------------------------------

print("Homework 4 start ------------------------------------------------------------------------------------")
print()


# Created Files: vertex.py, edge.py, node.py, disjoint_set.py, and kruskal.py

# Part 1: Disjoint Set / Union Find Data Structure function testing

print("Union Find structure testing: ----------------------------------------------------------------------")
print()

# First, we will test the core functions created for the union find function. We will do so on a simple graph,
# shown below (it is the same as graph_1 from C++ graph implementation. We must first create a graph, and then
# pass in a vertex list to create a disjoint set representation.

#  (0) ---- 2 ----- (1)
#   |                |
#   5                3
#   |                |
#  (3)-----4 ------ (2)


graph_1 = graph(4)

graph_1.set_edge(0,1,2)
graph_1.set_edge(0,3,5)
graph_1.set_edge(1,2,3)
graph_1.set_edge(2,3,4)

# Now we create a disjoint set representation

graph_1_disjoint = disjoint_set(graph_1.vector_list())

print("The disjoint set from Graph 1 in the overview document has been created.")
print()


# Check to see that the size is correct intiially
print("Checking to see that the size of the graph is initially correct ")
print("The size of graph_1 is " +  str(graph_1_disjoint.get_size()))
print()

# We can print the root of vertex 1 in the current representation. Since it points to itself, it should point
# to 1. We do so by using the find function.


print("The initial starting root of vertex 1 is: " + str(graph_1_disjoint.find(graph_1_disjoint.roots[1])))
print()

# Check to see if two vertices are in the same set initially
print("Checking to see if vertices 0 and 1 are in the same set initially:")
graph_1_disjoint.same_set(0,1)
print()

# Now we will union vertices 0 and 1.

graph_1_disjoint.union(graph_1_disjoint.roots[0],graph_1_disjoint.roots[1])

# Check to see if they are in the same set

print("Checking to see if vertices 0 and 1 are in the same set after a union operation:")
graph_1_disjoint.same_set(0,1)
print()

# Check to see that the size is correct after performing a union
print("Checking to see that the size of the graph is constant after a union operation:")
print("The size of graph_1 is " +  str(graph_1_disjoint.get_size()))
print()


print("Kruskal algorithm testing-------------------------------------------------------------------------")
print("")

# I am using graph 3 as referenced in the overview document. The inspiration of this graph came
# from the Wikipedia page on Kruskal's algorithm. The solution references are provided on the page which
# is linked in the overview document. Alphabetical vertex names have been replaced with integers, with A starting
# as the 0th indexed vertex

# All edges added to create the mst will be printed when main.py is run in order that they were added.

graph_3 = graph(7)

graph_3.set_edge(0,1,7)
graph_3.set_edge(0,3,5)
graph_3.set_edge(1,2,8)
graph_3.set_edge(1,3,8)
graph_3.set_edge(1,4,7)
graph_3.set_edge(2,4,5)
graph_3.set_edge(3,4,15)
graph_3.set_edge(3,5,6)
graph_3.set_edge(4,5,8)
graph_3.set_edge(4,6,9)
graph_3.set_edge(5,6,11)



graph_mst(graph_3)


