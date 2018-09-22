from node import node


# This class is the implementation of the disjoint set / union find data structure
# In this implementation, three other classes are utilized: edge, vertex, and node

# Edges and vertices can be thought of in the undirected graph sense. Edge objects indicate a weighted edge
# between a start and an end vertex, although order does not matter since this in an undirected implementation.
# Vertices also have a node value, which points to corresponding node that has been created

# Nodes represent the classical disjoint set / union find element.

# One object that is not explicitly created is the set. A set is simply a collection of nodes. A distinct property
# of the set is that every node contained in the set only belongs to that set. So, for example, if a set has four
# nodes called "node_a", "node_b", "node_c" and "node_d" then these nodes cannot belong to another set. Hence,
# within a given universe of n nodes, there can be at maximum n sets, and at minimum 1 set. Nodes cannot be added
# or created to a disjoint set in this implementation.

class disjoint_set(object):

    # Define class variables

    def __init__(self, list_vertex):

        # A list that is created. Holds all the vertex objects in the current universe
        self.list_vertex = list_vertex

        # A list to hold all the current nodes
        self.roots = []

        # Variable to determine the number of nodes
        self.node_count = 0

        # Variable to keep track of the number of sets in the disjoint set
        self.setCount = 0

        # Call to function to initialize the creation of nodes
        self.makeSet(list_vertex)

        # Number of vertices from the graph input
        self.size = len(self.list_vertex)


    def makeSet(self,list_vertex):
        # Helper function to create the appropriate number of nodes in the disjoint set / union find

        # Create a node for each vertex in the current universe by calling the make_set function
        # passing in each individual vertex in the vertex list

        for v in list_vertex:
            self.make_set(v)


    def make_set(self,vertex):
        # Function to create all the  nodes in the disjoint set

        # At the beginning of the disjoint set / union find data structure all nodes are contained
        # in sets that are separate from each other. This means that the height is 0, and there is no parent node.
        # This accounts for the first and third inputs of the next line. We initialize the node id to be the same
        # number as the vertex. Hence, the node at index i of the roots list is the node for vertex i in the vertex list

        # Create a new node
        new_node = node(0,len(self.roots), None )

        # Point the current vertex to the node
        vertex.parentNode = new_node

        # Append the node to the roots list
        self.roots.append(new_node)

        # The set count and node counts are also increased by one, as each node is completely separate from each
        # other

        self.setCount += 1
        self.node_count += 1

    def find(self, node):
        # Function to find the set of any node. The node that is passed in will be referred to below as the "find node".

        # Initialize a new variable, current node
        current_node = node

        # Check to see if there is a parent node of the current node
        while current_node.parentNode is not None:
            # If there is, make the current_node the parent
            current_node = current_node.parentNode

        # The while loop allows us to set the current_node to the "highest" parent in the set

        # Create a new node called root_test, which is equal to the "current node" parent
        root_test = current_node

        # Reset the current_node to be the "find node"
        current_node = node

        # Note, if the "find node" had no parent then we would be creating a duplicate
        # of the "find node" when we create root_test. This would allow us to bypass the while loop below, and
        # the "find node would be returned because it would have been the only node it it's set

        # This next step is critical : it is the path compression. Essentially, what we do is traverse the
        # path from the current node to the root node, and change all parent nodes to the new set parent node
        # This means that all nodes above the one we are searching for with have a 1 step path to it's new
        # parent

        # Check to see if the the current node is the root node
        while current_node is not root_test:

            # Traverse "up" the node path, and set all parent nodes to be the root node

            # Create a temporary current node parent
            temp_node = current_node.parentNode

            # Set the current nodes parent to be the root
            current_node.parentNode = root_test

            # Reset the current node to be the temp node, which was the previous parent
            current_node = temp_node

        # Return the id of the root node
        return root_test.nodeId


    def union(self, node_1,node_2):
        # Function to union two separate sets together

        # First we check to see if the two nodes are in the same set
        # If they are, then we do not need to union the two nodes.

        # Create two indices that are the parent node indices for each of the input nodes
        index_1=self.find(node_1)
        index_2=self.find(node_2)

        if index_1 == index_2: return;

        # Create two node variables, that are equal to the associated nodes of the two root vertices

        root_1 = self.roots[index_1]
        root_2 = self.roots[index_2]

        # If root 2 has a larger height, make it the root node of the joined set
        if root_1.height < root_2.height:
            root_1.parentNode = root_2  # Set parent node

        # If root 1 has a larger height, make it the root node of the joined set
        elif root_1.height > root_2.height:
            root_2.parentNode = root_1  # Set parent node

        # If  heights are equal, just make root 1 the root node of the new joined set. This choice is arbitrary.
        else:
            root_2.parentNode = root_1  # Set parent node

            # Here we must actually increase the height. Because of path compression, this
            # essentially means that both parent nodes were either the only ones in their set, or, both had multiple
            # nodes of depth 1

            root_1.height +=1

        # Reduce the set count as two sets have been merged
        self.setCount -= 1

    def get_size(self):
        # Function to return the size, which was initialized in the setup variables
        return self.size


    def same_set(self,int_1,int_2):
        # Function to determine if two nodes are currently in the same set

        # Simply perform the same initial steps in union and return the appropriate information to the user
        node_1 = self.roots[int_1]
        node_2 = self.roots[int_2]

        index_2 = self.find(node_2)
        index_1 = self.find(node_1)

        if index_1 == index_2:
            print("The two vertices are in the same set")
            return

        print("The two vertices are not in the same set")