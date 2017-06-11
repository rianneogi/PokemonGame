#include "Point.h"



Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}


Point::~Point()
{
}

void Point::display()
{
    printf("(%d, %d)", x, y);
}
