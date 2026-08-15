class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int count = 0;
        for(int i = 0 ; i < k ; i++){
            if(isVowel(s[i])){
                count++;
            }
        }

        int maxV = count;

        if(maxV == k) return k;

        for(int i = k ; i < n; i++){
           if(isVowel(s[i])){
            count++;
           }
           if(isVowel(s[i-k])){
            count--;
           }

           maxV = max(maxV,count);
           if(maxV == k) return k;
        }

        return maxV;
    }
};