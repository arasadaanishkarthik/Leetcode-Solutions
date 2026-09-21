1class Solution {
2public:
3    vector<long long> resultArray(vector<int>& nums, int k) {
4        vector<long long> ans(k, 0);
5        vector<long long> dp(k, 0);
6
7        for (int num : nums) {
8            vector<long long> newDp(k, 0);
9
10            // Start a new subarray containing only nums[i]
11            newDp[num % k]++;
12
13            // Extend all previous subarrays
14            for (int r = 0; r < k; r++) {
15                if (dp[r] > 0) {
16                    int newRemainder = (r * (num % k)) % k;
17                    newDp[newRemainder] += dp[r];
18                }
19            }
20
21            dp = newDp;
22
23            // Every subarray ending here is a valid operation
24            for (int r = 0; r < k; r++) {
25                ans[r] += dp[r];
26            }
27        }
28
29        return ans;
30    }
31};