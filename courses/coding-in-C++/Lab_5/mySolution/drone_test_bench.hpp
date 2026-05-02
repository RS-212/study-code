/**
 * @file drone_test_bench.hpp
 * 
 * @brief header file: learning templates using a drone test program as an example
 */

#include <iostream>
#include <string>
#include <vector>

/**
 * Task 1: A Template is better in this case because all given data types (int, double, string)
 * can be swapped using the method in the function.
 * Three different functions would just be the same code copy-pasted with different data types.
 */

/**
 * @brief generic function that swaps two values
 * 
 * @param[out] first_value will be swapped into second value
 * @param[out] second_value will be swapped into first value
 */
template <typename T>
void swap_payload(T& first_value, T& second_value)
{
    // Values before swap:
    std::cout   << "Before swap: \n first value: '"
                << first_value << "' second value: '"
                << second_value << "'" << std::endl;

    // Swapping code
    T temp = first_value;
    first_value = second_value;
    second_value = temp;

    // Values after swap:
    std::cout   << "After swap: \n first value: '"
                << first_value << "' second value: '"
                << second_value << "'" << std::endl;
}

/**
 * @brief prints all elements in sensor frame
 * 
 * @param[in] sensor_data array with sensor data
 */
template <typename T, int N>
void print_sensor_frame(T (&sensor_data)[N])
{
    std::cout << "[";
    for (int i = 0; i < N; i++)
    {
        std::cout << sensor_data[i];

        // Print commas between elements
        if (i < (N-1))
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

/**
 * @brief generic function that returns smallest member of array
 * 
 * @param[in] sensor_data array to analize
 * 
 * @return smallest value in in sensor_data
 */
template <typename T, int N>
T detect_weakest(T (&sensor_data)[N])
{
    T smallest = sensor_data[0];
    for (T element : sensor_data)
    {
        if (element < smallest)
        {
            smallest = element;
        }
    }
    return smallest;
}

/**
 * @brief generic function that prints 2 key value pairs
 * 
 * @param[in] label1 first key
 * @param[in] value1 first value
 * @param[in] label2 second key
 * @param[in] value2 second value
 */
template <typename T, typename U>
void compose_telemetry_tag(std::string label1, T value1, std::string label2, U value2)
{
    std::cout << label1 << ": " << value1 << " | " << label2 << ": " << value2 << std::endl;
}

/**
 * @brief Prints vector to console
 * 
 * @param vec Vector to print
 */
template <typename T>
void print_vector(const std::vector<T>& vec)
{
    std::cout << "[";
    for (typename std::vector<T>::const_iterator it = vec.begin(); it != (--vec.end()); ++it)
    {
        std::cout << *it << ", ";
    }
    std::cout << *(--vec.end()) << "]" << std::endl;
}