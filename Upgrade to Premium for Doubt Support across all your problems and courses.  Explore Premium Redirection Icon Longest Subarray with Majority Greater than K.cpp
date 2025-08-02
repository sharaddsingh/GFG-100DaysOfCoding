class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        unordered_map<int, int> first_occurrence;
    int prefix_sum = 0;
    int max_len = 0;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > k) {
            prefix_sum += 1;
        } else {
            prefix_sum -= 1;
        }

        if (prefix_sum > 0) {
            max_len = i + 1;
        }

        if (first_occurrence.find(prefix_sum) == first_occurrence.end()) {
            first_occurrence[prefix_sum] = i;
        }

        if (first_occurrence.find(prefix_sum - 1) != first_occurrence.end()) {
            int prev_index = first_occurrence[prefix_sum - 1];
            max_len = max(max_len, i - prev_index);
        }
    }

    return max_len;
        
    }
};
