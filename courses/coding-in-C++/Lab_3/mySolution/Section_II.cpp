/**
 * @file Section_II.cpp
 * @brief learning inheritance in C++
 */

#include <iostream>
#include <string>

/**
 * @class User
 * @brief Simple User class used as base class
 */
class User
{
protected:
    // Protected attributes
    std::string name;
    int id;

public:
    // Public methods
    /**
     * @brief Constructor for the User class
     * @param name user name
     * @param id user id
     */
    User(const std::string& name, int id) : name(name), id(id)
    {}

    /**
     * @brief Print relevant info to console
     */
    void printInfo() const
    {
        std::cout << "User Name: " << name << "\nUser ID: " << id << std::endl;
    }
};


// Task 2 answers:
/**
 * Protected is used instead of private, so that the derived classes can access the Attributes.
 * If the access specifier in the inheritance decleration is deleted C++ defaults to private inheritance
 * -> calling printInfo from main is no longer possible
 * Calling the base class contructor is important, because it enables initializing name and id through an innitializer list.
 * Also it could contain important code (e.g. dynamic memory allocation)
 */

/**
 * @class Student
 * @brief derived from User with additional attribute and method
 */
class Student : public User
{
private:
    std::string course;

public:
    /**
     * @brief Constructor for Student calling Base contructor of User
     * @param name user name -> given to base class constructor
     * @param id user id -> given to base class constructor
     * @param course course the student is attending
     */
    Student(const std::string& name, int id, const std::string& course)
    : User(name, id), course(course)
    {}

    /**
     * @brief additional methon in derived class student
     */
    void printRole() const
    {
        std::cout << "Student:\n";
        std::cout << "User Name: " << name << "\nUser ID: " << id << std::endl;
        std::cout << "Attending course: " << course << '\n' << std::endl;
    }
};

/**
 * @class Instructor
 * @brief derived from User
 */
class Instructor : User
{
private:
    Student* favouriteStudent;

public:
    /**
     * @brief Constructor for Intructor
     * @param name user name
     * @param id user id
     * @param favStudent favourite student
     */
    Instructor(const std::string& name, int id, Student& favStudent)
    : User(name, id), favouriteStudent(&favStudent)
    {}

    /**
     * @brief additional methon in derived class Instructor
     */
    void printRole() const
    {
        std::cout << "Instructor:\n";
        std::cout << "User Name: " << name << "\nUser ID: " << id << std::endl;
        std::cout << "Favourite Student:\n";
        favouriteStudent->printInfo();
        std::cout << std::endl;
    }
};

int main()
{
    Student jerry("Jerry", 101, "TFE");
    Instructor jimmy("Jimmy", 202, jerry);

    jerry.printRole();
    jimmy.printRole();

    //jerry.printInfo(); // Works due to public inheritance
    //jimmy.printInfo(); // Doesn't work -> C++ defaults to private inheritance

    return 0;
}