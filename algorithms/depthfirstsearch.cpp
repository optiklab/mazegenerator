#include "depthfirstsearch.h"
#include <algorithm>
#include <numeric>

std::vector<std::pair<int, int>> DepthFirstSearch::SpanningTree(int vertices, const Graph& adjacencylist)
{
	_spanningTree.clear();
	_parent = std::vector<int>(vertices, -1);

	_InternalDFS(std::uniform_int_distribution<int>(0, vertices - 1)(_generator), adjacencylist);

	return _spanningTree;
}

void DepthFirstSearch::_InternalDFS(int vertex, const Graph& adjacencylist)
{
	std::vector<int> nodeorder(adjacencylist[vertex].size());
	std::iota(nodeorder.begin(), nodeorder.end(), 0); // Make list 0, 1, 2, 3, 4...
	shuffle(nodeorder.begin(), nodeorder.end(), _generator); // Shuffle randomly

	for (auto index : nodeorder)
	{
		int nextvertex = std::get<0>(adjacencylist[vertex][index]);

		if (nextvertex < 0 || _parent[nextvertex] >= 0)
			continue;

		_spanningTree.push_back({ vertex, nextvertex });

		_parent[nextvertex] = vertex;

		_InternalDFS(nextvertex, adjacencylist);
	}
}

std::vector<int> DepthFirstSearch::Solve(int vertices, const Graph& adjacencylist, int startvertex)
{
	_spanningTree.clear();
	_parent = std::vector<int>(vertices, -1);
	_parent[startvertex] = startvertex;
	_InternalDFS(startvertex, adjacencylist);
	return _parent;
}
