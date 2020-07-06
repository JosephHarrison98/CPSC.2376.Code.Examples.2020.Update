
#include <iostream>
#include <algorithm>
#include "Graph.h"
#include <queue>
using namespace std;
Graph::Graph()
{}

void Graph::addEdge(int vertex, int adjacentVertex)
{
	auto result1{ addVertex(vertex) };
	auto result2{ addVertex(adjacentVertex) };
	result1->adjacents.insert(result2);
	result2->adjacents.insert(result1);	
}

void Graph::BFS(int startNum)
{
	std::shared_ptr<Vertex> start{ *(std::find_if(vertices.begin(), vertices.end(),
		[=](std::shared_ptr<Vertex> currVertex)
		{
			return startNum == currVertex->num;
		})) };
	vector<std::shared_ptr<Vertex>> visited{ start };
	queue<std::shared_ptr<Vertex>> vQueue;
	vQueue.push(start);

	while (!vQueue.empty())
	{
		start = vQueue.front();
		cout << start->num << " ";
		vQueue.pop();

		for (auto vertex : start->adjacents)
		{
			//if not in visited
			if (auto haveVisited{ std::find(visited.begin(), visited.end(), vertex) };
				haveVisited == visited.end())
			{
				visited.push_back(vertex);//put in visited
				vQueue.push(vertex);//push on queue
			}
		}
	}
}

int Graph::numVertices() const
{
	return vertices.size();
}

std::shared_ptr<Vertex> Graph::addVertex(int vertexNum)
{
	if (auto resultIter{ std::find_if(vertices.begin(), vertices.end(),[&](std::shared_ptr<Vertex>& vertice)
		{
			return vertexNum == vertice->num;
		}) };
		resultIter == vertices.end())
	{
		vertices.push_back(std::make_shared<Vertex>(vertexNum));
		return vertices.back();
	}
	else
	{
		return *resultIter;
	}
		
}
void Graph::DFS(int startNum)
{
	std::shared_ptr<Vertex> start{ *(std::find_if(vertices.begin(), vertices.end(),
		[=](std::shared_ptr<Vertex> currVertex)
		{
			return startNum == currVertex->num;
		})) };
	vector<std::shared_ptr<Vertex>> visited;
	DFSRecursive(start, visited);
}



void Graph::DFSRecursive(std::shared_ptr<Vertex> start, std::vector<std::shared_ptr<Vertex>>& visited)
{

	

	/*
	pushes the starting vertex onto the visited vector.
	loops over all items in the adjacency list for the item just pushed
	If the adjacent vertex is not in the visited vector
		call DFSRecursive passing in the adjacent vertex for start...
	Just before the closing } output the value of the start vertex
*/
	// oh okay --
	visited.push_back(std::move(start));
	// i think sets just set the object data so if you do setValue(x); it will return x = p vlaue
	for (int i{ 0 }; i < visited.back()->adjacents/*at this point. */.size(); i++) // the error is this line
	{// maybe try that? it could work with the reference maybe... idk
		//ugh
		// ive got no clue... i clicked the C2227 error ... thats cool ive already copied the code we can meet back up later
		// ill leave this up for now. but i got to go. i will be afk
		if (visited.back->adjacents.at(i) == start) {
		

		}
		if (visited.back->adjacents.at(i) != start && i >= visited.back->adjacents.size()) {

			DFSRecursive(start,visited);// this feels dirty i know... it just doesnt feel right is all... go for it
			
		}
		
	}
//its all ok no errors ahh// so it seems weird to you. want me to test the code?

}




//we are in the right one