class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //boore voting algo
        int candidate = 0;
        int ct = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(ct == 0)
            {
                candidate = nums[i];
            }
            if(candidate == nums[i])
            {
                ct++;
            }
            else
            {
                ct--;
            }
        }
        return candidate;
    }
};