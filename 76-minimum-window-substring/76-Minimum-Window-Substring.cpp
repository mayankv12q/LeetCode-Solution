class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();

        if(n>m || n == 0) return "";

        unordered_map<char,int> tFreq ;

        for(char c : t){
            tFreq[c]++;
        }     

        int req = tFreq.size();
        int formed = 0;

        unordered_map<char,int> windowFreq ;
        int left = 0;
        int minLen = INT_MAX ;
        int startIdx = 0;

        for(int right = 0 ; right < m;right++){
            char c = s[right];
            windowFreq[c]++;

            if(tFreq.count(c) && windowFreq[c] == tFreq[c]){
                formed++;
            }

            while(left <= right && formed == req){
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                    startIdx = left ;
                }

                char leftChar = s[left] ;
                windowFreq[leftChar]--;

                if(tFreq.count(leftChar) && windowFreq[leftChar] < tFreq[leftChar]){
                    formed--;
                }

                left++;
            }
        }  
        return (minLen == INT_MAX) ? "" : s.substr(startIdx,minLen); 
    }
};