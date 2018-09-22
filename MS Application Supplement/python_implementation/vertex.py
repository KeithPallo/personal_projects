# This is a vertex object for implementation in the disjoint set / union find data structure.
# It has two attributes - name and node. Node is simply the associated node object that is created
# in the disjoint set object sense.

class vertex(object):
    def __init__(self, name):
        self.name = name
        self.Node = None