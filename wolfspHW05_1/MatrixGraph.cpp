#include "MatrixGraph.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

MatrixGraph::MatrixGraph(unsigned num_nodes) {
	// Resizes matrix
	M.resize(num_nodes);
	for(int i=0; i<num_nodes; i++) {
		M[i].resize(num_nodes);
	}
	// Sets all values equal to -1
	for(int i=0; i<num_nodes; i++) {
		for(int k=0; k<num_nodes; k++) {
		 M[i][k]=-1;
		}
	}
	
}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {
	M[v][u]=weight;
	M[u][v]=weight;	
}
  

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	return M[u][v];
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	std::list<NWPair>* adj= new std::list<NWPair>;
	for(int i=0; i<M[u].size(); i++) {
		if(M[u][i]!=-1) {
			adj.push_back(std::make_pair(i, M[u][i]););
		
		}
	}			
}
unsigned MatrixGraph::degree(NodeID u) const{
}
unsigned MatrixGraph::size() const {
}
unsigned MatrixGraph::numEdges() const {
}