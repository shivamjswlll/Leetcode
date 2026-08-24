class Solution {
    bool isValid(int row,int col,vector<string> board){
        //upward
        for(int i = 0;i<row;i++){
            if(board[i][col] == 'Q') return false;
        }
        //left
        int drow = row;
        int dcol = col;
        while(drow >= 0 && dcol >=0){
            if(board[drow][dcol] == 'Q') return false;
            drow--;
            dcol--;
        }
        //right
        drow = row;
        dcol = col;

        while(drow >= 0 && dcol < board.size()){
            if(board[drow][dcol] == 'Q') return false;
            drow--;
            dcol++;
        }

        return true;

    }
    void solve(int row,int n,vector<string> board,vector<vector<string>> &ans){

        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int i = 0;i<n;i++){
            if(isValid(row,i,board)){
                board[row][i] = 'Q';
                solve(row+1,n,board,ans);
                board[row][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));

        solve(0,n,board,ans);

        return ans;

    }
};