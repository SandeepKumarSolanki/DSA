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
    void calculateAverage(TreeNode* root, vector<double>& result) {
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int N = que.size();
            double temp = 0.0;
            for(int i = 0; i < N; i++) {
                TreeNode* node = que.front();
                que.pop();
                temp += node->val;
                if (node->left != NULL) {
                    que.push(node->left);
                }
                if(node->right != NULL) {
                    que.push(node->right);
                }
            }
            double average = temp/N;
            result.push_back(average);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        if ( root == nullptr) {
            return {};
        }
        vector<double> result;
        calculateAverage(root, result);
        return result;
    }
};