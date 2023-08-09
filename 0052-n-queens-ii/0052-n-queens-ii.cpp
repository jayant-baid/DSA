class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n){
        int duprow=row, dupcol=col;
//         Upper Diagonal
        while(row>=0 && col>=0){
            if(board[row][col] == 'Q')
                return false;
            row--, col--;
        }
        
        row=duprow;
        col=dupcol;
//         Lower Diagonal
        while(row<n && col>=0){
            if(board[row][col] == 'Q')
                return false;
            row++, col--;
        }
        
        row=duprow;
        col=dupcol;
//         Same Row
        while(col>=0){
            if(board[row][col] == 'Q')
                return false;
            col--;
        }
        return true;
    }
    int solve(int col, int n, vector<string>& board){
        if(col == n){
            return 1;
        }
        int ans=0;
        for(int row=0;row<n;row++){
            if(isSafe(row, col, board, n)){
                board[row][col]='Q';
                ans+=solve(col+1, n, board);
                board[row][col]='.';
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        return solve(0, n, board);
    }
};