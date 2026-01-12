class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        //min heap
        vector<int> result(nums.size());
        priority_queue<int, vector<int>, greater<int>> minh;
        for(int i = 0; i < nums.size(); i++)
        {
            minh.push(nums[i]);
        }
        int idx = 0;
        while(!minh.empty())
        {
            int x = minh.top();
            minh.pop();
            int y = minh.top();
            minh.pop();
            result[idx] = y;
            idx++;
            result[idx] = x;
            idx++;
        }
        return result;
    }
};