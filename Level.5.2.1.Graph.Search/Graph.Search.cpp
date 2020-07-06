/*
Based on my Graph class from the code examples, write a Depth First Search method for the class.

Write a public starter method that passes in the value of the vertex to start at.:
void DFS(int start);
Find the starting vertex
create a visited vector:
vector<std::shared_ptr<Vertex>> visited;
call the helper function.
Write a recursive method that does the heavy lifitng:
void DFSRecursive(std::shared_ptr<Vertex> start, std::vector<std::shared_ptr<Vertex>>& visited);
 pushes the starting vertex onto the visited method.
loops over all items in the adjacency list for the item just pushed.
If the adjacent vertex is not in the visited vector
call DFSRecursive passing in the adjacent vertex for start...
Just before the closing } output the value of the start vertex
*/


#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
	Graph graph;
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 2);
	graph.addEdge(2, 3);
	/*3-2-0
		 \/
		  1*/

	cout << "Where do you want to start traversal from? (0 through " << graph.numVertices() - 1 << "): ";
	int start;
	cin >> start;
	graph.BFS(start);
	system("PAUSE");
	return 0;
}





