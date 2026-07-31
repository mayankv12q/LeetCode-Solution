class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.length();
        int plen = p.length();
        
        if(slen < plen) return{} ;

        vector<int> res;
        vector<int> pCount(26,0);
        vector<int> sCount(26,0);

        for(int i = 0; i < plen ;i++){
            pCount[p[i]-'a']++;
            sCount[s[i]-'a']++;
        }

        if(sCount == pCount) res.push_back(0);

        for(int i = plen ; i < slen ; i++){
            sCount[s[i]-'a']++;

            sCount[s[i-plen]-'a']--;

            if(sCount == pCount){
                res.push_back(i-plen+1);
            }
        }
        return res;
    }
};