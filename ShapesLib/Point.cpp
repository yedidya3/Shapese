#include "pch.h"
#include <cmath>
#include <corecrt_math.h>
#include "Point.h"

using namespace std;

static const double PI = 2.0 * acos(0.0);

Point& Point::RotateAround(CoordType a_rotationCenterX, CoordType a_rotationCenterY, double a_degrees)
{
	*this = GetRotatedAround(a_rotationCenterX, a_rotationCenterY, a_degrees);
	return *this;
}

Point Point::GetRotatedAround(CoordType a_rotationCenterX, CoordType a_rotationCenterY, double a_degrees) const
{
	double radians = PI * a_degrees / 180.0;
	CoordType originedX = m_x - a_rotationCenterX;
	CoordType originedY = m_y - a_rotationCenterY;
	double newX = originedX * cos(radians) - originedY * sin(radians);
	double newY = originedY * cos(radians) + originedX * sin(radians);
	return Point{ short(newX) + a_rotationCenterX, short(newY) + a_rotationCenterY };
}

double GetDegreeOfLine(const Point& a, const Point& b)
{
    // Calculate the midpoint of the line segment
    double centerX = (a.GetX() + b.GetX()) / 2.0;
    double centerY = (a.GetY() + b.GetY()) / 2.0;
    // Calculate the angle of the line segment relative to the x-axis
    double deltaX = b.GetX() - a.GetX();
    double deltaY = b.GetY() - a.GetY();
    double angle = std::atan2(deltaY, deltaX) * 180.0 / PI;
    // Rotate the line segment by the angle to get the x-axis-aligned line
    Point p1 = a.GetRotatedAround(centerX, centerY, -angle);
    Point p2 = b.GetRotatedAround(centerX, centerY, -angle);
    // Calculate the new angle of the x-axis-aligned line
    double newAngle = std::atan2(p2.GetY() - p1.GetY(), p2.GetX() - p1.GetX()) * 180.0 / PI;
    return newAngle;
}
