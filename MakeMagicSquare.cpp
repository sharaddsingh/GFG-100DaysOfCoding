Q1) A beautiful matrix is defined as a square matrix in which the sum of elements in every row and every column is equal. Given a square matrix mat[][], your task is to determine the minimum number of operations required to make the matrix beautiful.
In one operation, you are allowed to increment the value of any single cell by 1.

Examples:

Input: mat[][] = [[1, 2], 
                [3, 4]]
Output: 4
Explanation:
Increment value of cell(0, 0) by 3, 
Increment value of cell(0, 1) by 1. 
Matrix after the operations: [[4, 3], 
                            [3, 4]]
Here, sum of each row and column is 7.
Hence total 4 operation are required.


#include <iostream>
#include <vector>
#include <algorithm>  // for max
using namespace std;

class Solution {
public:
    int balanceSums(vector<vector<int>>& mat) {
        int m = mat[0].size();   // number of columns
        int n = mat.size();      // number of rows

        int totalSum = 0;        // total sum of matrix
        int maxSum = 0;          // maximum row or column sum

        // Loop through each row/column index
        for (int i = 0; i < n; ++i) {
            int rowSum = 0;
            int colSum = 0;

            for (int j = 0; j < m; ++j) {
                rowSum += mat[i][j];     // sum of current row
                colSum += mat[j][i];     // sum of current column

                totalSum += mat[i][j];   // accumulate total sum
            }

            // Update maxSum with max of current row and column sums
            maxSum = max({maxSum, rowSum, colSum});
        }

        // Final balanced total = maxSum per row × number of rows
        int balancedTotal = maxSum * n;

        // Return how much we need to add
        return balancedTotal - totalSum;
    }
};


