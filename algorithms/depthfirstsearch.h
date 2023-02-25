#ifndef DEPTHFIRSTSEARCH_H
#define DEPTHFIRSTSEARCH_H

#include "spanningtreealgorithmbase.h"
#include <vector>

class DepthFirstSearch : public SpanningtreeAlgorithmBase
{
public:
	std::vector<std::pair<int, int>> SpanningTree(int verticesNumber, const Graph& adjacencylist);
	std::vector<int> Solve(int, const Graph&, int);

private:
	std::vector<int> _parent;
	void _InternalDFS(int, const Graph&);
};

#endif
