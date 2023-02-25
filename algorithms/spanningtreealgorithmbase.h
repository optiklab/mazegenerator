#ifndef SPANNINGTREEALGORITHM_H
#define SPANNINGTREEALGORITHM_H

#include "cellborder.h"
#include <memory>
#include <random>
#include <vector>

typedef std::tuple<int, std::shared_ptr<CellBorder>> Edge;
typedef std::vector<std::vector<Edge>> Graph;

/**
 * Perfect mazes are mazes with exactly one solution.
 * All perfect mazes usually generated based on spanning tree which is the one single solution for the maze.
 * Thus, Perfect Maze base algorithm is a Spanning Tree algorithm.
 */
class SpanningtreeAlgorithmBase
{
public:
	SpanningtreeAlgorithmBase()
	{
		_generator = std::mt19937(_randomDevice());
	}

	virtual std::vector<std::pair<int, int>> SpanningTree(int verticesNumber, const Graph& adjacencylist) = 0;

protected:
	std::vector<std::pair<int, int>> _spanningTree;
	std::random_device _randomDevice;
	std::mt19937 _generator;
};

#endif
