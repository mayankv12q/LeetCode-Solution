class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currentAltitude = 0;
        int maxAltitude = 0; // Starts at 0 (point 0)

        for (int g : gain) {
            currentAltitude += g;
            maxAltitude = max(maxAltitude, currentAltitude);
        }

        return maxAltitude;
    }
};