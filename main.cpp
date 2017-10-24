#include "game.h"
#include "heuristics.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){

    clock_t start, end;
    double msecs;

    start = clock();

    int V =  atoi(argv[1]);
    srand(time(NULL));

    // cout << "\nEnter the number corresponding to the algorithm to be chosen: " << "\n1. Dijkstra" << "\n2. Heuristic Search Algorithm" << endl;
    int n;
    LABEL:
    //cin >> n;
    n = atoi(argv[2]);
    if(n == 1){
    	int u, v, w, vertices, edges;
    	vertices = V;
    	//cout << vertices << endl;
    	game g(vertices);
    	edges = int(rand() % vertices);
    	if(edges == 0)
    		edges = 1;
    	//cout << "\n" << edges << "\n";
    	//cout << "\nEnter the vertex to vertex and weight : \n";
    	for(int i = 0; i < edges; i++){
    		u = int(rand() % (i + 1));
    		//cout << "u = " << u << endl;
    		v = int(rand() % vertices);
    		//cout << "v = " << u << endl;
    		w = int(rand() % 1000);
    		//cout << "w = " << u << endl;
        	g.insert_edge(u, v, w);
    	}

    	// g.insert_edge(0, 1, 4);
    	// g.insert_edge(0, 7, 8);
    	// g.insert_edge(1, 2, 8);
    	// g.insert_edge(1, 7, 11);
    	// g.insert_edge(2, 3, 7);
    	// g.insert_edge(2, 8, 2);
    	// g.insert_edge(2, 5, 4);
    	// g.insert_edge(3, 4, 9);
    	// g.insert_edge(3, 5, 14);
    	// g.insert_edge(4, 5, 10);
    	// g.insert_edge(5, 6, 2);
    	// g.insert_edge(6, 7, 1);
    	// g.insert_edge(6, 8, 6);
    	// g.insert_edge(7, 8, 7);

    	g.dijkstra(0, edges);
    }
    else if(n == 2){

    	int u, v, w, vertices, edges;
    	vertices = V;
    	//cout << vertices << endl;
    	modified m(vertices);
    	edges = int(rand() % vertices);
    	if(edges == 0)
    		edges = 1;
    	//cout << "\n" << edges << "\n";
    	//cout << "\nEnter the vertex to vertex and weight : \n";
    	for(int i = 0; i < edges; i++){
    		u = int(rand() % (i + 1));
    		//cout << "u = " << u << endl;
    		v = int(rand() % vertices);
    		//cout << "v = " << u << endl;
    		w = int(rand() % 1000);
    		//cout << "w = " << u << endl;
        	m.insert_edge_modified(u, v, w);
    	}

    	// m.insert_edge_modified(0, 1, 4);
    	// m.insert_edge_modified(0, 7, 8);
    	// m.insert_edge_modified(1, 2, 8);
    	// m.insert_edge_modified(1, 7, 11);
    	// m.insert_edge_modified(2, 3, 7);
    	// m.insert_edge_modified(2, 8, 2);
    	// m.insert_edge_modified(2, 5, 4);
    	// m.insert_edge_modified(3, 4, 9);
    	// m.insert_edge_modified(3, 5, 14);
    	// m.insert_edge_modified(4, 5, 10);
    	// m.insert_edge_modified(5, 6, 2);
    	// m.insert_edge_modified(6, 7, 1);
    	// m.insert_edge_modified(6, 8, 6);
    	// m.insert_edge_modified(7, 8, 7);

    	m.dijkstra_modified(0, edges);
    }
    else{
    	//cout << "\nIncorrect Number. Please try again : \n";
    	goto LABEL;
    }

    end = clock();

    msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;

    std::cout << msecs << std::endl;
    return 0;
}