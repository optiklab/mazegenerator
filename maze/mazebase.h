#ifndef MAZE_H
#define MAZE_H

#include "spanningtreealgorithmbase.h"
#include <vector>

#include <SFML/Graphics.hpp>
#include "..\common.h"

using namespace sf;

class MazeBase
{
public:
	MazeBase(int verticesNumber = 0, int startvertex = 0, int endvertex = 1);

	virtual void InitialiseGraph() = 0;

	void GenerateMaze(SpanningtreeAlgorithmBase* algorithm);

	void PrintMazeSVG(const std::string& filename) const;

	void Draw(RenderWindow& window, Color& color) const;

protected:
	virtual std::tuple<double, double, double, double> GetCoordinateBounds() const = 0;

private:
	void _RemoveBorders(const std::vector<std::pair<int, int>>& edges);

	void _Solve(const std::vector<std::pair<int, int>>& edges);

protected:
	// Maze is graph-based, because:
	// - Solving a maze is equivalent to finding a path in a graph
	// - We can use different ways of visualization while still use same base graph structure
	Graph _adjacencylist;
	Graph _solution;

	int _verticesNumber;
	int _startvertex;
	int _endvertex;
};

#endif
