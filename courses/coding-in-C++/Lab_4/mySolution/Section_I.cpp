/**
 * @file Section_1.cpp
 * @brief contains solution for Section_I
 */

#include <iostream>
#include <cmath>
#include <iomanip>

/**
 * @class Vector2D
 * @brief simple 2D point class
 */
class Vector2D
{
private:
    double x;
    double y;

public:
    Vector2D() : x(0.0), y(0.0) {}

    Vector2D(double x, double y) : x(x), y(y) {}

    double getX() const
    {
        return x;
    }

    double getY() const
    {
        return y;
    }

    void print() const
    {
        std::cout << "(" << this->getX() << ", " << this->getY() << ")" << std::endl;
    }

    double magnitude() const
    {
        return std::sqrt(this->getX() * this->getX() + this->getY() * this->getY());
    }

    double magnitude(int precision) const
    {
        double value = this->magnitude();
        double factor = std::pow(10.0, precision);
        return std::round(value * factor) / factor;
    }

    // Operator overloads
    Vector2D operator+(const Vector2D& b)
    {
        return Vector2D(this->getX() + b.getX(), this->getY() + b.getY());
    }

    void operator+=(const Vector2D& b)
    {
        this->x += b.getX();
        this->y += b.getY();
    }

    double operator*(const Vector2D& b)
    {
        return this->x * b.getX() + this->y * b.getY();
    }

    // Comparison
    bool operator==(const Vector2D& b)
    {
        return (this->x == b.getX() && this->y == b.getY());
    }

    bool operator!=(const Vector2D& b)
    {
        return !(this->x == b.getX() && this->y == b.getY());
    }
};

Vector2D operator*(const Vector2D& a, double b)
{
    return Vector2D(a.getX() * b, a.getY() * b);
}

Vector2D operator*(double b, const Vector2D& a)
{
    return Vector2D(a.getX() * b, a.getY() * b);
}

int main()
{
    Vector2D vec1(5, 10);
    Vector2D vec2(1, 2);
    
    std::cout << "Length (exact): " << vec1.magnitude() << std::endl;
    std::cout << "Length (precision 2): " << vec1.magnitude(2) << std::endl;

    vec1 = vec1 + vec2;
    vec1.print();

    vec1 += vec2;
    vec1.print();

    vec1 = vec1 * 2;
    vec1.print();

    vec1 = 0.5 * vec1;
    vec1.print();

    std::cout << vec1 * vec2 << std::endl;

    std::cout << std::boolalpha << (vec1 == vec2) << '\n' << (vec1 != vec2) << std::endl;

    return 0;
}