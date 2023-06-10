#include <algorithm>
#include <fstream>
#include <iostream>
#include "depthfirstsearch.h"
#include "lineborder.h"
#include "mazebase.h"

MazeBase::MazeBase(int verticesNumber, int startVertex, int endVertex)
	: _verticesNumber(verticesNumber), _startVertex(startVertex), _endVertex(endVertex)
{
	
}

/**
 * \brief Creates a Graph to represent the maze. Basically, it creates a grid with all-closed cells for the future maze.
 * \param window to draw results.
 * \param color to draw.
 */
void MazeBase::InitialiseGraph()
{
	_edgesList.clear();
	_edgesList.resize(_verticesNumber);
}

/**
 * \brief Generates entire maze spanning tree and adjusts maze graph representation accordingly.
 * \param algorithm Algorithm that is used to generate ,aze spanning tree.
 */
void MazeBase::GenerateMaze(SpanningtreeAlgorithmBase* algorithm)
{
	auto spanningTreeEdges = algorithm->SpanningTree(_verticesNumber, _edgesList);

	// Optionally, find find a solution of a maze based on Graph DFS.
	_Solve(spanningTreeEdges);
	_RemoveBorders(spanningTreeEdges);
}

/**
 * \brief Optional method to find a solution of a maze based on Graph DFS. It's not actually change anything in the maze itself.
 * \param spanningTreeEdges List of vertex pairs that represent the connected cells of a maze.
 */
void MazeBase::_Solve(const std::vector<std::pair<int, int>>& spanningTreeEdges)
{
	// Convert pairs of vertex numbers into actual edges, to run DFS on it.
	// We should create 2 instances for every edge: one instance for FROM+Edge and one instance for TO+Edge.
	Graph spanningTreeGraph(_verticesNumber);
	for (const auto& [u, v] : spanningTreeEdges)
	{
		spanningTreeGraph[u].push_back(
			*std::find_if(_edgesList[u].begin(), _edgesList[u].end(),
				[v = v](const Edge& e)
				{
					return std::get<0>(e) == v;
				}));
		spanningTreeGraph[v].push_back(
			*std::find_if(_edgesList[v].begin(), _edgesList[v].end(),
				[u = u](const Edge& e)
				{
					return std::get<0>(e) == u;
				}));
	}

	// Find path from ENTRY point of a maze to the EXIT point.
	DepthFirstSearch dfs;
	auto parent = dfs.Solve(_verticesNumber, spanningTreeGraph, _startVertex);

	// Covert list of vertex numbers (path) back into Solution Graph (edges list).
	_solution = Graph(_verticesNumber);
	for (int u = _endVertex; parent[u] != u; u = parent[u])
	{
		_solution[u].push_back(*std::find_if(
			spanningTreeGraph[u].begin(), spanningTreeGraph[u].end(),
			[u, &parent](const Edge& e)
			{
				return std::get<0>(e) == parent[u];
			}));
	}
}

/**
 * \brief Based on maze spanning tree adjusts maze graph by removing unnecessary walls between connected cells.
 * \param spanningTreeEdges Spanning tree of a maze
 */
void MazeBase::_RemoveBorders(const std::vector<std::pair<int, int>>& spanningTreeEdges)
{
	for (const auto& [u, v] : spanningTreeEdges)
	{
		_edgesList[u].erase(
			std::find_if(_edgesList[u].begin(), _edgesList[u].end(),
				[v = v](const Edge& e)
				{
					return std::get<0>(e) == v;
				}));
		_edgesList[v].erase(
			std::find_if(_edgesList[v].begin(), _edgesList[v].end(),
				[u = u](const Edge& e)
				{
					return std::get<0>(e) == u;
				}));
	}
}


void MazeBase::Draw(RenderWindow& window, Color& color) const
{
	for (int i = 0; i < _verticesNumber; ++i)
	{
		for (const auto& edge : _edgesList[i])
		{
			std::get<1>(edge)->Draw(window, color);
		}
	}

	// TODO Draw a solution Graph as well.
}

void MazeBase::PrintMazeSVG(const std::string& filename) const
{
	std::ofstream svgfile(filename + ".svg");
	if (!svgfile)
	{
		std::cerr << "Error opening " << filename << ".svg for writing.\n";
		std::cerr << "Terminating.";
		exit(1);
	}
	double xmin, ymin, xmax, ymax;
	std::tie(xmin, ymin, xmax, ymax) = GetCoordinateBounds();
	int xresolution = (xmax - xmin + 2) * 30,
		yresolution = (ymax - ymin + 2) * 30;

	svgfile << "<svg width=\"" << xresolution << "\" height=\"" << yresolution
		<< "\" xmlns=\"http://www.w3.org/2000/svg\">" << std::endl;
	svgfile << "<g transform=\"translate(" << (1 - xmin) * 30 << ","
		<< yresolution - (1 - ymin) * 30 << ") scale(1,-1)\">" << std::endl;
	svgfile << "<rect x=\"" << (xmin - 1) * 30 << "\" y=\"" << (ymin - 1) * 30
		<< "\" width=\"" << xresolution << "\" height=\"" << yresolution
		<< "\" fill=\"white\"/>" << std::endl;

	for (int i = 0; i < _verticesNumber; ++i)
	{
		for (const auto& edge : _edgesList[i])
		{
			if (std::get<0>(edge) < i)
			{
				svgfile << std::get<1>(edge)->SVGPrint("black") << "\n";
			}
		}
	}
	svgfile << "</g>" << std::endl;
	svgfile << "</svg>" << std::endl;
}
