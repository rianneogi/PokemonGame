#include "Vector2.h"


Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Vector2::normalize() {
    double m = magnitude();
    x = x / m;
    y = y / m;
}

double Vector2::magnitude() {
    double sumOfSquares = (x * x) + (y * y) ;
    return sqrt(sumOfSquares);
}
double Vector2::dotProduct(Vector2 other) {
    return fabs((x * other.x) + (y * other.y)) ;
}

void Vector2::display () {
    printf("(%.3f, %.3f)", x, y);
}

Vector2::~Vector2()
{
}
