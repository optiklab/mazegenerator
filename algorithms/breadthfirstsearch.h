#ifndef BREADTHFIRSTSEARCH_H
#define BREADTHFIRSTSEARCH_H

#include "spanningtreealgorithmbase.h"
#include <vector>

#include "graph.h"

class BreadthFirstSearch : public SpanningtreeAlgorithmBase
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
	std::vector<bool> visited;
	std::vector<int> currentlevel, nextlevel;
};

#endif
