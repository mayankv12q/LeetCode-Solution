class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int totalBoom = 0;
        int n = points.size();

        for(int i = 0 ; i < n ; i++){
            unordered_map<int,int> distCount;

            for(int j = 0;j < n;j++){
                if(i == j) continue;

                int dx = points[i][0] - points[j][0]; 
                int dy = points[i][1] - points[j][1];

                int distSq = dx * dx + dy * dy;

                distCount[distSq]++;
            }

            for (auto& [dist, m] : distCount) {
                totalBoom += m * (m - 1);
            }
        }
        return totalBoom ;
    }
};