#ifndef PRIM_H
#define PRIM_H

#include "spanningtreealgorithmbase.h"
#include <vector>

class Prim : public SpanningtreeAlgorithmBase
{
public:
	std::vector<std::pair<int, int>> SpanningTree(int verticesNumber, const Graph& adjacencylist);

private:
	void _PrimAlgorithm(int, const Graph&);
};

#endif
