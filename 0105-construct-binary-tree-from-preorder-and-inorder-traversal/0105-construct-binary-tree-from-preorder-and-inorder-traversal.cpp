class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map to store indices of inorder elements for O(1) access
        unordered_map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);
    }

private:
    TreeNode* build(vector<int>& preorder, int prestart, int preend,
                    vector<int>& inorder, int instart, int inend,
                    unordered_map<int, int>& mpp) {
        if (prestart > preend || instart > inend) {
            return nullptr;
        }

        // Create the root node with the current value in preorder
        TreeNode* root = new TreeNode(preorder[prestart]);

        // Find the index of root in inorder
        int inroot = mpp[root->val];
        int numleft = inroot - instart;

        // Recursively build the left and right subtrees
        root->left = build(preorder, prestart + 1, prestart + numleft,
                           inorder, instart, inroot - 1, mpp);
        root->right = build(preorder, prestart + numleft + 1, preend,
                            inorder, inroot + 1, inend, mpp);

        return root;
    }
};
