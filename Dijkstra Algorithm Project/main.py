"""
Name: Connor McGoey
Date: April 4, 2023
"""

import collections
import sys

"""
heap class for creating and modifying a min heap.
"""
class heap:
    # Constructor with element list parameter containing elements of the form [id,key] and size of heap n.
    def __init__(self, elements, n):
        self.size = 0
        self.heap = [[0,0]] * (n + 1)

        # call the insert method on all elements passed as parameter
        for element in elements:
            self.insert(element)

    # function to determine if an element ID exists in the heap or not
    def in_heap(self, elementID):
        for i in range(1, self.size + 1):
            element = self.heap[i]
            if element[0] == elementID:
                return True
        return False

    # function to determine whether or not the heap is empty
    def is_empty(self):
        return self.size == 0

    # function to determine if an element ID exists in the heap or not.
    def min_key(self):
        return self.heap[1][1]

    # function to return the id of the minimum element in the heap
    def min_id(self):
        return self.heap[1][0]

    # function to return the id of the minimum element in the heap
    def key(self, elementID):
        for i in range(1, self.size + 1):
            element = self.heap[i]
            if element[0] == elementID:
                return element[1]

    # helper function to determine whether or not a node at a position is a leaf node or not
    def is_leaf_node(self, position):
        return position * 2 > self.size

    # heapify function to turn a non-heap array into a heap. Called when updating a node's key.
    def heapify(self, position):
        if not self.is_leaf_node(position):
            if ((self.leftChild(position) <= self.size and (self.heap[position][1] > self.heap[self.leftChild(position)][1])) or
                (self.rightChild(position) <= self.size and (self.heap[position][1] > self.heap[self.rightChild(position)][1]))):

                if self.heap[self.leftChild(position)][1] < self.heap[self.rightChild(position)][1]:
                    self.swap(position, self.leftChild(position))
                    self.heapify(self.leftChild(position))
                else:
                    self.swap(position, self.rightChild(position))
                    self.heapify(self.rightChild(position))

    # function to delete and return the top node from the heap
    def delete_min(self):
        element = self.heap[1]
        self.heap[1] = self.heap[self.size]
        self.heap.pop()
        self.size -= 1
        self.heapify(1)
        return element

    # function to find a node with a given ID in the heap, and update its key. Then re-heapify the structure.
    def decrease_key(self, elementID, new_key):
        for i in range(1, self.size + 1):
            if self.heap[i][0] == elementID:
                if self.heap[i][1] <= new_key:
                    return

                self.heap[i][1] = new_key
                current = i
                while self.heap[current][1] < self.heap[self.parent(current)][1]:
                    self.swap(current, self.parent(current))
                    current = self.parent(current)

    # helper function to return the parent position of a node at a given position
    def parent(self, position):
        return position // 2

    # helper function to return the left child position of a node at a given position
    def leftChild(self, position):
        return position * 2

    # helper function to return the right child position of a node at a given position
    def rightChild(self, position):
        return (position * 2) + 1

    # helper function to swap two nodes at two positions in the heap
    def swap(self, pos1, pos2):
        self.heap[pos1], self.heap[pos2] = self.heap[pos2], self.heap[pos1]

    # helper function to insert a new node into the heap with bottom-up.
    def insert(self, element):
        self.size += 1
        self.heap[self.size] = element

        current = self.size
        while self.heap[current][1] < self.heap[self.parent(current)][1]:
            self.swap(current, self.parent(current))
            current = self.parent(current)

"""
Implementation of Dijkstra's algorithm using a min-heap to find shortest-distance paths from the
source (1). Reads the file's graph information, creates an adjacency list, and the shortest paths
and prints them both.

Parameter: name of the file containing graph information
Return: nothing
"""
def dijkstra(fileName):
    try:
        graphFile = open(fileName, 'r')
    except FileNotFoundError:
        print("No such file:", fileName)
        return

    # create and populate the graph information from the file including number of vertices and the adjacency list.
    adjacencyList = collections.defaultdict(list)
    numEdges = int(graphFile.readline())
    for line in graphFile:
        elements = line.split(" ")
        edge = []
        for element in elements:
            if element != " " and element != "":
                edge.append(int(element))
        adjacencyList[edge[0]].append([edge[1], edge[2]])

    # print the adjacency list in a format of (u -> v. Weight: w) where there is an edge from u to v with weight w
    print("-" * 10, "Adjacency List", "-" * 10)
    for vertex in adjacencyList.keys():
        for edge in adjacencyList[vertex]:
            print("{} -> {}. Weight: {}".format(vertex, edge[0], edge[1]))

    # populate the predecessor and distance dictionaries to be used in Dijkstra's
    distances = []
    distancesDict = {i: float('inf') for i in range(2, numEdges + 1)}
    distancesDict[1] = 0
    predecessors = dict()
    for i in range(1, numEdges + 1):
        if i == 1:
            distances.append([i, 0])
        if i != 1:
            distances.append([i, float('inf')])
        predecessors[i] = None

    # Create the heap, set, and finalEdges array to know the order of elements popped off.
    Q = heap(distances, numEdges)
    s = set()
    finalEdges = []

    # Dijkstra's algorithm as described in class using the min heap
    while not Q.is_empty():
        u = Q.min_id()
        Q.delete_min()
        s.add(u)
        finalEdges.append(u)
        for edge in adjacencyList[u]:
            v = edge[0]
            w = edge[1]
            if Q.in_heap(edge[0]):
                if distancesDict[v] > (distancesDict[u] + w):
                    distancesDict[v] = distancesDict[u] + w
                    predecessors[v] = u
                Q.decrease_key(v, distancesDict[v])

    # Print the shortest path tree edges from source node 1
    print("\n\n\n\n")
    print("-" * 10, "Shortest Path Tree Edges", "-" * 10)
    for u in finalEdges:
        if u == 1:
            print("(1, {}) : {}".format(u, distancesDict[u]))
        else:
            print("({}, {}) : {}".format(predecessors[u], u, distancesDict[u]))




"""
Main driver function to call the dijkstra function with the file name passed as a command line
parameter 
"""
if __name__ == '__main__':
    if len(sys.argv) > 1:
        dijkstra(sys.argv[1])



