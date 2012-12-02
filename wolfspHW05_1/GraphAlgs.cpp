#include "GraphAlgs.h"
#include "Graph.h"
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>




pair<vector<NodeID>, EdgeWeight>  TSP(Graph* G) {

	
	vector<NodeID> currentPath;
	vector<NodeID> bestPath;
	EdgeWeight edgeWeight = 0;
	EdgeWeight bestWeight = DBL_MAX;
	list<NWPair> openList;
	list<NWPair>::iterator it;
	int size;

	/// 
	for (int i = 0; i < G->size(); i++)
		currentPath.push_back(i);
	size = G->size();

	for (int i = 0; i < factorial(size-1); i++) {
		edgeWeight = G->weight(0, currentPath[0]);
		for (int j = 0; j < size-1; j++) {
			if (edgeWeight > bestWeight)
				//Originally had return here, but apparently that's not ok. Must be break
				//Cite: Jake Gregg
				break;
			else {
				if (j == size-2)
					edgeWeight += G->weight(0, currentPath.at(j));
				else 
					edgeWeight += G->weight(currentPath.at(j+1), currentPath.at(j));
			}
		}

		if (edgeWeight < bestWeight) {
			bestWeight = edgeWeight;
			bestPath = currentPath;
		}
		// Cite: Jake Gregg
		next_permutation(currentPath.begin(), currentPath.end());

		
	}
	bestPath.insert(bestPath.begin(), 0);
	return make_pair(bestPath, bestWeight);
}

int factorial(int x) {
	if (x == 1) {
		return 1;
	}
	else {
		return factorial(x-1)*x;
	}
}