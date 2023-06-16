#include "pch.h"
#include "Rectangle.h"
#include <iostream>
namespace experis
{

namespace setToPropertyTreeRectangle
{
	std::string ColorableShape{"ColorableShape"};
	std::string lengthHorizon{"lengthHorizon"};
	std::string lengthVertical{"lengthVertical"};
	std::string degree{"degree"};
	std::string type{"type"};
	std::string Rectangle{"Rectangle"};
}



Rectangle::~Rectangle()
{
}

Rectangle::Rectangle(const Point& a_basePoint, const short a_lengthVertical, const short a_lengthHorizon)
	:ColorableShape{a_basePoint.GetX(), a_basePoint.GetY()}
	,m_lengthVertical{a_lengthVertical}
	,m_lengthHorizon{a_lengthHorizon}
	,m_degree{0}
{
}

Rectangle::Rectangle(const Rectangle& a_other)
	:ColorableShape{a_other.GetBasePoint().GetX(), a_other.GetBasePoint().GetY()}
	,m_lengthVertical{a_other.m_lengthVertical}
	,m_lengthHorizon{a_other.m_lengthHorizon}
	,m_degree{a_other.m_degree}
{
	this->SetFg(a_other.GetColorFront());
	this->SetBrush(a_other.GetBrush());
	this->SetBg(a_other.GetColorBack());
}

Rectangle::Rectangle(const PropTree& a_propTree)
	:ColorableShape{a_propTree.get_child_optional(setToPropertyTreeRectangle::ColorableShape).value()}
	,m_lengthHorizon{a_propTree.get<short>(setToPropertyTreeRectangle::lengthHorizon)}
	,m_lengthVertical{a_propTree.get<short>(setToPropertyTreeRectangle::lengthVertical)}
	,m_degree{a_propTree.get<short>(setToPropertyTreeRectangle::degree)}
{
}

void Rectangle::Exporting(std::function<void(const PropTree&)> a_funcInfoHandling) const
{
	PropTree propTree{};
	ColorableShape::Exporting([&](const PropTree& a_treeProp)
		{
			propTree.push_back(PropTree::value_type(setToPropertyTreeRectangle::ColorableShape, a_treeProp));
		});
	propTree.push_back(PropTree::value_type(setToPropertyTreeRectangle::type, PropTree(setToPropertyTreeRectangle::Rectangle)));
	propTree.push_back(PropTree::value_type(setToPropertyTreeRectangle::lengthHorizon, PropTree(std::to_string(m_lengthHorizon))));
	propTree.push_back(PropTree::value_type(setToPropertyTreeRectangle::lengthVertical, PropTree(std::to_string(m_lengthVertical))));
	propTree.push_back(PropTree::value_type(setToPropertyTreeRectangle::degree, PropTree(std::to_string(m_degree))));
	a_funcInfoHandling(propTree);
}


void Rectangle::MoveBy(const Delta& a_deltaX, const Delta& a_deltaY)
{
	ColorableShape::MoveBy(a_deltaX, a_deltaY);
}

void Rectangle::Draw(ascii::ColoredCanvas& a_canvas) const
{
	if(GetIsDrawn())
	{
		const Point& basePoint = ColorableShape::GetBasePoint();
		Line up{basePoint.GetX(), basePoint.GetY() , m_lengthHorizon};
		up.SetDegrees(m_degree);
		up.SetBg(ColorableShape::GetColorBack()).SetFg(ColorableShape::GetColorFront()).SetBrush(ColorableShape::GetBrush());
		
		Line left{basePoint.GetX(), basePoint.GetY() , m_lengthVertical};
		left.SetDegrees(m_degree + 90);
		left.SetBg(ColorableShape::GetColorBack()).SetFg(ColorableShape::GetColorFront()).SetBrush(ColorableShape::GetBrush());

		Line down{basePoint.GetX(), basePoint.GetY() + m_lengthVertical, m_lengthHorizon};
		down.SetDegrees(m_degree);
		down.SetBg(ColorableShape::GetColorBack()).SetFg(ColorableShape::GetColorFront()).SetBrush(ColorableShape::GetBrush());

		Line right{basePoint.GetX() + m_lengthHorizon, basePoint.GetY() , m_lengthVertical};
		right.SetDegrees(m_degree + 90);
		right.SetBg(ColorableShape::GetColorBack()).SetFg(ColorableShape::GetColorFront()).SetBrush(ColorableShape::GetBrush());

		up.Draw(a_canvas);
		left.Draw(a_canvas);
		down.Draw(a_canvas);
		right.Draw(a_canvas);
		//a_canvas.Print(std::cout);
		
	}
}

void Rectangle::SetDegrees(const short a_degree)
{
	m_degree = std::abs(a_degree) % 360;
}

Rectangle* Rectangle::Copy() const
{
	return new Rectangle(*this);
}

short Rectangle::GetLengthVertical() const
{
	return m_lengthVertical;
}

short Rectangle::GetLengthHorizon() const
{
	return m_lengthHorizon;
}

} //