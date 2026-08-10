class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCan = 0 ;
        for(int can : candies){
            if(can >= maxCan){
                maxCan = can;
            }
        }

        vector<bool> res ;

        for(int candy : candies){
            res.push_back(candy + extraCandies >= maxCan) ;
        }

        return res ;
    }
};