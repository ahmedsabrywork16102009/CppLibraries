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
    bool isPrime(int number) {
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
    bool isPerfect(int number) {
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
    bool isPalindrome(int number) {
        return number == reverseNumber(number);
    }

    /**
     * @brief Attempts to guess a 3-letter password by brute force.
     *
     * @param password Password to guess.
     * @return true If found.
     * @return false Otherwise.
     */
    bool guess3LetterPassword(const std::string &password) {
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
        for (char &character : text) {
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
        for (char &character : text) {
            character -= key;
        }

        return text;
    }

    /**
     * @brief Swaps the values of two integer numbers.
     *
     * @param num1 First number (passed by reference).
     * @param num2 Second number (passed by reference).
     */
    void swapNumbers(int &num1, int &num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    /**
     * @brief Generates a random number within a range.
     *
     * @param from Minimum value.
     * @param to Maximum value.
     * @return int Random number between from and to.
     */
    int randomInRange(int from, int to) {
        if (from > to) {
            swapNumbers(from, to);
        }

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

    /**
     * @brief Finds the maximum number in an array.
     *
     * @param arr Target array.
     * @param arrSize Number of elements in the array.
     * @return int The maximum value found.
     */
    int maxInArray(const int arr[], unsigned int arrSize) {
        if (arrSize == 0) return 0;
        
        int max = arr[0];

        for (unsigned int i = 1; i < arrSize; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        return max;
    }

    /**
     * @brief Finds the minimum number in an array.
     *
     * @param arr Target array.
     * @param arrSize Number of elements in the array.
     * @return int The minimum value found.
     */
    int minInArray(const int arr[], unsigned int arrSize) {
        if (arrSize == 0) return 0;

        int min = arr[0];

        for (unsigned int i = 1; i < arrSize; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }

        return min;
    }

    /**
     * @brief Calculates the sum of all elements in an array.
     *
     * @param arr Target array.
     * @param arrSize Number of elements in the array.
     * @return int The total sum of elements.
     */
    int sumArray(const int arr[], unsigned int arrSize) {
        int sum = 0;

        for (unsigned int i = 0; i < arrSize; i++) {
            sum += arr[i];
        }

        return sum;
    }

    /**
     * @brief Calculates the average of all elements in an array.
     *
     * @param arr Target array.
     * @param arrSize Number of elements in the array.
     * @return float The total average of elements (with decimals).
     */
    float averageArray(const int arr[], unsigned int arrSize) {
        if (arrSize == 0) return 0;

        return (float)sumArray(arr, arrSize) / arrSize;
    }

    /**
     * @brief Copies elements from one array to another.
     *
     * @param arr1 Source array to copy from.
     * @param arrSize Number of elements to copy.
     * @param arrResult Result array to copy into.
     */
    void copyArray(const int arr1[], unsigned int arrSize, int arrResult[]) {
        for (unsigned int i = 0; i < arrSize; i++) {
            arrResult[i] = arr1[i];
        }
    }

    /**
     * @brief Copies only prime numbers from source to result.
     *
     * @param arr1 Source array to search for prime numbers.
     * @param arrSize Number of elements in the source array.
     * @param arrResult Array where prime numbers will be stored.
     * @param resultSize Reference to store the number of elements actually copied.
     */
    void copyOnlyPrime(const int arr1[], unsigned int arrSize, int arrResult[], unsigned int &resultSize) {
        resultSize = 0;

        for (unsigned int i = 0; i < arrSize; i++) {
            if (isPrime(arr1[i])) {
                arrResult[resultSize] = arr1[i];
                resultSize++;
            }
        }
    }

    /**
     * @brief Sums elements of two arrays into a third array.
     *
     * @param arr1 First source array.
     * @param arr2 Second source array.
     * @param arrSize Number of elements to sum.
     * @param arrSum Array to store the results.
     */
    void sumArrays(const int arr1[], const int arr2[], unsigned int arrSize, int arrResult[]) {
        for (unsigned int i = 0; i < arrSize; i++) {
            arrResult[i] = arr1[i] + arr2[i];
        }
    }

}  // namespace process