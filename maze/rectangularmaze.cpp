#include "rectangularmaze.h"

#include "lineborder.h"

#include <SFML/Graphics.hpp>
#include "..\common.h"

using namespace sf;

RectangularMaze::RectangularMaze(int width, int height)
	: MazeBase(width* height, 0, width* height - 1),
	_width(width),
	_height(height)
{

}

int RectangularMaze::_VertexIndex(int row, int column)
{
	return row * _width + column;
}

/**
 * \brief Creates a Graph to represent the maze. Basically, it creates a grid with all-closed cells for the future maze.
 * \param window to draw results.
 * \param color to draw.
 */
void RectangularMaze::InitialiseGraph()
{
	MazeBase::InitialiseGraph();

	// Lower and upper boundaries of a maze
	for (int i = 0; i < _width; ++i)
	{
		_adjacencyList[_VertexIndex(0, i)].push_back(
			{ -1, std::make_shared<LineBorder>(i, 0, i + 1, 0) });
		_adjacencyList[_VertexIndex(_height - 1, i)].push_back(
			{ -1, std::make_shared<LineBorder>(i, _height, i + 1, _height) });
	}

	// Left and right boundaries of a maze, leaving space for entry and exit.
	// Entry and exit are always in the same locations - fixed.
	for (int i = 0; i < _height; ++i)
	{
		if (i != 0)
			_adjacencyList[_VertexIndex(i, 0)].push_back(
				{ -1, std::make_shared<LineBorder>(0, i, 0, i + 1) });

		if (i != _height - 1)
			_adjacencyList[_VertexIndex(i, 0)].push_back(
				{ -1, std::make_shared<LineBorder>(_width, i, _width, i + 1) });
	}

	// Add horizontally adjacent cells of a maze row by row.
	// If we would draw a grid: grid would have all vertical lines drawn.
	for (int i = 0; i < _height; ++i)
	{
		for (int j = 0; j < _width - 1; ++j)
		{
			std::shared_ptr<LineBorder> ptr = std::make_shared<LineBorder>(j + 1, i, j + 1, i + 1);
			_adjacencyList[_VertexIndex(i, j)].push_back({ _VertexIndex(i, j + 1), ptr });
			_adjacencyList[_VertexIndex(i, j + 1)].push_back({ _VertexIndex(i, j), ptr });
		}
	}

	// Add vertically adjacent cells of a maze column by column.
	// If we would draw a grid: grid would have all horizontal lines drawn.
	for (int i = 0; i < _height - 1; ++i)
	{
		for (int j = 0; j < _width; ++j)
		{
			std::shared_ptr<LineBorder> ptr = std::make_shared<LineBorder>(j, i + 1, j + 1, i + 1);
			_adjacencyList[_VertexIndex(i, j)].push_back({ _VertexIndex(i + 1, j), ptr });
			_adjacencyList[_VertexIndex(i + 1, j)].push_back({ _VertexIndex(i, j), ptr });
		}
	}
}

std::tuple<double, double, double, double> RectangularMaze::GetCoordinateBounds() const
{
	return std::make_tuple(0, 0, _width, _height);
}
