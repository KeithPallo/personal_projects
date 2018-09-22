class edge(object):

    # This is an edge object in the disjoint set / union find data structure. It has three distinct measures:
    # An edge, a start vertex, and an end vertex. The vertex pointers refer to the vertices in the graph,
    # but one important characteristic is that they must be vertex objects. The reason for this is because
    # in the implementation of the Kruskal algorithm, we will use the edge to look to a specific vertex object
    # and call the find function on that vertex itself

    def __init__(self, weight, start_vect,end_vect):
        self.weight = weight
        self.start_vect = start_vect
        self.end_vect = end_vect

    # Override the str function to effectively print the edge if desired
    def __str__(self):
        return str(self.weight) + " " + str(self.start_vect) + " " + str(self.end_vect)

    # Here, override the compare function in python. The reason for this is so that we can sort the edges
    # in any edgelist, as the Kruskal algorithm must always look to add on vertices that have edges with the
    # lowest weight

    def __cmp__(self, other):
        return self.cmp(self.weight, other.weight)

    # Also override the less than function for the same reason - it will be used to compare edge weights

    def __lt__(self, other):
        self_weight = self.weight
        other_weight = other.weight

        return self_weight < other_weight

