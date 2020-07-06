#ifndef GRAPH_H
#define GRAPH_H
#include <set>
#include <vector>
#include <memory>
struct Vertex
{
	Vertex(int num):num(num){}
	int num;
	std::set<std::shared_ptr<Vertex>> adjacents;
};
class Graph
{
public:
	Graph();

	void addEdge(int vertex, int adjacentVertex);

	void BFS(int startNum);
	void DFS(int start);
	
	int numVertices() const;
private:
	void DFSRecursive(std::shared_ptr<Vertex> start, std::vector<std::shared_ptr<Vertex>>& visited);
	std::shared_ptr<Vertex> addVertex(int vertexNum);
	std::vector<std::shared_ptr<Vertex>> vertices;
	std::vector<std::shared_ptr<Vertex>> visited;

};
#endif // !GRAPH_H

