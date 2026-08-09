class Solution {
public:
    void backtrack(int start,vector<int>& nums,vector<int>& path,vector<vector<int>>& result){
        result.push_back(path);

        for(int i = start;i < nums.size();i++){
            path.push_back(nums[i]);
            backtrack(i+1,nums,path,result);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> result;
        backtrack(0,nums,path,result);
        return result;
    }
};