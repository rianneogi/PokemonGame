#pragma once
#include <stdio.h>
class Point
{
public:
    int x;
    int y;
    void display ();
	Point(int x = 0, int y = 0);
	~Point();
};

