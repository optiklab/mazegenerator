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
	MazeBase(int verticesNumber = 0, int startVertex = 0, int endVertex = 1);

	/**
	 * \brief Creates a Graph to represent the maze. Basically, it creates a grid with all-closed cells for the future maze.
	 * \param window to draw results.
	 * \param color to draw.
	 */
	virtual void InitialiseGraph() = 0;

	/**
	 * \brief Generates entire maze spanning tree and adjusts maze graph representation accordingly.
	 * \param algorithm Algorithm that is used to generate ,aze spanning tree.
	 */
	void GenerateMaze(SpanningtreeAlgorithmBase* algorithm);

	void PrintMazeSVG(const std::string& filename) const;

	void Draw(RenderWindow& window, Color& color) const;

protected:
	virtual std::tuple<double, double, double, double> GetCoordinateBounds() const = 0;

private:
	/**
	 * \brief Based on maze spanning tree adjusts maze graph by removing unnecessary walls between connected cells.
	 * \param spanningTreeEdges Spanning tree of a maze
	 */
	void _RemoveBorders(const std::vector<std::pair<int, int>>& spanningTreeEdges);

	/**
	 * \brief Optional method to find a solution of a maze based on Graph DFS. It's not actually change anything in the maze itself.
	 * \param spanningTreeEdges List of vertex pairs that represent the connected cells of a maze.
	 */
	void _Solve(const std::vector<std::pair<int, int>>& spanningTreeEdges);

protected:
	// Maze is graph-based, because:
	// - Solving a maze is equivalent to finding a path in a graph
	// - We can use different ways of visualization while still use same base graph structure
	Graph _edgesList;
	Graph _solution;

	int _verticesNumber;
	int _startVertex;
	int _endVertex;
};

#endif
