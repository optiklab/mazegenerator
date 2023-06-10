#ifndef SPANNINGTREEALGORITHM_H
#define SPANNINGTREEALGORITHM_H

#include "cellborder.h"
#include "edge.h"
#include "graph.h"
#include <memory>
#include <random>
#include <vector>

/**
 * Perfect mazes are mazes with exactly one solution.
 * All perfect mazes usually generated based on spanning tree which is the one single solution for the maze.
 * Thus, Perfect Maze base algorithm is a Spanning Tree algorithm.
 *
 * Fundamental algorithms of building a spanning tree usually are distinguished by the data structure or fundamental method used to select the next cell.
 */
class SpanningtreeAlgorithmBase
{
public:
	SpanningtreeAlgorithmBase()
	{
		_generator = std::mt19937(_randomDevice());
	}

	/**
	 * \brief Generates entire maze spanning tree by randomly selecting next cell and moving using DFS.
	 * \param verticesNumber Number of vertices in the graph or cells in the maze.
	 * \param adjacencylist Graph representation
	 * \return A list of pairs of connected maze cells (without walls).
	 */
	virtual std::vector<std::pair<int, int>> SpanningTree(int verticesNumber, const Graph& adjacencylist) = 0;

protected:
	std::vector<std::pair<int, int>> _spanningTree;
	std::random_device _randomDevice;
	std::mt19937 _generator;
};

#endif
