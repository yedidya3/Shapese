#pragma once
#include "BaseShape.h"
#include "Point.h"
#include <memory>
//#include "LeakMemoryCheck.h"
namespace experis
{

class Group : public BaseShape
{
public:

	explicit Group() = delete;
	Group(const Group& a_other);
	Group& operator=(const Group& a_other) = delete;
	~Group();

	explicit Group(short a_coordinateX, short a_coordinateY);
	explicit Group(const PropTree& a_propTree);	


	virtual void MoveBy(const Delta& a_deltaX, const Delta& a_deltaY) override;
	virtual void Draw(ascii::ColoredCanvas& a_canvas) const override;
	virtual Group* Copy() const override;

	virtual void SetDegrees(const short a_degree) override;

	template<typename T>
	T& Add(short a_coordinateX, const short a_coordinateY)
	{
		T *ptr = new T{a_coordinateX + BaseShape::GetBasePoint().GetX(), a_coordinateY +  BaseShape::GetBasePoint().GetY()};
		m_shapes.push_back(ptr);
		return *ptr;
	}

	template<typename T>
	T& Add(const short a_coordinateX, const short a_coordinateY,const short a_spaceshipArcRadius)
	{
		T *ptr = new T{a_coordinateX + BaseShape::GetBasePoint().GetX(), a_coordinateY +  BaseShape::GetBasePoint().GetY(), a_spaceshipArcRadius};
		m_shapes.push_back(ptr);
		return *ptr;
	}

	template<typename T, typename Arg1, typename Arg2>
	T& Add(const Point& a_basePoint, Arg1 a_arg1, Arg2 a_arg2)
	{
		T *ptr = new T{a_basePoint.GetMovedBy(BaseShape::GetBasePoint().GetX(), BaseShape::GetBasePoint().GetY()), short{a_arg1}, short{a_arg2}};
		m_shapes.push_back(ptr);
		return *ptr;
	}

	void Add(std::unique_ptr<BaseShape> a_shape);

	virtual void Exporting(std::function<void(const PropTree&)> a_funcExportHandling) const override;

	
private:
	std::vector<BaseShape*> m_shapes;
};

} //experis
