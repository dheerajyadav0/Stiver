class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int, pair<int, int>>> q;
        
    
        int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        dist[0][0] = 1;
        q.push({1, {0, 0}});  

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // If destination is reached
            if (r == n - 1 && c == n - 1)
                return dis;

            for (int i = 0; i < 8; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if (newr >= 0 && newr < n && newc >= 0 && newc < n && 
                    grid[newr][newc] == 0 && dis + 1 < dist[newr][newc]) {

                    dist[newr][newc] = dis + 1;
                    q.push({dis + 1, {newr, newc}});
                }
            }
        }

        return -1;  
    }
};
