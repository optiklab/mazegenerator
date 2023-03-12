#ifndef LINEBORDER_H
#define LINEBORDER_H

#include <string>

#include "cellborder.h"

class LineBorder : public CellBorder
{
public:
	LineBorder(double x1, double y1, double x2, double y2);
	LineBorder(std::tuple<double, double, double, double> xy);
	virtual std::string SVGPrint(const std::string& color) const;
	virtual void Draw(sf::RenderWindow& window, Color& color) const;

protected:
	double _x1, _y1, _x2, _y2;
};

#endif
