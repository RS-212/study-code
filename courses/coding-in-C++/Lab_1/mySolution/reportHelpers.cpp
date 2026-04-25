/**
 * @file reportHelpers.cpp
 * 
 * @brief Implementation File containing helper functions to generate a report card
 */

// === Includes ===
#include "reportHelpers.hpp"
#include <limits>
#include <iomanip>

// === Helper Functions ===

/**
 * @brief Helper function to repeatedly read in a number from user until it is in valid range (between MIN_SCORE and MAX_SCORE)
 * 
 * @param[in] userPrompt Text to print as the prompt for the user
 * 
 * @return valid score
 */
std::uint_fast8_t readScore(std::string userPrompt)
{
    const std::uint_fast16_t MIN_SCORE = 0;
    const std::uint_fast16_t MAX_SCORE = 100;

    std::uint_fast16_t scoreFromUser = 0; // Use 16 bit int here -> avoid input being interpreted as char

    while (true)
    {
        std::cout << userPrompt << std::flush;

        if (std::cin.fail())
        {
            // Reset input buffer in case of invalid input
            std::cin.clear(); // Clear fail bit
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Read score as number
        if (!(std::cin >> scoreFromUser))
        {
            // Input failed 
            std::cout << "The value entered was not a number!, Please try again \n"; // no endl -> flush is called when the user is prompted for input again
            continue;
        }

        // Check if number is in valid range
        if (scoreFromUser < MIN_SCORE || scoreFromUser > MAX_SCORE)
        {
            // Invalid number entered
            std::cout << "Please enter a score between " << MIN_SCORE << " and " << MAX_SCORE << "!\n";
            continue;
        }

        // All checks passed
        break;
    }

    return static_cast<uint_fast8_t>(scoreFromUser);
}


// === Function Implementations ===

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
    std::uint_fast16_t& scoreFinalExam)
{
    // Prompt user for name
    std::cout << "Please enter your name: " << std::flush;
    
    // Read name using getline()
    std::string nameInput;
    std::cin >> std::ws; // Clear leading whitespace
    std::getline(std::cin, nameInput);

    // Store name using call by reference parameter
    studentName = nameInput;


    // Prompt user for Scores and store them directly:
    scoreHomework = readScore("Homework score: ");
    scoreMidterm = readScore("Midterm score: ");
    scoreFinalExam = readScore("Final exam score: ");
}

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
    std::string& letterGrade)
{
    const std::uint_fast16_t A_LIMIT = 90;
    const std::uint_fast16_t B_LIMIT = 80;
    const std::uint_fast16_t C_LIMIT = 70;
    const std::uint_fast16_t D_LIMIT = 60;
    const std::uint_fast16_t E_LIMIT = 50;
    // else: F

    const double HOMEWORK_WEIGHT = 0.4;
    const double MIDTERM_WEIGHT = 0.25;
    const double FINAL_WEIGHT = 0.35;

    // Weighted average of grades
    finalGrade = (scoreHomework * HOMEWORK_WEIGHT) + (scoreMidterm * MIDTERM_WEIGHT) + (scoreFinalExam * FINAL_WEIGHT);

    // Determine letter grade
    if (finalGrade < E_LIMIT)
    {
        letterGrade = "F";
        return;
    }
    if (finalGrade < D_LIMIT)
    {
        letterGrade = "E";
        return;
    }
    if (finalGrade < C_LIMIT)
    {
        letterGrade = "D";
        return;
    }
    if (finalGrade < B_LIMIT)
    {
        letterGrade = "C";
        return;
    }
    if (finalGrade < A_LIMIT)
    {
        letterGrade = "B";
        return;
    }
    letterGrade = "A";
}

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
    std::string const& letterGrade)
{
    const std::uint_fast16_t WIDTH_REPORT_CARD = 50;
    const std::uint_fast16_t WIDTH_ENTRY = 25;
    const std::uint_fast16_t GRADE_PRECISION = 2;

    // determine status before printing
    std::string status = "PASS";
    if (letterGrade == "D" || letterGrade == "F")
    {
        status = "CONDITIONAL PASS";
    }
    else if (letterGrade == "F")
    {
        status = "FAIL";
    }

    // Print formatted report card
    std::cout   << std::setfill('-') << std::right                      // '-' as filler for dividers
                << '\n'
                << std::setw(WIDTH_REPORT_CARD) << '\n'                 // divider is just a newline filled with '-'
                << "Student Report \n"
                << std::setw(WIDTH_REPORT_CARD) << '\n'
                << "Name: " << studentName << '\n'
                << '\n'
                << "Scores\n"
                << std::setw(WIDTH_REPORT_CARD) << '\n'
                << std::setprecision(GRADE_PRECISION)                   // Set grade precision
                << std::setfill(' ') << std::left                       // set space as filler for correct spacing
                << std::setw(WIDTH_ENTRY) << "Homework" << ": " << std::fixed << static_cast<double>(scoreHomework) << '\n'
                << std::setw(WIDTH_ENTRY) << "Midterm" << ": " << std::fixed << static_cast<double>(scoreMidterm) << '\n'
                << std::setw(WIDTH_ENTRY) << "Final Exam" << ": " << std::fixed << static_cast<double>(scoreFinalExam) << '\n'
                << '\n'
                << std::setw(WIDTH_ENTRY) << "Final Grade" << ": " << std::fixed << finalGrade << '\n'
                << std::setw(WIDTH_ENTRY) << "Letter Grade" << ": " << letterGrade << '\n'
                << std::setw(WIDTH_ENTRY) << "Status" << ": " << status << '\n'
                << std::setfill('-') << std::right                      // '-' as filler for dividers
                << std::setw(WIDTH_REPORT_CARD) << '\n' << std::flush;  // Last divider -> flush
}