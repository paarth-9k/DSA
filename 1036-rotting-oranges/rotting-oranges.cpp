class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        //bfs
        int fresh = 0;
        queue<pair<int, int>> q;
        int mins = 0;

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});

                }
                if(grid[i][j] == 1)
                {
                    fresh++;
                }

            }
        }

        if(fresh == 0)
            return 0;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while(!q.empty())
        {
            bool change = false;
            int sz = q.size();

            for(int i = 0; i < sz; i++)
            {   
                
                int rn = q.front().first;
                int cn = q.front().second;
                q.pop();

                for(int j = 0; j < 4; j++)
                {
                    int rnew = rn + dr[j];
                    int cnew = cn + dc[j];

                    if(rnew >= 0 && cnew >= 0 && rnew < r && cnew < c && grid[rnew][cnew] == 1)
                    {
                        grid[rnew][cnew] = 2;
                        fresh--;
                        change = true;
                        q.push({rnew, cnew});
                    }
                }   
            }
            if(change)
            {
                mins++;
            } 
        }

        int result = fresh == 0 ? mins : -1;

        return result;
    }
};