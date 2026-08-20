class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        int leftSum = 0;

        // Step 1: Calculate the total sum of the array
        for (int x : nums) {
            totalSum += x;
        }

        // Step 2: Iterate through the array and check the pivot condition
        for (int i = 0; i < nums.size(); i++) {
            // Check if Left Sum equals Right Sum
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i; // Found the leftmost pivot
            }
            // Update leftSum for the next index
            leftSum += nums[i];
        }

        return -1; // No pivot found
    }
};