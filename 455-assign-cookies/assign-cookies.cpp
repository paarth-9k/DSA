class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort krlo
        int n = g.size();
        int m = s.size();
        int satisfied = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        int j = 0;
        while(i < n && j < m)
        {
            if(g[i] <= s[j])
            {
                i++;
                j++;
                satisfied++;
            }
            else
            {
                j++;
            }
        }
        return satisfied;

    }
};