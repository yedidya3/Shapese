#include "pch.h"
#include "Group.h"

namespace experis
{
namespace setToPropertyTreeGroup //convert to constexpr
{
	std::string baseShape{"BaseShape"};
	std::string typeStart{"StartGroup"};
	std::string typeEnd{"EndGroup"};
	std::string type{"type"};
}


Group::Group(short a_coordinateX, short a_coordinateY)
	:BaseShape{a_coordinateX, a_coordinateY}
	,m_shapes{}
{
}

Group::Group(const Group& a_other)
	:BaseShape{a_other.GetBasePoint().GetX(), a_other.GetBasePoint().GetY()}
	,m_shapes{}
{
	for (const BaseShape* oldElement : a_other.m_shapes)
	{
		m_shapes.push_back(oldElement->Copy());
	}
}

Group::Group(const PropTree& a_propTree)
	:BaseShape{a_propTree.get_child_optional(setToPropertyTreeGroup::baseShape).value()}
{
}

void Group::Exporting(std::function<void(const PropTree&)> a_funcExportHandling) const
{
	PropTree propTreeStart{};
	BaseShape::Exporting([&](const PropTree& a_treeProp)
		{
			propTreeStart.push_back(PropTree::value_type(setToPropertyTreeGroup::baseShape, a_treeProp));
		});
	propTreeStart.push_back(PropTree::value_type(setToPropertyTreeGroup::type, PropTree(setToPropertyTreeGroup::typeStart)));
	a_funcExportHandling(propTreeStart);
	for (const BaseShape* shape : m_shapes)
	{
		shape->Exporting(a_funcExportHandling);
	}
	PropTree propTreeEnd{};
	propTreeEnd.push_back(PropTree::value_type(setToPropertyTreeGroup::type, PropTree(setToPropertyTreeGroup::typeEnd)));
	a_funcExportHandling(propTreeEnd);
}

Group::~Group()
{
	for (const BaseShape* shape : m_shapes)
	{
		delete shape;
	}
}

void Group::MoveBy(const Delta& a_deltaX, const Delta& a_deltaY)
{
	BaseShape::MoveBy(a_deltaX, a_deltaY);
	for (BaseShape* shape : m_shapes)
	{
		shape->MoveBy(a_deltaX, a_deltaY);
	}
}

void Group::Draw(ascii::ColoredCanvas& a_canvas) const
{
	for (const BaseShape* shape : m_shapes)
	{
		shape->Draw(a_canvas);
	}
}

Group* Group::Copy() const
{
	return new Group{*this};
}

void Group::SetDegrees(const short a_degree)
{
	for (BaseShape* shape : m_shapes)
	{
		shape->SetDegrees(a_degree);
	}
}
void Group::Add(std::unique_ptr<BaseShape> a_shape)
{
	BaseShape *ptr = a_shape->Copy();
	m_shapes.push_back(ptr);
}

} //experis