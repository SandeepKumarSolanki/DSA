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
    void zigzagTraversal(TreeNode* root, vector<vector<int>> &result) {
        queue<TreeNode*> que;
        que.push(root);
        int k = 0;
        while(!que.empty()) {
            int N = que.size();
            vector<int> temp;
            for(int i = 0; i < N; i++)  {
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);
                if(node->left) {
                    que.push(node->left);
                }
                if(node->right) {
                    que.push(node->right);
                }
            }
            if(k % 2 == 0) {
                result.push_back(temp);
            } else {
                reverse(temp.begin(), temp.end());
                result.push_back(temp);
            }
            k = 1 - k;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> result;
        zigzagTraversal(root, result);
        return result;
    }
};