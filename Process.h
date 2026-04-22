#pragma once
#include <algorithm>
#include <random>
#include <string>
#include <string_view>

namespace process {

    /**
     * @brief Helper function to get the global random engine.
     *
     * @return std::mt19937& Reference to the static Mersenne Twister engine.
     */
    inline std::mt19937 &getRandomEngine() {
        static std::random_device rd;
        static std::mt19937 engine(rd());
        return engine;
    }

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
     * @return T Reversed number.
     */
    template <typename T>
    T reverseNumber(T number) {
        T reversedNumber = 0;

        while (number > 0) {
            T remainder = number % 10;
            number /= 10;

            reversedNumber = reversedNumber * 10 + remainder;
        }

        return reversedNumber;
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
     * @brief Counts occurrences of a specific digit in a number.
     *
     * @param number Target number to search.
     * @param digitToCheck Digit to find.
     * @return int Count of the digit occurrences.
     */
    template <typename T>
    int countDigitOccurrences(T number, T digitToCheck) {
        int occurrencesCount = 0;

        while (number > 0) {
            T remainder = number % 10;
            number /= 10;

            if (remainder == digitToCheck) {
                occurrencesCount++;
            }
        }

        return occurrencesCount;
    }

    /**
     * @brief Attempts to guess a 3-letter password by brute force.
     *
     * @param password Password to guess.
     * @return true If found.
     * @return false Otherwise.
     */
    bool guess3LetterPassword(std::string_view password) {
        std::string word = "AAA";

        for (int i = 0; i < 26; i++) {
            word[0] = 'A' + i;

            for (int j = 0; j < 26; j++) {
                word[1] = 'A' + j;

                for (int k = 0; k < 26; k++) {
                    word[2] = 'A' + k;

                    if (word == password) {
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
    std::string encryptTextV1(std::string_view text, short key) {
        std::string result(text);

        for (char &character : result) {
            character += key;
        }

        return result;
    }

    /**
     * @brief Decrypts text using a shift key.
     *
     * @param text Encrypted text.
     * @param key Shift value used for encryption.
     * @return std::string Decrypted text.
     */
    std::string decryptTextV1(std::string_view text, short key) {
        std::string result(text);

        for (char &character : result) {
            character -= key;
        }

        return result;
    }

    /**
     * @brief Swaps the values of two values.
     *
     * @param value1 First value (passed by reference).
     * @param value2 Second value (passed by reference).
     */
    template <typename T>
    void swapValue(T &value1, T &value2) {
        T temp = value1;
        value1 = value2;
        value2 = temp;
    }

    /**
     * @brief Generates a random number within a range.
     *
     * @param from Minimum value.
     * @param to Maximum value.
     * @return T Random number between from and to.
     */
    template <typename T>
    T randomInRange(T from, T to) {
        if (from > to) {
            swapValue(from, to);
        }

        std::uniform_int_distribution<long long> dist(from, to);
        return (T)dist(getRandomEngine());
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
     * @brief Counts occurrences of a specific element in an array.
     *
     * @param arr Target array.
     * @param arrSize Array size.
     * @param elementToSearch Element to count.
     * @return unsigned int Count of the element occurrences.
     */
    template <typename T>
    unsigned int countOccurrences(const T arr[], unsigned int arrSize, T elementToSearch) {
        unsigned int occurrencesCount = 0;

        for (unsigned int i = 0; i < arrSize; i++) {
            if (arr[i] == elementToSearch) {
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
    template <typename T>
    void fillRandom(T arr[], unsigned int arrSize, T from, T to) {
        for (unsigned int i = 0; i < arrSize; i++) {
            arr[i] = (T)randomInRange(from, to);
        }
    }

    /**
     * @brief Finds the maximum number in an array.
     *
     * @param arr Target array.
     * @param arrSize Number of elements in the array.
     * @return int The maximum value found.
     */
    template <typename T>
    T maxInArray(const T arr[], unsigned int arrSize) {
        if (arrSize == 0) return T();

        T max = arr[0];

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
     * @return T The minimum value found.
     */
    template <typename T>
    T minInArray(const T arr[], unsigned int arrSize) {
        if (arrSize == 0) return T();

        T min = arr[0];

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
     * @return T The total sum of elements.
     */
    template <typename T>
    T sumArray(const T arr[], unsigned int arrSize) {
        T sum = 0;

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
    template <typename T>
    float averageArray(const T arr[], unsigned int arrSize) {
        if (arrSize == 0) return 0;

        return (float)sumArray(arr, arrSize) / arrSize;
    }

    /**
     * @brief Copies elements from one array to another.
     *
     * @param arrSource Source array to copy from.
     * @param sourceSize Number of elements to copy.
     * @param arrDestination Result array to copy into.
     */
    template <typename T>
    void copyArray(const T arrSource[], unsigned int sourceSize, T arrDestination[]) {
        for (unsigned int i = 0; i < sourceSize; i++) {
            arrDestination[i] = arrSource[i];
        }
    }

    /**
     * @brief Copies only prime numbers from source to result.
     *
     * @param arrSource Source array to search for prime numbers.
     * @param sourceSize Number of elements in the source array.
     * @param arrDestination Array where prime numbers will be stored.
     * @param destSize Reference to store the number of elements actually copied.
     */
    template <typename T>
    void copyOnlyPrime(const T arrSource[], unsigned int sourceSize, T arrDestination[], unsigned int &destSize) {
        destSize = 0;

        for (unsigned int i = 0; i < sourceSize; i++) {
            if (isPrime((int)arrSource[i])) {
                arrDestination[destSize] = arrSource[i];
                destSize++;
            }
        }
    }

    /**
     * @brief Sums elements of two arrays into a third array.
     *
     * @param arrSource1 First source array.
     * @param arrSource2 Second source array.
     * @param arrSize Number of elements to sum.
     * @param arrDestination Array to store the results.
     */
    template <typename T>
    void sum2Arrays(const T arrSource1[], const T arrSource2[], unsigned int arrSize, T arrDestination[]) {
        for (unsigned int i = 0; i < arrSize; i++) {
            arrDestination[i] = arrSource1[i] + arrSource2[i];
        }
    }

    /**
     * @brief Fills the array with sorted numbers from 1 to arrSize.
     *
     * @param arr Target array.
     * @param arrSize Number of elements to fill.
     */
    template <typename T>
    void fillSorted(T arr[], unsigned int arrSize) {
        for (unsigned int i = 0; i < arrSize; i++) {
            arr[i] = (T)(i + 1);
        }
    }

    /**
     * @brief Shuffles the elements of an array randomly.
     *
     * @param arr Target array to shuffle.
     * @param arrSize Number of elements in the array.
     */
    template <typename T>
    void shuffleArray(T arr[], unsigned int arrSize) {
        std::shuffle(arr, arr + arrSize, getRandomEngine());
    }

    /**
     * @brief Copies elements from one array to another in reverse order.
     *
     * @param arrSource Source array.
     * @param sourceSize Number of elements to copy.
     * @param arrDestination Array to store the reversed elements.
     */
    template <typename T>
    void copyInReverse(const T arrSource[], unsigned int sourceSize, T arrDestination[]) {
        for (unsigned int i = 0, j = sourceSize - 1; i < sourceSize; i++, j--) {
            arrDestination[i] = arrSource[j];
        }
    }

    /**
     * @brief Checks if an array is sorted in ascending order.
     *
     * @param arr Target array.
     * @param arrSize Number of elements in the array.
     * @return true If the array is sorted in ascending order.
     * @return false Otherwise.
     */
    template <typename T>
    bool isSorted(const T arr[], unsigned int arrSize) {
        if (arrSize <= 1) return true;

        for (unsigned int i = 0; i < arrSize - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }

        return true;
    }

    /**
     * @brief Fills a string array with random keys.
     *
     * @param arr Target array.
     * @param arrSize Number of elements.
     * @param wordsPerKey Words per key.
     * @param wordLength Characters per word.
     * @param charType Character set to use.
     * @param separator Delimiter separating words.
     */
    void fillWithRandomKeys(std::string arr[], unsigned int arrSize, int wordsPerKey, int wordLength, enCharType charType, char separator) {
        for (unsigned int i = 0; i < arrSize; i++) {
            arr[i] = generateRandomKey(wordsPerKey, wordLength, charType, separator);
        }
    }

    /**
     * @brief Finds the first occurrence index of an element in an array.
     *
     * @param arr Target array.
     * @param arrSize Number of elements.
     * @param elementToSearch Value to find.
     * @return short Index (0-based) if found, -1 otherwise.
     */
    /**
     * @brief Generates a descending inverted number pattern string.
     *
     * @param rows Start number for the pattern.
     * @return std::string The formatted pattern.
     */
    std::string generateInvertedNumberPattern(int rows) {
        std::string pattern = "";
        // Formula: (rows * (rows + 1) / 2) for total digits + 'rows' for newline characters
        pattern.reserve((rows * (rows + 1) / 2) + rows);

        for (int i = rows; i >= 1; i--) {
            std::string strI = std::to_string(i);
            for (int j = 1; j <= i; j++) {
                pattern.append(strI);
            }
            pattern.push_back('\n');
        }
        return pattern;
    }

    /**
     * @brief Generates an ascending number pattern string.
     *
     * @param rows End number for the pattern.
     * @return std::string The formatted pattern.
     */
    std::string generateNumberPattern(int rows) {
        std::string pattern = "";
        // Formula: (rows * (rows + 1) / 2) for total digits + 'rows' for newline characters
        pattern.reserve((rows * (rows + 1) / 2) + rows);

        for (int i = 1; i <= rows; i++) {
            std::string strI = std::to_string(i);
            for (int j = 1; j <= i; j++) {
                pattern.append(strI);
            }
            pattern.push_back('\n');
        }
        return pattern;
    }

    /**
     * @brief Generates a descending inverted letter pattern string.
     *
     * @param rows Number of letter rows.
     * @return std::string The formatted pattern.
     */
    std::string generateInvertedLetterPattern(int rows) {
        std::string pattern = "";
        // Formula: (rows * (rows + 1) / 2) for total letters + 'rows' for newline characters
        pattern.reserve((rows * (rows + 1) / 2) + rows);

        for (int i = rows; i >= 1; i--) {
            char ch = char(i + 64);
            for (int j = 1; j <= i; j++) {
                pattern.push_back(ch);
            }
            pattern.push_back('\n');
        }
        return pattern;
    }

    /**
     * @brief Generates an ascending letter pattern string.
     *
     * @param rows Number of letter rows.
     * @return std::string The formatted pattern.
     */
    std::string generateLetterPattern(int rows) {
        std::string pattern = "";
        // Formula: (rows * (rows + 1) / 2) for total letters + 'rows' for newline characters
        pattern.reserve((rows * (rows + 1) / 2) + rows);

        for (int i = 1; i <= rows; i++) {
            char ch = char(i + 64);
            for (int j = 1; j <= i; j++) {
                pattern.push_back(ch);
            }
            pattern.push_back('\n');
        }
        return pattern;
    }

    /**
     * @brief Finds the first occurrence index of an element in an array.
     *
     * @param arr Target array.
     * @param arrSize Number of elements.
     * @param elementToSearch Value to find.
     * @return int Index (0-based) if found, -1 otherwise.
     */
    template <typename T>
    int findIndexInArray(const T arr[], unsigned int arrSize, T elementToSearch) {
        for (unsigned int i = 0; i < arrSize; i++) {
            if (arr[i] == elementToSearch) {
                return (int)i;
            }
        }
        return -1;
    }

    /**
     * @brief Checks if a specific element exists in the array.
     *
     * @param arr Target array.
     * @param arrSize Number of elements.
     * @param elementToSearch Value to find.
     * @return true If the element is found, false otherwise.
     */
    template <typename T>
    bool isElementInArray(const T arr[], unsigned int arrSize, T elementToSearch) {
        return findIndexInArray(arr, arrSize, elementToSearch) != -1;
    }

    /**
     * @brief Adds a new element to the array and increments the size.
     *
     * @param arr The target array.
     * @param arrSize Reference to the current number of elements.
     * @param element The value to add.
     */
    template <typename T>
    void addArrayElement(T arr[], unsigned int &arrSize, T element) {
        arr[arrSize] = element;
        arrSize++;
    }

    /**
     * @brief Copies an array into another using addArrayElement logic.
     *
     * @param arrSource Source array.
     * @param sourceSize Number of elements to copy.
     * @param arrDestination Destination array.
     * @param destSize Reference to the destination array's current length.
     */
    template <typename T>
    void copyArrayUsingAddElement(const T arrSource[], unsigned int sourceSize, T arrDestination[], unsigned int &destSize) {
        for (unsigned int i = 0; i < sourceSize; i++) {
            addArrayElement(arrDestination, destSize, arrSource[i]);
        }
    }

    /**
     * @brief Copies only odd elements to the result array.
     *
     * @param arrSource Source array.
     * @param sourceSize Number of elements in source.
     * @param arrDestination Destination array.
     * @param destSize Reference to store result count.
     */
    template <typename T>
    void copyOddNumbers(const T arrSource[], unsigned int sourceSize, T arrDestination[], unsigned int &destSize) {
        destSize = 0;

        for (unsigned int i = 0; i < sourceSize; i++) {
            if (arrSource[i] % 2 != 0) {
                addArrayElement(arrDestination, destSize, arrSource[i]);
            }
        }
    }

    /**
     * @brief Copies only prime numbers to the result array.
     *
     * @param arrSource Source array.
     * @param sourceSize Number of elements in source.
     * @param arrDestination Destination array.
     * @param destSize Reference to store count of prime numbers.
     */
    template <typename T>
    void copyPrimeNumbers(const T arrSource[], unsigned int sourceSize, T arrDestination[], unsigned int &destSize) {
        destSize = 0;

        for (unsigned int i = 0; i < sourceSize; i++) {
            if (isPrime(arrSource[i])) {
                addArrayElement(arrDestination, destSize, arrSource[i]);
            }
        }
    }

    /**
     * @brief Copies only distinct elements to the result array.
     *
     * @param arrSource Source array.
     * @param sourceSize Number of elements in source.
     * @param arrDestination Destination array.
     * @param destSize Reference to store count of distinct elements.
     */
    template <typename T>
    void copyDistinctElements(const T arrSource[], unsigned int sourceSize, T arrDestination[], unsigned int &destSize) {
        destSize = 0;

        for (unsigned int i = 0; i < sourceSize; i++) {
            if (countOccurrences(arrDestination, destSize, arrSource[i]) == 0) {
                addArrayElement(arrDestination, destSize, arrSource[i]);
            }
        }
    }

}  // namespace process
