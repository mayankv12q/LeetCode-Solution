class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        //int maxCandies = *max_element(candies.begin(), candies.end());
        int maxCan = 0 ;
        for(int can : candies){
            maxCan = max(maxCan,can);
        }

        vector<bool> res ;

        for(int candy : candies){
            res.push_back(candy + extraCandies >= maxCan) ;
        }

        return res ;
    }
};