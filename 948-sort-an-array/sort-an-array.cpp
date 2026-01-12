class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> result(nums.size());
        priority_queue<int, vector<int>, greater<int>> minh;
        for(int i = 0; i < nums.size(); i++)
        {
            minh.push(nums[i]);
        } 
        int idx = 0;
        while(!minh.empty())
        {
            result[idx] = minh.top();
            minh.pop();
            idx++;
        }
        return result;
    }
};