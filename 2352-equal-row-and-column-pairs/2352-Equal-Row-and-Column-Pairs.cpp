class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> rowFreq ;
        int n = grid.size() ;

        for(int r = 0 ; r < n ; r++){
            rowFreq[grid[r]]++;
        }

        int count = 0;

        for(int c = 0 ; c < n ; c++){
            vector<int> col(n) ;

            for(int r = 0 ; r < n ; r++){
                col[r] = grid[r][c];
            }

            if(rowFreq.count(col)){
                count += rowFreq[col] ;
            }
        }
        return count ;
    }
};