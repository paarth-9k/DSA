class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int i = 0, n = nums.size();
        int maxLen = 1;
        sort(nums.begin(), nums.end());
        for (int j = 0; j < n; j++) {
            while ((long long)nums[j] > (long long)nums[i] * k) {
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return n - maxLen;

    }
};