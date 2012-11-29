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
	// Sets all weights equal to -1
	for(int i=0; i<num_nodes; i++) {
		for(int k=0; k<num_nodes; k++) {
				M[i][k]=0;
			}
		}
	}
	
}

MatrixGraph::~MatrixGraph() {
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
			adj->push_back(std::make_pair(i, M[u][i]));
		
		}
	}	
	return *adj;
}

unsigned MatrixGraph::degree(NodeID u) const{
	return getAdj(u).size();
}

unsigned MatrixGraph::size() const {
	return M[0].size()*M[0].size();
}

unsigned MatrixGraph::numEdges() const {
	return num_edges;
}