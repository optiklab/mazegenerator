#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

#include "edge.h"

/// <summary>
/// Adjacency list of EDGES for UNORIENTED graph of the maze.
/// Edge is a Node Id (for UNORIENTED graph it can be FROM or TO) and coordiantes (x1, y1, x2, y2 in LineBorder), 
/// color, and helper methods to draw SVG.
/// We should create 2 instances for every edge: one instance for FROM+Edge and one instance for TO+Edge.
/// </summary>
typedef std::vector<std::vector<Edge>> Graph;

#endif
