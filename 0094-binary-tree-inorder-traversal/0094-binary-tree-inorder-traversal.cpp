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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;        
    }

private:
    void inorder(TreeNode* node, vector<int>& res) {
        if (!node) {
            return;
        }
        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
    }    
};





// vector<int> morris(TreeNode* root){
//     vector<int> inorder;
//     TreeNode* cur = root;
//     while(cur!NULL){
//         uf(cur->left == NULL){
//             inorder.push_back(cur->val);
//             cur = cur->right;
//         }else{
//             TreeNode* prev = cur->left;
//             while(prev->right && prev->right != cur){
//                 prev = prev->right;
//             }
//             if(prev->right ==NULL){
//                 prev->right = cur;
//                 cur = cur->left;
//             }
//             else{
//                 prev->right =NULL;
//                 inorder.push_back(cur)->val;

//                 cur = cur->right;
//             }
//         }
//     }
//     return inorder

// }