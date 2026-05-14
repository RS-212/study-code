/**
 * @file Section_I.cpp
 * @brief C++ implementation of the Learning Platform UML diagramm
 */

#include <iostream>
#include <string>

#include "LearningPlatform.hpp"
#include "User.hpp"
#include "Course.hpp"
#include "Lesson.hpp"

// === Main function ===
int main()
{
    LearningPlatform moodle("Moodle");
    User frank("Frank Schneider", "schnfr", 2005, 101);
    Course informatik("Informaitk I", "In diesem Kurs lernt man das Programmieren.");

    moodle.enroll(frank, informatik);

    frank.printInfo();
    moodle.printInfo();

    std::cout << "Run successful!" << std::endl;
    return 0;
}