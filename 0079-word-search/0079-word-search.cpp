class Solution {
    bool solve(int row,int col,int idx,string word,vector<vector<char>> &board){
        if(row >= board.size() || row < 0 || col >= board[0].size() || col < 0) return false;

        if(board[row][col] != word[idx]){
            return false;
        }
        if(idx == word.size()-1){
            return true;
        } 
        char a = board[row][col];
        board[row][col] = '-1';

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for(int i = 0;i<4;i++){
            int drow = row + dx[i];
            int dcol = col + dy[i];

            if(solve(drow,dcol,idx+1,word,board)) return true;

        }
        board[row][col] = a;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(word[0] == board[i][j] ){
                    if(solve(i,j,0,word,board)) return true;
                }
            }
        }

        return false;
    }
};