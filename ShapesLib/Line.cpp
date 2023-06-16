#include "pch.h"
#include "Line.h"
namespace experis
{

namespace setToPropertyTreeLine
{
	std::string ColorableShape{"ColorableShape"};
	std::string xEnd{"xEnd"};
	std::string yEnd{"yEnd"};
	std::string type{"type"};
	std::string line{"Line"};
}


Line::Line(const Line& a_other)
	:ColorableShape{a_other.GetBasePoint().GetX(), a_other.GetBasePoint().GetY()}
	,m_end{a_other.m_end}
{
	this->SetFg(a_other.GetColorFront());
	this->SetBrush(a_other.GetBrush());
	this->SetBg(a_other.GetColorBack());
}

Line::Line(const PropTree& a_propTree)
	:ColorableShape{a_propTree.get_child_optional(setToPropertyTreeLine::ColorableShape).value()}
	,m_end{a_propTree.get<Point::CoordType>(setToPropertyTreeLine::xEnd)
		,a_propTree.get<Point::CoordType>(setToPropertyTreeLine::yEnd)}
{
}



void Line::Exporting(std::function<void(const PropTree&)> a_funcInfoHandling) const
{
	PropTree propTree{};
	ColorableShape::Exporting([&](const PropTree& a_treeProp)
		{
			propTree.push_back(PropTree::value_type(setToPropertyTreeLine::ColorableShape, a_treeProp));
		});

	propTree.push_back(PropTree::value_type(setToPropertyTreeLine::type, PropTree(setToPropertyTreeLine::line)));
	propTree.push_back(PropTree::value_type(setToPropertyTreeLine::xEnd, PropTree(std::to_string(m_end.GetX()))));
	propTree.push_back(PropTree::value_type(setToPropertyTreeLine::yEnd, PropTree(std::to_string(m_end.GetY()))));

	a_funcInfoHandling(propTree);
}

Line::~Line()
{
}

Line::Line(const Point::CoordType& a_x, const  Point::CoordType& a_y, const short a_spaceShipArcRadius)
	:ColorableShape{a_x, a_y}
	,m_end{a_x  + a_spaceShipArcRadius, a_y}
{
}

void Line::MoveBy(const Delta& a_deltaX, const Delta& a_deltaY)
{
	BaseShape::MoveBy(a_deltaX, a_deltaY);
	m_end.MoveBy(a_deltaX, a_deltaY);
}

void Line::Draw(ascii::ColoredCanvas& a_canvas) const
{
	if (GetIsDrawn())
	{
		
		ascii::DrawLine(a_canvas, GetBrush(), GetColorFront(), GetColorBack(), ColorableShape::GetBasePoint(), m_end);
	}
}

void Line::SetDegrees(const short a_degree)
{
	double rotationAngle = a_degree - GetDegreeOfLine(ColorableShape::GetBasePoint(), m_end);
	m_end = m_end.GetRotatedAround(ColorableShape::GetBasePoint().GetX(), ColorableShape::GetBasePoint().GetY(), rotationAngle);
}

Line* Line::Copy() const
{
	return new Line{*this};
}

}