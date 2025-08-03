You are given a 2D integer matrix mat[][] of size n × m and a list of q operations opr[][]. Each operation is represented as an array [v, r1, c1, r2, c2], where:

v is the value to be added
(r1, c1) is the top-left cell of a submatrix
(r2, c2) is the bottom-right cell of the submatrix (inclusive)
For each of the q operations, add v to every element in the submatrix from (r1, c1) to (r2, c2). Return the final matrix after applying all operations.

Examples:

Input: mat[][] = [[1, 2, 3],  opr[][] = [[2, 0, 0, 1, 1], [-1, 1, 0, 2, 2]]
                [1, 1, 0],
                [4,-2, 2]]
Output: [[3, 4, 3],
        [2, 2, -1],
        [3, -3, 1]] 
Explanation: 
 
Constraint:
1 ≤ n×m, q ≤ 105
0 ≤ r1 ≤ r2 ≤ n - 1
0 ≤ c1 ≤ c2 ≤ m - 1
-104 ≤ mat[i][j], v ≤ 104

   int n = mat.size();
    int m = mat[0].size();

    // Step 1: Create diff matrix
    vector<vector<int>> diff(n + 2, vector<int>(m + 2, 0));

    // Step 2: Apply each operation to the diff matrix
    for (auto& op : opr) {
        int v = op[0], r1 = op[1], c1 = op[2], r2 = op[3], c2 = op[4];
        diff[r1][c1] += v;
        diff[r1][c2 + 1] -= v;
        diff[r2 + 1][c1] -= v;
        diff[r2 + 1][c2 + 1] += v;
    }

    // Step 3: Compute prefix sums over rows
    for (int i = 0; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            diff[i][j] += diff[i][j - 1];

    // Step 4: Compute prefix sums over columns
    for (int j = 0; j <= m; ++j)
        for (int i = 1; i <= n; ++i)
            diff[i][j] += diff[i - 1][j];

    // Step 5: Apply diff to the original matrix
    vector<vector<int>> result = mat;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            result[i][j] += diff[i][j];

    return result;
