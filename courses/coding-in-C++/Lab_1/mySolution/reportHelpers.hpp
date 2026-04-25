/**
 * @file reportHelpers.hpp
 * 
 * @brief Header File containing helper functions to generate a report card
 */

#ifndef REPORT_HELPERS_HPP
#define REPORT_HELPERS_HPP

// === Includes ===
#include <iostream>
#include <string>
#include <cstdint>

// === Function Definitions ===

/**
 * @brief Prompts user for input. Validates input. Stores user input using call by reference
 * 
 * @param[out] studentName name of the student
 * @param[out] scoreHomework homework score
 * @param[out] scoreMidterm midterm score
 * @param[out] scoreFinalExam finals score
 */
void readStudentData(
    std::string& studentName,
    std::uint_fast16_t& scoreHomework,
    std::uint_fast16_t& scoreMidterm,
    std::uint_fast16_t& scoreFinalExam);

/**
 * @brief Applies weights to grades and calculates letter grade from finalGrade
 * 
 * @param[in] scoreHomework homework grade
 * @param[in] scoreMidterm midterm grade
 * @param[in] scoreFinalExam final exam grade
 * @param[out] finalGrade final weighted average grade
 * @param[out] letterGrade grade in letter form (A to F)
 */
void calculateGrade(
    std::uint_fast16_t scoreHomework,
    std::uint_fast16_t scoreMidterm,
    std::uint_fast16_t scoreFinalExam,
    double& finalGrade,
    std::string& letterGrade);

/**
 * @brief Prints formatted report card to console. Also determines status (Pass/Conditional Pass/Fail) before printing
 * 
 * @param[in] studentName name of the student
 * @param[in] scoreHomework homework grade
 * @param[in] scoreMidterm midterm grade
 * @param[in] scoreFinalExam final exam grade
 * @param[in] finalGrade weighted grade average
 * @param[in] letterGrade letter representation of the grade average
 */
void printReport(
    std::string const& studentName,
    std::uint_fast16_t scoreHomework,
    std::uint_fast16_t scoreMidterm,
    std::uint_fast16_t scoreFinalExam,
    double finalGrade,
    std::string const& letterGrade);

#endif // REPORT_HELPERS_HPP