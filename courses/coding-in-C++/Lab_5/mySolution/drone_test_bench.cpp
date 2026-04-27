/**
 * @file drone_test_bench.cpp
 * 
 * @brief learning templates using a drone test program as an example
 */

#include "drone_test_bench.hpp"
#include <iostream>
#include <string>

int main ()
{
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

    /**
     * Answers to questions:
     * The size is no longer needed, because the compiler knows the array size at compile time.
     * The template allows 
     */

    return 0;
}