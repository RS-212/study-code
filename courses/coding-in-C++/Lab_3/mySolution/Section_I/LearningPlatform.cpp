/**
 * @file LearningPlatform.cpp
 * @brief class implementation for LearningPlatform class
 */

#include "LearningPlatform.hpp"
#include <iostream>
#include "User.hpp"
#include "Course.hpp"

 /**
 * @brief prints info about the learning platform to console
 */
void LearningPlatform::printInfo() const
{
    std::cout << "Name: " << name << "\nNumber of Users: " << numUsers << std::endl;
}

/**
 * @brief get name of platform
 * @return platform name
 */
std::string LearningPlatform::setName() const
{
    return name;
}

/**
 * @brief add user to course, add course to users courses
 * @param user user to add to course
 * @param course course to add user to
 */
void LearningPlatform::enroll(User& user, Course& course)
{
    user.enroll(course);
    course.enroll(user);
}

/**
 * @brief remove user from course
 * @param user user to remove
 * @param course course to leave
 */
void LearningPlatform::leave(User& user, Course& course)
{
    user.leave(course);
    course.leave(user);
}