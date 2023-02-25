#include "mazebase.h"

/**
 * Rectangular maze with START (ENTER) position in the most Left (zero) cell
 * and END (EXIT) position in the most Right cell.
 */
class RectangularMaze : public MazeBase
{
public:
	RectangularMaze(int width, int height);
	virtual void InitialiseGraph();

private:
	int _width;
	int _height;

	int _VertexIndex(int row, int column);
	virtual std::tuple<double, double, double, double> GetCoordinateBounds() const;
};
