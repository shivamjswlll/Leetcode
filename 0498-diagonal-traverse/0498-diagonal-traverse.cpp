class Solution {
    void solve(int row,int col,int up,vector<int>&ans,vector<vector<int>> &mat){
        int m = mat.size();
        int n = mat[0].size();
        if(row == m-1 && col == n-1){
            ans.push_back(mat[row][col]);
            return;
        }

        if(up){
            int i = row;
            int j = col;

            while( i >= 0 && j < n){
                ans.push_back(mat[i][j]);
                i--;
                j++;
            }

            if(i < 0 && j < n){
                solve(i+1,j,0,ans,mat);
            }
            else{
                solve(i+2,j-1,0,ans,mat);
            }
        }
        else{
            int j = col;
            int i = row;
            while( i < m && j >= 0){
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
            if( j < 0 && i < m){
                solve(i,j+1,1,ans,mat);
            }
            else{
                solve(i-1,j+2,1,ans,mat);
            }
        }
    }
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        solve(0,0,1,ans,mat);

        return ans;
    }
};