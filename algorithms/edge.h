#pragma once
#ifndef EDGE_H
#define EDGE_H

#include "cellborder.h"
#include <memory>

typedef std::tuple<int, std::shared_ptr<CellBorder>> Edge;

#endif
