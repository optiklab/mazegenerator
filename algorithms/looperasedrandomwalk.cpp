#include "looperasedrandomwalk.h"
#include <algorithm>
#include <numeric>

/**
 * \brief Generates entire maze spanning tree by randomly selecting next cell and moving using DFS.
 * \param verticesNumber Number of vertices in the graph or cells in the maze.
 * \param adjacencylist Graph representation
 * \return A list of pairs of connected maze cells (without walls).
 */
std::vector<std::pair<int, int>> LoopErasedRandomWalk::SpanningTree(int verticesNumber, const Graph& adjacencylist)
{
	_spanningTree.clear();
	_visited = std::vector<int>(verticesNumber, 0);

	std::vector<int> nodes(verticesNumber);
	std::iota(nodes.begin(), nodes.end(), 0);
	shuffle(nodes.begin(), nodes.end(), _generator);
	_visited[nodes[0]] = 1;
	for (int round = 1, i = 1; i < verticesNumber; ++i)
	{
		if (_visited[nodes[i]]) continue;
		++round;
		_LERW(nodes[i], round, adjacencylist);
	}

	return _spanningTree;
}

void LoopErasedRandomWalk::_LERW(int vertex, int round, const Graph& adjacencylist)
{
	std::vector<int> current;

	while (!_visited[vertex]) {
		_visited[vertex] = round;
		current.push_back(vertex);
		int nextvertex;
		do {
			nextvertex =
				std::get<0>(adjacencylist[vertex][std::uniform_int_distribution<int>(
					0, adjacencylist[vertex].size() - 1)(_generator)]);
		} while (nextvertex < 0);

		if (_visited[nextvertex] == round) {
			// Erase the loop
			do {
				vertex = current.back();
				_visited[vertex] = 0;
				current.pop_back();
			} while (vertex != nextvertex);
		}

		vertex = nextvertex;
	}
	current.push_back(vertex);
	for (unsigned int i = 0; i + 1 < current.size(); ++i)
	{
		_spanningTree.push_back({ current[i], current[i + 1] });
	}
}
