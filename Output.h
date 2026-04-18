#pragma once
#include <iostream>
#include <string>

#include "process.h"

namespace output {
    /**
     * @brief Prints the 1-10 multiplication table.
     */
    void printMultiplicationTable() {
        // Multiplication Header
        std::cout << "\n\t\t\t\tMultiplication Table From 1 to 10\n\n";
        for (int i = 1; i <= 10; i++) {
            std::cout << "\t" << i;
        }
        std::cout << "\n____________________________________________________________________________________\n";

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
    void printPrimeNumbersInRange(int from, int to) {
        std::cout << "Prime numbers from " << from << " to " << to << " are [";

        bool isFirst = true;

        for (int i = from; i <= to; i++) {
            if (process::isPrimeNumber(i)) {
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
    void printPerfectNumbersInRange(int from, int to) {
        std::cout << "Perfect numbers from " << from << " to " << to << " are [";

        bool isFirst = true;

        for (int i = from; i <= to; i++) {
            if (process::isPerfectNumber(i)) {
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
    void printDigitsReversed(int number) {
        while (number > 0) {
            int remainder = number % 10;
            number /= 10;

            std::cout << remainder << std::endl;
        }
    }

    /**
     * @brief Prints the occurrences count of each digit within a number.
     *
     * @param number Target number.
     */
    void printDigitOccurrences(int number) {
        for (int i = 0; i < 10; i++) {
            short occurrencesCount = process::countDigitOccurrences(number, i);
            if (occurrencesCount > 0) {
                std::cout << "Digit " << i << " Occurrences is " << occurrencesCount << " Time(s).\n";
            }
        }
    }

    /**
     * @brief Prints a descending inverted number pattern.
     *
     * @param number Start number for the pattern.
     */
    void printInvertedNumberPattern(int number) {
        std::cout << "\n";

        for (int i = number; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                std::cout << i;
            }

            std::cout << "\n";
        }
    }

    /**
     * @brief Prints an ascending number pattern.
     *
     * @param number End number for the pattern.
     */
    void printNumberPattern(int number) {
        std::cout << "\n";

        for (int i = 1; i <= number; i++) {
            for (int j = 1; j <= i; j++) {
                std::cout << i;
            }

            std::cout << "\n";
        }
    }

    /**
     * @brief Prints a descending inverted letter pattern.
     *
     * @param number Number of letter rows.
     */
    void printInvertedLetterPattern(int number) {
        std::cout << "\n";

        for (int i = number; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                std::cout << char(i + 64);
            }

            std::cout << "\n";
        }
    }

    /**
     * @brief Prints an ascending letter pattern.
     *
     * @param number Number of letter rows.
     */
    void printLetterPattern(int number) {
        std::cout << "\n";

        for (int i = 1; i <= number; i++) {
            for (int j = 1; j <= i; j++) {
                std::cout << char(i + 64);
            }

            std::cout << "\n";
        }
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
    void printRandomKeys(int numberOfKeys, int wordsPerKey, int wordLength, process::enCharType charType, char separator) {
        for (int i = 1; i <= numberOfKeys; i++) {
            std::cout << "Key [" << i << "] : " << process::generateRandomKey(wordsPerKey, wordLength, charType, separator) << "\n";
        }
    }

    /**
     * @brief Prints all elements in an array.
     *
     * @param arr Target array.
     * @param arrSize Array size.
     */
    void printArray(const int arr[], unsigned int arrSize) {
        for (unsigned int i = 0; i < arrSize; i++) {
            std::cout << arr[i] << " ";
        }
    }

    /**
     * @brief Prints the occurrences count of a number within an array.
     *
     * @param arr Target array.
     * @param arrSize Array size.
     * @param numberToCheck Number to count.
     */
    void printOccurrences(const int arr[], unsigned int arrSize, int numberToCheck) {
        std::cout << "\n"
                  << numberToCheck << " is repeated " << process::countOccurrences(arr, arrSize, numberToCheck) << " time(s)";
    }

}  // namespace output