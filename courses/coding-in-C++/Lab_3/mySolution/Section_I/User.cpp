/**
 * @file User.cpp
 * @brief class implementation of User
 */

#include "User.hpp"
#include <iostream>

/**
 * @brief print user info to console
 */
void User::printInfo() const
{
    std::cout << "Username: " << username << "\nName: " << name
            << "\nUser ID: " << id << std::endl;
}

/**
 * @brief get name of user
 * @return name attribute
 */
std::string User::getName() const
{
    return name;
}

/**
 * @brief get username of user
 * @return username attribute
 */
std::string User::getUsername() const
{
    return username;
}

/**
 * @brief get user id
 * @return user id
 */
int User::getId() const
{
    return id;
}

/**
 * @brief get user age based on current year
 * @param year current year
 * @return user age
 */
int User::getAge(int year)
{
    return year - birthyear;
}

/**
 * @brief set name of user
 * @param name new name
 */
void User::setName(const std::string& name)
{
    this->name = name;
}

/**
 * @brief set username for user
 * @param username new username
 */
void User::setUsername(const std::string username)
{
    this->username = username;
}

/**
 * @brief set year of birth for user
 * @param year new birthyear
 */
void User::setBirthyear(int year)
{
    this->birthyear = year;
}

/**
 * @brief set new user id
 * @param id new user id
 */
void User::setId(int id)
{
    this->id = id;
}

/**
 * @brief enroll user in Course
 * @param course course to add to my courses
 */
void User::enroll(Course& course)
{
    myCourses.push_back(&course);
}

/**
 * @brief remove course from myCourses
 * @param course course to remove
 */
void User::leave(Course& course)
{
    myCourses.remove(&course);
}