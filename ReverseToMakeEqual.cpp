#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> reversedPermutations;
public:
    void reverse(vector<int>&, int, int);
    void getReversedPermutations(vector<int>&);
    bool areTheyEqual(vector<int>&, vector<int>&);
    void checkOutput(bool, bool);
};

// Function to reverse a sub array of an array given start and end pointers
void Solution::reverse(vector<int>& inputA, int start, int end) {
    vector<int> newA = inputA; // Make a copy of inputA and store it in newA

    // While we are in range of start and end pointers
    while (start < end) {
        // Swap elements at position of current start and end pointers
        int temp = newA[start];
        newA[start] = newA[end];
        newA[end] = temp;
        
        // Increment the start pointer and decrement the end pointer
        start++;
        end--;
    }

    reversedPermutations.push_back(newA); // Push this new array with a reversed sub array to reversedPermutations
}

// Function to generate all sub arrays of an array
void Solution::getReversedPermutations(vector<int>& inputA) {
    // Start pointer
    for (int start = 0; start < inputA.size(); start++) {
        // End pointer
        for (int end = start; end < inputA.size(); end++) {
            reverse(inputA, start, end); // Reverse a sub array of the input array from current start pointer to current end pointer
        }
    }
}

// Function that returns true if sub arrays of arrayB can be reversed to be made equal to arrayA and false if they cannot
bool Solution::areTheyEqual(vector<int>& arrayA, vector<int>& arrayB) {
    // Base case => arrays are already equal
    if (arrayA == arrayB) {
        return true; // Return true
    }

    getReversedPermutations(arrayB); // Get reversed permutations of arrayB

    // Traverse through  reversed permutations of arrayB
    for (int i = 0; i < reversedPermutations.size(); i++) {
        // If this  reversed permutations of arrayB is equal to arrayA
        if (reversedPermutations[i] == arrayA) {
            return true; // Return true
        }
    }

    return false; // Return false if there was no reversed permuation of arrayB that equals arrayA
}

// Function to check test cases
void Solution::checkOutput(bool expected, bool actual) {
    // If the expected output matches the actual output 
    if (expected == actual) {
        cout << "Correct" << endl; // Output that the actual output is correct
    // If the expected output does not match the actual output 
    } else {
        cout << "Incorrect" << endl; // Output that the actual output is incorrect
    }
}

int main() {
    Solution solution;

    vector<int> arrayA{ 1, 2, 3, 4 };
    vector<int> arrayB{ 1, 4, 3, 2 };

    bool expected = true;
    bool actual = solution.areTheyEqual(arrayA, arrayB);

    solution.checkOutput(expected, actual);

    Solution solutionTwo;

    vector <int> arrayATwo{ 1, 2, 3, 4 };
    vector <int> arrayBTwo{ 1, 4, 3, 3 };

    bool expectedTwo = false;
    bool actualTwo = solutionTwo.areTheyEqual(arrayATwo, arrayBTwo);

    solutionTwo.checkOutput(expectedTwo, actualTwo);

    return 0;
}