#include "depthfirstsearch.h"
#include <algorithm>
#include <numeric>

/**
 * \brief Generates entire maze spanning tree by randomly selecting next cell and moving using DFS.
 *		  The interesting fact is that generation starts from the random vertex of a Graph (not just start of a maze).
 * \param verticesNumber Number of vertices in the graph or cells in the maze.
 * \param adjacencyList Graph representation
 * \return A list of pairs of connected maze cells (without walls).
 */
std::vector<std::pair<int, int>> DepthFirstSearch::SpanningTree(int verticesNumber, const Graph& adjacencyList)
{
	_spanningTree.clear();
	_parent = std::vector<int>(verticesNumber, -1);

	_InternalDFS(
		// Randomly select very first cell
		std::uniform_int_distribution<int>(0, verticesNumber - 1)(_generator),
		adjacencyList);

	return _spanningTree;
}

void DepthFirstSearch::_InternalDFS(int vertex, const Graph& adjacencyList)
{
	std::vector<int> nodeorder(adjacencyList[vertex].size());
	std::iota(nodeorder.begin(), nodeorder.end(), 0); // Make list 0, 1, 2, 3, 4... of neighbor cells
	shuffle(nodeorder.begin(), nodeorder.end(), _generator); // Shuffle randomly to randomly select NEXT cell.

	// We have to visit every neighbor at some moment,
	// so this loop implements backtracking.
	for (auto index : nodeorder)
	{
		int nextvertex = std::get<0>(adjacencyList[vertex][index]);

		if (nextvertex < 0 || _parent[nextvertex] >= 0) // Skip already visited cells that are already in pair.
			continue;

		_spanningTree.push_back({ vertex, nextvertex }); // Make pairs of connected neighbors (without wall).

		_parent[nextvertex] = vertex;

		_InternalDFS(nextvertex, adjacencyList); // Go to the next cell until the end.
	}
}

/**
 * \brief Finds a path from ENTRY start cell of a maze to the EXIT cell by using DFS.
 * \param verticesNumber Number of vertices in the graph or cells in the maze.
 * \param adjacencyList Graph representation
 * \param startVertex a number of start vertex of a Graph mapped to the start cell of a maze.
 * \return a path as a numbers of cells/vertexes.
 */
std::vector<int> DepthFirstSearch::Solve(int verticesNumber, const Graph& adjacencyList, int startVertex)
{
	_spanningTree.clear();
	_parent = std::vector<int>(verticesNumber, -1);
	_parent[startVertex] = startVertex;
	_InternalDFS(startVertex, adjacencyList);
	return _parent;
}
