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
    void traverseRightSideView(TreeNode* root, vector<int>& result) {
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int N = que.size();
            vector<int> temp;
            for(int i = 0; i < N; i++) {
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);
                if(node->left != NULL) {
                    que.push(node->left);
                }
                if(node->right != NULL) {
                    que.push(node->right);
                }
            }
            result.push_back(temp[temp.size()-1]);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        vector<int> result;
        traverseRightSideView(root, result);
        return result;
    }
};