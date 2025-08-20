class Solution {
    bool dfs(int row,int col,int idx,string &word,vector<vector<int>> &vis,vector<vector<char>> &board){
        if(board[row][col] != word[idx]) return false;
        if(idx == word.size()-1) return true;
        int m = board.size();
        int n = board[0].size();
        
        vis[row][col] = 1;

        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};

        for(int i = 0;i<4;i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
    if(nrow >= m || nrow < 0 || ncol >= n || ncol < 0 || vis[nrow][ncol]) continue;
        if(dfs(nrow,ncol,idx+1,word,vis,board)) return true;
        }
        vis[row][col] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == word[0]){
                   if(dfs(i,j,0,word,vis,board)) return true;
                }
                
            }
        }
        return false;
    }
};