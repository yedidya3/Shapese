#include "pch.h"
#include "Circle.h"
#include "colored_canvas.hpp"
namespace experis
{

namespace setToPropertyTreeCircle
{
	std::string colorableShape{"ColorableShape"};
	std::string radius{"lengthHorizon"};
	std::string type{"type"};
	std::string circle{"Circle"};
}



Circle::Circle(const short a_coordinateX, const short a_coordinateY, const short a_spaceShipArcRadius)
	:ColorableShape{a_coordinateX, a_coordinateY}
	,m_radius{a_spaceShipArcRadius}
{
}

Circle::Circle(const Circle& a_other)
	:ColorableShape{a_other.GetBasePoint().GetX(), a_other.GetBasePoint().GetY()}
	,m_radius{a_other.m_radius}
{
	this->SetFg(a_other.GetColorFront());
	this->SetBrush(a_other.GetBrush());
	this->SetBg(a_other.GetColorBack());
}

Circle::~Circle()
{
}

Circle::Circle(const PropTree& a_propTree)
	:ColorableShape{a_propTree.get_child_optional(setToPropertyTreeCircle::colorableShape).value()}
	,m_radius{a_propTree.get<Radius>(setToPropertyTreeCircle::radius)}
{
}

void Circle::Exporting(std::function<void(const PropTree&)> a_funcInfoHandling) const
{
	PropTree propTree{};
	ColorableShape::Exporting([&](const PropTree& a_treeProp)
		{
			propTree.push_back(PropTree::value_type("ColorableShape", a_treeProp));
		});
	propTree.push_back(PropTree::value_type(setToPropertyTreeCircle::type, PropTree(setToPropertyTreeCircle::circle)));
	propTree.push_back(PropTree::value_type(setToPropertyTreeCircle::radius, PropTree(std::to_string(m_radius))));
	a_funcInfoHandling(propTree);
}
	

void Circle::MoveBy(const Delta& a_deltaX, const Delta& a_deltaY)
{
	ColorableShape::MoveBy(a_deltaX, a_deltaY);
}

void Circle::Draw(ascii::ColoredCanvas& a_canvas) const 
{
	if (GetIsDrawn())
	{
		ascii::DrawCircle(a_canvas, GetBrush(), GetColorFront(), GetColorBack(), ColorableShape::GetBasePoint(), m_radius);
	}
}

Circle* Circle::Copy() const
{
	return new Circle{*this};
}
} //experis
