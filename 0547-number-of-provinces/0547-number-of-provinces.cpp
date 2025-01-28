
class Solution {
private:
    void bfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto it : adj[curr]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);  // Adjacency list
        vector<int> vis(n, 0);      // Visited array
        int provinces = 0;

        // Create adjacency list from the adjacency matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        // Perform BFS for each unvisited node
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                provinces++;
                bfs(i, adj, vis);
            }
        }

        return provinces;
    }
};
