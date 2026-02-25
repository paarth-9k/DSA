class Solution {
public:
    static bool compare(int x, int y) {
        return to_string(x) + to_string(y) > to_string(y) + to_string(x);
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        if (nums[0] == 0) return "0";

        string res;
        for (int num : nums) {
            res += to_string(num);
        }
        return res;
    }
};