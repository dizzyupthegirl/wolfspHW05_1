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
	
	// The first section checks to see if it's already in the list
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
			num_edges++;
			return;
		  }
		}
	}

	// The next section is for if it's not already in the list
	NWPair pair=std::make_pair(v,weight);
	edgeList[u].push_back(pair);
	pair.first = u;	
	edgeList[v].push_back(pair);
	num_edges++;

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
	return edgeList[u];

}

unsigned ListGraph::degree(NodeID u) const {

}

unsigned ListGraph::size() const {

}

unsigned ListGraph::numEdges() const{

}