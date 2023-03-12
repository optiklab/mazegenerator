#include "kruskal.h"
#include <algorithm>
#include <numeric>

/**
 * \brief Generates entire maze spanning tree by randomly selecting next cell and moving using DFS.
 * \param verticesNumber Number of vertices in the graph or cells in the maze.
 * \param adjacencylist Graph representation
 * \return A list of pairs of connected maze cells (without walls).
 */
std::vector<std::pair<int, int>> Kruskal::SpanningTree(int verticesNumber, const Graph& adjacencylist)
{
	std::vector<std::pair<int, int>> edges;
	for (int i = 0; i < verticesNumber; ++i)
	{
		for (const auto& edge : adjacencylist[i])
		{
			if (std::get<0>(edge) > i) 
				edges.push_back(
					{ i, std::get<0>(edge) });
		}
	}
	shuffle(edges.begin(), edges.end(), _generator);

	_parent = std::vector<int>(verticesNumber);
	std::iota(_parent.begin(), _parent.end(), 0);

	_spanningTree.clear();
	for (const auto& edge : edges)
	{
		int u = _GetParent(std::get<0>(edge)), v = _GetParent(edge.second);
		if (u == v)
			continue;
		_parent[u] = v;
		_spanningTree.push_back(edge);
	}
	return _spanningTree;
}

int Kruskal::_GetParent(int u)
{
	return (_parent[u] == u) ? u : (_parent[u] = _GetParent(_parent[u]));
}
