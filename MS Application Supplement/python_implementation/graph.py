from edge import edge # This import is used to create edges for the union find / disjoing set data structure.
from vertex import vertex

# For this implementation of the undirected graph data structure I have used the adjacency matrix representation.


class graph(object):

    # The graph has two attributes - the maximum number of vertices and the adjacency matrix
    # Within the adjacency matrix we will represent the weights of each edge with an integer
    # This implementation does use the built in list function within python, so we could in fact
    # built out the class further to add new vertices to the graph.

    # Using the input max size, create a size variable and the appropriate adjacency matrix
    def __init__(self, max_vert):
        self.max_vert = max_vert
        # Within the ad_matrix, a weight of 0 indicates that there is no edge between the two corresponding vertices
        self.ad_matrix = [[0 for x in range(max_vert)] for y in range(max_vert)]


    def graph_size(self):
        # Function returns the number of vertices in the graph

        # The length of the list will represent the number of vertices in the graph. Return the length.
        return len(self.ad_matrix)

    def set_edge(self,u,v,w):
        # Function to add a new edge to the graph

        # If the user inputs False, this indicates they want to remove an edge. Check to see if the input
        # is False. If so, set the associated adjacency matrix integers to 0
        if w == False:
            self.ad_matrix[u][v] = 0
            self.ad_matrix[v][u] = 0

        # If not, set both matrix elements to be the appropriate weight
        self.ad_matrix[u][v] = w
        self.ad_matrix[v][u] = w

    def get_adjacent(self,u):
        # Function to get all vertices adjacent to vertex u

        # Create a copy of the individual list (think of as row / column) for the associated vertex
        current_list = self.ad_matrix[u]
        return_list = []

        # Initilize variable for use in loop below
        x = 0

        # Append all indice values to the return list that have a corresponding edge weight greater than 0, indicating
        # that there is an edge between the two vertices
        while x < len(current_list):
            if current_list[x] > 0:
                return_list.append(x)
            x +=1

        # Return a list containing integers which indicate all the edges that are connected to the input vertex
        return return_list




    def get_edge(self,u,v):
        # Function to return the edge weight between two vertices

        # Check to see if there is a corresponding edge in the graph. This means that there will be a weight
        # of greater than 0 in the corresponding adjacency matrix value. If there is a weight greater than 0,
        # the return statement following the if statement returns the integer value

        if self.ad_matrix[u][v] == 0:
            return False

        return self.ad_matrix[u][v]



    def depth_first(self, start):
        # Helper function to initiate a depth first search

        # Create a 1 dimensional list that has all False values with the number of elements being equal
        # to the number of vertices in the graph. These False values indicate that  the vertex corresponding
        # to the index has not been visited in our search function

        search_list = len(self.ad_matrix) * [False]

        # Pass in the start vertex and the search_list to the dfs execute function

        self.dfs_execute(start,search_list)





    def dfs_execute(self,start,search_list):
        # Function to execute a depth first search on the graph

        # Mark the search list index corresponding to this vertex as visited by setting the boolean value to True
        search_list[start] = True

        # Print statement to show which vertex was visited in this current iteration of the function
        print(start)

        # Check to see if each of the vertices adjacent to the current start vertex are visited. Do so
        # by using the get_adjacent function which will allow us to only check the adjacent vertices for the
        # current vertex that is being searched

        for i in self.get_adjacent(start):

            if search_list[i] == False:

                # If the vertex in question is not visited, recursively call the
                # dfs execute function to visit it. This is the key to the depth first approach.

                self.dfs_execute(i,search_list)




    def vector_list(self):
        # This is a helper function to run the Kruskal algorithm. It creates a list of "vertex" objects
        # in the disjoint set sense. The number of "vertex" objects is equivalent to the number of
        # simple vertices in the graph class, as referenced above. This list will also be used to create
        # an associated edgelist which will hold edge objects which represent the graph structure

        # Create an empty list to hold the vertex objects to be created
        vertexlist = []

        # Initialize a constant for loop below
        i = 0

        # Create n number of vertices, with each named vertex_i for reference.
        # The location in the list will determine the actual edges, but this is useful for the user
        # to understand and reference back to

        while i < self.max_vert:
            new_vector = vertex(("vertex_" + str(i)))
            vertexlist.append(new_vector)
            i += 1

        # Return the newly created edgelist
        return vertexlist





    def edge_list_create(self,vectorlist):
        # This is a helper function to run the Kruskal algorithm. It creates edge objects from the adjacency
        # matrix of the graph. These edge objects hold the weight of each edge, along with pointer to their start
        # and ending vector objects.
        #
        # Since the graph is undirected, the actual order of these vectors is not important. However,
        # if one wanted to apply another algorithmic approach to finding a minimum spanning tree within a graph
        # this could be useful.

        # Initialize an empty list
        edgelist = []

        # Create a copy of the adjacency matrix dimensions with a False boolean in all positions.
        # This matrix will be used to ensure that duplicate edges are not added to our edgelist. This is
        # useful for the Kruskal algorithm as we can override the standard compare function (cmp) to
        # sort the edgelist, and since it will have no duplicates, we can sort it without having to do
        # any additional steps
        edge_check = [[False for x in range(self.max_vert)] for y in range(self.max_vert)];

        # Initialize integer for looping
        i = 0

        # For each vertex in the simple graph do the following:
        while i < self.max_vert:

            # Get a list of adjacent vertices
            for x in self.get_adjacent(i):

                # Check to see if the edge has already been added
                if edge_check[i][x] == False:

                    # If it has not, create a new edge and add it to the edge list
                    new_edge = edge(self.ad_matrix[i][x],vectorlist[i],vectorlist[x])
                    edgelist.append(new_edge)

                    # Mark both edges in the matrix as true, so a duplicate will not be added
                    edge_check[i][x] == True
                    edge_check[x][i] == True

            # Increase constant i to move onto the next position in the main adjacency matrix
            i +=1

        # Return the created edgelist that has no duplicate edge objects
        return edgelist

