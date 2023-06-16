#include "pch.h"
#include "MoveBase.h"


namespace experis
{

MoveBase::MoveBase(const short a_moveX, const short a_moveY)
	:m_moveX{a_moveX}
	,m_moveY{a_moveY}
{
}

MoveBase::MoveBase(const MoveBase& a_other)
	:m_moveX{a_other.m_moveX}
	,m_moveY{a_other.m_moveY}
{
}

void MoveBase::operator()(BaseShape& a_shape) const
{
	a_shape.MoveBy(m_moveX, m_moveY);
}

MoveRight::MoveRight()
	:MoveBase{1,0}
{
}

MoveRight::MoveRight(const MoveRight& a_other)
	:MoveBase(a_other)
{
}

MoveLeft::MoveLeft()
	:MoveBase{-1,0}
{
}

MoveLeft::MoveLeft(const MoveLeft& a_other)
	:MoveBase(a_other)
{
}

MoveDown::MoveDown()
	:MoveBase{0,1}
{
}

MoveDown::MoveDown(const MoveDown& a_other)
	:MoveBase(a_other)
{
}

MoveUp::MoveUp()
	:MoveBase{0,-1}
{
}

MoveUp::MoveUp(const MoveUp& a_other)
	:MoveBase(a_other)
{
}

} //experis