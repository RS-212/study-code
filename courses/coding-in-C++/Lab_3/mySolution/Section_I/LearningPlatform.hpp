/**
 * @file LearningPlatform.hpp
 * @brief Class header for LearningPlatform class
 */

#ifndef LEARNING_PLATFORM_HPP
#define LEARNING_PLATFORM_HPP

#include <string>
#include <list>

// Forward declarations
class User;
class Course;

 /**
 * @class LearningPlatform
 * @brief Manages Courses and allows Users to enroll
 */
class LearningPlatform
{
private:
    std::string name;
    int numUsers;

    std::list<User*> users;
    std::list<Course*> courses;

public:
    /**
     * @brief Constructor of LearningPlatform
     * @param name name of the platform
     */
    LearningPlatform(const std::string& name) : name(name), numUsers(0)
    {}

    // Methonds defined in .cpp
    void printInfo() const;
    std::string setName() const;
    void enroll(User& user, Course& course);
    void leave(User& user, Course& course);
};

#endif // LEARNING_PLATFORM_HPP