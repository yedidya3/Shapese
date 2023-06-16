#include "pch.h"
#include "ColorableShape.h"
#include <colored_canvas.hpp>
namespace experis
{

namespace setToPropertyTreeColorable
{
	std::string baseShape{"BaseShape"};
	std::string brush{"brush"};
	std::string front{"front"};
	std::string backGround{"backGround"};

}


ColorableShape::ColorableShape(const Point::CoordType& a_x, const  Point::CoordType& a_y)
	:BaseShape(a_x, a_y)
	,m_brush{'#'}
	,m_front{ascii::ColoredCanvas::RED}
	,m_backGround{ascii::ColoredCanvas::TERMINAL_COLOR}
	
{
}

ColorableShape::ColorableShape(const PropTree& a_propTree)
	:BaseShape{a_propTree.get_child_optional(setToPropertyTreeColorable::baseShape).value()}
	,m_brush{char(std::stoi(a_propTree.get<std::string>(setToPropertyTreeColorable::brush)))}
	,m_front{ascii::ColoredCanvas::Color(a_propTree.get<int>(setToPropertyTreeColorable::front))}
	,m_backGround{ascii::ColoredCanvas::Color(a_propTree.get<int>(setToPropertyTreeColorable::backGround))}
{
}

void ColorableShape::Exporting(std::function<void(const PropTree&)> a_funcInfoHandling) const 
{
	PropTree propTree{};
	BaseShape::Exporting([&](const PropTree& a_treeProp)
		{
			propTree.push_back(PropTree::value_type(setToPropertyTreeColorable::baseShape, a_treeProp));
		});

	propTree.push_back(PropTree::value_type(setToPropertyTreeColorable::brush, PropTree(std::to_string(m_brush))));
	propTree.push_back(PropTree::value_type(setToPropertyTreeColorable::front, PropTree(std::to_string(m_front))));
	propTree.push_back(PropTree::value_type(setToPropertyTreeColorable::backGround, PropTree(std::to_string(m_backGround))));
	a_funcInfoHandling(propTree);
}

ColorableShape::~ColorableShape()
{
}


ColorableShape& ColorableShape::SetFg(const ascii::ColoredCanvas::Color& a_color)
{
	m_front = a_color;
	return *this;
}

ColorableShape& ColorableShape::SetBg(const ascii::ColoredCanvas::Color& a_color)
{
	m_backGround = a_color;
	return *this;
}

ColorableShape& ColorableShape::SetBrush(const char a_brush)
{
	m_brush = a_brush;
	return *this;
}

const ascii::ColoredCanvas::Color& ColorableShape::GetColorFront() const
{
	return m_front;
}
const ascii::ColoredCanvas::Color& ColorableShape::GetColorBack() const
{
	return m_backGround;
}

const char ColorableShape::GetBrush() const
{
	return m_brush;
}

} //experis