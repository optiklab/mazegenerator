#pragma once
#ifndef EDGE_H
#define EDGE_H

#include "cellborder.h"
#include <memory>

/// Edge is a Node Id (for UNORIENTED graph it can be FROM or TO)
/// and coordinates (x1, y1, x2, y2 in LineBorder), color, and helper methods to draw SVG.
/// We should create 2 instances for every edge: one instance for FROM+Edge and one instance for TO+Edge.
/// Thus, we use Shared Ptr to have a references to the Edges without duplicates.
typedef std::tuple<int, std::shared_ptr<CellBorder>> Edge;

#endif
