#pragma once
#include "BaseShape.h"
#include "AnimationStep.h"
namespace experis
{

template<typename T>
class AnimationRepeat : public AnimationStep
{
public:
	AnimationRepeat() = delete;
	AnimationRepeat(const AnimationRepeat& a_other) = delete;
	AnimationRepeat& operator=(const AnimationRepeat& a_other) = delete;
	~AnimationRepeat() = default;

	AnimationRepeat(BaseShape& a_shape, size_t a_numRepetitions , const T& a_executing)
		:AnimationStep{}
		,m_shape{a_shape}
		,m_numRepetitions{a_numRepetitions}
		,m_executing{a_executing}
	{
	}

	virtual void Operate()
	{
		for (size_t idx = 0 ; idx < m_numRepetitions ; ++idx)
		{
			m_executing(m_shape);
		}
	}

private:
	BaseShape& m_shape;
	size_t m_numRepetitions;
	T m_executing;
};


} //experis