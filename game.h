#pragma once
#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <bits/stdc++.h>
#include <limits.h>
#include <stdlib.h>

class game{
private:
	int vertices, infinite;
	std::list< std::pair <int, int> > *adjList;
	std::vector<int> path;
public:
	game();
	game(int vertices);
	void insert_edge(int u, int v, int w);
	void dijkstra(int source, int destination);
};