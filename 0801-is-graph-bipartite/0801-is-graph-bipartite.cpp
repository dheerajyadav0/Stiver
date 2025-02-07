class Solution {
private:
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = col;

        for (auto it : graph[node]) {
            if (color[it] == -1) {
                if (!dfs(it, !col, color, graph)) {
                    return false;
                }
            } else if (color[it] == col) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {  // Fix condition
                if (!dfs(i, 0, color, graph)) { //agar dfs n false return kiya toh 
                    return false;
                }
            }
        }
        return true;  
    }
};
