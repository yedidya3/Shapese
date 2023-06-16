#pragma once
#include "AnimationStep.h";
#include "BaseShape.h"
#include "AnimationRepeat.h"
#include <list>
#include "ShapeActionFuncHolder.h"

namespace experis
{

class Animation
{
public:
	Animation();
	Animation(const Animation& a_other) = delete;
	const Animation& operator=(const Animation& a_other) = delete;
	~Animation();

	void Add(AnimationStep* const a_step);
	void Add(BaseShape& a_shape, unsigned int a_numFrames, ShapeActionFuncHolder a_func);
	bool HasAnimation() const;
	void operator++();

private:
	std::list<AnimationStep*> m_steps;
};


} //experis