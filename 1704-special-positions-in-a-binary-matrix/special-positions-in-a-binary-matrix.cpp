class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ct = 0;
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 1)
                {
                    int rones = 0;
                    for(int k = 0; k < m; k++)
                    {
                        if(mat[k][j] == 1)
                            rones++; 
                    }
                    int cones = 0;
                    for(int k = 0; k < n; k++)
                    {
                        if(mat[i][k] == 1)
                            cones++; 
                    }
                    if(rones == 1 && cones == 1)
                    {
                        ct++;
                    }
                }
            }
        }
        return ct;
    }
};