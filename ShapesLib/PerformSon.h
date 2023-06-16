#pragma once
#include "ShapeActionFuncHolder.h"
#include "MoveBase.h"
#include "PerformBase.h"
namespace experis
{

template<typename T>
class PerformSon : public AbstractFunction
{
public:
	explicit PerformSon() = delete;
	PerformSon(const PerformSon<T>& a_other);
	PerformSon& operator=(const PerformSon<T>& a_other) = delete;
	~PerformSon();

	PerformSon(const T& a_someOne);

	virtual void operator()(BaseShape& a_shape) const override;
	virtual PerformSon<T>* Clone() const override;

private:
	T* m_someOne;
};

template<typename T>
PerformSon<T>::PerformSon(const PerformSon<T>& a_other)
	:AbstractFunction{a_other}
	,m_someOne{new T{a_other.m_someOne}}
{
}

template<typename T>
PerformSon<T>::~PerformSon() 
{
	delete m_someOne; 
};

template<typename T>
PerformSon<T>::PerformSon(const T& a_someOne)
	:AbstractFunction{}
	,m_someOne{ new T{a_someOne} }
{
}

template<typename T>
void PerformSon<T>::operator()(BaseShape& a_shape) const
{
	m_someOne->operator()(a_shape);
}

template<typename T>
PerformSon<T>* PerformSon<T>::Clone() const
{
	return new PerformSon<T>{*m_someOne};
}

} //experis

