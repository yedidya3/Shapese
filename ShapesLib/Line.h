#pragma once
#include "ColorableShape.h"
#include "Point.h"
#include <boost/property_tree/ptree.hpp>
namespace experis
{

class Line : public ColorableShape
{
public:
	using PropTree = boost::property_tree::ptree;


	Line() = delete;
	Line(const Line& a_other);
	Line& operator=(const Line& a_other) = delete;
	virtual ~Line();
	explicit Line(const Point::CoordType& a_x, const  Point::CoordType& a_y, const short a_length);
	explicit Line(const PropTree& a_propTree);

	virtual void MoveBy(const Delta& a_deltaX, const Delta& a_deltaY) override;
	virtual void Draw(ascii::ColoredCanvas& a_canvas) const override;
	virtual void SetDegrees(const short a_degree) override;
	virtual Line* Copy() const override;


	virtual void Exporting(std::function<void(const PropTree&)> a_funcInfoHandling) const override;
private:
	Point m_end;
};


} //experis
