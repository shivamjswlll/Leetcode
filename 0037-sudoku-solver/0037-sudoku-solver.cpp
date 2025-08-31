class Solution {
public:
    bool isValid(char c,int row,int col,vector<vector<char>> &board){

        for(int i = 0;i<9;i++){
            if(board[i][col] == c) return false;
            if(board[row][i] == c) return false;
            int drow = (3*(row/3) + i/3);
            int dcol = (3*(col/3)+ i%3);
            if(board[drow][dcol] == c) return false;
        }
        return true;
    }
    bool Solve(vector<vector<char>> &board){

        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.'){
                   for(char c = '1';c<='9';c++){
                        if(isValid(c,i,j,board)){
                            board[i][j] = c;
                           if(Solve(board)) return true;
                            board[i][j] = '.';
                        }
                   }
                   return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        Solve(board);
    }
};