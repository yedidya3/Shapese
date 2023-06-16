#pragma once
#include <chrono>
#include "Point.h"
#include "Circle.h"
#include "Line.h"
#include "Group.h"
#include "Rectangle.h"
#include "colored_canvas.hpp"
#include "canvas.hpp"
#include "canvas_inl.hpp"
#include "MoveBase.h"

#include "AnimationStep.h"

#include "AnimationRepeat.h"
#include "Animation.h"
#include <list>
namespace experis
{
using Color = ascii::ColoredCanvas;

void Waggon(Group& groupy);

void Train(Group& groupy);

void Rail(Group& a_group);

void Cloud(Group& a_group);

void Sun(Group& a_group);

void Car(Group& groupy);

std::list<Line*> Tree(Group& groupy);

} //experis
