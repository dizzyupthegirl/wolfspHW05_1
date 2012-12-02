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
	int n;

	/// 
	for (int i = 0; i < G->size(); i++)
		currentPath.push_back(i);
	n = G->size();

	for (int i = 0; i < factorial(n-1); i++) {
		edgeWeight = G->weight(0, currentPath[0]);
		for (int j = 0; j < n-1; j++) {
			if (edgeWeight > bestWeight)
				return;
			else {
				if (j == n-2)
					edgeWeight += G->weight(0, currentPath.at(j));
				else 
					edgeWeight += G->weight(currentPath.at(j+1), currentPath.at(j));
			}
		}

		if (edgeWeight < bestWeight) {
			bestPath = currentPath;
			bestWeight = edgeWeight;
		}

		
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