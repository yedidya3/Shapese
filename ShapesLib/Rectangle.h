#pragma once
#include "ColorableShape.h"
#include "Line.h"
#include "Point.h"

namespace experis
{

class Rectangle : public ColorableShape
{
public:
	Rectangle() = delete;
	Rectangle(const Rectangle& a_other);
	Rectangle& operator=(const Rectangle& a_other) = delete;
	virtual ~Rectangle();

	explicit Rectangle(const Point& a_basePoint, const short a_lengthVertical, const short a_lengthHorizon);
	explicit Rectangle(const PropTree& a_propTree);
	
	
	virtual void MoveBy(const Delta& a_deltaX, const Delta& a_deltaY) override;
	virtual void Draw(ascii::ColoredCanvas& a_canvas) const override;

	virtual void SetDegrees(const short a_degree) override;
	virtual Rectangle* Copy() const override;

	short GetLengthVertical() const;
	short GetLengthHorizon() const;


	virtual void Exporting(std::function<void(const PropTree&)> a_funcInfoHandling) const override;


private:
	short m_lengthVertical;
	short m_lengthHorizon;
	short m_degree;
};

} //experis

