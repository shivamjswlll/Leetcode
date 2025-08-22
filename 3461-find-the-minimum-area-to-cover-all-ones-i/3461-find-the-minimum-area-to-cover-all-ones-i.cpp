class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int top = INT_MAX;
        int left = INT_MAX;
        int right = INT_MIN;
        int down = INT_MIN;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1){
                    top = min(i,top);
                    left = min(j,left);
                    right = max(right,j);
                    down = max(down,i);
                }
            }
        }
        int length = right-left + 1;
        int breadth = down - top + 1;
        
        return length*breadth;
    }
};