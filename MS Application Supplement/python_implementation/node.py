class node(object):

    # This node represents a node in the disjoint set / union find data structure.
    # The node has three distinct characteristics. The height, which could also be considered the rank
    # of the node. Initially this will be set to 0 in our implementation as all nodes are in separate sets.
    # The nodeId which is simply a reference to call the object. Finally, there is a parent node "pointer" of
    # sorts. This parent node identity determines which set the particular object is in. There may be only
    # one parent node for each set.


    def __init__(self, height, nodeId, parentNode):

        self.height = height
        self.nodeId = nodeId
        self.parentNode = parentNode

