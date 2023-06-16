#include "pch.h"
#include "Animation.h"

namespace experis
{

Animation::Animation()
	:m_steps{}
{
}

Animation::~Animation()
{
}

void Animation::Add(AnimationStep* const a_step)
{
	m_steps.push_back(a_step);
}

void Animation::Add(BaseShape& a_shape, unsigned int a_numFrames, ShapeActionFuncHolder a_func)
{
	m_steps.push_back(new AnimationRepeat<ShapeActionFuncHolder>{a_shape, a_numFrames, a_func});
}

bool Animation::HasAnimation() const 
{
	return !m_steps.empty();
}

void Animation::operator++()
{
	m_steps.front()->Operate();
	m_steps.pop_front();
}

} //experis