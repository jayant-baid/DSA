class Solution {
public:
    void solve(int col, int n, vector<string>& board, vector<vector<string>>& ans, 
               vector<int>& leftRow, vector<int>& upperDiagnal, vector<int>& lowerDiagnal){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(leftRow[row] == 0 && upperDiagnal[n-1+col-row] == 0 && lowerDiagnal[row+col] == 0){
                board[row][col]='Q';
                leftRow[row] = 1;
                upperDiagnal[n-1+col-row] = 1;
                lowerDiagnal[row+col] = 1;
                
                solve(col+1, n, board, ans, leftRow, upperDiagnal, lowerDiagnal);
                
                leftRow[row] = 0;
                upperDiagnal[n-1+col-row] = 0;
                lowerDiagnal[row+col] = 0;
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        
        vector<int> leftRow(n, 0), upperDiagnal(2*n-1, 0), lowerDiagnal(2*n-1, 0);
        
        solve(0, n, board, ans, leftRow, upperDiagnal, lowerDiagnal);
        return ans;
    }
};