/**
 * @file Course.hpp
 * @brief class header for Course class
 */

#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include <list>

// Forward declarations
class User;
class LearningPlatform;
class Lesson;

/**
 * @class Course
 * @brief Course class for the learning platform
 */
class Course
{
private:
    // Attributes
    std::string title;
    std::string description;

    // Associations
    std::list<User*> enrolledUsers;
    std::list<LearningPlatform*> platforms;
    std::list<Lesson*> lessons;

public:
    /**
     * @brief Constructor
     * @param title title of the course
     * @param description course description
     */
    Course(const std::string& title, const std::string& description)
    : title(title), description(description)
    {}

    // Methods defined later
    void enroll(User& user);
    void leave(User& user);
};

#endif // COURSE_HPP