#include <iostream>
#include <vector>

using namespace std;

// Function to perform Josephus Permutation on a given vector
std::vector<int> josephusPermutation(std::vector<int>& array, int k) {
    // Vector to store the resulting permutation
    std::vector<int> permutation;
    
    // Starting index for Josephus Permutation
    int index = 0;

    // Continue the permutation until the input vector is empty
    while (!array.empty()) {
        // Calculate the next index using Josephus formula
        index = (index + k - 1) % array.size();

        // Get the item at the calculated index
        int item = array[index];

        // Erase the item at the calculated index from the input vector
        array.erase(array.begin() + index);

        // Add the item to the resulting permutation
        permutation.push_back(item);
    }

    // Return the final permutation
    return permutation;
}

int main() {
    // Number of soldiers
    int soldiers = 7;

    // Create a vector representing soldiers
    std::vector<int> arr(soldiers);

    // Initialize the vector with soldier numbers
    for (int i = 0; i < soldiers; ++i) {
        arr[i] = i + 1;
    }

    // Josephus Permutation parameter
    int k = 3;

    // Call the Josephus Permutation function
    std::vector<int> perm = josephusPermutation(arr, k);

    // Print the resulting permutation
    for (size_t i = 0; i < perm.size(); ++i) {
        std::cout << perm[i] << " ";
    }

    return 0;
}