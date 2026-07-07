class Solution {
public:

    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
        {
            return;
        }

        grid[i][j] = 0;

        dfs(grid, i + 1 , j);
        dfs(grid, i - 1, j);
        dfs(grid, i , j + 1);
        dfs(grid, i , j - 1);

    }

    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        // Top row
        for (int col = 0; col < c; col++)
            if (grid[0][col] == 1)
                dfs(grid, 0, col);

        // Bottom row
        for (int col = 0; col < c; col++)
            if (grid[r - 1][col] == 1)
                dfs(grid, r - 1, col);

        // Left column
        for (int row = 0; row < r; row++)
            if (grid[row][0] == 1)
                dfs(grid, row, 0);

        // Right column
        for (int row = 0; row < r; row++)
            if (grid[row][c - 1] == 1)
                dfs(grid, row, c - 1);

        int ct = 0;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 1)
                    ct++;
            }
        }

        return ct;
    }
};