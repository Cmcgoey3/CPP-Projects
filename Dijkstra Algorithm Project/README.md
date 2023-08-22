# Dijkstra's Single Source Shortest Path Project

## Author
Connor McGoey

## Description
This program implements the Dijkstra’s single source shortest path algorithm for a weighted directed
graph with non-negative weights using a heap data structure. It takes as input the name of a file containing graph information. 

An input graph file will be available. The format of the input file is the following:
1. The first line of the input file contains an integer, n, indicating the number of vertices
of the input graph.
2. Each of the remaining lines contains a triple ”i j w”, where 1 ≤ i, j ≤ n, indicating an
edge from vertex i to vertex j with cost w.
3. Vertex 1 is used as the source.

## To Run
To run the program, do not use the "<" operator, simply pass the name of the input file over to the python arguments.

For example:
python main.py infile

## Example Output
Example output can be found in the "programOutput.nice" file.