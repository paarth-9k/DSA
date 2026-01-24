class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int j = nums.size() - 1;
        int i = 0;
        int maxSum = 0;
        while(i < j)
        {
            if(nums[i] + nums[j] > maxSum)
                maxSum = nums[i] + nums[j];
            i++;
            j--;
        }
        return maxSum;
    }
};