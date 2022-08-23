#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> CountSubarrays(vector<int>&);
};

vector<int> Solution::CountSubarrays(vector<int>& arr) {
    vector<int> contiguousSubarraysCount; // Each index i contains an integer denoting the maximum number of contiguous subarrays of arr[i]

    // For each index i
    for (int i = 0; i < arr.size(); i++) {
        vector<vector<int>> contiguousSubarrays; // Holds contiguous subarrays found for arr[i]
        // Start indices
        for (int start = 0; start < arr.size(); start++) {
            // End indices
            for (int end = start; end < arr.size(); end++) {
                vector<int> contiguousSubarray; // Holds current contiguous subarray
                // Indices in range from start to end
                for (int range = start; range <= end; range++) {
                    contiguousSubarray.push_back(arr[range]);
                }

                // The value at index i must be the maximum element in the contiguous subarray
                if (arr[i] == *max_element(contiguousSubarray.begin(), contiguousSubarray.end())) {
                    // These contiguous subarrays must either start from or end on index i
                    if (contiguousSubarray.front() == arr[i] || contiguousSubarray.back() == arr[i]) {
                        contiguousSubarrays.push_back(contiguousSubarray); // Push contiguousSubarray to contiguousSubarrays
                    }
                }
            }
        }
       contiguousSubarraysCount.push_back(contiguousSubarrays.size()); // Index i contains an integer denoting the maximum number of contiguous subarrays of arr[i]
    }

    return contiguousSubarraysCount; // Return contiguousSubarraysCount
}

int main() {
    Solution solution;

    vector <int> testOne{ 3, 4, 1, 6, 2 };
    vector <int> expectedOne{ 1, 3, 1, 5, 1 };

    vector <int> actualOne = solution.CountSubarrays(testOne);

    for (int i = 0; i < actualOne.size(); i++) {
        cout << actualOne[i] << " ";
    }

    cout << endl;

    // ----------------------------------------------------------

    Solution solutionTwo;

    vector <int> testTwo{ 2, 4, 7, 1, 5, 3 };
    vector <int> expectedTwo{ 1, 2, 6, 1, 3, 1 };

    vector <int> actualTwo = solutionTwo.CountSubarrays(testTwo);

    for (int i = 0; i < actualTwo.size(); i++) {
        cout << actualTwo[i] << " ";
    }

    cout << endl;

    return 0;
}