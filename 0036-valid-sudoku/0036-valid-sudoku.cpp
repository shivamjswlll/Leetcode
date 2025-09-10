class Solution {
    bool isValid(int row,int col,vector<vector<char>> &board){
        char a = board[row][col];
        for(int i = 0;i<9;i++){
            if( i != col && board[row][i] == a) return false;
            if( i != row && board[i][col] == a) return false;
            int duprow = 3*(row/3)+ i/3;
            int dupcol = 3*(col/3)+ i%3;
            if(duprow != row && dupcol != col && board[duprow][dupcol] == a) return false;
        }
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] != '.'){
                    if(!isValid(i,j,board)) return false;
                }
            }
        }
        return true;
    }
};