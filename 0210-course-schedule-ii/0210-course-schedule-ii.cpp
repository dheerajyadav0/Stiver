class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<int> adj[], stack<int>& order) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, vis, pathVis, adj, order)) return true;
            } else if (pathVis[it]) {
                return true;  // Cycle detected
            }
        }

        pathVis[node] = 0;
        order.push(node);  // Store the course order in stack
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];  // Adjacency list
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);  // Edge from prerequisite to course
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        stack<int> order;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis, adj, order)) {
                    return {};  // Return empty vector if a cycle is detected
                }
            }
        }

        vector<int> result;
        while (!order.empty()) {
            result.push_back(order.top());
            order.pop();
        }
        return result;
    }
};