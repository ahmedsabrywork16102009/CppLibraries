#pragma once
#include <iostream>
#include <string>
#include <string_view>

#include "process.h"

namespace input {

    /**
     * @brief Reads a number of any type from the user.
     * 
     * @param message Prompt displayed to the user.
     * @return T The inputted number.
     */
    template <typename T>
    T readNumber(std::string_view message) {
        T number;

        std::cout << message;
        std::cin >> number;

        return number;
    }

    /**
     * @brief Reads a positive number from the user.
     * 
     * @param message Prompt displayed to the user.
     * @return T The inputted positive number.
     */
    template <typename T>
    T readPositiveNumber(std::string_view message) {
        T number;

        do {
            number = readNumber<T>(message);
        } while (number < 0);

        return number;
    }

    /**
     * @brief Reads a negative number from the user.
     * 
     * @param message Prompt displayed to the user.
     * @return T The inputted negative number.
     */
    template <typename T>
    T readNegativeNumber(std::string_view message) {
        T number;

        do {
            number = readNumber<T>(message);
        } while (number > 0);

        return number;
    }

    /**
     * @brief Reads a number within a range from the user.
     * 
     * @param message Prompt displayed to the user.
     * @param from The lower bound of the range.
     * @param to The upper bound of the range.
     * @return T The inputted number.
     */
    template <typename T>
    T readNumberInRange(std::string_view message, T from, T to) {
        T number;

        do {
            number = readNumber<T>(message);
        } while (number < from || number > to);

        return number;
    }

    /**
     * @brief Reads a full line of text from the user.
     * 
     * @param message Prompt displayed to the user.
     * @return std::string The inputted text.
     */
    std::string readString(std::string_view message) {
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
     * @param label Prefix for element index display.
     */
    template <typename T>
    void readArray(T arr[], unsigned int arrSize, std::string_view label = "Element [") {
        for (unsigned int i = 0; i < arrSize; i++) {
            std::cout << label << i + 1 << "] : ";
            std::cin >> arr[i];
        }
    }

    /**
     * @brief Prompts the user to enter numbers into an array until they choose to stop.
     * 
     * @param arr Target array.
     * @param arrSize Reference to store the final count of elements.
     * @param valueMessage Prompt for value input.
     * @param moreMessage Prompt for continuation choice.
     */
    template <typename T>
    void readArrayDynamically(T arr[], unsigned int &arrSize, std::string_view valueMessage = "\nPlease enter a value? ", std::string_view moreMessage = "\nDo you want to add more? [0]:No,[1]:yes? ") {
        bool addMore = true;
        arrSize = 0;

        do {
            T value = readNumber<T>(valueMessage);
            
            process::addArrayElement(arr, arrSize, value);

            addMore = readNumberInRange<bool>(moreMessage, 0, 1);
        } while (addMore);
    }

}  // namespace input