#include "game.h"

using namespace std;

game::game(){}

game::game(int vertices){
	this->vertices = vertices;
	adjList = new list< pair <int, int> >[vertices];
	infinite = INT_MAX;
}

void game::insert_edge(int u, int v, int w){
	adjList[u].push_back(make_pair(v, w));
	adjList[v].push_back(make_pair(u, w));
}

void game::dijkstra(int source, int destination){
	int dest = destination;
	set< pair< int, int> > setds;
	vector<int> distance(vertices, infinite);

	setds.insert(make_pair(0, source));
	distance[source] = 0;
	path.push_back(source);

	while(!setds.empty()){
		pair< int, int> temp = (*setds.begin());
		setds.erase(setds.begin());

		int u = temp.second;
		list< pair< int, int> >::iterator itr;

		for(itr = adjList[u].begin(); itr != adjList[u].end(); itr++){
			int v = (*itr).first;
			int weight = (*itr).second;

			if(distance[v] > distance[u] + weight){
				if(distance[v] != infinite){
					setds.erase(setds.find(make_pair(distance[v], v)));
				}
				distance[v] = distance[u] + weight;
				setds.insert(make_pair(distance[v], v));
				path.push_back(v);
			}
		}
	}
	//cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < vertices; ++i){
    	//cout << i << "\t\t" << distance[i] << "\n";
    }
    for (int i = 0; i < path.size(); ++i){
    	//cout << path[i] << " ";
    	if(path[i] == dest)
    		break;
    }
    //cout << endl;
    //cout << source << "->" << dest << ":  " << distance[dest] << endl << endl;
}