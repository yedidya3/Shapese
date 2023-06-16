#pragma once

#include "Rectangle.h"

namespace experis
{

class Square : public Rectangle
{
public:
	Square() = delete;
	Square(const Square& a_other);
	Square& operator=(const Square& a_other) = delete;
	virtual ~Square();

	explicit Square(const Point& a_basePoint, const short a_length);
	
	virtual Square* Copy() const override;
	short GetLength() const;

private:
};

} //experis
