/**
 * @file User.hpp
 * @brief class header for User class
 */

#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <list>

// Forward declarations
class LearningPlatform;
class Course;

/**
 * @class User
 * @brief Simple User class for the Learning Platform
 */
class User
{
private:
    // Attributes
    std::string name;
    std::string username;
    int birthyear;
    int id;

    // Assosiations
    std::list<Course*> myCourses;
    std::list<LearningPlatform*> myLearningPlatforms;

public:
    /**
     * @brief Constructor initializing all relevant attributes
     * @param name name of user
     * @param username username for user
     * @param birthyear year of birth
     * @param id user id
     */
    User(const std::string& name, const std::string& username, int birthyear, int id)
    : name(name), username(username), birthyear(birthyear), id(id)
    {}

    // Methods defined later
    void printInfo() const;
    std::string getName() const;
    std::string getUsername() const;
    int getId() const;
    int getAge(int year);
    void setName(const std::string& name);
    void setUsername(const std::string username);
    void setBirthyear(int year);
    void setId(int id);
    void enroll(Course& course);
    void leave(Course& course);
};

#endif // USER_HPP