#pragma once
#include "colored_canvas.hpp"
#include "Point.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <functional>
namespace experis
{

using PropTree = boost::property_tree::ptree;
class BaseShape
{
public:
	using Coordinate = Point::CoordType;
	using Delta = short;
	explicit BaseShape() = delete;
	BaseShape(const BaseShape& a_other) = delete;
	BaseShape& operator=(const BaseShape& a_other) = delete;
	virtual ~BaseShape();

	explicit BaseShape(const Coordinate& a_x, const  Coordinate& a_y);
	explicit BaseShape(const PropTree& a_propTree);
	


	virtual void MoveBy(const Delta& a_deltaX, const Delta& a_deltaY) = 0;
	virtual void Draw(ascii::ColoredCanvas& a_canvas) const = 0;
	
	virtual void SetDegrees(const short a_degree);

	const bool GetIsDrawn() const;
	void SetIsDrawn(const bool a_isDrawn);
	const Point& GetBasePoint() const;

	virtual BaseShape* Copy() const = 0;

	virtual void Exporting(std::function<void(const PropTree&)> a_funcInfoHandling) const;
	
private:
	Point m_basePoint;
	bool m_isDrawn;
	
};


} //experis
