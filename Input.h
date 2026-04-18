#pragma once
#include <iostream>
#include <string>

namespace input {

    /**
     * @brief Reads a positive integer from the user.
     * 
     * @param message Prompt displayed to the user.
     * @return int The inputted positive integer.
     */
    int readPositiveInt(const std::string& message) {
        int number;

        do {
            std::cout << message;
            std::cin >> number;
        } while (number < 0);

        return number;
    }

    /**
     * @brief Reads a negative integer from the user.
     * 
     * @param message Prompt displayed to the user.
     * @return int The inputted negative integer.
     */
    int readNegativeInt(const std::string& message) {
        int number;

        do {
            std::cout << message;
            std::cin >> number;
        } while (number > 0);

        return number;
    }

    /**
     * @brief Reads a full line of text from the user.
     * 
     * @param message Prompt displayed to the user.
     * @return std::string The inputted text.
     */
    std::string readString(const std::string& message) {
        std::string text = "";

        std::cout << message;
        std::getline(std::cin, text);

        return text;
    }

    /**
     * @brief Fills an array with user input.
     * 
     * @param arr Array to fill.
     * @param arrSize Number of elements to read.
     */
    void readArray(int arr[], unsigned int arrSize) {
        for (unsigned int i = 0; i < arrSize; i++) {
            std::cout << "Element [" << i + 1 << "] : ";
            std::cin >> arr[i];
        }
    }

}  // namespace input