class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(); // O(N+M)
        int m = needle.length();

        if(m == 0) return 0;
        if(m > n) return -1;

        vector<int> lps(m,0);
        int prelps = 0;
        int i = 1;

        while(i<m){
            if(needle[i] == needle[prelps]){
                lps[i++] = ++prelps;
            }
            else if(prelps == 0){
                lps[i++] = 0;
            }
            else{
                prelps = lps[prelps - 1];
            }
        }

        i = 0;
        int j = 0;
        
        while(i<n){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }
            else{
                if(j == 0 ) i++;
                else  j = lps[j-1] ;
            }

            if(j == m){
                return i-m ;
            }
        }

        return -1;
    }
};



/* O(M*N)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        if(m > n) return -1;

        for(int i = 0 ; i <= n-m ; i++){
            int j = 0;
            while(j < m && haystack[i+j] == needle[j]){
                j++;
            }

            if(j == m){
                return i;
            }
        }
        return -1;
    }
};
*/