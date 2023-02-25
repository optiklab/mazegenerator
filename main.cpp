#include "breadthfirstsearch.h"
#include "depthfirstsearch.h"
#include "kruskal.h"
#include "looperasedrandomwalk.h"
#include "prim.h"

#include "rectangularmaze.h"
#include <cstring>
#include <iostream>
#include <map>
#include <string>

#include <SFML/Graphics.hpp>
#include "common.h"

using namespace sf;
using namespace std;

int main(int argc, char* argv[])
{
	RenderWindow window(VideoMode(HORIZONTAL_CELLS * SQUARE_TILE_SIZE + SQUARE_TILE_SIZE,
		VERTICAL_CELLS * SQUARE_TILE_SIZE + SQUARE_TILE_SIZE), "Maze!");

	std::string outputprefix = "maze";

	MazeBase* maze = new RectangularMaze(HORIZONTAL_CELLS, VERTICAL_CELLS);
	SpanningtreeAlgorithmBase* algorithm = new DepthFirstSearch; // BreadthFirstSearch // Kruskal // Prim //LEDW

	// Redraw.
	window.clear(Color::White);

	std::cout << "Initialising graph..." << std::endl;
	maze->InitialiseGraph();

	// Grey
	Color rgba = Color::Black;
	rgba.r = 235;
	rgba.g = 235;
	rgba.b = 235;

	maze->Draw(window, rgba);

	std::cout << "Generating maze..." << std::endl;
	maze->GenerateMaze(algorithm);

	Color black = Color::Black;
	maze->Draw(window, black);

	std::cout << "Rendering maze to '" << outputprefix << ".svg'..." << std::endl;
	maze->PrintMazeSVG(outputprefix);

	window.display();

	while (window.isOpen())
	{
		// Handle key events
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
	}

	return 0;
}
