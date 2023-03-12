#ifndef PRIM_H
#define PRIM_H

#include "spanningtreealgorithmbase.h"
#include <vector>

class Prim : public SpanningtreeAlgorithmBase
{
public:
	/**
	 * \brief Generates entire maze spanning tree by randomly selecting next cell and moving using DFS.
	 * \param verticesNumber Number of vertices in the graph or cells in the maze.
	 * \param adjacencylist Graph representation
	 * \return A list of pairs of connected maze cells (without walls).
	 */
	std::vector<std::pair<int, int>> SpanningTree(int verticesNumber, const Graph& adjacencylist);

private:
	void _PrimAlgorithm(int, const Graph&);
};

#endif
