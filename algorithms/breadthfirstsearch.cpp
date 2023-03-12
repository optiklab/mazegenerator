#include "breadthfirstsearch.h"
#include <algorithm>

/**
 * \brief Generates entire maze spanning tree by randomly selecting next cell and moving using DFS.
 * \param verticesNumber Number of vertices in the graph or cells in the maze.
 * \param adjacencylist Graph representation
 * \return A list of pairs of connected maze cells (without walls).
 */
std::vector<std::pair<int, int>> BreadthFirstSearch::SpanningTree(int verticesNumber, const Graph& adjacencylist)
{
	visited = std::vector<bool>(verticesNumber, false);

	int startvertex = std::uniform_int_distribution<int>(0, verticesNumber - 1)(_generator);
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
