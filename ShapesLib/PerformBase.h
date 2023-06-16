#pragma once
#include "BaseShape.h"

namespace experis
{


class AbstractFunction 
{
public:
	explicit AbstractFunction() = default;
	AbstractFunction(const AbstractFunction& a_other) = delete;
	AbstractFunction& operator=(const AbstractFunction& a_other) = delete;
	virtual ~AbstractFunction() = default;

	virtual void operator()(BaseShape& a_shape) const = 0; // Try not to have a virtual operator
	virtual AbstractFunction* Clone() const = 0;
private:

};

}
