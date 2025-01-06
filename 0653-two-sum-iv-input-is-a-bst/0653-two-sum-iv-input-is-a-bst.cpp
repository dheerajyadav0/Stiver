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
    void storeInorder(TreeNode* root, vector<int>& v) {
        if (!root)
            return;

        storeInorder(root->left, v);  // L
        v.push_back(root->val);       // N
        storeInorder(root->right, v); // R
    }
    bool findTarget(TreeNode* root, int k) {

        vector<int> v; // vector for storing inorder
        storeInorder(root, v);
        int start = 0, end = v.size() - 1;

        // 2 pointer approach
        while (start < end) {

            int sum = v[start] + v[end];

            if (sum == k)
                return true;
            else if (sum > k) { // sum bada hai ,chhoti value chahiye
                end--;
            } else { // sum chhota hai ,badi value chahiye
                start++;
            }
        }
        return false;
    }
};