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
    #define pni pair<TreeNode*, int>

private:
    pni findLCA(TreeNode* curr) {
        if (!curr) return {nullptr, 0};  // base case

        pni lft = findLCA(curr->left);
        pni rgt = findLCA(curr->right);

        if (lft.second == rgt.second) {
            return {curr, rgt.second + 1};
        } else if (lft.second > rgt.second) {
            return {lft.first, lft.second + 1};
        } else {
            return {rgt.first, rgt.second + 1};
        }
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return findLCA(root).first;
    }
};
