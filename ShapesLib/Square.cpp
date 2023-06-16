#include "pch.h"
#include "Square.h"

namespace experis
{

Square::~Square()
{
}

Square::Square(const Point& a_basePoint, const short a_length)
	:Rectangle{a_basePoint, a_length, a_length}
{
}

Square::Square(const Square& a_other)
	:Rectangle{a_other.GetBasePoint(), GetLength(), GetLength()}
{
}

Square* Square::Copy() const
{
	return new Square(*this);
}

short Square::GetLength() const
{
	return GetLengthVertical();
}


} //