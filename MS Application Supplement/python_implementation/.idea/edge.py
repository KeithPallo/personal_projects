class edge(object):

    def __init__(self, weight, start_vect,end_vect):
        self.height = weight;
        self.start_vect = start_vect;
        self.end_vect = end_vect;


    def __cmp__(self, other):
        return self.cmp(self.weight, other.weight);

    def __lt__(self, other):
        self_weight = self.weight
        other_weight = other.weight

        return self_weight < other_weight;
