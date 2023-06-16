#pragma once
#include "BaseShape.h"
namespace experis
{

class MoveBase
{
public:
	MoveBase() = delete;
	MoveBase(const MoveBase& a_other);
	MoveBase& operator=(const MoveBase& a_other) = delete;
	virtual ~MoveBase() = default;
	 
	MoveBase(const short a_moveX, const short a_moveY);
	virtual void operator()(BaseShape& a_shape) const;
private:
	short m_moveX;// = 0;
	short m_moveY;// = 0;
};

class MoveRight : public MoveBase
{
public:
	MoveRight();
	MoveRight(const MoveRight& a_other);
	MoveRight& operator=(const MoveRight& a_other) = delete;
	virtual ~MoveRight() = default;
};

class MoveLeft : public MoveBase
{
public:
	MoveLeft();
	MoveLeft(const MoveLeft& a_other);
	MoveLeft& operator=(const MoveLeft& a_other) = delete;
	virtual ~MoveLeft() = default;
};


class MoveDown : public MoveBase
{
public:
	MoveDown();
	MoveDown(const MoveDown& a_other);
	MoveDown& operator=(const MoveDown& a_other) = delete;
	virtual ~MoveDown() = default;
};

class MoveUp : public MoveBase
{
public:
	MoveUp();
	MoveUp(const MoveUp& a_other);
	MoveUp& operator=(const MoveUp& a_other) = delete;
	virtual ~MoveUp() = default;
};




}