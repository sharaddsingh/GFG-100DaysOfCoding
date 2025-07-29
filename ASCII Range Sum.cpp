Given a string s consisting of lowercase English letters, for every character whose first and last occurrences are at different positions, calculate the sum of ASCII values of characters strictly between its first and last occurrence.
Return all such non-zero sums (order does not matter).

Examples:

Input: s = "abacab"
Output: [293, 294]
Explanation: characters 'a' and 'b' appear more than once:
'a' : between positions 1 and 5 → characters are b, a, c and ascii sum is 98 + 97 + 99 = 294.
'b' : between positions 2 and 6 → characters are a, c, a and ascii sum is 97 + 99 + 97 = 293.

Constraints:
1 ≤ s.size() ≤ 105

// i learned how to use two unordered_map.

  class Solution {
public:
    vector<int> asciirange(string& s) {
        int n = s.length();
        vector<int> pf(n + 1);  

      
        for (int i = 0; i < n; ++i) {
            pf[i + 1] = pf[i] + s[i];
        }

        unordered_map<char, int> first, last;

        for (int i = 0; i < n; ++i) {
            if (first.find(s[i]) == first.end()) {
                first[s[i]] = i;
            }
            last[s[i]] = i;
        }

        vector<int> result;
        for (auto& entry : first) {
            char ch = entry.first;
            int i = first[ch], j = last[ch];
            if (j - i > 1) {
              
                int sum = pf[j] - pf[i + 1];
                result.push_back(sum);
            }
        }

        return result;
    }
};
