class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> res;
        vector<int> left;
        vector<int> right(nums.size());
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            left.push_back(sum);
            sum += nums[i];
        }
        sum = 0;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            right[i] = sum;
            sum += nums[i];
        }
        for(int i = 0; i < nums.size(); i++)
        {
            res.push_back(abs(left[i] - right[i]));
        }
        return res;
    }
};