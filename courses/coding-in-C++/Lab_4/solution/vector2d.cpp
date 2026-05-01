#include <iostream>
#include <cmath>

class Vector2D
{
private:
    double x;
    double y;

public:
    Vector2D() : x(0.0), y(0.0) {}
    Vector2D(double x, double y) : x(x), y(y) {}
    double getX() { return x; }
    double getY() { return y; }

    double getMagnitude()
    {
        return sqrt((x * x) + (y * y));
    }
    double getMagnitude(int precision)
    {
        double factor = std::pow(10.0, precision);
        double length = sqrt((x * x) + (y * y));
        return std::round(length * factor) / factor;
    }
};

int main()
{
    Vector2D vec1(4, 5);
    Vector2D vec2(1, 9);

    std::cout << vec1.getMagnitude() << std::endl;
    std::cout << vec1.getMagnitude(3) << std::endl;
}
