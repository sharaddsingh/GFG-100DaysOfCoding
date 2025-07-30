Q3) Given an unsorted array arr[] of integers, find the number of subarrays whose sum exactly equal to a given number k.

Examples:

Input: arr[] = [10, 2, -2, -20, 10], k = -10
Output: 3
Explaination: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum exactly equal to -10

Constraints:
1 ≤ arr.size() ≤ 105
-103 ≤ arr[i] ≤ 103
-105 ≤ k ≤ 105

i learned to trtaverse and calculate subarray sum equal to K
class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
    unordered_map<int, int> prefixSumFreq;
    int prefix_sum = 0, count = 0;

    for (int i = 0; i < arr.size(); ++i) {
        prefix_sum += arr[i];

        if (prefix_sum == k)
            count++;

        if (prefixSumFreq.find(prefix_sum - k) != prefixSumFreq.end()) {
            count += prefixSumFreq[prefix_sum - k];
        }

        prefixSumFreq[prefix_sum]++;
    }

    return count;

    }
};
