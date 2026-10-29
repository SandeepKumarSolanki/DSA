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
    void levelOrderTraversal(TreeNode* root, vector<vector<int>> &result) {
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int N = que.size();
            vector<int> temp;
            for(int i = 0; i < N; i++) {
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);
                if(node->left != nullptr) 
                    que.push(node->left);
                if(node->right != nullptr)
                    que.push(node->right);
            }
            result.push_back(temp);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        vector<vector<int>> result;
        levelOrderTraversal(root, result);
        return result;
    }
};