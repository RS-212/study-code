/**
 * @file gradeReport.cpp
 * 
 * @brief Program to visualize a report card
 */

#include <iostream>
#include <cstdint>
#include "reportHelpers.hpp"

int main()
{
    // Necessary variables:
    std::string studentName;
    std::uint_fast16_t scoreHomework = 0;
    std::uint_fast16_t scoreMidterm = 0;
    std::uint_fast16_t scoreFinalExam = 0;
    double finalGrade = 0.0;
    std::string letterGrade;

    // Function calls
    readStudentData(studentName, scoreHomework, scoreMidterm, scoreFinalExam);
    calculateGrade(scoreHomework, scoreMidterm, scoreFinalExam, finalGrade, letterGrade);
    printReport(studentName, scoreHomework, scoreMidterm, scoreFinalExam, finalGrade, letterGrade);

    return 0;
}