#pragma once

#include <iostream>
#include <string>
#include <string_view>

#include "process.h"

namespace output {
    /**
     * @brief Prints the 1-10 multiplication table.
     */
    void printMultiplicationTable(std::string_view title = "\n\t\t\t\tMultiplication Table From 1 to 10\n\n", std::string_view separator = "\n____________________________________________________________________________________\n") {
        // Multiplication Header
        std::cout << title;
        for (int i = 1; i <= 10; i++) {
            std::cout << "\t" << i;
        }
        std::cout << separator;

        // Multiplication Main
        for (int i = 1; i <= 10; i++) {
            std::cout << i << process::columnSeparator(i) << " ";
            for (int j = 1; j <= 10; j++) {
                std::cout << "\t" << i * j;
            }

            std::cout << "\n";
        }
    }

    /**
     * @brief Prints prime numbers within a range.
     *
     * @param from Start of the range.
     * @param to End of the range.
     */
    void printPrimeNumbersInRange(std::string_view message, int from, int to) {
        std::cout << message;

        bool isFirst = true;

        for (int i = from; i <= to; i++) {
            if (process::isPrime(i)) {
                if (!isFirst) {
                    std::cout << ", ";
                }

                std::cout << i;

                isFirst = false;
            }
        }

        std::cout << "]";
    }

    /**
     * @brief Prints perfect numbers within a range.
     *
     * @param from Start of the range.
     * @param to End of the range.
     */
    void printPerfectNumbersInRange(std::string_view message, int from, int to) {
        std::cout << message;

        bool isFirst = true;

        for (int i = from; i <= to; i++) {
            if (process::isPerfect(i)) {
                if (!isFirst) {
                    std::cout << ", ";
                }

                std::cout << i;

                isFirst = false;
            }
        }

        std::cout << "]";
    }

    /**
     * @brief Prints digits of a number in reverse order.
     *
     * @param number Target number.
     */
    template <typename T>
    void printDigitsReversed(T number) {
        std::cout << process::reverseNumber(number);
    }

    /**
     * @brief Prints the occurrences count of each digit within a number.
     *
     * @param number Target number.
     */
    template <typename T>
    void printDigitOccurrences(T number, std::string_view label = "Digit ", std::string_view resultText = " Occurrences is ", std::string_view unitText = " Time(s).\n") {
        for (int i = 0; i < 10; i++) {
            int occurrencesCount = process::countDigitOccurrences(number, (T)i);
            if (occurrencesCount > 0) {
                std::cout << label << i << resultText << occurrencesCount << unitText;
            }
        }
    }

    /**
     * @brief Prints a descending inverted number pattern.
     *
     * @param rows Start number for the pattern.
     */
    void printInvertedNumberPattern(int rows) {
        std::cout << process::generateInvertedNumberPattern(rows);
    }

    /**
     * @brief Prints an ascending number pattern.
     *
     * @param rows End number for the pattern.
     */
    void printNumberPattern(int rows) {
        std::cout << process::generateNumberPattern(rows);
    }

    /**
     * @brief Prints a descending inverted letter pattern.
     *
     * @param rows Number of letter rows.
     */
    void printInvertedLetterPattern(int rows) {
        std::cout << process::generateInvertedLetterPattern(rows);
    }

    /**
     * @brief Prints an ascending letter pattern.
     *
     * @param rows Number of letter rows.
     */
    void printLetterPattern(int rows) {
        std::cout <<process::generateLetterPattern(rows);
    }

    /**
     * @brief Prints all 3-letter combinations from AAA to ZZZ.
     */
    void printWordsFromAAAToZZZ() {
        std::string word = "AAA";

        for (int i = 0; i < 26; i++) {
            word[0] = 'A' + i;

            for (int j = 0; j < 26; j++) {
                word[1] = 'A' + j;

                for (int k = 0; k < 26; k++) {
                    word[2] = 'A' + k;

                    std::cout << word << "\n";
                }
            }
        }
    }

    /**
     * @brief Prints generated random keys.
     *
     * @param numberOfKeys Total keys to print.
     * @param wordsPerKey Words per key.
     * @param wordLength Characters per word.
     * @param charType Character set to use.
     * @param separator Delimiter between words.
     */
    void printRandomKeys(int numberOfKeys, int wordsPerKey, int wordLength, process::enCharType charType, char separator, std::string_view keyPrefix = "Key [", std::string_view keySeparator = "] : ") {
        for (int i = 1; i <= numberOfKeys; i++) {
            std::cout << keyPrefix << i << keySeparator << process::generateRandomKey(wordsPerKey, wordLength, charType, separator) << "\n";
        }
    }

    /**
     * @brief Prints all elements in an array with a custom header.
     *
     * @param header Text to display before elements.
     * @param arr Target array.
     * @param arrSize Array size.
     */
    template <typename T>
    void printArray(std::string_view header, const T arr[], unsigned int arrSize) {
        std::cout << header;

        for (unsigned int i = 0; i < arrSize; i++) {
            std::cout << arr[i] << " ";
        }

        std::cout << "\n";
    }

    /**
     * @brief Prints the occurrences count of an element within an array.
     *
     * @param arr Target array.
     * @param arrSize Array size.
     * @param elementToSearch Element to count.
     * @param message Text formatting prefix.
     */
    template <typename T>
    void printOccurrences(const T arr[], unsigned int arrSize, T elementToSearch, std::string_view message = "", std::string_view suffix = " time(s)\n") {
        std::cout << message << process::countOccurrences(arr, arrSize, elementToSearch) << suffix;
    }

    /**
     * @brief Prints a string array with indices.
     *
     * @param arr Target array.
     * @param arrSize Array size.
     * @param message Header message.
     */
    void printStringArray(const std::string arr[], unsigned int arrSize, std::string_view message = "", std::string_view indexPrefix = "Array[", std::string_view indexSuffix = "] : ") {
        std::cout << message;
        for (unsigned int i = 0; i < arrSize; i++) {
            std::cout << indexPrefix << i << indexSuffix << arr[i] << "\n";
        }
    }

    /**
     * @brief Prints the result of a search operation.
     *
     * @param index The found index or -1 if not found.
     * @param foundMsg Descriptive text for successful search.
     * @param notFoundMsg Text for failed search.
     */
    void printSearchResult(int index, std::string_view foundMsg = "Found at index: ", std::string_view notFoundMsg = "Not found.") {
        if (index == -1) {
            std::cout << notFoundMsg << "\n";
        } else {
            std::cout << foundMsg << index << "\n";
        }
    }

}  // namespace output