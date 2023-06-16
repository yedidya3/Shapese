#pragma once
#include "BaseShape.h"
#include "colored_canvas.hpp"
namespace experis

{
class ColorableShape : public BaseShape
{
public:
	explicit ColorableShape(const Point::CoordType& a_x, const  Point::CoordType& a_y);
	ColorableShape(const BaseShape& a_other) = delete;
	ColorableShape& operator=(const ColorableShape& a_other) = delete;
	
	explicit ColorableShape(const PropTree& a_propTree);	
	virtual ~ColorableShape();

	ColorableShape& SetFg(const ascii::ColoredCanvas::Color& a_color);
	ColorableShape& SetBg(const ascii::ColoredCanvas::Color& a_color);
	ColorableShape& SetBrush(const char a_brush);

	const ascii::ColoredCanvas::Color& GetColorFront() const;
	const ascii::ColoredCanvas::Color& GetColorBack() const;
	const char GetBrush() const;

	virtual void Exporting(std::function<void(const PropTree&)> a_funcInfoHandling) const override;

private:
	char m_brush;
	ascii::ColoredCanvas::Color m_front;
	ascii::ColoredCanvas::Color m_backGround;
	
};


} //experis