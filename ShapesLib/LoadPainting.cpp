#include "pch.h"
#include "LoadPainting.h"
#include "Line.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <functional>
#include <unordered_map>
#include <stack>
#include <sstream>
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include <fstream>
namespace experis
{
using PropTree = boost::property_tree::ptree;

//{type: Line, xBase:num, yBase:num, length:num, isDraw:bool, bg: } 
template<typename T>
void AddColarableShape(std::stack<std::unique_ptr<Group>>& a_groups, const PropTree& a_ptree)
{
	std::unique_ptr<T> k{std::make_unique<T>(a_ptree)};
	a_groups.top()->Add(std::move(std::make_unique<T>(a_ptree)));
}

void AddGroup(std::stack<std::unique_ptr<Group>>& a_groups, const PropTree& a_ptree)
{
	a_groups.push(std::make_unique<Group>(a_ptree));
}

void TakenOutGroup(std::stack<std::unique_ptr<Group>>& a_groups, const PropTree& a_ptree)
{
	if (a_groups.size() > 1)
	{
		std::unique_ptr<Group> groupToAdd{std::move(a_groups.top())};
		a_groups.pop();
		a_groups.top()->Add(std::move(groupToAdd));
	}
}


static std::unordered_map <std::string, std::function<void(std::stack<std::unique_ptr<Group>>&,const PropTree&)>> addsObjs
{
	{std::string{"Line"},&AddColarableShape<Line>}
	,{std::string{"Circle"},&AddColarableShape<Circle>}
	,{std::string{"Rectangle"},&AddColarableShape<Rectangle>}
	,{std::string{"StartGroup"},&AddGroup}
	,{std::string{"EndGroup"},&TakenOutGroup}
};



void WritePainting(const std::string& a_nameFile, const Group& a_painting)
{
	std::ofstream fileStream(a_nameFile);
	PropTree propTree{};
	a_painting.Exporting([&](const PropTree& a_treeProp)
		{
			std::stringstream  ssTempy{};
			boost::property_tree::json_parser::write_json(ssTempy, a_treeProp);\
			std::string result{ssTempy.str()};
			std::replace(result.begin() , result.end() , '\n' , ' ');
			fileStream << result << '\n';
		});

	
}
//std::unique_ptr<Group> LoadPainting::Load(const std::string& a_nameFile)
std::unique_ptr<Group> LoadPainting(const std::string& a_nameFile)
{
	std::ifstream infile(a_nameFile);
	std::stack<std::unique_ptr<Group>> stackGroups{};
	std::string line;
	while (std::getline(infile, line)) {

		std::stringstream lineStream{line};
		boost::property_tree::ptree pt;
		boost::property_tree::read_json(lineStream, pt);
		addsObjs[pt.get<std::string>("type")](stackGroups, pt); //TODo create to class
	}
	return std::move(stackGroups.top());
}


} //experis