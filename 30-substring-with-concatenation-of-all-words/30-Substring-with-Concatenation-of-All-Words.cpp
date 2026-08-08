class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(s.empty() || words.empty()) return res;

        int n = s.length();
        int k = words.size();
        int wordLen = words[0].length();

        int totalLen = k * wordLen ;

        if(n < totalLen) return res;

        unordered_map<string,int> wordCount ;

        for(const string& w : words){
            wordCount[w]++;
        }

        for(int offset = 0 ; offset < wordLen ; offset++){
            unordered_map<string,int> seen ;
            int count = 0 ;
            int left = offset ;

            for(int right = offset ; right + wordLen <= n ; right += wordLen){
                string sub = s.substr(right,wordLen);

                if(wordCount.count(sub)){
                    seen[sub]++;
                    count++;

                    while(seen[sub] > wordCount[sub]){
                        string leftsub = s.substr(left,wordLen);
                        seen[leftsub]--;
                        count--;
                        left += wordLen ;
                    }

                    if(count == k){
                        res.push_back(left);
                    }
                }
                    else{
                        seen.clear();
                        count = 0;
                        left = right + wordLen;
                    }
            }

        }
        return res;
    }
};