class Solution {
public:
    int arrangeCoins(int n) {
        long low = 1, high = n;
        int ans = 0;
        while(low <= high){
            int mid  = low + (high-low) / 2;
            
            long coinsUsed = 1LL * mid * (mid + 1) / 2;

            if(coinsUsed <= n){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};

/*
    int arrangeCoins(int n) {
    return (sqrt(1.0 + 8.0 *n)-1.0) /2 ;
    }
*/