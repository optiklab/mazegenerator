#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "spanningtreealgorithmbase.h"
#include <vector>

class Kruskal : public SpanningtreeAlgorithmBase
{
public:
	std::vector<std::pair<int, int>> SpanningTree(int verticesNumber, const Graph& adjacencylist);

private:
	std::vector<int> _parent;

	int _GetParent(int);
};

#endif
