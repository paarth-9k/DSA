class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> xyz(nums.begin(), nums.end());

        return nums.size() != xyz.size();
    }
};
