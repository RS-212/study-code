/**
 * @file drone_test_bench.cpp
 * 
 * @brief learning templates using a drone test program as an example
 */

#include "drone_test_bench.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main ()
{
    // === SECTION I ===

    // test values int
    int number1 = 42;
    int number2 = 21;

    // test values double
    double d_number1 = 42.2;
    double d_number2 = 21.1;

    // test values std::string
    std::string text1 = "Hallo";
    std::string text2 = "Welt";

    // test array int
    int sensor_frame_int[] = {12, 15, 18, 21};

    // test array double
    double sensor_frame_double[] = {12.2, 15.5, 18.8, 21.1};

    // test array char
    char sensor_frame_char[] = {'2', '5', '8', '1'};


    // === Task 1 ===
    // int test
    swap_payload(number1, number2);

    std::cout << '\n';

    // double test
    swap_payload(d_number1, d_number2);

    std::cout << '\n';

    // std::string test
    swap_payload(text1, text2);

    std::cout << '\n';


    // === Task 2 ===
    // int test
    print_sensor_frame(sensor_frame_int);

    // double test
    print_sensor_frame(sensor_frame_double);

    // char test
    print_sensor_frame(sensor_frame_char);

    std::cout << '\n';

    // === Task 3 ===
    // int test
    std::cout << detect_weakest(sensor_frame_int) << std::endl;

    // double test
    std::cout << detect_weakest(sensor_frame_double) << std::endl;

    std::cout << '\n';


    // === Task 4 ===
    compose_telemetry_tag("Channel", "motor_temp", "Priority", 2);

    std::cout << '\n';

    
    // === Task 5 ===
    int int_arr_size_4[4] = {1, 2, 3, 4};
    double double_arr_size_6[6] = {1, 2, 3, 4, 5, 6};

    print_sensor_frame(int_arr_size_4);
    std::cout << detect_weakest(int_arr_size_4) << std::endl;

    print_sensor_frame(double_arr_size_6);
    std::cout << detect_weakest(double_arr_size_6) << std::endl;

    std::cout << std::endl;

    /**
     * Answers to questions:
     * The size is no longer needed, because the compiler knows the array size at compile time.
     * This eliminates the risk of accessing memory outside the array by mistake
     * The user cannot give an incorrect size, simpler function interface,
     * safer function, errors are caught by compiler at compile time 
     */

    // === SECTION II ===

    std::cout << "=== Section II ===\n";

    // === Task 6 ===

    std::vector<int> flight_data = {42, 17, 42, 5, 99, 17, 63, 12};

    // Print data using foreach
    for (int data_point : flight_data)
    {
        std::cout << data_point << ' ';
    }
    std::cout << '\n' << std::endl;

    // Sort data using STL function
    std::sort(flight_data.begin(), flight_data.end());

    // Print sorted data
    print_vector(flight_data);

    std::cout << std::endl;

    // Search for value
    const int search_value = 63;

    std::vector<int>::iterator it;
    it = std::find(flight_data.begin(), flight_data.end(), search_value);

    std::cout << "The value '" << search_value;
    if (it != flight_data.end())
    {
        std::cout << "' exists!";
    }
    else
    {
        std::cout << "' doesn't exist!";
    }
    std::cout << '\n' << std::endl;


    // === Task 7 ===

    flight_data = {7, -1, 13, -1, 21, 21, 8, -1, 8};


    // Replace -1 with 0
    std::replace(flight_data.begin(), flight_data.end(), -1, 0);

    // Print data
    print_vector(flight_data);


    // Count number 8
    const int count_num = 8;
    int occurences = std::count(flight_data.begin(), flight_data.end(), count_num);

    // Print result
    std::cout << "The number " << count_num << " occurs " << occurences << " times." << std::endl;


    // Reverse data set
    std::reverse(flight_data.begin(), flight_data.end());

    // Print data
    print_vector(flight_data);

    std::cout << "\n\n";

    // === Task 8 ===
    // I already did something like this in my print function
    
    // Loop through vector using iterators
    for (std::vector<int>::iterator it = flight_data.begin(); it != flight_data.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    /**
     * using ++it increments the iterator. The iterator now points at the next element in the vector
     * 
     * using *it is like dereferencing a pointer. It allows accessing the value in the vector, the iterator points to
     */

    // === SECTION III ===

    std::cout << "\n=== SECTION III ===" << std::endl;

    // Task 9

    // Part A
    std::vector<int> test_vector_int = {42, 67, 81, 212, 90};
    std::vector<double> test_vector_double = {42.2, 67.7, 81.1, 212.2, 90.0};

    print_metrics(test_vector_int);
    print_metrics(test_vector_double);

    // Part B
    double sensor_frame[5] = {42.2, 34.4, 17.7, 18.8, 2.0};
    std::vector<double> frame_vector;

    frame_vector = transfer_data(sensor_frame);
    print_metrics(frame_vector);

    // Part C
    

    return 0;
}