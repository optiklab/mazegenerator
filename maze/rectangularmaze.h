#include "mazebase.h"

/**
 * Rectangular maze with START (ENTER) position in the most Left (zero) cell
 * and END (EXIT) position in the most Right cell.
 */
class RectangularMaze : public MazeBase
{
public:
	RectangularMaze(int width, int height);

	/**
	 * \brief Creates a Graph to represent the maze. Basically, it creates a grid with all-closed cells for the future maze.
	 * \param window to draw results.
	 * \param color to draw.
	 */
	virtual void InitialiseGraph();

private:
	int _width;
	int _height;

	int _VertexIndex(int row, int column);
	virtual std::tuple<double, double, double, double> GetCoordinateBounds() const;
};
