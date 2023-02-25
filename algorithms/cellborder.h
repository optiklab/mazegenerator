#ifndef CELLBORDER_H
#define CELLBORDER_H

#include <string>

#include <SFML/Graphics.hpp>
#include "..\common.h"

using namespace sf;

class CellBorder
{
public:
	virtual std::string SVGPrintString(const std::string& color) const = 0;

	virtual void Draw(sf::RenderWindow& window, Color& color) const = 0;
};

#endif
