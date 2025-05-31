/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "#,";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if (!cur) s.append("#,");
            else {
                s.append(to_string(cur->val) + ',');
                q.push(cur->left);
                q.push(cur->right);
            }
        }

        return s;
    }

    TreeNode* deserialize(string data) {
        if (data == "#,") return NULL;

        vector<string> words;
        string word;
        stringstream ss(data);

        while (getline(ss, word, ',')) {
            words.push_back(word);
        }

        TreeNode* root = new TreeNode(stoi(words[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < words.size()) {
            TreeNode* node = q.front();
            q.pop();

            if (i < words.size() && words[i] != "#") {
                node->left = new TreeNode(stoi(words[i]));
                q.push(node->left);
            }
            i++;

            if (i < words.size() && words[i] != "#") {
                node->right = new TreeNode(stoi(words[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));