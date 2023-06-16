#pragma once
#include "ColorableShape.h"
#include "Point.h"
namespace experis
{


class Circle : public ColorableShape
{
public:
	using Radius = short;
	Circle() = delete;
	Circle(const Circle& a_other);
	Circle& operator=(const Circle& a_other) = delete;
	virtual ~Circle();

	explicit Circle(const PropTree& a_propTree);
	
	explicit Circle(const short a_coordinateX, const short a_coordinateY, const short a_spaceShipArcRadius);
	virtual void MoveBy(const Delta& a_deltaX, const Delta& a_deltaY) override;

	virtual void Draw(ascii::ColoredCanvas& a_canvas) const override;

	virtual Circle* Copy() const override;

	virtual void Exporting(std::function<void(const PropTree&)> a_funcExportHandling) const override;

private:
	Radius m_radius;
};

} //experis
