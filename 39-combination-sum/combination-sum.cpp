class Solution {
public:

    // backtracking
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(int idx, vector<int>& candidates, int target)\
    {
        if(target == 0)
        {
            ans.push_back(curr);
            return;
        }

        if(target < 0 || idx == candidates.size())
        {
            return;
        }

        //recursion aage jao check kro then back

        //case 1 same idx pai combinations
        curr.push_back(candidates[idx]);
        solve(idx, candidates, target - candidates[idx]);
        curr.pop_back();

        //case 2 move indx
        solve(idx + 1, candidates, target);
    }



    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, candidates, target);
        return ans;
    }
};