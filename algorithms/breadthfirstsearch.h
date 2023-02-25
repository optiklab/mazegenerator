#ifndef BREADTHFIRSTSEARCH_H
#define BREADTHFIRSTSEARCH_H

#include "spanningtreealgorithmbase.h"
#include <vector>

#include "graph.h"

class BreadthFirstSearch : public SpanningtreeAlgorithmBase
{
public:
	std::vector<std::pair<int, int>> SpanningTree(int, const Graph&);

private:
	std::vector<bool> visited;
	std::vector<int> currentlevel, nextlevel;
};

#endif
