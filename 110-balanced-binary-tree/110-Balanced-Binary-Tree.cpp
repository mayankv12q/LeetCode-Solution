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
    int checkHeight(TreeNode* root){
        if(root == NULL) return 0;

        int leftHt = checkHeight(root->left);
        if(leftHt == -1)  return -1;

        int rightHt = checkHeight(root->right);
        if(rightHt == -1) return -1;

        if(abs(leftHt - rightHt) > 1) return  -1;

        return max(leftHt,rightHt) + 1 ;
    }
 
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};