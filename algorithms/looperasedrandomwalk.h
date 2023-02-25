#ifndef LOOPERASEDRANDOMWALK_H
#define LOOPERASEDRANDOMWALK_H

#include "spanningtreealgorithmbase.h"
#include <vector>

class LoopErasedRandomWalk : public SpanningtreeAlgorithmBase
{
public:
	std::vector<std::pair<int, int>> SpanningTree(int verticesNumber, const Graph& adjacencylist);

private:
	std::vector<int> _visited;
	void _LERW(int, int, const Graph&);
};

#endif
