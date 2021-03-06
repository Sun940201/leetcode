/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *addOneRow(TreeNode *root, int v, int d) {
        class Utils {
        public:
            void add(TreeNode *root, int current, int v, int d) {
                if (root == nullptr) {
                    return;
                }
                if (current == d - 1) {
                    TreeNode *tempLeft = root->left;
                    TreeNode *newLeft = new TreeNode(v);
                    newLeft->left = tempLeft;
                    root->left = newLeft;

                    TreeNode *tempRight = root->right;
                    TreeNode *newRight = new TreeNode(v);
                    newRight->right = tempRight;
                    root->right = newRight;
                } else {
                    add(root->left, current + 1, v, d);
                    add(root->right, current + 1, v, d);
                }
            }
        };
        if (d == 1) {
            TreeNode *newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        Utils utils;
        utils.add(root, 1, v, d);
        return root;
    }
};