#include <algorithm>
#include <fstream>
#include <iostream>
#include "depthfirstsearch.h"
#include "lineborder.h"
#include "mazebase.h"

MazeBase::MazeBase(int verticesNumber, int startvertex, int endvertex)
	: _verticesNumber(verticesNumber), _startvertex(startvertex), _endvertex(endvertex)
{
	
}

void MazeBase::InitialiseGraph()
{
	_adjacencylist.clear();
	_adjacencylist.resize(_verticesNumber);
}

void MazeBase::GenerateMaze(SpanningtreeAlgorithmBase* algorithm)
{
	auto spanningTreeEdges = algorithm->SpanningTree(_verticesNumber, _adjacencylist);
	_Solve(spanningTreeEdges);
	_RemoveBorders(spanningTreeEdges);
}

void MazeBase::_Solve(const std::vector<std::pair<int, int>>& spanningTreeEdges)
{
	Graph spanningTreeGraph(_verticesNumber);
	for (const auto& [u, v] : spanningTreeEdges)
	{
		spanningTreeGraph[u].push_back(
			*std::find_if(_adjacencylist[u].begin(), _adjacencylist[u].end(),
				[v = v](const Edge& e)
				{
					return std::get<0>(e) == v;
				}));
		spanningTreeGraph[v].push_back(
			*std::find_if(_adjacencylist[v].begin(), _adjacencylist[v].end(),
				[u = u](const Edge& e)
				{
					return std::get<0>(e) == u;
				}));
	}

	DepthFirstSearch dfs;
	auto parent = dfs.Solve(_verticesNumber, spanningTreeGraph, _startvertex);

	_solution = Graph(_verticesNumber);
	for (int u = _endvertex; parent[u] != u; u = parent[u])
	{
		_solution[u].push_back(*std::find_if(
			spanningTreeGraph[u].begin(), spanningTreeGraph[u].end(),
			[u, &parent](const Edge& e)
			{
				return std::get<0>(e) == parent[u];
			}));
	}
}

void MazeBase::_RemoveBorders(const std::vector<std::pair<int, int>>& spanningTreeEdges)
{
	for (const auto& [u, v] : spanningTreeEdges)
	{
		_adjacencylist[u].erase(
			std::find_if(_adjacencylist[u].begin(), _adjacencylist[u].end(),
				[v = v](const Edge& e)
				{
					return std::get<0>(e) == v;
				}));
		_adjacencylist[v].erase(
			std::find_if(_adjacencylist[v].begin(), _adjacencylist[v].end(),
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
		for (const auto& edge : _adjacencylist[i])
		{
			std::get<1>(edge)->Draw(window, color);
		}
	}
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
		for (const auto& edge : _adjacencylist[i])
		{
			if (std::get<0>(edge) < i)
			{
				svgfile << std::get<1>(edge)->SVGPrintString("black") << "\n";
			}
		}
	}
	svgfile << "</g>" << std::endl;
	svgfile << "</svg>" << std::endl;
}
