#include "pch.h"
#include "BaseShape.h"

namespace experis
{

namespace setToPropertyTreeBaseShape
{
	std::string xBase{"xBase"};
	std::string yBase{"yBase"};
	std::string isDrawn{"isDrawn"};
}

BaseShape::BaseShape(const  Coordinate& a_x, const Coordinate& a_y)
	:m_basePoint{a_x, a_y}
	,m_isDrawn{true}
{
}



BaseShape::~BaseShape()
{
}
	
void BaseShape::MoveBy(const Delta& a_deltaX, const Delta& a_deltaY)
{
	m_basePoint.MoveBy(a_deltaX, a_deltaY);
}

void BaseShape::Draw(ascii::ColoredCanvas& a_canvas) const
{
}

void BaseShape::SetIsDrawn(const bool a_isDrawn)
{
	m_isDrawn = a_isDrawn;
}

const bool BaseShape::GetIsDrawn() const
{
	return m_isDrawn;
}

const Point& BaseShape::GetBasePoint() const
{
	return m_basePoint;
}

void BaseShape::SetDegrees(const short a_degree)
{
}

BaseShape::BaseShape(const PropTree& a_propTree)
	:m_basePoint{a_propTree.get<BaseShape::Coordinate>(setToPropertyTreeBaseShape::xBase)
		,a_propTree.get<BaseShape::Coordinate>(setToPropertyTreeBaseShape::yBase)}
	,m_isDrawn{a_propTree.get<bool>(setToPropertyTreeBaseShape::isDrawn)}
{
}

void BaseShape::Exporting(std::function<void(const PropTree&)> a_funcInfoHandling) const
{
	PropTree propTree{};
	propTree.push_back(PropTree::value_type(setToPropertyTreeBaseShape::xBase, PropTree(std::to_string(m_basePoint.GetX()))));
	propTree.push_back(PropTree::value_type(setToPropertyTreeBaseShape::yBase, PropTree(std::to_string(m_basePoint.GetY()))));
	propTree.push_back(PropTree::value_type(setToPropertyTreeBaseShape::isDrawn, PropTree(std::to_string(GetIsDrawn()))));
	a_funcInfoHandling(propTree);
}


} //experis