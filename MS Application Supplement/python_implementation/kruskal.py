from disjoint_set import disjoint_set;
from vertex import vertex;
from edge import edge;



def graph_mst(graph_current):
    # Helper function to create to create a vector object list and an edge object list to pass
    # into the Kruskal min spanning tree algorithm

    # Using the build in methods from the graph class, create the two lists
    vectors = graph_current.vector_list()
    edges = graph_current.edge_list_create(vectors)

    # Call the min spanning tree function with the newly created lists
    return min_spanning_tree(vectors,edges)

def min_spanning_tree(vertexlist,edgeList):
    # Function to find the minimum spanning tree from any vertex and edgelist using the Kruskal Algorithm

    # Create a new instance of a disjoint set based upon the vertexlist
    current_set = disjoint_set(vertexlist)

    # Create an empty list that will contain the minimum spanning tree
    mst = []

    # Sort the edgelist (capable because of method overrides)
    edgeList.sort()

    # Going from the least weighted edges to the largest execute the following:
    for edge in edgeList:

        # Initialize two new variables, which simply represent the two vertices in the edge
        start = edge.start_vect
        end = edge.end_vect

        # Using find, check to see if they are in the same set
        if current_set.find(start.parentNode) is not current_set.find(end.parentNode):

            # If not, add the edge to the edgelist
            mst.append(edge)

            # Merge the two corresponding sets, as they have been visited in the mst
            current_set.union(start.parentNode,end.parentNode)

    # Now, the mst is complete. Return the appropriate information to the user including a print statement
    # and the actual mst in list format

    print("The following are the edges in the minimum spanning tree in order that that the Kruskal algorithm "
          "added them.")

    for edge in mst:
        print(" Edge from ", edge.start_vect.name, " to ", edge.end_vect.name)

    return mst
