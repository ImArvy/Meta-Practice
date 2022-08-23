// arr[1...n] includes the integers from 1 to n exactly once each, in some order.
// Initially, each student is holding their own yearbook.
// Each student i will first sign the yearbook that they're currently holding (either their own or another student's).
// Then they'll pass it to student arr[i-1].
// It's possible that arr[i-1] = i for any given i, in which case student i will pass their yearbook back to themselves.
// Once a student has received their own yearbook back, they will hold on to it and no longer participate in the passing process.
// Each student will eventually receive their own yearbook back and will never end up holding more than one yearbook at a time.
// Compute a list of n integers output, whose element at i-1 is equal to the number of signatures that will be present in student i's yearbook once they receive it back.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findSignatureCounts(vector<int>&);
	void printVector(vector<int>&);
	void checkOutput(vector<int>&, vector<int>&);
};

// Function that computes a list of n integers output whose element at i - 1 is equal to the 
// number of signatures that will be present in student i's yearbook once they receive it back
vector<int> Solution::findSignatureCounts(vector<int>& arr) {
	vector<int> signatureCounts(arr.size(), 0);
	vector<bool> hasOwnYearbook(arr.size(), false);

	for (int i = 1; i < arr.size(); i++) {
		// If student i can pass their yearbook
		if (hasOwnYearbook[i] == false) {
			signatureCounts[i]++; // Student 1 signs their own yearbook
			signatureCounts[i - 1]++; // Student 2 signs their own yearbook

			// If student i will pass their yearbook back to themselves
			if (arr[i - 1] == i) {
				hasOwnYearbook[i] = true; // They have their own yearbook and no longer participate in the passing process
			// If student i does not have thier own yearbook
			} else {
				signatureCounts[i - 1]++; // Student 1 signs Student 2's yearbook
				signatureCounts[i]++; // Student 2 signs Student 1's yearbook
			}
		}
	}

	return signatureCounts; // Return vector signatureCounts  
}

// Function to print an int vector
void Solution::printVector(vector<int>& arr) {
	cout << "[";
	for (int i = 0; i < arr.size(); i++) {
		if (i != 0) {
			cout << ", ";
		}
		cout << arr[i];
	}
	cout << "]" << endl;
}

// Function to check test cases
void Solution::checkOutput(vector<int>& expected, vector<int>& actual) {
	cout << "Expected: ";
	printVector(expected);

	cout << "Actual: ";
	printVector(actual);
	
	if (expected == actual) {
		cout << "Correct" << endl;
	} else {
		cout << "Incorrect" << endl;
	}

	cout << endl;
}

int main() {
	Solution solution;

	vector<int> arr{2, 1};

	vector<int> expected{2, 2};
	vector<int> actual = solution.findSignatureCounts(arr);

	solution.checkOutput(expected, actual);

	// -------------------------------------------------------------

	Solution solutionTwo;

	vector<int> arrTwo{1, 2};

	vector<int> expectedTwo{1, 1};
	vector<int> actualTwo = solutionTwo.findSignatureCounts(arrTwo);

	solutionTwo.checkOutput(expectedTwo, actualTwo);

	return 0;
}