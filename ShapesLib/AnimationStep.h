#pragma once

namespace experis
{

class AnimationStep
{
public:
	AnimationStep();
	AnimationStep(const AnimationStep& a_other) = delete;
	AnimationStep& operator=(const AnimationStep& a_other) = delete;
	virtual ~AnimationStep();

	virtual void Operate() = 0;

private:

};

} //experis
