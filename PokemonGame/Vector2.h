#pragma once
#include <math.h>
#include <stdio.h>
class Vector2
{

public:
	double x;
	double y;
	Vector2(float x = 0, float y = 0);
    void normalize();
	double magnitude();
	double dotProduct(Vector2 other);
    void display();
	~Vector2();
};

