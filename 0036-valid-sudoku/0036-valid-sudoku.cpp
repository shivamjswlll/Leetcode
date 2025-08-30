class Solution {
public:
    bool isValid(int row,int col,vector<vector<char>> &board,char c){
        for(int i=0;i<9;i++){
            if(i != col && board[row][i] == c) return false;
            if(i != row && board[i][col] == c) return false;
            int duprow = 3*(row/3) + i/3;
            int dupcol = 3*(col/3) + i%3;
            if(duprow != row && dupcol != col && board[duprow][dupcol] == c) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] != '.' && !isValid(i,j,board,board[i][j])) return false;
            }
        }

        return true;
    }
};