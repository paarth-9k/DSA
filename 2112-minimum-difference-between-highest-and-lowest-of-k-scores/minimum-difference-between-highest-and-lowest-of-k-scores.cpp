class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int minDiff = nums[k - 1] - nums[0];
        for(int i = 0; i + k <= nums.size(); i++)
        {
            minDiff = min(minDiff, nums[i + k - 1] - nums[i]);
        }
        return minDiff;
    }
};