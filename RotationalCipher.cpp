#include <iostream>
#include <string>

using namespace std;

// Helper function to check test cases
void checkOutput(string& expected, string& actual) {
    cout << "Expected: " << expected << endl << "Actual: " << actual << endl; // Output the strings expected and actual

    // If the expected output matches the actual output 
    if (expected.compare(actual) == 0) {
        cout << "Correct" << endl << endl; // Output that the actual output is correct
    // If the expected output does not match the actual output 
    }
    else {
        cout << "Incorrect" << endl << endl; // Output that the actual output is incorrect
    }
}

// Helper function rotateNumbers will rotate a char that is a number by a given rotationFactor
void rotateNumbers(string& input, int i, int rotationFactor) {
    int charToRotate = (int)input[i] - 48; // Normalize range 48-57 to 0-9
    int rotatedChar = ((charToRotate + rotationFactor) % 10) + 48; // Rotate and wrap back around to 0
    input[i] = rotatedChar;
}

// Helper function rotateUppercaseLetters will rotate a char that is an uppercase letter by a given rotationFactor
void rotateUppercaseLetters(string& input, int i, int rotationFactor) {
    int charToRotate = (int)input[i] - 65; // Normalize range 65-90 to 0-25
    int rotatedChar = ((charToRotate + rotationFactor) % 26) + 65; // Rotate and wrap back around to 0
    input[i] = rotatedChar;
}

// Helper function rotateLowercaseLetters will rotate a char that is an lowercase letter by a given rotationFactor
void rotateLowercaseLetters(string& input, int i, int rotationFactor) {
    int charToRotate = (int)input[i] - 97; // Normalize range 97-122 to 0-25
    int rotatedChar = ((charToRotate + rotationFactor) % 26) + 97; // Rotate and wrap back around to 0
    input[i] = rotatedChar;
}

// Function rotationalCipher will rotate chars that are numbers, uppercase letters, and lowercase letters by a given rotationFactor
string rotationalCipher(string& input, int rotationFactor) {
    // Iterate over the string input
    for (int i = 0; i < input.length(); i++) {
        int currentChar = (int)input[i]; // ASCII code for input[i] stored in currentChar
        // Char is a number if ASCII in range 48-57
        if (currentChar >= 48 && currentChar <= 57) {
            rotateNumbers(input, i, rotationFactor); // Rotate the number
        // Char is an uppercase letter if ASCII in range 65-90
        } else if (currentChar >= 65 && currentChar <= 90) {
            rotateUppercaseLetters(input, i, rotationFactor); // Rotate the uppercase letter
        // Char is a lowercase letter if ASCII in range 97-122
        } else if (currentChar >= 97 && currentChar <= 122) {
            rotateLowercaseLetters(input, i, rotationFactor); // Rotate the lowercase letter
        // Char is not a number, uppercase letter, or lowercase letter
        } else {
            continue; // Skip this char
        }
    }
    return input; // Return the mutated string input
}

int main() {
    string input = "All-convoYs-9-be:Alert1.";
    int rotationFactor = 4;
    string expected = "Epp-gsrzsCw-3-fi:Epivx5.";
    string actual = rotationalCipher(input, rotationFactor);
    checkOutput(expected, actual);

    // --------------------------------------------------------------------

    string inputTwo = "abcdZXYzxy-999.@";
    int rotationFactorTwo = 200;
    string expectedTwo = "stuvRPQrpq-999.@";
    string actualTwo = rotationalCipher(inputTwo, rotationFactorTwo);
    checkOutput(expectedTwo, actualTwo);

    // --------------------------------------------------------------------

    string inputThree = "Zebra-493?";
    int rotationFactorThree = 3;
    string expectedThree = "Cheud-726?";
    string actualThree = rotationalCipher(inputThree, rotationFactorThree);
    checkOutput(expectedThree, actualThree);

    // --------------------------------------------------------------------

    string inputFour = "abcdefghijklmNOPQRSTUVWXYZ0123456789";
    int rotationFactorFour = 39;
    string expectedFour = "nopqrstuvwxyzABCDEFGHIJKLM9012345678";
    string actualFour = rotationalCipher(inputFour, rotationFactorFour);
    checkOutput(expectedFour, actualFour);

    // --------------------------------------------------------------------

    return EXIT_SUCCESS;
}