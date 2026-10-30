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
    bool isTrue(TreeNode* p, TreeNode* q) {
        if(!p && !q) {
            return true;
        }
        if(!p || !q) {
            return false;
        }
        return p->val == q->val && isTrue(p->left, q->left) && isTrue(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q != NULL) {
            return false;
        }
        if(p != NULL && q == NULL) {
            return false;
        }
        if(p == NULL && q == NULL) {
            return true;
        }

        return isTrue(p, q);
    }
};