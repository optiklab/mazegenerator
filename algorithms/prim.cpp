#include "prim.h"
#include <algorithm>

std::vector<std::pair<int, int>> Prim::SpanningTree(
	int vertices, const Graph& adjacencylist) {
	_spanningTree.clear();

	_PrimAlgorithm(vertices, adjacencylist);
	return _spanningTree;
}

void Prim::_PrimAlgorithm(int vertices, const Graph& adjacencylist) {
	std::vector<bool> visited(vertices, false);
	std::vector<std::pair<int, int>> boundary;
	int vertex = std::uniform_int_distribution<int>(0, vertices - 1)(_generator);

	for (int i = 1; i < vertices; ++i) {
		visited[vertex] = true;
		for (auto p : adjacencylist[vertex]) {
			if (std::get<0>(p) != -1 and !visited[std::get<0>(p)])
				boundary.push_back({ vertex, std::get<0>(p) });
		}

		std::pair<int, int> nextedge = { -1, -1 };
		do {
			int index =
				std::uniform_int_distribution<int>(0, boundary.size() - 1)(_generator);
			std::swap(boundary[index], boundary.back());
			if (!visited[boundary.back().second]) nextedge = boundary.back();
			boundary.pop_back();
		} while (nextedge.first == -1);

		_spanningTree.push_back(nextedge);
		vertex = nextedge.second;
	}
}
