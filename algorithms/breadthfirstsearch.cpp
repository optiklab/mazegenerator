#include "breadthfirstsearch.h"
#include <algorithm>
#include <iostream>

std::vector<std::pair<int, int>> BreadthFirstSearch::SpanningTree(int vertices, const Graph& adjacencylist)
{
	visited = std::vector<bool>(vertices, false);

	int startvertex = std::uniform_int_distribution<int>(0, vertices - 1)(_generator);
	currentlevel.push_back(startvertex);
	visited[startvertex] = true;

	_spanningTree.clear();
	while (!currentlevel.empty())
	{
		for (auto vertex : currentlevel)
		{
			for (const auto& edge : adjacencylist[vertex])
			{
				int nextvertex = std::get<0>(edge);

				if (nextvertex < 0 or visited[nextvertex])
					continue;

				visited[nextvertex] = true;

				_spanningTree.push_back(
					{
							vertex,
							nextvertex
					});
				nextlevel.push_back(nextvertex);
			}
		}

		currentlevel.clear();
		swap(currentlevel, nextlevel);
		shuffle(currentlevel.begin(), currentlevel.end(), _generator);
	}
	return _spanningTree;
}
