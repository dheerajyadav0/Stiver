/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        stack<TreeNode*> st;
        int i = 0;
        int n = s.size();
        
        while(i < n) {
            int level = 0;
            while(i < n && s[i] == '-') {
                level++;
                i++;
            }
            
            int val = 0;
            while(i < n && isdigit(s[i])) {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            
            TreeNode* node = new TreeNode(val);
            
            while(st.size() > level) {
                st.pop();
            }
            
            if(!st.empty()) {
                if (!st.top()->left)
                    st.top()->left = node;
                else
                    st.top()->right = node;
            }
            
            st.push(node);
        }
        
        while(st.size() > 1) {
            st.pop();
        }
        return st.top();
    }
};