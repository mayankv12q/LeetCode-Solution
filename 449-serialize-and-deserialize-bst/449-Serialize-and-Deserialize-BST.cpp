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
private:
    void serializeHelper(TreeNode* root,string& res) {
        if(!root) return ;

        res += to_string(root->val) + " " ;

        serializeHelper(root->left,res);
        serializeHelper(root->right,res);
    }

    TreeNode* deserializeHelper(const vector<int>& val, int& idx,int lower,int upper){
        if(idx >= val.size()) return NULL ;
        if(val[idx] < lower || val[idx] > upper) return NULL ;

        int currVal = val[idx++] ;
        TreeNode* root = new TreeNode(currVal) ;

        root->left = deserializeHelper(val,idx,lower,currVal);
        root->right = deserializeHelper(val,idx,currVal,upper);

        return root ;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "" ;
        serializeHelper(root,res) ;
        return res ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL ;

        vector<int> val ;
        stringstream ss(data) ;
        int num ;

        while(ss >> num){
            val.push_back(num);
        }

        int idx = 0 ;

        return deserializeHelper(val,idx,INT_MIN,INT_MAX) ;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;