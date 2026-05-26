
#include <iostream>
#include <numbers>

class Shape
{
public:
    // the = 0 makes this class an abstrakt class, by making the function
    // area an entirely virtual function. It is no longer possible to instantiate
    // objects of the type Shape.
    virtual double area() const = 0;
    // This method should be virtual, because it is suppossed to have different behaviour
    // depending on the type of shape

    virtual ~Shape() {}
    // The class need a virtual destructor to avoid memory leaks
    // In case of storing child objects in Shape containers, only the shape
    // is destructed, when the child leaves scope.
};

class Circle : public Shape
{
private:
    double radius;
public:
    Circle(double radius) : radius(radius) {}

    // override makes sense here, because it avoids programmer error.
    // It makes sure the overridden function exists in the base class
    double area() const override
    {
        return std::numbers::pi * (radius * radius);
    }
};

class Rectangle : public Shape
{
private:
    double a;
    double b;
public:
    Rectangle(double a, double b) : a(a), b(b) {}

    // override makes sense here, because it avoids programmer error.
    // It makes sure the overridden function exists in the base class
    double area() const override
    {
        return a * b;
    }
};

int main()
{
    Circle circ(10);
    Rectangle rect(10, 20);

    std::cout << "Area Circle: " << circ.area() << std::endl;
    std::cout << "Area Rectangle: " << rect.area() << std::endl;

    // Polymorphism
    Circle circle1(5);
    Circle circle2(3);
    Rectangle rectangle1(12, 5);
    Rectangle rectangle2(3, 4);

    Shape* shapes[] = {&circle1, &circle2, &rectangle1, &rectangle2};

    for (int i = 0; i < sizeof(shapes) / sizeof(shapes[0]); i++)
    {
        std::cout << "Area of object at index " << i << ": " << shapes[i]->area() << std::endl;
    }
    // In the loop the implementation of the child classes of area is used.

    // The keaword virtual marks a method that is suppossed to be overridden in the child class.
    // Overriding a function gives the same function (same name and parameters) new behavior, depending on the type of object calling it
    // -> functions from parent classes are overridden in their children. (Polymorphism at runtime)
    // Overloading is using the same function name with different parameters. (Polymorphism at compile time)

    // A pure virtual function is a function marked virtual without an in implementation (= 0). It has to be overridden in the child class!
    // It also turns the class which contains it into an abstract class
    // Abtract classes are useful for implementing behaivior/structure, which is shared across different classes, but cannot exist without
    // further specifying things. (E.g. Shape is abstract, because calculating the area depends on the type of shape.
    // But area is shared behavior (all shapes have an area))

    return 0;
}