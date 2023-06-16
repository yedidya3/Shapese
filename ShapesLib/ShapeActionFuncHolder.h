#pragma once
#include "BaseShape.h"
#include "PerformBase.h"
#include "PerformSon.h"
namespace experis
{

class ShapeActionFuncHolder
{
public:
	ShapeActionFuncHolder() = delete;
	ShapeActionFuncHolder(const ShapeActionFuncHolder& a_other)
		:m_perform{ a_other.m_perform->Clone()}
	{
	}

	template<typename T>
	ShapeActionFuncHolder(T a_t)
		:m_perform{ new PerformSon<T>{a_t} }
	{
	}

	ShapeActionFuncHolder& operator=(const ShapeActionFuncHolder& a_other) = delete;
	~ShapeActionFuncHolder() { delete m_perform; };

	void operator()(BaseShape& a_shape) const
	{
		m_perform->operator()(a_shape);
	}

private:
	AbstractFunction* m_perform;

};

}
