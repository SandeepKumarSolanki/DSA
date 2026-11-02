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
    int countLeftHeights(TreeNode* root) {
        int heights = 0;
        while(root) {
            heights++;
            root = root->left;
        }
        return heights;
    }
    int countRightHeights(TreeNode* root) {
        int heights = 0;
        while(root) {
            heights++;
            root = root->right;
        }
        return heights;
    }
    int maxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        if(root != NULL && root->left == NULL && root->right == NULL) {
            return 1;
        } 
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }
};