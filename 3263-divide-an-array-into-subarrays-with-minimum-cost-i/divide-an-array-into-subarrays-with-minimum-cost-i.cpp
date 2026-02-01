class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sub1 = nums[0];
        nums[0] = 1000;
        int min1 = 100;
        for(int i = 0; i < nums.size() ; i++)
        {
            if(nums[i] < min1)
                min1 = nums[i];
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == min1)
            {
                nums[i] = 1000;
                break;
            }
        }
        int min2 = 1000;
        for(int i = 0; i < nums.size() ; i++)
        {
            if(nums[i] < min2)
                min2 = nums[i];
        }
        return sub1+min1+min2;

    }
};