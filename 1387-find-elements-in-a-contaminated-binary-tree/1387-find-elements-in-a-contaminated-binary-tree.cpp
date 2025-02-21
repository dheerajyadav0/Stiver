#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class FindElements {
private:
    unordered_set<int> values; // Store valid node values for O(1) lookup

    // Helper function to recover the tree using preorder traversal
    void preorder(TreeNode* root, int val) {
        if (!root) return; 

        root->val = val;      // Assign the correct value to the node
        values.insert(val);   // Store it in the hash set

        preorder(root->left, 2 * val + 1);  // Recover left child
        preorder(root->right, 2 * val + 2); // Recover right child
    }

public:
    FindElements(TreeNode* root) {
        if (root) preorder(root, 0); // Set root = 0 and recover the tree
    }

    bool find(int target) {
        return values.count(target); 
    }
};
