#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <Point.h>
#include <Vector2.h>

class PerlinNoise
{
public:

    static const int LATTICE_X = 9;
    static const int LATTICE_Y = 9;
    static const int CELL_SIZE = 10;
    static const int PIXEL_X = (LATTICE_X - 1) * CELL_SIZE;
    static const int PIXEL_Y = (LATTICE_Y - 1) * CELL_SIZE;
    double pixels[PIXEL_X][PIXEL_Y];
	void populate();
	PerlinNoise();
	~PerlinNoise();
    double lerp(double a, double b, double t);
    double getRand();
};

