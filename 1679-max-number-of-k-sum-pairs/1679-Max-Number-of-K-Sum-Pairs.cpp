class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left = 0 , right = nums.size()-1;
        int operation = 0;
        while(left < right){
            int currSum = nums[left] + nums[right];
            
            if(currSum == k){
                operation++;
                left++;
                right--;
            }
            else if(currSum < k){
                left++;
            }
            else{
                right--;
            }
        }
        return operation;
    }
};