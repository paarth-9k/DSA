class Solution {
public:
    
    vector<string> result;
    void solve(string curr, int open, int close, int n)
    {
        if(curr.size() == 2 * n)
        {
            result.push_back(curr);
            return;
        }

        if(open < n)
        {
            solve(curr + '(', open + 1, close, n);
        }
        if(close < open)
        {
            solve(curr + ')', open, close + 1, n);
        }

    }
    
    vector<string> generateParenthesis(int n) {
        //build krrhe hai from empty
        solve("", 0, 0, n);
        return result;
    }
};