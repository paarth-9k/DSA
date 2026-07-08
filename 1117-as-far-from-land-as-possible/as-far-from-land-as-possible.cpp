class Solution {
public:
    // basically multisorce bfs from every land cell start bfs level order
    // traversal which when it stops. jab queue empty tab vo count of
    // interations hi max distance hoga
    int maxDistance(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    // land
                    q.push({i, j});
                }
            }
        }

        int ct = 0;

        if (q.empty() || q.size() == r * c)
            return -1;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int nr = x + dr[k];
                    int nc = y + dc[k];
                    if (nr >= 0 && nc >= 0 && nr < r && nc < c &&
                        grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            ct++;
        }

        return ct-1;
    }
};