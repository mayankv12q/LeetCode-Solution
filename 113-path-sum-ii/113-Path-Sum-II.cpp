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
    vector<vector<int>> ans;

    void dfs(TreeNode* root,int targ,vector<int>& currPath){
        if(!root) return ;

        currPath.push_back(root->val);
        targ -= root->val ;

        if(!root->left && !root->right){
            if(targ == 0){
                ans.push_back(currPath);
            }
        }
            else{
                dfs(root->left,targ,currPath);
                dfs(root->right,targ,currPath);
            }
        
        currPath.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ans.clear();
        vector<int> currPath;
        dfs(root,targetSum,currPath);
        return ans;
    }
};