#pragma once
#include "game.h"

struct modified{
	modified(int vertices);

	int vertices, infinite;
	std::list< std::pair <int, int> > *adjList;
	std::vector<int> path;

	void insert_edge_modified(int u, int v, int w);
	int heuristic(int a, int b);
	void dijkstra_modified(int source, int destination);
};