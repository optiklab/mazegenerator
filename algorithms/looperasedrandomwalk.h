#ifndef LOOPERASEDRANDOMWALK_H
#define LOOPERASEDRANDOMWALK_H

#include "spanningtreealgorithmbase.h"
#include <vector>

class LoopErasedRandomWalk : public SpanningtreeAlgorithmBase
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
	std::vector<int> _visited;
	void _LERW(int, int, const Graph&);
};

#endif
