class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxv = 0;
        int x = accounts[0].size();
        for(int i = 0; i < accounts.size(); i++)
        {
            int sum = 0;
            for(int j = 0; j < x; j++)
            {
                sum += accounts[i][j];
            }
            maxv = max(maxv, sum);
        }
        return maxv;
    }
};