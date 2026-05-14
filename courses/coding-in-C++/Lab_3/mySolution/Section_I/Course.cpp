/**
 * @file Course.cpp
 * @brief class implementation of Course
 */

#include "Course.hpp"

/**
 * @brief Add user to enrolled users list
 * @param user user to add
 */
void Course::enroll(User& user)
{
    enrolledUsers.push_back(&user);
}

/**
 * @brief remove user from enrolled users list
 * @param user user to remove from list
 */
void Course::leave(User& user)
{
    enrolledUsers.remove(&user);
}