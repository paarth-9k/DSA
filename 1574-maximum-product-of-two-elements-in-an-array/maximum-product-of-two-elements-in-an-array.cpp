class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> maxh;
        for(int i = 0; i < nums.size(); i++)
        {
            maxh.push(nums[i]);
        }
        int x = maxh.top();
        maxh.pop();
        int y = maxh.top();
        while(!maxh.empty())
        {
            maxh.pop();
        }
        return (x - 1) * (y - 1); 
    }
};