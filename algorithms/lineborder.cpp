#include "lineborder.h"
#include <tuple>

LineBorder::LineBorder(double x1, double y1, double x2, double y2) : _x1(x1), _y1(y1), _x2(x2), _y2(y2)
{

}

LineBorder::LineBorder(std::tuple<double, double, double, double> xy)
{
	std::tie(_x1, _y1, _x2, _y2) = xy;
}

std::string LineBorder::SVGPrintString(const std::string& color) const
{
	return "<line x1=\"" + std::to_string(_x1 * 30) + "\" x2=\"" +
		std::to_string(_x2 * 30) + "\" y1=\"" + std::to_string(_y1 * 30) +
		"\" y2=\"" + std::to_string(_y2 * 30) + "\" stroke=\"" + color +
		"\" stroke-linecap=\"round\" stroke-width=\"3\"/>";
}


void LineBorder::Draw(sf::RenderWindow& window, Color& color) const
{
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(_x1 * 30, _y1 * 30), color),
		sf::Vertex(sf::Vector2f(_x2 * 30, _y2 * 30), color)
	};

	window.draw(line, 2, sf::Lines);
}