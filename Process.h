#pragma once
#include <iostream>
#include <string>

namespace process {

    /**
     * @brief Helper to format column spacing for multiplication tables.
     *
     * @param number Base number.
     * @return std::string Spacing and vertical bar formatting.
     */
    std::string columnSeparator(int number) {
        if (number < 10) {
            return "    |";
        } else if (number < 100) {
            return "   |";
        } else if (number < 1000) {
            return "  |";
        } else if (number < 10000) {
            return " |";
        } else {
            return "";
        }
    }

    /**
     * @brief Checks if a number is prime.
     *
     * @param number Target number.
     * @return true If prime.
     * @return false Otherwise.
     */
    bool isPrimeNumber(int number) {
        if (number <= 1) {
            return false;
        }

        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                return false;
            }
        }

        return true;
    }

    /**
     * @brief Checks if a number is perfect.
     *
     * @param number Target number.
     * @return true If perfect.
     * @return false Otherwise.
     */
    bool isPerfectNumber(int number) {
        int sum = 0;

        for (int i = 1; i < number; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }

        return number == sum;
    }

    /**
     * @brief Calculates the sum of all digits in a number.
     *
     * @param number Target number.
     * @return int Sum of digits.
     */
    int sumDigits(int number) {
        int sum = 0;

        while (number > 0) {
            int remainder = number % 10;
            number /= 10;

            sum += remainder;
        }

        return sum;
    }

    /**
     * @brief Reverses the digits of a number.
     *
     * @param number Target number.
     * @return int Reversed number.
     */
    int reverseNumber(int number) {
        int reversedNumber = 0;

        while (number > 0) {
            int remainder = number % 10;
            number /= 10;

            reversedNumber = reversedNumber * 10 + remainder;
        }

        return reversedNumber;
    }

    /**
     * @brief Counts occurrences of a specific digit in a number.
     *
     * @param number Target number to search.
     * @param digitToCheck Digit to find.
     * @return int Count of the digit occurrences.
     */
    int countDigitOccurrences(int number, short digitToCheck) {
        int occurrencesCount = 0;

        while (number > 0) {
            int remainder = number % 10;
            number /= 10;

            if (remainder == digitToCheck) {
                occurrencesCount++;
            }
        }

        return occurrencesCount;
    }

    /**
     * @brief Checks if a number reads the same forwards and backwards.
     *
     * @param number Target number.
     * @return true If palindrome.
     * @return false Otherwise.
     */
    bool isPalindromeNumber(int number) {
        return number == reverseNumber(number);
    }

    /**
     * @brief Attempts to guess a 3-letter password by brute force.
     *
     * @param password Password to guess.
     * @return true If found.
     * @return false Otherwise.
     */
    bool guess3LetterPassword(const std::string& password) {
        std::string word = "AAA";

        int counter = 0;

        for (int i = 0; i < 26; i++) {
            word[0] = 'A' + i;

            for (int j = 0; j < 26; j++) {
                word[1] = 'A' + j;

                for (int k = 0; k < 26; k++) {
                    word[2] = 'A' + k;

                    counter++;

                    std::cout << "Trial [" << counter << "] : " << word << "\n";

                    if (word == password) {
                        std::cout << "Password is: " << password << "\n";
                        std::cout << "Found after " << counter << " Trial(s)";

                        return true;
                    }
                }
            }
        }

        return false;
    }

    /**
     * @brief Encrypts text using a shift key.
     *
     * @param text Original text.
     * @param key Shift value.
     * @return std::string Encrypted text.
     */
    std::string encryptTextV1(std::string text, short key) {
        for (char& character : text) {
            character += key;
        }

        return text;
    }

    /**
     * @brief Decrypts text using a shift key.
     *
     * @param text Encrypted text.
     * @param key Shift value used for encryption.
     * @return std::string Decrypted text.
     */
    std::string decryptTextV1(std::string text, short key) {
        for (char& character : text) {
            character -= key;
        }

        return text;
    }

    /**
     * @brief Generates a random number within a range.
     *
     * @param from Minimum value.
     * @param to Maximum value.
     * @return int Random number between from and to.
     */
    int randomInRange(int from, int to) {
        return rand() % (to - from + 1) + from;
    }

    /**
     * @brief Generates a random lowercase letter.
     *
     * @return char Random letter (a-z).
     */
    char randomSmallLetter() {
        return (char)randomInRange(97, 122);
    }

    /**
     * @brief Generates a random uppercase letter.
     *
     * @return char Random letter (A-Z).
     */
    char randomCapitalLetter() {
        return (char)randomInRange(65, 90);
    }

    /**
     * @brief Generates a random special character.
     *
     * @return char Random character (! to /).
     */
    char randomSpecialCharacter() {
        return (char)randomInRange(33, 47);
    }

    /**
     * @brief Generates a random digit character.
     *
     * @return char Random digit (0-9).
     */
    char randomDigit() {
        return randomInRange(48, 57);
    }

    /**
     * @brief Character type enum for generation.
     */
    enum enCharType {
        smallLetter = 1,
        capitalLetter = 2,
        specialCharacter = 3,
        digit = 4,
    };

    /**
     * @brief Gets a random character of a specific type.
     *
     * @param charType Required character type.
     * @return char Generated character.
     */
    char getRandomCharacter(enCharType charType) {
        switch (charType) {
            case enCharType::smallLetter:
                return randomSmallLetter();
            case enCharType::capitalLetter:
                return randomCapitalLetter();
            case enCharType::specialCharacter:
                return randomSpecialCharacter();
            case enCharType::digit:
                return (char)randomDigit();
            default:
                return '\0';
        }
    }

    /**
     * @brief Generates a random string word.
     *
     * @param charType Required character type.
     * @param wordLength Number of characters.
     * @return std::string The generated word.
     */
    std::string generateRandomWord(enCharType charType, int wordLength) {
        std::string word = "";

        word.reserve(wordLength);

        for (int i = 1; i <= wordLength; i++) {
            word.push_back(getRandomCharacter(charType));
        }

        return word;
    }

    /**
     * @brief Generates a multi-word random key.
     *
     * @param wordsPerKey Number of words.
     * @param wordLength Characters per word.
     * @param charType Character set to use.
     * @param separator Delimiter separating words.
     * @return std::string The generated key.
     */
    std::string generateRandomKey(int wordsPerKey, int wordLength, enCharType charType, char separator) {
        std::string key = "";
        int totalCapacity = (wordsPerKey * wordLength) + (wordsPerKey - 1);
        bool isFirst = true;

        key.reserve(totalCapacity);

        for (int i = 1; i <= wordsPerKey; i++) {
            if (!isFirst) {
                key.push_back(separator);
            }

            key.append(generateRandomWord(charType, wordLength));

            isFirst = false;
        }

        return key;
    }

    /**
     * @brief Counts occurrences of a specific number in an array.
     *
     * @param arr Target array.
     * @param arrSize Array size.
     * @param numberToCheck Number to count.
     * @return int Count of the number occurrences.
     */
    int countOccurrences(const int arr[], unsigned int arrSize, int numberToCheck) {
        int occurrencesCount = 0;

        for (unsigned int i = 0; i < arrSize; i++) {
            if (arr[i] == numberToCheck) {
                occurrencesCount++;
            }
        }

        return occurrencesCount;
    }

    /**
     * @brief Fills an array with random numbers within a specific range.
     *
     * @param arr Target array to fill.
     * @param arrSize Number of elements.
     * @param from Minimum random value.
     * @param to Maximum random value.
     */
    void fillRandom(int arr[], unsigned int arrSize, int from, int to) {
        for (unsigned int i = 0; i < arrSize; i++) {
            arr[i] = randomInRange(from, to);
        }
    }

}  // namespace process