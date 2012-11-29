#include "ListGraph.h"

using namespace std;


ListGraph::ListGraph(int numNodes) {
	edgeList.resize(numNodes);
	num_edges=0;
}

ListGraph::~ListGraph(){

}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {
	EList:: const_iterator it;
	bool switchOn=false;
	for(it=edgeList[u].begin(); it!=edgeList[u].end(); it++) {
		NWPair pair = (*it);
		if(pair.first==v) {
			pair.second=weight;
			switchOn=true;
		}
	}
	if(switchOn) {
		for(it=edgeList[v].begin(); it!=edgeList[v].end(); it++) {
		NWPair pair = (*it);
		if(pair.first==u) {
			pair.second=weight;
			switchOn=true;
		}
	}







}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const {
	// We went over how to do this method in class.
	EList:: const_iterator it;
	for(it=edgeList[u].begin(); it!=edgeList[u].end(); it++) {
		NWPair theEdge=*it;
		if(theEdge.first==v) {
			return theEdge.second;
		}
	}
	return 0.0;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const {

}

unsigned ListGraph::degree(NodeID u) const {

}

unsigned ListGraph::size() const {

}

unsigned ListGraph::numEdges() const{

}