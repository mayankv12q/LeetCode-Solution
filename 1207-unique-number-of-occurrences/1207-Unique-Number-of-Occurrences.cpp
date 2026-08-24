class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> countMap;
        for (int x : arr) {
            countMap[x]++;
        }

        unordered_set<int> uniqueFreqs;
        for (const auto& [val, freq] : countMap) {
            // If the frequency already exists in our set, it's not unique
            if (!uniqueFreqs.insert(freq).second) {
                return false;
            }
        }

        return true;
    }
};